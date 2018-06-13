#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>

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

private slots:
    void on_actionLoad_folder_triggered();

private:
    Ui::MainWindow *ui;
    void update_file_list();
};

#endif // MAINWINDOW_H
