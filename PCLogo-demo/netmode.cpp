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
//    connect();
}

NetMode::~NetMode()
{
    delete ui;
    delete canvas;
    delete localEditor;
    delete netEditor;
}

void NetMode::initForm(){
    this->setFixedSize(1200, 800);
    this->setPalette(QColor("#d7f0ff"));
    this->setStyleSheet("QWidget:window {background-image: url(:/image/bkgimg.png);}"
                        "QMenu {background-color: white; border: 1px solid white;}"
                        "QMenu::item {background-color: transparent; padding:6px 30px; margin:0px 8px;}"
                        "QMenu::item:selected {background-color:#BDBDBD;}"
                        "QTabWidget::pane {"
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
    canvas->setGeometry(450, 70, 720, 715);
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    canvas_opacity = new QGraphicsOpacityEffect();
    canvas->setGraphicsEffect(canvas_opacity);
    canvas_opacity->setOpacity(OPACITY);

    tabEditor = new QTabWidget(this);
    tabEditor->setGeometry(30, 50, 390, 735);
    tabEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor_opacity = new QGraphicsOpacityEffect();
    tabEditor->setGraphicsEffect(tabEditor_opacity);
    tabEditor_opacity->setOpacity(OPACITY);

    localEditor = new CodeEditor();
    localEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->addTab(localEditor, "本机用户");
    netEditor = new CodeEditor();
    netEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->addTab(netEditor, "网络用户");
}

void NetMode::connect(){
    netConnection = new Connect();
    netConnection->show();
}
