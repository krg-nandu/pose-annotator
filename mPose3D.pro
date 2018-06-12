#-------------------------------------------------
#
# Project created by QtCreator 2018-06-12T11:59:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mPose3D
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    /usr/include \
    /usr/local/include/ \
    /usr/include/OGRE/

LIBS += -L/usr/local/lib/ -lopencv_highgui -lopencv_calib3d -lopencv_contrib -lopencv_core \
    -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_imgproc \
    -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_video \
    -lpthread -lboost_thread -lboost_system -lboost_filesystem -lboost_iostreams
LIBS += -lOgreMain -lGL -lGLU -lglut

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
        FishPose.h \
        FishRender.h \
        ImgProc.hpp \
        Utility.h

FORMS += \
        mainwindow.ui

DESTDIR = ../bin/
