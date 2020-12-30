#include "localmode.h"
#include "ui_localmode.h"
#include <QDebug>
#include "command.h"
#include <QTextBlock>

QString reminder = "";
int lineNumber = 1;
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
    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(closeWindow()));     //关闭窗口
    connect(ui->action_run, SIGNAL(triggered()), this, SLOT(parseLine()));     //运行
    connect(tabEditor, SIGNAL(tabCloseRequested(int)), this, SLOT(removeTab(int))); //关闭标签页
    connect(this->cmdLine, &CmdLine::sendNewLine, this, &LocalMode::receiveNewLine);  // receive new line from cmd-line
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
    tabEditor->setGeometry(30, 40, 390, 730);
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

    cmdLine = new CmdLine(this);  // new QPlainTextEdit(this);
    cmdLine->setGeometry(450, 600, 720, 170);
    // cmdLine->appendPlainText("这里将会是是命令行，暂时还没实现。");
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
 * 碰到断点会停下。（第一行除外
 */
void LocalMode::parseAll(){
    reset_editor();
    if(!editor)return;

    QString str = this->editor->toPlainText();
     //    str.remove(QRegExp("^ +\\s*"));//去掉前面的空格
    qDebug()<<str;
    if(str[0] == " " || str[0] == '\n'){

        QMessageBox::information(this,"错误","运行代码片段不能以空格和空行开头，请检查代码是否符合格式","确定");
            return;
        }
        str = "";
        QTextCursor cursor = this->editor->textCursor();
        cursor.movePosition(QTextCursor::Start);
        for (int i = 0; i < this->editor->lastBreakPoint; i++) cursor.movePosition(QTextCursor::Down);
        this->editor->setTextCursor(cursor);
        lineNumber = cursor.block().blockNumber();

        while (cursor.block().blockNumber() < this->editor->blockCount()-1) {   //最后一行之前
            if (cursor.block().blockNumber() != this->editor->lastBreakPoint
                    && this->editor->breakPoints.contains(cursor.block().blockNumber())) {  //如果遇到断点
                this->editor->lastBreakPoint = cursor.block().blockNumber();
                command* cmd = this->lineInterpreter->parseLine(str);
                qDebug()<<"step1";
                if(reminder != "" && reminder.at(reminder.size() - 1) == "）")reminder = "";
                qDebug()<<"step2";
                if(reminder != ""){
                    reminder += "（错误发生在第";
                    QString LN = QString::number(lineNumber+1, 10);
                    reminder += LN;
                    reminder += "行）";
                    QString error_message = reminder;
                    QMessageBox::information(this,"错误",error_message,"确定");
                    reminder = "";
                    return;
                }else{
                    qDebug()<<"step3";
                    if(cmd == nullptr){
                        qDebug()<<"step4";
                                return;
                            }
                    this->canvas->parseCommand(cmd);
                    return;
                }
//                this->canvas->parseCommand(cmd);
//                return;
            }
            str += cursor.block().text() + "\n";
            cursor.movePosition(QTextCursor::Down);
            this->editor->setTextCursor(cursor);
        }

        //最后一行
        if (cursor.block().blockNumber() != this->editor->lastBreakPoint
                && this->editor->breakPoints.contains(cursor.block().blockNumber())) {
            this->editor->lastBreakPoint = cursor.block().blockNumber();

            command* cmd = this->lineInterpreter->parseLine(str);
            qDebug()<<"step5";
            if(reminder != "" && reminder.at(reminder.size() - 1) == "）")reminder = "";
                if(reminder != ""){
                    reminder += "（错误发生在第";
                    QString LN = QString::number(lineNumber+1, 10);
                    reminder += LN;
                    reminder += "行）";
                    QString error_message = reminder;
                    QMessageBox::information(this,"错误",error_message,"确定");
                    reminder = "";
                }else{
                    if(cmd == nullptr){
                        qDebug()<<"step6";
                        return;
                    }
                    this->canvas->parseCommand(cmd);
                    return;
                }
        }
        str += cursor.block().text() + "\n";

        command* cmd = this->lineInterpreter->parseLine(str);

        if(reminder != "" && reminder.at(reminder.size() - 1) == "）")reminder = "";
        if(reminder != ""){
            reminder += "（错误发生在第";
            QString LN = QString::number(lineNumber+1, 10);
            reminder += LN;
            reminder += "行）";
            QString error_message = reminder;
            QMessageBox::information(this,"错误",error_message,"确定");
            reminder = "";
        }else{
            if(cmd == nullptr){
                qDebug()<<"step7";
                this->editor->lastBreakPoint = 0;
                return;
            }
            this->canvas->parseCommand(cmd);
            this->editor->lastBreakPoint = 0;
        }
//        this->canvas->parseCommand(cmd);
        this->editor->lastBreakPoint = 0;


    //分界线


//    QString str = this->editor->toPlainText();
// //    str.remove(QRegExp("^ +\\s*"));//去掉前面的空格
//if(str[0] == " "){
//        QMessageBox::information(this,"错误","全部运行指令要求代码片段不能以空格和空行开头，请检查代码是否符合格式","确定");
//    }else{
//        str.remove(QRegExp("\\s* +$"));//去掉后面的空格
//        qDebug()<<str;
//        command* cmd = this->lineInterpreter->parseLine(str);
//        if(reminder.at(reminder.size() - 1) == "）")reminder = "";
//            if(reminder != ""){
//                reminder += "（错误发生在第";
//                QString LN = QString::number(lineNumber, 10);
//                reminder += LN;
//                reminder += "行）";
//                QString error_message = reminder;
//                QMessageBox::information(this,"错误",error_message,"确定");
//                reminder = "";
//            }else{
//                this->canvas->parseCommand(cmd);

//            }
//    }
    

    

}

