#ifndef Chat_H
#define Chat_H

#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>
#include "codeeditor.h"
#include <QPushButton>
#include "canvas.h"

namespace Ui {
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

private:
    Ui::Chat *ui;
};

#endif // Chat_H
