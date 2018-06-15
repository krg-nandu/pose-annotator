#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void::MainWindow::apply_current_pose_parameters()
{
    this->monkeypose->Render();
}

void MainWindow::update_views(QString selectedFile)
{
    // first read in the depth image
    cv::Mat img = cv::imread(selectedFile.toUtf8().constData(),cv::IMREAD_ANYDEPTH);
    // make a colorized version of the depthmap
    cv::Mat depth_color = IMGShow::colormap(img, this->d1, this->d2);

    // apply the current pose parameters and get the rendered image
    apply_current_pose_parameters();

    cv::Mat render_image = this->monkeypose->shortdepth;
    render_image = IMGShow::colormap(render_image, this->d1, this->d2, true);

    cv::Mat overlap_view1 = 0.6*depth_color + 0.4*render_image;
    QImage qcolor((const unsigned char*)(overlap_view1.data), this->width, this->height, QImage::Format_RGB888);
    //IMGShow::OverlapImages();

    this->ui->view1->setPixmap(QPixmap::fromImage(qcolor));

    //this->ui->view2->setPixmap(QPixmap::fromImage(qcolor));
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
    int curRow = this->ui->ui_file_list->currentRow();
    QString fullPath = this->listOfFiles[curRow].path + "/" + item->text();
    update_views(fullPath);
}
