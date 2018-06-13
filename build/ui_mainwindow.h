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
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
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
    QGroupBox *groupBox;
    QFrame *frame;
    QFrame *frame_2;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_4;
    QDial *dial;
    QDial *dial_2;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_5;
    QSlider *horizontalSlider_4;
    QLabel *label_6;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;
    QSlider *horizontalSlider_7;
    QSlider *horizontalSlider_8;
    QSlider *horizontalSlider_9;
    QSlider *horizontalSlider_10;
    QSlider *horizontalSlider_11;
    QSlider *horizontalSlider_12;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QSlider *horizontalSlider_13;
    QSlider *horizontalSlider_14;
    QSlider *horizontalSlider_15;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QDial *dial_3;
    QDial *dial_4;
    QDial *dial_5;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1202, 820);
        actionLoad_folder = new QAction(MainWindow);
        actionLoad_folder->setObjectName(QString::fromUtf8("actionLoad_folder"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 551, 741));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        groupBox->setFont(font);
        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 30, 531, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 380, 531, 351));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(570, 0, 331, 741));
        groupBox_2->setFont(font);
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 30, 311, 91));
        groupBox_3->setFont(font);
        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 30, 271, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(groupBox_3);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(30, 50, 271, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(groupBox_3);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(30, 70, 271, 16));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 28, 16, 17));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 46, 16, 17));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(9, 67, 16, 17));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 130, 171, 131));
        groupBox_4->setFont(font);
        dial = new QDial(groupBox_4);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(0, 51, 81, 71));
        dial_2 = new QDial(groupBox_4);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setGeometry(QRect(90, 50, 71, 71));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(26, 33, 31, 17));
        label_4->setFont(font);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(111, 33, 41, 17));
        label_5->setFont(font);
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 270, 311, 411));
        groupBox_5->setFont(font);
        horizontalSlider_4 = new QSlider(groupBox_5);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(80, 150, 221, 16));
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(12, 149, 67, 17));
        label_6->setFont(font);
        horizontalSlider_5 = new QSlider(groupBox_5);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setGeometry(QRect(80, 170, 221, 16));
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        horizontalSlider_6 = new QSlider(groupBox_5);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setGeometry(QRect(80, 190, 221, 16));
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        horizontalSlider_7 = new QSlider(groupBox_5);
        horizontalSlider_7->setObjectName(QString::fromUtf8("horizontalSlider_7"));
        horizontalSlider_7->setGeometry(QRect(80, 210, 221, 16));
        horizontalSlider_7->setOrientation(Qt::Horizontal);
        horizontalSlider_8 = new QSlider(groupBox_5);
        horizontalSlider_8->setObjectName(QString::fromUtf8("horizontalSlider_8"));
        horizontalSlider_8->setGeometry(QRect(80, 230, 221, 16));
        horizontalSlider_8->setOrientation(Qt::Horizontal);
        horizontalSlider_9 = new QSlider(groupBox_5);
        horizontalSlider_9->setObjectName(QString::fromUtf8("horizontalSlider_9"));
        horizontalSlider_9->setGeometry(QRect(80, 250, 221, 16));
        horizontalSlider_9->setOrientation(Qt::Horizontal);
        horizontalSlider_10 = new QSlider(groupBox_5);
        horizontalSlider_10->setObjectName(QString::fromUtf8("horizontalSlider_10"));
        horizontalSlider_10->setGeometry(QRect(80, 280, 221, 16));
        horizontalSlider_10->setOrientation(Qt::Horizontal);
        horizontalSlider_11 = new QSlider(groupBox_5);
        horizontalSlider_11->setObjectName(QString::fromUtf8("horizontalSlider_11"));
        horizontalSlider_11->setGeometry(QRect(80, 300, 221, 16));
        horizontalSlider_11->setOrientation(Qt::Horizontal);
        horizontalSlider_12 = new QSlider(groupBox_5);
        horizontalSlider_12->setObjectName(QString::fromUtf8("horizontalSlider_12"));
        horizontalSlider_12->setGeometry(QRect(80, 320, 221, 16));
        horizontalSlider_12->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(12, 170, 67, 17));
        label_7->setFont(font);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(12, 230, 67, 17));
        label_8->setFont(font);
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(12, 190, 67, 17));
        label_9->setFont(font);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(12, 250, 67, 17));
        label_10->setFont(font);
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(12, 210, 67, 17));
        label_11->setFont(font);
        horizontalSlider_13 = new QSlider(groupBox_5);
        horizontalSlider_13->setObjectName(QString::fromUtf8("horizontalSlider_13"));
        horizontalSlider_13->setGeometry(QRect(80, 340, 221, 16));
        horizontalSlider_13->setOrientation(Qt::Horizontal);
        horizontalSlider_14 = new QSlider(groupBox_5);
        horizontalSlider_14->setObjectName(QString::fromUtf8("horizontalSlider_14"));
        horizontalSlider_14->setGeometry(QRect(80, 380, 221, 16));
        horizontalSlider_14->setOrientation(Qt::Horizontal);
        horizontalSlider_15 = new QSlider(groupBox_5);
        horizontalSlider_15->setObjectName(QString::fromUtf8("horizontalSlider_15"));
        horizontalSlider_15->setGeometry(QRect(80, 360, 221, 16));
        horizontalSlider_15->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(12, 280, 67, 17));
        label_12->setFont(font);
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(12, 321, 67, 17));
        label_13->setFont(font);
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(12, 381, 67, 17));
        label_14->setFont(font);
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(12, 361, 67, 17));
        label_15->setFont(font);
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(12, 341, 67, 17));
        label_16->setFont(font);
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(12, 301, 67, 17));
        label_17->setFont(font);
        dial_3 = new QDial(groupBox_5);
        dial_3->setObjectName(QString::fromUtf8("dial_3"));
        dial_3->setGeometry(QRect(10, 46, 91, 91));
        dial_4 = new QDial(groupBox_5);
        dial_4->setObjectName(QString::fromUtf8("dial_4"));
        dial_4->setGeometry(QRect(104, 46, 91, 91));
        dial_5 = new QDial(groupBox_5);
        dial_5->setObjectName(QString::fromUtf8("dial_5"));
        dial_5->setGeometry(QRect(200, 45, 91, 91));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 33, 67, 17));
        label_18->setFont(font);
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(231, 33, 31, 17));
        label_19->setFont(font);
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(135, 34, 31, 17));
        label_20->setFont(font);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 699, 89, 25));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 699, 89, 25));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 699, 89, 25));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(910, 20, 281, 721));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 279, 719));
        scrollArea->setWidget(scrollAreaWidgetContents);
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
        groupBox->setTitle(QApplication::translate("MainWindow", "Pointcloud view panel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Control panel", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Orientation", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Yaw", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Pitch", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Pose", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "L. Collar", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "L. Arm", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "L. Shin", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "L. Hand", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "L. Foot", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "L. Thigh", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "R. Collar", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "R. Hand", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "R. Foot", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "R. Shin", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "R. Thigh", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "R. Arm", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Abdomen", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Head", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Neck", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Previous", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Next", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
