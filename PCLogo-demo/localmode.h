#ifndef LOCALMODE_H
#define LOCALMODE_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTabWidget>
#include "codeeditor.h"
#include <QToolButton>
#include "canvas.h"

namespace Ui {
class LocalMode;
}

class LocalMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit LocalMode(QWidget *parent = nullptr);
    ~LocalMode();

private:
    Ui::LocalMode *ui;
    Canvas *canvas;
    QTabWidget *tabEditor;
    CodeEditor *editor;
    QLabel *welcome, *mask;
    QToolButton *runButton, *debugButton, *buildButton;

private slots:
    void initForm();
};

#endif // LOCALMODE_H
