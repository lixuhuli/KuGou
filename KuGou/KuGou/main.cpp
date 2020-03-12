#include "mainwnd/mainwnd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWnd::getInstance().show();

    return a.exec();
}
