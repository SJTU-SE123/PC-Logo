#include "localmode.h"
#include "ui_localmode.h"
#include <QToolButton>

LocalMode::LocalMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LocalMode)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 本地");
    this->initForm();
}

LocalMode::~LocalMode()
{
    delete ui;
    delete welcome;
    delete canvas;
    delete editor;
}


void LocalMode::initForm(){
    this->setFixedSize(1200, 900);
    this->setStyleSheet("QWidget:window {background-color: #eeeeee;}");
    ui->mainToolBar->setStyleSheet("background-color: #404142;");
    ui->statusbar->setStyleSheet("background-color: #404142;");

    runButton = new QToolButton();
    runButton->setIcon(QIcon(":/image/run.png"));
    runButton->setFixedSize(30, 30);
    ui->mainToolBar->addWidget(runButton);
    debugButton = new QToolButton();
    debugButton->setIcon(QIcon(":/image/debug.png"));
    debugButton->setFixedSize(30, 30);
    ui->mainToolBar->addWidget(debugButton);
    buildButton = new QToolButton();
    buildButton->setIcon(QIcon(":/image/build.png"));
    buildButton->setFixedSize(30, 30);
    ui->mainToolBar->addWidget(buildButton);

    welcome = new QLabel(this);
    canvas = new Canvas(this);
    editor = new CodeEditor(this);

    welcome->setGeometry(810, 55, 380, 20);
    canvas->setGeometry(38, 60, 720, 815);
    editor->setGeometry(795, 80, 390, 795);

    welcome->setText("欢迎来到PCLogo的世界，请在下框中输入指令吧OvO");
    welcome->setStyleSheet("font-family: Microsoft Yahei; font-size: 15px;");
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    editor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
}
