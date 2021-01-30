#include "myApplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myApplication w;
    w.show();

    return a.exec();
}
