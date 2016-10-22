#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*在main函数中改变主窗口的函数*/
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(700,500);
    w.show();

    return a.exec();
}
