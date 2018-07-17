#include "mainwindow.h"
#include "ui_mainwindow.h"

#define sind(x) (sin((x) * M_PI / 180))
#define cosd(x) (cos((x) * M_PI / 180))

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // initialize the monkey pose class
    monkeypose = new MonkeyPose_::MonkeyPose(focal);
    monkeypose->monkey_renderer.mCamera->setNearClipDistance(d1);
    monkeypose->monkey_renderer.mCamera->setFarClipDistance(d2);
    monkeypose->monkey_node->setPosition(0,-200,-1200);

    ui->vangle->setRange(0,360);
    ui->scale->setRange(75,125);
    ui->scale->setValue(100); // this is to set the initial value

    ui->xpos->setRange(-75,75);
    ui->ypos->setRange(-75,75);
    ui->zpos->setRange(0,1000);

    ui->yaw->setRange(0,360);
    ui->pitch->setRange(0,360);
    ui->roll->setRange(0,360);

    ui->abdomen->setRange(-15,10);
    ui->neck->setRange(-15,15);
    ui->head->setRange(-15,15);

    // provide handles for the pose controls with joint indices to be modified in the Ogre model
    dial_pose_controls.push_back(ui->abdomen); dial_jnt_num.push_back(57);
    dial_pose_controls.push_back(ui->neck); dial_jnt_num.push_back(97);
    dial_pose_controls.push_back(ui->head); dial_jnt_num.push_back(98);

    // similarly for sliders
    slider_pose_controls.push_back(ui->l_collar); slider_jnt_num.push_back(59);
    slider_pose_controls.push_back(ui->l_arm); slider_jnt_num.push_back(60);
    slider_pose_controls.push_back(ui->l_hand); slider_jnt_num.push_back(62);
    slider_pose_controls.push_back(ui->l_thigh); slider_jnt_num.push_back(38);
    slider_pose_controls.push_back(ui->l_shin); slider_jnt_num.push_back(39);
    slider_pose_controls.push_back(ui->l_foot); slider_jnt_num.push_back(21);

    slider_pose_controls.push_back(ui->r_collar); slider_jnt_num.push_back(78);
    slider_pose_controls.push_back(ui->r_arm); slider_jnt_num.push_back(79);
    slider_pose_controls.push_back(ui->r_hand); slider_jnt_num.push_back(81);
    slider_pose_controls.push_back(ui->r_thigh); slider_jnt_num.push_back(19);
    slider_pose_controls.push_back(ui->r_shin); slider_jnt_num.push_back(20);
    slider_pose_controls.push_back(ui->r_foot); slider_jnt_num.push_back(40);

    for (int j=0; j < slider_jnt_num.size(); ++j){
        slider_pose_controls[j]->setRange(-50,50);
    }

    jnts_to_display.push_back(std::vector<int>());
    jnts_to_display[0].push_back(97); jnts_to_display[0].push_back(60); jnts_to_display[0].push_back(61); jnts_to_display[0].push_back(62); jnts_to_display[0].push_back(69); jnts_to_display[0].push_back(71);

    jnts_to_display.push_back(std::vector<int>());
    jnts_to_display[1].push_back(97); jnts_to_display[1].push_back(79); jnts_to_display[1].push_back(80); jnts_to_display[1].push_back(81); jnts_to_display[1].push_back(91); jnts_to_display[1].push_back(93);

    jnts_to_display.push_back(std::vector<int>());
    jnts_to_display[2].push_back(57); jnts_to_display[2].push_back(38); jnts_to_display[2].push_back(39); jnts_to_display[2].push_back(40); jnts_to_display[2].push_back(41); jnts_to_display[2].push_back(50);

    jnts_to_display.push_back(std::vector<int>());
    jnts_to_display[3].push_back(57); jnts_to_display[3].push_back(19); jnts_to_display[3].push_back(20); jnts_to_display[3].push_back(21); jnts_to_display[3].push_back(22); jnts_to_display[3].push_back(31);

    jnts_to_display.push_back(std::vector<int>());
    jnts_to_display[4].push_back(100); jnts_to_display[4].push_back(97); jnts_to_display[4].push_back(57);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief getfilelist
 * @param "path" is the selected folder via the file browser
 * @return updates a member structure directly
 */
