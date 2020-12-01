#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    cmd = new CmdLine(this);
    cmd->setGeometry(50, 50, 700, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}
