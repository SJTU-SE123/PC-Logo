#include "startwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));
    qApp->setPalette(qApp->palette());
    StartWindow w;
    w.show();

    return a.exec();
}