inline void get_file_list(MainWindow * w, QString path)
{
    QDir dirinfo(path);
    // get all files in the given directory
    QStringList fileList = dirinfo.entryList();
    // get only the image files.. usually they are only pngs
    for (auto file:fileList) {
        if (file.contains(".png")) {
            FileItem f(path,file);
            w->listOfFiles.push_back(f);
        }
    }
}


/**
 * @brief MainWindow::xyztouvd
 * @param xyz
 * @return
 */
vec3f MainWindow::xyztouvd(vec3f xyz) {
    vec3f uvd;
    uvd.y = xyz.x/xyz.z * (-focal) + cx;
    uvd.x = -xyz.y/xyz.z * (-focal) + cy;
    uvd.z = -xyz.z;
    return uvd;
}

/**
 * @brief MainWindow::uvdtoxyz
 * @param uvd
 * @return
 */
vec3f MainWindow::uvdtoxyz(vec3f uvd){
    vec3f xyz;
    xyz.x = ((cx - uvd.y) / (-focal)) * uvd.z;
    xyz.y = ((uvd.x - cy) / (-focal)) * uvd.z;
    xyz.z = -uvd.z;
    return xyz;
}

std::vector<vec3f> MainWindow::get_point_list(cv::Mat img, vec3f mu)
{
    vec3f uvd_mu = xyztouvd(mu);
    std::vector<vec3f> dpt_pts;

    int x_start = std::max(0,int(uvd_mu.x)-150);
    int x_end = std::min(int(uvd_mu.x)+150,img.rows);
    int y_start = std::max(0,int(uvd_mu.y)-150);
    int y_end = std::min(int(uvd_mu.y)+150,img.cols);
    int z_start = uvd_mu.z - 500;
    int z_end = uvd_mu.z + 500;

    for (int r = x_start; r < x_end; r++){
        for (int c = y_start; c < y_end; c++){
            vec3f v = MainWindow::uvdtoxyz(vec3f(r,c,img.at<u_int16_t>(r,c)));
            int d = abs(v.z);
            if ((d < z_start) || (d > z_end)){
                continue;
            }
            dpt_pts.push_back(v);
        }
    }
    return dpt_pts;
}

inline std::vector<vec3f> rotate_points(std::vector<vec3f> pts, vec3f mu, float angle)
{
    std::vector<vec3f> rotated_pts;
    // rotation about z
    for(auto pt : pts){
        pt -= mu;
        vec3f v;
        v.x = pt.x * cosd(angle) + pt.z * sind(angle);
        v.y = pt.y;
        v.z = -pt.x * sind(angle) + pt.z * cosd(angle);
        v.z -= 1500;
        rotated_pts.push_back(v);
    }
    return rotated_pts;
}

void MainWindow::paint_on_image(cv::Mat& dst, std::vector<vec3f> pts, cv::Vec3b color)
{
    for (auto pt : pts){
        vec3f v = xyztouvd(pt);
        dst.at<cv::Vec3b>(int(v.x),int(v.y)) = color;
    }
}

void MainWindow::apply_current_pose_parameters()
{
    using namespace Ogre;
    this->monkeypose->monkey_node->setPosition(0,0,-1200-this->ui->zpos->value());
    float scale = this->ui->scale->value()/100.;
    this->monkeypose->monkey_node->setScale(this->monkeypose->orgscale * scale);

    for (int j = 0; j < dial_jnt_num.size(); ++j){
        monkeypose->SetJointOrientation(dial_jnt_num[j],dial_pose_controls[j]->value(),0,0);
    }

    for (int j = 0; j < slider_jnt_num.size(); ++j){
        monkeypose->SetJointOrientation(slider_jnt_num[j],slider_pose_controls[j]->value(),0,0);
    }

    monkeypose->SetJointOrientation(1,ui->pitch->value(),ui->yaw->value(),ui->roll->value());

    /**
        This convoluted logic needs to be done because the monkey model has an
        extremely long pivot. This is for all practical purposes the controller bone.
        To precisely want the monkey at a particular position, we need to set this bone
        and then find out the offset to move the node
    */
    this->monkeypose->skeleton->getBone(0)->setPosition(this->ui->xpos->value(),this->ui->ypos->value(),0);
    Vector3 pos = monkeypose->GetJointPosition(0);
    Vector3 dpos = monkeypose->GetJointPosition(0) - monkeypose->GetJointPosition(1);
    this->monkeypose->monkey_node->setPosition(dpos.x+pos.x,dpos.y+pos.y,dpos.z+pos.z);

    this->monkeypose->Render();
}

