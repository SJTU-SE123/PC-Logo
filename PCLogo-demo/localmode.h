#ifndef LOCALMODE_H
#define LOCALMODE_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTabWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QGraphicsOpacityEffect>
#include "codeeditor.h"
#include "canvas.h"
#include "lineinterpreter.h"
#include "speech/audio.h"
#include "speech/speech.h"
#include "cmdline.h"

namespace Ui {
class LocalMode;
}

extern QString reminder;
extern int lineNumber;
class LocalMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit LocalMode(QWidget *parent = nullptr);
    ~LocalMode() override;

private:
    Ui::LocalMode *ui;
    QTabWidget *tabEditor;
    Canvas *canvas;
    CmdLine *cmdLine;
    CodeEditor *editor;
    QPushButton *runAllButton, *runLineButton, *speechButton;
    LineInterpreter *lineInterpreter;
    Audio *audio;
    QGraphicsOpacityEffect *tabEditor_opacity, *canvas_opacity, *cmdLine_opacity;
    const double OPACITY = 0.8;
    void initForm();
    void reset_editor();   //使editor指向当前现实的标签

private slots:
    void parseLine();
    void parseAll();
    void speechStart();
    void speechEnd();
    void openFile();
    void newTab();
    void removeTab(int n);
    void saveFile();
    void saveFileAs();

public slots:
    void receiveNewLine(QString newLine);
    void closeWindow();
};

#endif // LOCALMODE_H
