#ifndef NETMODE_H
#define NETMODE_H

#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include "codeeditor.h"
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
    QGraphicsOpacityEffect *tabEditor_opacity, *canvas_opacity;
    const double OPACITY = 0.8;

private slots:
    void initForm();
    void connect();
};

#endif // NETMODE_H
