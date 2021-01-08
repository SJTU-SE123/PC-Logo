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
#include "coursedialog.h"

namespace Ui {
class LocalMode;
}

extern QString reminder;
extern int lineNumber;
class LocalMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit LocalMode(QWidget *parent = nullptr, bool isTutorial = false);
    ~LocalMode() override;

private:
    bool isTutorial, tutorBlock;
    QLabel *tutorial;
    QString tutorText;
    int tutorStep;
    Ui::LocalMode *ui;
    QTabWidget *tabEditor;
    Canvas *canvas;
    CmdLine *cmdLine;
    CodeEditor *editor;
    QPushButton *runAllButton, *runLineButton, *speechButton, *tutorButton;
    QPushButton *openButton, *makeButton;
    LineInterpreter *lineInterpreter;
    Audio *audio;
    QGraphicsOpacityEffect *tabEditor_opacity, *canvas_opacity, *cmdLine_opacity;
    courseDialog *dialog;
    const double OPACITY = 0.8;
    void initForm();
    void reset_editor();   //使editor指向当前现实的标签

private slots:
    void parseCurrentLine();
    void parseLine(QString line);
    void parseAll();
    void speechStart();
    void speechEnd();
    void openFile();
    void newTab();
    void removeTab(int n);
    void saveFile();
    void saveFileAs();
    void tutorNextStep();
    void onTabChanged(int);
    void showHelp();

public slots:
    void receiveNewLine(QString newLine);
    void closeWindow();
};

#endif // LOCALMODE_H
