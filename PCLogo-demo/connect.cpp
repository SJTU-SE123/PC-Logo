#include "connect.h"
#include "ui_connect.h"
#include <QAction>
#include <QStandardItemModel>

Connect::Connect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connect)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 建立连接");

//    QStandardItemModel *ItemModel = new QStandardItemModel(this);
//    QStringList strList;
//    strList.append("苏dalao");
//    strList.append("苏大佬");
//    strList.append("我不是苏大佬");

//    int nCount = strList.size();
//    for(int i = 0; i < nCount; i++)
//    {
//       QString string = static_cast<QString>(strList.at(i));
//       QStandardItem *item = new QStandardItem(string);
//       ItemModel->appendRow(item);
//    }
//    ui->listView->setModel(ItemModel);
}

Connect::~Connect()
{
    delete ui;
}
