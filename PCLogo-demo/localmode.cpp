 #include "localmode.h"
#include "ui_localmode.h"
#include <QToolButton>
#include <QDebug>
#include "command.h"

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
    delete canvas;
    delete editor;
}


void LocalMode::initForm(){
    this->setFixedSize(1200, 800);
    this->setPalette(QColor("#d7f0ff"));
    this->setStyleSheet("QWidget:window {background-color: #d7f0ff;}"
                        "QMenu {background-color: white; border: 1px solid white;}"
                        "QMenu::item {background-color: transparent; padding:8px 32px; margin:0px 8px; border-bottom:1px solid #DBDBDB;}"
                        "QTabWidget::pane{"
                        "   border-top: 1px solid #E5E5E5; "
                        "   border-left: 1px solid #E5E5E5; "
                        "   position: absolute;"
                        "   font-size: 14px;"
                        "   background-color: #FFFFFF;"
                        "}"
                        "QTabBar::tab {"
                        "   border: 1px solid black;"
                        "   border-bottom-color: #FFFFFF;"
                        "   border-top-left-radius: 4px;"
                        "   border-top-right-radius: 4px;"
                        "   min-width: 100px;"
                        "   padding: 2px;"
                        "   font-size: 18px;"
                        "   font-family: Microsoft Yahei;"
                        "   background-color: #FFFFFF;"
                        "   border-bottom: 2px solid gray;"
                        "   color: gray;"
                        "}"
                        "QTabBar::tab:selected, QTabBar::tab:hover{background-color:#FFFFFF;}"
                        "QTabBar::tab:selected {color: #2080F7; border-bottom: 2px solid #2080F7; font-weight: bold; background-color:#FFFFFF;}"
                        "QTabWidget::tab-bar {"
                        "   border-top: 2px solid #E5E5E5;"
                        "   border-bottom: 2px solid #E5E5E5;"
                        "   border-left:1px solid #E5E5E5;"
                        "   alignment: left;"
                        "   font-size: 14px;"
                        "   background-color:#FFFFFF;"
                        "}");
    ui->statusbar->setStyleSheet("background-color: #d7f0ff;");

    runAllButton = new QPushButton(this);
    runAllButton->setGeometry(1030, 35, 110, 30);
    runAllButton->setStyleSheet("background-image: url(:/image/runall.png)");
    runLineButton = new QPushButton(this);
    runLineButton->setGeometry(900, 35, 110, 30);
    runLineButton->setStyleSheet("background-image: url(:/image/runline.png)");

    canvas = new Canvas(this);
    tabEditor = new QTabWidget(this);
    canvas->setGeometry(450, 70, 720, 715);
    tabEditor->setGeometry(30, 50, 390, 735);
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    tabEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");

    editor = new CodeEditor();
    editor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->addTab(editor, "未命名1");
    editor = new CodeEditor();
    editor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->addTab(editor, "未命名2");

    connect(runLineButton, SIGNAL(clicked()), this, SLOT(parseLine()));
}

void LocalMode::parseLine() {
    QString str = this->editor->toPlainText();
    command* cmd = this->lineInterpreter->parseLine(str);
    this->canvas->paintLine(10);
}

