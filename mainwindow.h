#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include <QListWidget>
#include <QDial>
#include <opencv2/opencv.hpp>
#include "Utility.h"
#include "ImgProc.hpp"
#include "MonkeyPose.h"
#include <algorithm>

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
    QVector<QDial*> dial_pose_controls;
    std::vector<int> dial_jnt_num;
    QVector<QSlider*> slider_pose_controls;
    std::vector<int> slider_jnt_num;

    const int d1 = 100;
    const int d2 = 10000;
    const int width = 512;
    const int height = 424;
    const int cx = width/2;
    const int cy = height/2;
    const float focal = 365.456;
    cv::Mat depth_image;
    cv::Mat depth_color;
    int curRow;

    MonkeyPose_::MonkeyPose *monkeypose;
    vec3f uvdtoxyz(vec3f);
    vec3f xyztouvd(vec3f);
    std::vector<vec3f> get_point_list(cv::Mat,vec3f);
    void paint_on_image(cv::Mat&, std::vector<vec3f>, cv::Vec3b);
    void get_side_view(cv::Mat&, const cv::Mat, cv::Vec3b, float);

private slots:
    void on_actionLoad_folder_triggered();
    void on_ui_file_list_itemDoubleClicked(QListWidgetItem *item);
    void apply_current_pose_parameters();

    void on_xpos_sliderMoved(int position);

    void on_ypos_sliderMoved(int position);

    void on_zpos_sliderMoved(int position);

    void on_yaw_sliderMoved(int position);

    void on_pitch_sliderMoved(int position);

    void on_roll_sliderMoved(int position);

    void on_abdomen_sliderMoved(int position);

    void on_neck_sliderMoved(int position);

    void on_head_sliderMoved(int position);

    void on_l_collar_sliderMoved(int position);

    void on_l_arm_sliderMoved(int position);

    void on_l_hand_sliderMoved(int position);

    void on_l_thigh_sliderMoved(int position);

    void on_l_shin_sliderMoved(int position);

    void on_l_foot_sliderMoved(int position);

    void on_r_collar_sliderMoved(int position);

    void on_r_arm_sliderMoved(int position);

    void on_r_hand_sliderMoved(int position);

    void on_r_thigh_sliderMoved(int position);

    void on_r_shin_sliderMoved(int position);

    void on_r_foot_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    void update_file_list();
    void update_views();
};

#endif // MAINWINDOW_H
