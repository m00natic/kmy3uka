#include <QtGui/QApplication>
#include "my3uka.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my3uka w;
    w.show();
    return a.exec();
}
