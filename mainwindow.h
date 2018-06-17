#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include <QListWidget>
#include <opencv2/opencv.hpp>
#include "Utility.h"
#include "ImgProc.hpp"
#include "MonkeyPose.h"

struct FileItem {
    QString path;
    QString fileName;
    bool isAnnotated;

    FileItem(QString dir, QString name)
    {
        path = dir;
        fileName = name;
        // compute the boolean value
        QFileInfo check_file(path+'/'+name.replace(".png",".txt"));
        // check if file exists and if yes: Is it really a file and no directory?
        if (check_file.exists() && check_file.isFile()) {
            isAnnotated = true;
        } else {
            isAnnotated = false;
        }
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::vector<FileItem> listOfFiles;

    const int d1 = 100;
    const int d2 = 10000;
    const int width = 512;
    const int height = 424;
    const int cx = width/2;
    const int cy = height/2;
    const float focal = 365.456;

    MonkeyPose_::MonkeyPose *monkeypose;
    vec3f uvdtoxyz(vec3f);
    vec3f xyztouvd(vec3f);
    std::vector<vec3f> get_point_list(cv::Mat);
    void paint_on_image(std::vector<vec3f>);

private slots:
    void on_actionLoad_folder_triggered();
    void on_ui_file_list_itemDoubleClicked(QListWidgetItem *item);
    void apply_current_pose_parameters();

private:
    Ui::MainWindow *ui;
    void update_file_list();
    void update_views(QString);
};

#endif // MAINWINDOW_H
