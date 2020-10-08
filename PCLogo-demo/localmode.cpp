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
    mask = new QLabel(this);
    canvas = new Canvas(this);
    tabEditor = new QTabWidget(this);

    welcome->setGeometry(50, 45, 380, 20);
    mask->setGeometry(38, 25, 1162, 15);
    canvas->setGeometry(470, 50, 720, 825);
    tabEditor->setGeometry(38, 70, 390, 805);

    editor = new CodeEditor();
    editor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->addTab(editor, "未命名1");
    editor = new CodeEditor();
    editor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->addTab(editor, "未命名2");

    welcome->setText("欢迎来到PCLogo的世界，请在下框中输入指令吧OvO");
    welcome->setStyleSheet("font-family: Microsoft Yahei; font-size: 15px;");
    mask->setStyleSheet("background-color: #404142;");
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    tabEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
}
