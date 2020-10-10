#ifndef CONNECT_H
#define CONNECT_H

#include <QWidget>

namespace Ui {
class Connect;
}

class Connect : public QWidget
{
    Q_OBJECT

public:
    explicit Connect(QWidget *parent = nullptr);
    ~Connect();

private:
    Ui::Connect *ui;
};

#endif // CONNECT_H
