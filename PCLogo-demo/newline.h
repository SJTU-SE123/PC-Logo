#ifndef NEWLINE_H
#define NEWLINE_H
#include <QLineEdit>
#include <QList>
#include <QString>

class Parser;

class NewLine : public QLineEdit
{
    Q_OBJECT
public:
    NewLine(QWidget *parent);
    void resetLine();
    void keyPressEvent(QKeyEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    QString cleanText();

signals:
    void sendNewLine(QString newLine);

private:
    QList<QString> currentCmds;
    int currentCmdIndex;
    void readCurrentCmd(int index);
    QString lineHeadMark;
};

#endif // NEWLINE_H
