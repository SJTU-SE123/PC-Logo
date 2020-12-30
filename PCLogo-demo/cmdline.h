#ifndef CMDLINE_H
#define CMDLINE_H

#include <QTextBrowser>
#include <newline.h>

class CmdLine : public QTextBrowser
{
    Q_OBJECT
public:
    CmdLine(QWidget *parent);
    NewLine *newline;
public slots:
    void receiveNewLine(QString newLine);
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    const int LINE_HEIGHT = 24;
signals:
    void sendNewLine(QString newLine);
};

#endif // CMDLINE_H
