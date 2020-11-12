#ifndef LOCALMODE_H
#define LOCALMODE_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTabWidget>
#include "codeeditor.h"
#include <QPushButton>
#include "canvas.h"
#include "lineinterpreter.h"

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
    QPushButton *runAllButton, *runLineButton;
    LineInterpreter *lineInterpreter;

private slots:
    void initForm();
    void parseLine();
};

#endif // LOCALMODE_H
