#ifndef NETMODE_H
#define NETMODE_H

#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>
#include "codeeditor.h"
#include <QToolButton>
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
    QLabel *mask;
    CodeEditor *localEditor, *netEditor;
    QToolButton *runButton, *debugButton, *buildButton;
    QWidget *netConnection;

private slots:
    void initForm();
    void connect();
};

#endif // NETMODE_H
