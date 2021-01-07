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
    // void mousePressEvent(QMouseEvent *) override;
    QString pureCmd();
    int getLineHeadMarkLength() const { return this->lineHeadMark.length(); }

signals:
    void sendNewLine(QString newLine);

private:
    enum SwitchType { REVERSE = -1, FORWARD = 1 };
    QList<QString> cmdHistory;
    int currentCmdIndex;
    void readCurrentCmd();
    void writeCurrentCmd();
    void switchCurrentCmd(SwitchType st);
    QString lineHeadMark;

    void handleReturn();
};

#endif // NEWLINE_H
