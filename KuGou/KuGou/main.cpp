#include "mainwnd/mainwnd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto mainWnnd = mainWnd::getInstance();
    if (mainWnnd) mainWnnd->show();

    return a.exec();
}
