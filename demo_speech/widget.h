#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <audio.h>
#include <speech.h>

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void on_pushButton_pressed();
    void on_pushButton_released();

    void on_clearButton_clicked();

private:
    Ui::widget *ui;
    Audio *audio;
};

#endif // WIDGET_H
