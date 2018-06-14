#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    cv::Mat img = cv::imread(fullPath.toUtf8().constData());
    qDebug() << "read image";

    //QPalette* palette = new QPalette();
    cv::cvtColor(img, img, CV_BGR2RGB);
    QImage qcolor(img.data, 512, 424, QImage::Format_RGB888);
    //QPixmap pixmap = QPixmap::fromImage(qcolor);
    //QBrush* brush = new QBrush(pixmap);
    //palette->setBrush(QPalette::Background,*brush);

    qDebug() << "set brush";

    //this->ui->view1->setPalette(*palette);
    //this->ui->view1->repaint();
    this->ui->view1->setPixmap(QPixmap::fromImage(qcolor));
    this->ui->view2->setPixmap(QPixmap::fromImage(qcolor));
    //cv::imshow("image",img);
    //cv::waitKey(0);
}
