#ifndef NETMODE_H
#define NETMODE_H

#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>
#include "codeeditor.h"
#include <QPushButton>
#include "canvas.h"

namespace Ui {
class NetMode;
}

class NetMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetMode(QWidget *parent = nullptr);
    ~NetMode();

private:
    Ui::NetMode *ui;
    Canvas *canvas;
    QTabWidget *tabEditor;
    CodeEditor *localEditor, *netEditor;
    QPushButton *runAllButton, *runLineButton;
    QWidget *netConnection;

private slots:
    void initForm();
    void connect();
};

#endif // NETMODE_H