void MainWindow::get_side_view(cv::Mat& dst, const cv::Mat src, cv::Vec3b color, float angle)
{
    // get the location of the chest
    Ogre::Vector3 root = this->monkeypose->GetJointPosition(58);
    vec3f mu(root.x,root.y,root.z);
    std::vector<vec3f> dpt_pts = get_point_list(src,mu);
    std::vector<vec3f> rot_pts = rotate_points(dpt_pts,mu,angle);
    paint_on_image(dst, rot_pts, color);
}

void MainWindow::draw_skeleton(cv::Mat& dst)
{
    using namespace Ogre;

    for (int chain = 0; chain < jnts_to_display.size(); chain++){
        vec3f _prev;
        for (int jnt = 0; jnt < jnts_to_display[chain].size(); ++jnt){
            Vector3 v = this->monkeypose->GetJointPosition(jnts_to_display[chain][jnt]);
            vec3f _v = xyztouvd(vec3f(v.x,v.y,v.z));
            cv::circle(dst, cvPoint2D32f(_v.y,_v.x), 3, cv::Scalar(255,0,0));
            if (jnt > 0){
                cv::line(dst,cvPoint2D32f(_v.y,_v.x),cvPoint2D32f(_prev.y,_prev.x),cv::Scalar(0,0,255),2);
            }
            _prev = _v;
        }
    }
}

void MainWindow::update_views()
{
    // apply the current pose parameters and get the rendered image
    apply_current_pose_parameters();
    this->monkeypose->Render();

    IMGT<float> depthKN;
    depthKN.Create(cvSize(monkeypose->depth->width,monkeypose->depth->height),16,1);
    ImgProcDepth::CvtDepthGL2KN(monkeypose->depth,depthKN,d1,d2,focal);
    cv::Mat render_image_d = depthKN.img;

    //cv::Mat render_image = this->monkeypose->shortdepth;
    cv::Mat render_image = IMGShow::colormap(render_image_d, this->d1, this->d2, true);

    //cv::Mat overlap_view1 = 0.4*depth_color + 0.6*render_image;
    cv::Mat overlap_view1;
    cv::addWeighted(render_image,0.5,this->depth_color,0.5,0.0,overlap_view1);

    draw_skeleton(overlap_view1);
    QImage qcolor((const unsigned char*)(overlap_view1.data), this->width, this->height, QImage::Format_RGB888);
    this->ui->view1->setPixmap(QPixmap::fromImage(qcolor));

    // create an empty placeholder for the side view panel
    cv::Mat side_view(cv::Size(width, height), CV_8UC3, cv::Scalar(0,0,0));
    // paint depth points from both data and render
    get_side_view(side_view, depth_image, cv::Vec3b(128,128,128), ui->vangle->value());
    get_side_view(side_view, render_image_d, cv::Vec3b(0,128,0), ui->vangle->value());

    // update the view panel
    QImage qsidecolor((const unsigned char*)(side_view.data), this->width, this->height, QImage::Format_RGB888);
    this->ui->view2->setPixmap(QPixmap::fromImage(qsidecolor));
}

/**
 * @brief Updates the file list on the right panel, on load and subsequent modifications
 * @param imageFiles
 */
void MainWindow::update_file_list()
{
    int row = 0;
    for (auto a : this->listOfFiles) {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(a.fileName);
        MainWindow::ui->ui_file_list->insertItem(row, newItem);
        if (a.isAnnotated) {
            MainWindow::ui->ui_file_list->item(row)->setForeground(Qt::green);
        }
        else {
            MainWindow::ui->ui_file_list->item(row)->setForeground(Qt::gray);
        }
        row++;
    }
}

void MainWindow::refresh_file_list()
{
    int row = 0;
    for (auto a : this->listOfFiles) {
        if (a.isAnnotated) {
            MainWindow::ui->ui_file_list->item(row)->setForeground(Qt::green);
        }
        else {
            MainWindow::ui->ui_file_list->item(row)->setForeground(Qt::gray);
        }
        row++;
    }
}

