#ifndef MODESELECT_H
#define MODESELECT_H

#include <QWidget>
#include <QMainWindow>
#include "login.h"

namespace Ui {
class ModeSelect;
}

class ModeSelect : public QWidget
{
    Q_OBJECT

public:
    explicit ModeSelect(QString username, QWidget *parent = nullptr);
    ~ModeSelect();

private slots:
    void on_LocalMode_clicked();
    void on_NetMode_clicked();
    void on_Tutorial_clicked();

    // void on_NetMode2_clicked();

private:
    Ui::ModeSelect *ui;
    QMainWindow *logoWindow;
    QString username;
    Login *loginWindow;
    void onUserLogin(QString username);
};

#endif // MODESELECT_H
