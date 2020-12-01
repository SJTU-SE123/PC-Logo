#ifndef CMDLINE_H
#define CMDLINE_H

#include <QTextBrowser>
#include <QLineEdit>

class CmdLine : public QTextBrowser
{
public:
    CmdLine(QWidget *parent);
    QLineEdit *theLine;
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    const int LINE_HEIGHT = 24;
};

#endif // CMDLINE_H
