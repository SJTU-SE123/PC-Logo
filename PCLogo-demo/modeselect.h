#ifndef MODESELECT_H
#define MODESELECT_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class ModeSelect;
}

class ModeSelect : public QWidget
{
    Q_OBJECT

public:
    explicit ModeSelect(QWidget *parent = nullptr);
    ~ModeSelect();

private slots:
    void on_LocalMode_clicked();
    void on_NetMode_clicked();
    void on_Tutorial_clicked();

private:
    Ui::ModeSelect *ui;
    QMainWindow *logoWindow;

};

#endif // MODESELECT_H
