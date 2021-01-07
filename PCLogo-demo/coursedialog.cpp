#include "coursedialog.h"
#include "ui_coursedialog.h"

courseDialog::courseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courseDialog)
{
    ui->setupUi(this);
}

courseDialog::~courseDialog()
{
    delete ui;
}
