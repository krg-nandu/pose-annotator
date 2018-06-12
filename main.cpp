#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "FishPose.h"
#include "ImgProc.hpp"

int main(int argc, char *argv[])
{
    std::cout << "hello!";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

//    int d1 = 100; //500;
//    int d2 = 10000; //2000;
//    float focal = 365.456;
//    FishPose_::FishPose fishpose(focal);
//    fishpose.fish_renderer.mCamera->setNearClipDistance(d1);
//    fishpose.fish_renderer.mCamera->setFarClipDistance(d2);
//    fishpose.Render();

//    int a;
//    std::cin >> a;

    return 0;
}
