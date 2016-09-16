#ifndef DRAWER_H
#define DRAWER_H

#include <QToolBox>
#include <QToolButton>
#include "widget.h"
class drawer : public QToolBox
{
    Q_OBJECT
public:
    explicit drawer(QWidget *parent = 0);

private :
    Widget *w;
    QToolButton *toolbtn1;
    QToolButton *toolbtn2;
    QToolButton *toolbtn3;
    QToolButton *toolbtn4;
public slots:
    void showmyWidget();
};

#endif // DRAWER_H
