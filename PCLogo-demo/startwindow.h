#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
//#include <QMovie>
#include <QLabel>

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_ModeSelect_clicked();
    void on_Exit_clicked();
    void on_otherButton_clicked();
    void onTaskBoxContextMenuEvent();

private:
    Ui::StartWindow *ui;
    QWidget *t, *nextWidget;
    QMovie *gif;
    QLabel *gifPlayer;
};

#endif // STARTWINDOW_H
