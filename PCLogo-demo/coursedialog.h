#ifndef COURSEDIALOG_H
#define COURSEDIALOG_H

#include <QDialog>

namespace Ui {
class courseDialog;
}

class courseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit courseDialog(QWidget *parent = nullptr);
    ~courseDialog();

//private:
    Ui::courseDialog *ui;
};

#endif // COURSEDIALOG_H