/**
 * 运行当前光标所在的行,然后将光标置于下一行行首。
 */
void LocalMode::parseLine() {
    reset_editor();
    QTextCursor cursor = this->editor->textCursor();
    QString str = cursor.block().text();
    str.remove(QRegExp("^ +\\s*"));
    qDebug()<<str;
    command* cmd = this->lineInterpreter->parseLine(str);
    if(reminder.at(reminder.size() - 1) == "）")reminder = "";
        if(reminder != ""){
            QString error_message = "当前光标所在行 " + reminder;
            QMessageBox::information(this,"错误",error_message,"确定");
            reminder = "";
        }else{
            this->canvas->parseCommand(cmd);
            cursor.movePosition(QTextCursor::Down);
            this->editor->setTextCursor(cursor);
        }
    
}

/**
 * 按下“语音识别”按钮，文字变蓝后开始录音。
 */
void LocalMode::speechStart(){
    speechButton->setStyleSheet("background-image: url(:/image/speech-on.png)");
    //开始录音
    audio = new Audio;
    audio->startAudio("audio.pcm");
}

/**
 * 松开“语音识别”按钮，停止录音，按钮变灰。
 */
void LocalMode::speechEnd(){
    audio->stopAudio();             //停止录音
    reset_editor();
    if (editor == nullptr){
        QMessageBox::information(this,"无效操作","当前没有打开的标签页，无法进行语音输入","确定");
        return;  //没有标签页时，不读入。
    }

    speechButton->setStyleSheet("background-image: url(:/image/speech-off.png)");
    Speech m_speech;
    QString text =  m_speech.speechIdentify("audio.pcm");   //进行识别
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
    QMessageBox messageBox(QMessageBox::NoIcon,
                                   "退出", "你确定要关闭该文件吗? ps:请先确认文件是否保存！",
                                   QMessageBox::No | QMessageBox::Yes , NULL);
            int result=messageBox.exec();


            switch (result)
            {
            case QMessageBox::Yes:
                qDebug()<<"Yes";
                editor = static_cast<CodeEditor*>(tabEditor->widget(n));
                tabEditor->removeTab(n);
                delete editor;
                reset_editor();
                break;
            case QMessageBox::No:
                qDebug()<<"NO";
                break;
            default:
                break;
            }
}

/**
 * 保存当前标签页到文件。
 */
void LocalMode::saveFile(){
    reset_editor();
    if (editor == nullptr){
            QMessageBox::information(this,"非法操作","当前没有打开的标签页，无法保存","确定");
            return;  //没有标签页时，不做动作。
        }

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
    if (editor == nullptr){
            QMessageBox::information(this,"非法操作","当前没有打开的标签页，无法保存","确定");
            return;  //没有标签页时，不做动作。
        }

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

void LocalMode::receiveNewLine(QString newLine)
{
    command* cmd = this->lineInterpreter->parseLine(newLine);
    this->canvas->parseCommand(cmd);
}

void LocalMode::closeWindow() {
    QMessageBox messageBox(QMessageBox::NoIcon,
                               "退出", "你确定要退出吗? ps:请先确认文件是否保存！",
                               QMessageBox::No | QMessageBox::Yes, nullptr);
        int result=messageBox.exec();

        switch (result)
        {
        case QMessageBox::Yes:
            qDebug()<<"Yes";
            close();
            break;
        case QMessageBox::No:
            qDebug()<<"NO";
            break;
        default:
            break;
        }
}
