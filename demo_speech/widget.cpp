#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->pushButton->setText("按住说话");
}

widget::~widget()
{
    delete ui;
}

void widget::on_pushButton_pressed()
{
    ui->pushButton->setText("松开识别");
    //开始录音
    audio = new Audio;
    audio->startAudio("E:\\Qt\\audio.pcm");
}

void widget::on_pushButton_released()
{
    //停止录音
    audio->stopAudio();
    //修改按钮文字
    ui->pushButton->setText("开始识别");
    //开始识别
    Speech m_speech;
    QString text =  m_speech.speechIdentify("E:\\Qt\\audio.pcm");
    ui->textEdit->setText(text);

    ui->pushButton->setText("按住说话");

}


void widget::on_clearButton_clicked()
{
    ui->textEdit->clear();
}

