#ifndef LOCALMODE_H
#define LOCALMODE_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTabWidget>
#include <QPushButton>
#include "codeeditor.h"
#include "canvas.h"
#include "lineinterpreter.h"
#include "speech/audio.h"
#include "speech/speech.h"

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
    QPushButton *runAllButton, *runLineButton, *speechButton;
    LineInterpreter *lineInterpreter;
    Audio *audio;

private slots:
    void initForm();
    void parseLine();
    void speechStart();
    void speechEnd();
};

#endif // LOCALMODE_H
