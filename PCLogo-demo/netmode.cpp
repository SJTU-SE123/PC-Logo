#include "netmode.h"
#include "ui_netmode.h"
#include <QToolButton>
#include "codeeditor.h"
#include "connect.h"

NetMode::NetMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NetMode)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 联网");
    this->palette();
    initForm();
    connect();
}

NetMode::~NetMode()
{
    delete ui;
    delete canvas;
    delete localEditor;
    delete netEditor;
}

void NetMode::initForm(){
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

    mask = new QLabel(this);
    canvas = new Canvas(this);
    tabEditor = new QTabWidget(this);

    mask->setGeometry(38, 25, 1162, 15);
    canvas->setGeometry(470, 50, 720, 825);
    tabEditor->setGeometry(38, 50, 390, 825);

    localEditor = new CodeEditor();
    localEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->addTab(localEditor, "本机用户");
    netEditor = new CodeEditor();
    netEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->addTab(netEditor, "网络用户");

    mask->setStyleSheet("background-color: #404142;");
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    tabEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
}

void NetMode::connect(){
    netConnection = new Connect();
    netConnection->show();
}
