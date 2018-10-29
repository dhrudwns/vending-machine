#include "wiget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wiget w;
    w.show();

    return a.exec();
}
