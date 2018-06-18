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
    uvd.y = xyz.x/xyz.z * focal + cx;
    uvd.x = -xyz.y/xyz.z * focal + cy;
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
    xyz.x = ((cx - uvd.y) / focal) * uvd.z;
    xyz.y = ((uvd.x - cy) / focal) * uvd.z;
    xyz.z = -uvd.z;
    return xyz;
}

std::vector<vec3f> MainWindow::get_point_list(cv::Mat img)
{
    std::vector<vec3f> dpt_pts;
    for (int r = 0; r < img.rows; r++){
        for (int c = 0; c < img.cols; c++){
            vec3f v = MainWindow::uvdtoxyz(vec3f(r,c,img.at<u_int16_t>(r,c)));
            if (abs(v.z) > 9000)
                continue;
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
        v += mu;

//        v.x = pt.x * cosd(angle) + pt.z * sind(angle) + mu.x;
//        v.z = pt.y + mu.y;
//        v.y = -pt.x * sind(angle) + pt.z * cosd(angle) + mu.z;
        //qDebug() << v.x << " " << v.y << " " << v.z;
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
    this->monkeypose->Render();
}

void MainWindow::get_side_view(cv::Mat& dst, const cv::Mat src, cv::Vec3b color, float angle)
{
    std::vector<vec3f> dpt_pts = get_point_list(src);
    Ogre::Vector3 root = this->monkeypose->GetJointPosition(1);
    vec3f mu(root.x,root.y,root.z);
    std::vector<vec3f> rot_pts = rotate_points(dpt_pts,mu,angle);
    paint_on_image(dst, rot_pts, color);
}

void MainWindow::update_views()
{

    // apply the current pose parameters and get the rendered image
    apply_current_pose_parameters();

    cv::Mat render_image = this->monkeypose->shortdepth;
    render_image = IMGShow::colormap(render_image, this->d1, this->d2, true);

    cv::Mat overlap_view1 = 0.6*depth_color + 0.4*render_image;
    QImage qcolor((const unsigned char*)(overlap_view1.data), this->width, this->height, QImage::Format_RGB888);
    this->ui->view1->setPixmap(QPixmap::fromImage(qcolor));

    IMGT<float> depthKN;
    depthKN.Create(cvSize(monkeypose->depth->width,monkeypose->depth->height),16,1);
    ImgProcDepth::CvtDepthGL2KN(monkeypose->depth,depthKN,d1,d2,focal);
    cv::Mat render_image_d = depthKN.img;

    // create an empty placeholder for the side view panel
    cv::Mat side_view(cv::Size(width, height), CV_8UC3, cv::Scalar(0,0,0));
    // paint depth points from both data and render
    get_side_view(side_view, depth_image, cv::Vec3b(128,128,128), 45);
    get_side_view(side_view, render_image_d, cv::Vec3b(0,128,0), 45);

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

void MainWindow::on_ui_file_list_itemDoubleClicked(QListWidgetItem *item)
{
    curRow = this->ui->ui_file_list->currentRow();
    QString fullPath = this->listOfFiles[curRow].path + "/" + item->text();

    // Read in the depth image
    depth_image = cv::imread(selectedFile.toUtf8().constData(),cv::IMREAD_ANYDEPTH);
    // make a colorized version of the depthmap
    depth_color = IMGShow::colormap(depth_image, this->d1, this->d2);

    // if this has been annotations, load in the pose
    if (listOfFiles[curRow].isAnnotated) {
        //TODO
    }

    // update the view panels
    update_views();
}
