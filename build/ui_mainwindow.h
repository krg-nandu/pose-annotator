/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_folder;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGroupBox *pcloud;
    QLabel *view1;
    QLabel *view2;
    QGroupBox *panel;
    QGroupBox *pos;
    QSlider *xpos;
    QSlider *ypos;
    QSlider *zpos;
    QLabel *x_label;
    QLabel *y_label;
    QLabel *z_label;
    QGroupBox *ori;
    QDial *yaw;
    QDial *pitch;
    QLabel *yaw_label;
    QLabel *pitch_label;
    QGroupBox *pose;
    QSlider *l_collar;
    QLabel *l_collar_label;
    QSlider *l_arm;
    QSlider *l_hand;
    QSlider *l_thigh;
    QSlider *l_shin;
    QSlider *l_foot;
    QSlider *r_collar;
    QSlider *r_arm;
    QSlider *r_hand;
    QLabel *l_arm_label;
    QLabel *l_shin_label;
    QLabel *l_hand_label;
    QLabel *l_foot_label;
    QLabel *l_thigh_label;
    QSlider *r_thigh;
    QSlider *r_foot;
    QSlider *r_shin;
    QLabel *r_collar_label;
    QLabel *r_hand_label;
    QLabel *r_foot_label;
    QLabel *r_shin_label;
    QLabel *r_thigh_label;
    QLabel *r_arm_label;
    QDial *abdomen;
    QDial *neck;
    QDial *head;
    QLabel *abdomen_label;
    QLabel *head_label;
    QLabel *neck_label;
    QPushButton *button_save;
    QPushButton *button_prev;
    QPushButton *button_next;
    QListWidget *ui_file_list;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1202, 810);
        actionLoad_folder = new QAction(MainWindow);
        actionLoad_folder->setObjectName(QString::fromUtf8("actionLoad_folder"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pcloud = new QGroupBox(centralWidget);
        pcloud->setObjectName(QString::fromUtf8("pcloud"));
        pcloud->setGeometry(QRect(10, 0, 551, 741));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        pcloud->setFont(font);
        view1 = new QLabel(pcloud);
        view1->setObjectName(QString::fromUtf8("view1"));
        view1->setGeometry(QRect(10, 30, 531, 341));
        view2 = new QLabel(pcloud);
        view2->setObjectName(QString::fromUtf8("view2"));
        view2->setGeometry(QRect(10, 380, 531, 351));
        panel = new QGroupBox(centralWidget);
        panel->setObjectName(QString::fromUtf8("panel"));
        panel->setGeometry(QRect(570, 0, 331, 741));
        panel->setFont(font);
        pos = new QGroupBox(panel);
        pos->setObjectName(QString::fromUtf8("pos"));
        pos->setGeometry(QRect(10, 30, 311, 91));
        pos->setFont(font);
        xpos = new QSlider(pos);
        xpos->setObjectName(QString::fromUtf8("xpos"));
        xpos->setGeometry(QRect(30, 30, 271, 16));
        xpos->setOrientation(Qt::Horizontal);
        ypos = new QSlider(pos);
        ypos->setObjectName(QString::fromUtf8("ypos"));
        ypos->setGeometry(QRect(30, 50, 271, 16));
        ypos->setOrientation(Qt::Horizontal);
        zpos = new QSlider(pos);
        zpos->setObjectName(QString::fromUtf8("zpos"));
        zpos->setGeometry(QRect(30, 70, 271, 16));
        zpos->setOrientation(Qt::Horizontal);
        x_label = new QLabel(pos);
        x_label->setObjectName(QString::fromUtf8("x_label"));
        x_label->setGeometry(QRect(9, 28, 16, 17));
        y_label = new QLabel(pos);
        y_label->setObjectName(QString::fromUtf8("y_label"));
        y_label->setGeometry(QRect(9, 46, 16, 17));
        z_label = new QLabel(pos);
        z_label->setObjectName(QString::fromUtf8("z_label"));
        z_label->setGeometry(QRect(9, 67, 16, 17));
        ori = new QGroupBox(panel);
        ori->setObjectName(QString::fromUtf8("ori"));
        ori->setGeometry(QRect(10, 130, 221, 131));
        ori->setFont(font);
        yaw = new QDial(ori);
        yaw->setObjectName(QString::fromUtf8("yaw"));
        yaw->setGeometry(QRect(0, 38, 111, 91));
        pitch = new QDial(ori);
        pitch->setObjectName(QString::fromUtf8("pitch"));
        pitch->setGeometry(QRect(103, 37, 91, 91));
        yaw_label = new QLabel(ori);
        yaw_label->setObjectName(QString::fromUtf8("yaw_label"));
        yaw_label->setGeometry(QRect(42, 27, 31, 17));
        yaw_label->setFont(font);
        pitch_label = new QLabel(ori);
        pitch_label->setObjectName(QString::fromUtf8("pitch_label"));
        pitch_label->setGeometry(QRect(134, 26, 41, 17));
        pitch_label->setFont(font);
        pose = new QGroupBox(panel);
        pose->setObjectName(QString::fromUtf8("pose"));
        pose->setGeometry(QRect(10, 270, 311, 411));
        pose->setFont(font);
        l_collar = new QSlider(pose);
        l_collar->setObjectName(QString::fromUtf8("l_collar"));
        l_collar->setGeometry(QRect(80, 150, 221, 16));
        l_collar->setOrientation(Qt::Horizontal);
        l_collar_label = new QLabel(pose);
        l_collar_label->setObjectName(QString::fromUtf8("l_collar_label"));
        l_collar_label->setGeometry(QRect(12, 149, 67, 17));
        l_collar_label->setFont(font);
        l_arm = new QSlider(pose);
        l_arm->setObjectName(QString::fromUtf8("l_arm"));
        l_arm->setGeometry(QRect(80, 170, 221, 16));
        l_arm->setOrientation(Qt::Horizontal);
        l_hand = new QSlider(pose);
        l_hand->setObjectName(QString::fromUtf8("l_hand"));
        l_hand->setGeometry(QRect(80, 190, 221, 16));
        l_hand->setOrientation(Qt::Horizontal);
        l_thigh = new QSlider(pose);
        l_thigh->setObjectName(QString::fromUtf8("l_thigh"));
        l_thigh->setGeometry(QRect(80, 210, 221, 16));
        l_thigh->setOrientation(Qt::Horizontal);
        l_shin = new QSlider(pose);
        l_shin->setObjectName(QString::fromUtf8("l_shin"));
        l_shin->setGeometry(QRect(80, 230, 221, 16));
        l_shin->setOrientation(Qt::Horizontal);
        l_foot = new QSlider(pose);
        l_foot->setObjectName(QString::fromUtf8("l_foot"));
        l_foot->setGeometry(QRect(80, 250, 221, 16));
        l_foot->setOrientation(Qt::Horizontal);
        r_collar = new QSlider(pose);
        r_collar->setObjectName(QString::fromUtf8("r_collar"));
        r_collar->setGeometry(QRect(80, 280, 221, 16));
        r_collar->setOrientation(Qt::Horizontal);
        r_arm = new QSlider(pose);
        r_arm->setObjectName(QString::fromUtf8("r_arm"));
        r_arm->setGeometry(QRect(80, 300, 221, 16));
        r_arm->setOrientation(Qt::Horizontal);
        r_hand = new QSlider(pose);
        r_hand->setObjectName(QString::fromUtf8("r_hand"));
        r_hand->setGeometry(QRect(80, 320, 221, 16));
        r_hand->setOrientation(Qt::Horizontal);
        l_arm_label = new QLabel(pose);
        l_arm_label->setObjectName(QString::fromUtf8("l_arm_label"));
        l_arm_label->setGeometry(QRect(12, 170, 67, 17));
        l_arm_label->setFont(font);
        l_shin_label = new QLabel(pose);
        l_shin_label->setObjectName(QString::fromUtf8("l_shin_label"));
        l_shin_label->setGeometry(QRect(12, 230, 67, 17));
        l_shin_label->setFont(font);
        l_hand_label = new QLabel(pose);
        l_hand_label->setObjectName(QString::fromUtf8("l_hand_label"));
        l_hand_label->setGeometry(QRect(12, 190, 67, 17));
        l_hand_label->setFont(font);
        l_foot_label = new QLabel(pose);
        l_foot_label->setObjectName(QString::fromUtf8("l_foot_label"));
        l_foot_label->setGeometry(QRect(12, 250, 67, 17));
        l_foot_label->setFont(font);
        l_thigh_label = new QLabel(pose);
        l_thigh_label->setObjectName(QString::fromUtf8("l_thigh_label"));
        l_thigh_label->setGeometry(QRect(12, 210, 67, 17));
        l_thigh_label->setFont(font);
        r_thigh = new QSlider(pose);
        r_thigh->setObjectName(QString::fromUtf8("r_thigh"));
        r_thigh->setGeometry(QRect(80, 340, 221, 16));
        r_thigh->setOrientation(Qt::Horizontal);
        r_foot = new QSlider(pose);
        r_foot->setObjectName(QString::fromUtf8("r_foot"));
        r_foot->setGeometry(QRect(80, 380, 221, 16));
        r_foot->setOrientation(Qt::Horizontal);
        r_shin = new QSlider(pose);
        r_shin->setObjectName(QString::fromUtf8("r_shin"));
        r_shin->setGeometry(QRect(80, 360, 221, 16));
        r_shin->setOrientation(Qt::Horizontal);
        r_collar_label = new QLabel(pose);
        r_collar_label->setObjectName(QString::fromUtf8("r_collar_label"));
        r_collar_label->setGeometry(QRect(12, 280, 67, 17));
        r_collar_label->setFont(font);
        r_hand_label = new QLabel(pose);
        r_hand_label->setObjectName(QString::fromUtf8("r_hand_label"));
        r_hand_label->setGeometry(QRect(12, 321, 67, 17));
        r_hand_label->setFont(font);
        r_foot_label = new QLabel(pose);
        r_foot_label->setObjectName(QString::fromUtf8("r_foot_label"));
        r_foot_label->setGeometry(QRect(12, 381, 67, 17));
        r_foot_label->setFont(font);
        r_shin_label = new QLabel(pose);
        r_shin_label->setObjectName(QString::fromUtf8("r_shin_label"));
        r_shin_label->setGeometry(QRect(12, 361, 67, 17));
        r_shin_label->setFont(font);
        r_thigh_label = new QLabel(pose);
        r_thigh_label->setObjectName(QString::fromUtf8("r_thigh_label"));
        r_thigh_label->setGeometry(QRect(12, 341, 67, 17));
        r_thigh_label->setFont(font);
        r_arm_label = new QLabel(pose);
        r_arm_label->setObjectName(QString::fromUtf8("r_arm_label"));
        r_arm_label->setGeometry(QRect(12, 301, 67, 17));
        r_arm_label->setFont(font);
        abdomen = new QDial(pose);
        abdomen->setObjectName(QString::fromUtf8("abdomen"));
        abdomen->setGeometry(QRect(10, 46, 91, 91));
        neck = new QDial(pose);
        neck->setObjectName(QString::fromUtf8("neck"));
        neck->setGeometry(QRect(104, 46, 91, 91));
        head = new QDial(pose);
        head->setObjectName(QString::fromUtf8("head"));
        head->setGeometry(QRect(200, 45, 91, 91));
        abdomen_label = new QLabel(pose);
        abdomen_label->setObjectName(QString::fromUtf8("abdomen_label"));
        abdomen_label->setGeometry(QRect(30, 33, 67, 17));
        abdomen_label->setFont(font);
        head_label = new QLabel(pose);
        head_label->setObjectName(QString::fromUtf8("head_label"));
        head_label->setGeometry(QRect(231, 33, 31, 17));
        head_label->setFont(font);
        neck_label = new QLabel(pose);
        neck_label->setObjectName(QString::fromUtf8("neck_label"));
        neck_label->setGeometry(QRect(135, 34, 31, 17));
        neck_label->setFont(font);
        button_save = new QPushButton(panel);
        button_save->setObjectName(QString::fromUtf8("button_save"));
        button_save->setGeometry(QRect(120, 699, 89, 25));
        button_prev = new QPushButton(panel);
        button_prev->setObjectName(QString::fromUtf8("button_prev"));
        button_prev->setGeometry(QRect(20, 699, 89, 25));
        button_next = new QPushButton(panel);
        button_next->setObjectName(QString::fromUtf8("button_next"));
        button_next->setGeometry(QRect(220, 699, 89, 25));
        ui_file_list = new QListWidget(centralWidget);
        ui_file_list->setObjectName(QString::fromUtf8("ui_file_list"));
        ui_file_list->setGeometry(QRect(910, 20, 281, 721));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1202, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad_folder);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionLoad_folder->setText(QApplication::translate("MainWindow", "Load folder", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        pcloud->setTitle(QApplication::translate("MainWindow", "Pointcloud view panel", 0, QApplication::UnicodeUTF8));
        view1->setText(QString());
        view2->setText(QString());
        panel->setTitle(QApplication::translate("MainWindow", "Control panel", 0, QApplication::UnicodeUTF8));
        pos->setTitle(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        x_label->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        y_label->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        z_label->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        ori->setTitle(QApplication::translate("MainWindow", "Orientation", 0, QApplication::UnicodeUTF8));
        yaw_label->setText(QApplication::translate("MainWindow", "Yaw", 0, QApplication::UnicodeUTF8));
        pitch_label->setText(QApplication::translate("MainWindow", "Pitch", 0, QApplication::UnicodeUTF8));
        pose->setTitle(QApplication::translate("MainWindow", "Pose", 0, QApplication::UnicodeUTF8));
        l_collar_label->setText(QApplication::translate("MainWindow", "L. Collar", 0, QApplication::UnicodeUTF8));
        l_arm_label->setText(QApplication::translate("MainWindow", "L. Arm", 0, QApplication::UnicodeUTF8));
        l_shin_label->setText(QApplication::translate("MainWindow", "L. Shin", 0, QApplication::UnicodeUTF8));
        l_hand_label->setText(QApplication::translate("MainWindow", "L. Hand", 0, QApplication::UnicodeUTF8));
        l_foot_label->setText(QApplication::translate("MainWindow", "L. Foot", 0, QApplication::UnicodeUTF8));
        l_thigh_label->setText(QApplication::translate("MainWindow", "L. Thigh", 0, QApplication::UnicodeUTF8));
        r_collar_label->setText(QApplication::translate("MainWindow", "R. Collar", 0, QApplication::UnicodeUTF8));
        r_hand_label->setText(QApplication::translate("MainWindow", "R. Hand", 0, QApplication::UnicodeUTF8));
        r_foot_label->setText(QApplication::translate("MainWindow", "R. Foot", 0, QApplication::UnicodeUTF8));
        r_shin_label->setText(QApplication::translate("MainWindow", "R. Shin", 0, QApplication::UnicodeUTF8));
        r_thigh_label->setText(QApplication::translate("MainWindow", "R. Thigh", 0, QApplication::UnicodeUTF8));
        r_arm_label->setText(QApplication::translate("MainWindow", "R. Arm", 0, QApplication::UnicodeUTF8));
        abdomen_label->setText(QApplication::translate("MainWindow", "Abdomen", 0, QApplication::UnicodeUTF8));
        head_label->setText(QApplication::translate("MainWindow", "Head", 0, QApplication::UnicodeUTF8));
        neck_label->setText(QApplication::translate("MainWindow", "Neck", 0, QApplication::UnicodeUTF8));
        button_save->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        button_prev->setText(QApplication::translate("MainWindow", "Previous", 0, QApplication::UnicodeUTF8));
        button_next->setText(QApplication::translate("MainWindow", "Next", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
