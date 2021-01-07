#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
//#include <QMovie>
#include <QLabel>
#include "login.h"
#include "coursedialog.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    QWidget *getNextWidget() {return this->nextWidget;}

private slots:
    void on_ModeSelect_clicked();
    void on_Exit_clicked();
    void on_otherButton_clicked();
    void onTaskBoxContextMenuEvent();
    void onUserLogin(QString username);

    void on_Help_clicked();

private:
    Ui::StartWindow *ui;
    QWidget *t, *nextWidget;
    QMovie *gif;
    QLabel *gifPlayer;
    Login * login;
    QString username = nullptr;
    courseDialog *dialog;
};

#endif // STARTWINDOW_H
