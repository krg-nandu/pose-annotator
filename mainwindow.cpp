#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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
    Open a file browser and select the folder containing the images to be annotated
    @param void
    @return void
*/
void MainWindow::on_actionLoad_folder_triggered()
{
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    //dialog.setFileMode(QFileDialog::ExistingFile);
    //dialog.setNameFilter(trUtf8("Splits (*.000 *.001)"));
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
}
