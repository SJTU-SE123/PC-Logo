#ifndef LOCALMODE_H
#define LOCALMODE_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
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
    CodeEditor *editor;
    QLabel *welcome;
    QToolButton *runButton, *debugButton, *buildButton;

private slots:
    void initForm();
};

#endif // LOCALMODE_H
