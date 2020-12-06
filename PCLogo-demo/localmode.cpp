#include "localmode.h"
#include "ui_localmode.h"
#include <QDebug>
#include "command.h"
#include <QTextBlock>

LocalMode::LocalMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LocalMode)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 本地");
    this->initForm();
    connect(runAllButton, SIGNAL(clicked()), this, SLOT(parseAll()));       //运行程序按钮
    connect(runLineButton, SIGNAL(clicked()), this, SLOT(parseLine()));     //单步运行按钮
    connect(speechButton, SIGNAL(pressed()), this, SLOT(speechStart()));    //点击语音输入按钮
    connect(speechButton, SIGNAL(released()), this, SLOT(speechEnd()));     //松开语音输入按钮
    connect(ui->action_open, SIGNAL(triggered()), this, SLOT(openFile()));  //打开文件
    connect(ui->action_new, SIGNAL(triggered()), this, SLOT(newTab()));     //新建标签页
    connect(ui->action_save, SIGNAL(triggered()), this, SLOT(saveFile()));  //保存文件
    connect(ui->action_save_as, SIGNAL(triggered()), this, SLOT(saveFileAs()));     //文件另存为
    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(close()));     //关闭窗口
    connect(ui->action_run, SIGNAL(triggered()), this, SLOT(parseLine()));     //运行
    connect(tabEditor, SIGNAL(tabCloseRequested(int)), this, SLOT(removeTab(int))); //关闭标签页
}

LocalMode::~LocalMode()
{
    delete ui;
    delete canvas;
    delete editor;
}

/**
 * 对界面进行设置。
 */
void LocalMode::initForm(){
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
    runAllButton->setGeometry(1030, 35, 110, 31);
    runAllButton->setStyleSheet("background-image: url(:/image/runall.png)");
    runLineButton = new QPushButton(this);
    runLineButton->setGeometry(900, 35, 110, 31);
    runLineButton->setStyleSheet("background-image: url(:/image/runline.png)");
    speechButton = new QPushButton(this);
    speechButton->setGeometry(770, 35, 110, 31);
    speechButton->setStyleSheet("background-image: url(:/image/speech-off.png)");

    tabEditor = new QTabWidget(this);
    tabEditor->setGeometry(30, 40, 390, 700);
    tabEditor->setStyleSheet("background-color: white; font-family: Microsoft Yahei; font-size: 18px;");
    tabEditor->setTabsClosable(true);
    //用图形效果设置透明度。setOpacity()的参数为透明度，范围是0~1。
    tabEditor_opacity = new QGraphicsOpacityEffect();
    tabEditor->setGraphicsEffect(tabEditor_opacity);
    tabEditor_opacity->setOpacity(OPACITY);

    canvas = new Canvas(this);
    canvas->setGeometry(450, 70, 720, 515);
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    canvas_opacity = new QGraphicsOpacityEffect();
    canvas->setGraphicsEffect(canvas_opacity);
    canvas_opacity->setOpacity(OPACITY);

    cmdLine = new QPlainTextEdit(this);
    cmdLine->setGeometry(450, 600, 720, 170);
    cmdLine->appendPlainText("这里将会是是命令行，暂时还没实现。");
    cmdLine_opacity = new QGraphicsOpacityEffect();
    cmdLine->setGraphicsEffect(cmdLine_opacity);
    cmdLine_opacity->setOpacity(OPACITY);

    reset_editor();
}

/**
 * 使editor指针指向当前显示的标签页。
 */
void LocalMode::reset_editor(){
    editor = static_cast<CodeEditor*>(tabEditor->currentWidget());
}

/**
 * 运行当前打开的标签页中的程序。
 */
void LocalMode::parseAll(){
    reset_editor();
    QString str = this->editor->toPlainText();
    command* cmd = this->lineInterpreter->parseLine(str);
    this->canvas->parseCommand(cmd);
}

/**
 * 暂时为运行当前光标所在的行。
 */
void LocalMode::parseLine() {
    reset_editor();
    QTextCursor cursor = this->editor->textCursor();
    QString str = cursor.block().text();
    command* cmd = this->lineInterpreter->parseLine(str);
    this->canvas->parseCommand(cmd);
}

/**
 * 按下“语音识别”按钮，文字变蓝后开始录音。
 */
void LocalMode::speechStart(){
    speechButton->setStyleSheet("background-image: url(:/image/speech-on.png)");
    //开始录音
    audio = new Audio;
    audio->startAudio("E:\\audio.pcm");
}

/**
 * 松开“语音识别”按钮，停止录音，按钮变灰。
 * !!!!!!mac用户注意，这里的E:\\audio.pcm请更换为mac上能用的路径。之后会改的（在改了在改了
 */
void LocalMode::speechEnd(){
    audio->stopAudio();             //停止录音
    reset_editor();
    if (editor == nullptr) return;  //没有标签页时，不读入。

    speechButton->setStyleSheet("background-image: url(:/image/speech-off.png)");
    Speech m_speech;
    QString text =  m_speech.speechIdentify("E:\\audio.pcm");   //进行识别
//    qDebug() << text;
    editor->appendPlainText(text.left(text.size() - 1));
}

/**
 * 打开文件到新标签。文件内容必须是英文（暂时）。
 */
void LocalMode::openFile(){
    editor = new CodeEditor();
    QFileDialog *qfd = new QFileDialog();
    qfd->show();
    editor->fileName = qfd->getOpenFileName();
    qfd->close();
    delete qfd;
    if (editor->fileName.isEmpty()){
        delete editor;
        reset_editor();
        return;
    }

    QFile file(editor->fileName);
    if (!file.open(QIODevice::ReadOnly)){
        delete editor;
        reset_editor();
        return;
    }
    QTextStream in(&file);
    editor->clear();
    while (!in.atEnd()){
        QString line = in.readLine();
        editor->appendPlainText(line);
    }
    file.close();
    tabEditor->addTab(editor, editor->fileName.mid(editor->fileName.lastIndexOf('/')+1));
    reset_editor();
}

/**
 * 新建标签
 */
void LocalMode::newTab(){
    editor = new CodeEditor();
    tabEditor->addTab(editor, "未命名"+QString::number(tabEditor->count()+1));
    reset_editor();
}

/**
 * 按叉关闭标签。
 */
void LocalMode::removeTab(int n){
    editor = static_cast<CodeEditor*>(tabEditor->widget(n));
    tabEditor->removeTab(n);
    delete editor;
    reset_editor();
}

/**
 * 保存当前标签页到文件。
 */
void LocalMode::saveFile(){
    reset_editor();
    if (editor == nullptr) return;  //没有标签页时，不做动作。

    if (editor->fileName.isEmpty()) saveFileAs();   //未命名文件的保存，等价于另存为
    else {
        QFile file(editor->fileName);
        if (!file.open(QIODevice::WriteOnly)) return;
        QTextStream out(&file);
        out << editor->toPlainText();
        file.close();
    }
}

/**
 * 另存为，或保存未命名标签页到文件。
 */
void LocalMode::saveFileAs(){
    reset_editor();
    if (editor == nullptr) return;  //没有标签页时，不做动作。

    QFileDialog *qfd = new QFileDialog();
    qfd->show();
    editor->fileName = qfd->getSaveFileName();
    qfd->close();
    if (editor->fileName.isEmpty()) return;

    tabEditor->setTabText(tabEditor->currentIndex(), editor->fileName.mid(editor->fileName.lastIndexOf('/')+1));
    QFile file(editor->fileName);
    if (!file.open(QIODevice::WriteOnly)) return;
    QTextStream out(&file);
    out << editor->toPlainText();
    file.close();
}
