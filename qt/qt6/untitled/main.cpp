#include "widget.h"
#include <QApplication>
#include "drawer.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    drawer drawer;
    drawer.resize(400,400);
    drawer.show();
    return a.exec();
}
