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
#include "FishPose.h"

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
    const int d1 = 1000;
    const int d2 = 3000;
    const int width = 512;
    const int height = 424;
    const float focal = 365.456;
    //FishPose_::FishPose fishpose(focal);
    FishPose_::FishPose monkeypose;
    //    fishpose.fish_renderer.mCamera->setNearClipDistance(d1);
    //    fishpose.fish_renderer.mCamera->setFarClipDistance(d2);
    //    fishpose.Render();

private slots:
    void on_actionLoad_folder_triggered();
    void on_ui_file_list_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    void update_file_list();
    void update_views(QString);
};

#endif // MAINWINDOW_H