/**
 * @brief MainWindow::on_actionLoad_folder_triggered
 * Open a file browser and select the folder containing the images to be annotated
 */
void MainWindow::on_actionLoad_folder_triggered()
{
    QFileDialog dialog(this);
    // by default start from /home
    dialog.setDirectory(QDir::homePath());
    // lets the user only pick a directory
    dialog.setFileMode(QFileDialog::Directory);

    QStringList folderName;
    if (dialog.exec())
        folderName = dialog.selectedFiles();

    // if something went wrong and no folder was selected
    if (folderName.isEmpty())
        return;
    get_file_list(this,folderName.at(0));
    update_file_list();
}

void MainWindow::simulate_itemDoubleClicked()
{
    refresh_file_list();
    curRow = this->ui->ui_file_list->currentRow();
    QString fullPath = this->listOfFiles[curRow].path + "/" +  this->ui->ui_file_list->item(curRow)->text();
    MainWindow::ui->ui_file_list->item(curRow)->setForeground(Qt::red);
    // Read in the depth image
    depth_image = cv::imread(fullPath.toUtf8().constData(),cv::IMREAD_ANYDEPTH);
    // make a colorized version of the depthmap
    depth_color = IMGShow::colormap(depth_image, this->d1, this->d2,true);
    // if this has been annotations, load in the pose
    if (listOfFiles[curRow].isAnnotated) {
        //TODO
    }
    // update the view panels
    update_views();
}

void MainWindow::on_ui_file_list_itemDoubleClicked(QListWidgetItem *item)
{
//    refresh_file_list();
//    curRow = this->ui->ui_file_list->currentRow();
//    QString fullPath = this->listOfFiles[curRow].path + "/" + item->text();

//    MainWindow::ui->ui_file_list->item(curRow)->setForeground(Qt::red);

//    // Read in the depth image
//    depth_image = cv::imread(fullPath.toUtf8().constData(),cv::IMREAD_ANYDEPTH);
//    // make a colorized version of the depthmap
//    depth_color = IMGShow::colormap(depth_image, this->d1, this->d2,true);

//    // if this has been annotations, load in the pose
//    if (listOfFiles[curRow].isAnnotated) {
//        //TODO
//    }
//    // update the view panels
//    update_views();
    simulate_itemDoubleClicked();
}

void MainWindow::on_view1_mouseMoveEvent()
{
    qDebug() << "hi";
}

void MainWindow::on_xpos_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_ypos_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_zpos_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_yaw_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_pitch_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_roll_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_abdomen_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_neck_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_head_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_l_collar_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_l_arm_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_l_hand_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_l_thigh_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_l_shin_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_l_foot_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_r_collar_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_r_arm_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_r_hand_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_r_thigh_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_r_shin_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_r_foot_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_vangle_sliderMoved(int position)
{
    update_views();
}

void MainWindow::on_scale_sliderMoved(int position)
{
    update_views();
}


void MainWindow::on_button_save_clicked()
{
    using namespace Ogre;
    // get all the parameter values and store them to a file
    // also, get the 3D joint locations and store them in a separate label file
    QString path = this->listOfFiles[curRow].path;
    QString name = this->ui->ui_file_list->item(curRow)->text();
    name.replace(".png","_params.txt");
    QString label_file_name = path + "/" + name;

    std::ofstream label_file;
    label_file.open(label_file_name.toUtf8().constData());

    float x = this->ui->xpos->value(), y = this->ui->ypos->value(), z = this->ui->zpos->value();
    float scale = this->ui->scale->value()/100.;
    float pitch = ui->pitch->value(), yaw = ui->yaw->value(), roll = ui->roll->value();
    label_file << x << " " << y << " " << z << " " << pitch << " " << yaw << " " << roll << " " << scale;

    for (int j = 0; j < dial_jnt_num.size(); ++j){
        label_file << " " << dial_pose_controls[j]->value();
    }

    for (int j = 0; j < slider_jnt_num.size(); ++j){
        label_file << " " << slider_pose_controls[j]->value();
    }
    label_file.close();

    // set annotation label
    this->listOfFiles[curRow].isAnnotated = true;
    this->ui->ui_file_list->setCurrentRow(curRow+1);
    simulate_itemDoubleClicked();
}
