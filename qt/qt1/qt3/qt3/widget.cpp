#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    edit1=new QLineEdit;
    edit2=new QLineEdit;
    label2=new QLabel;
    label1=new QLabel;
    label1->setText("姓名");
    label2->setText("年龄");
    btn1=new QPushButton;
    btn2=new QPushButton;
    btn1->setText("保存");
    btn2->setText("取消");
    /*
    QVBoxLayout *layout=new QVBoxLayout;

    //layout->addWidget(label1);
    //layout->addWidget(edit1);
    layout->addWidget(label2);
    layout->addWidget(edit2);
    QHBoxLayout *hl=new QHBoxLayout;
    hl->addWidget(label1);
    hl->addWidget(edit1);
    layout->addLayout(hl);
    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(btn1);
    layout2->addWidget(btn2);
    layout->addLayout(layout2);

    this->setLayout(layout);
    */
    QGridLayout *grid=new QGridLayout(this);
    grid->addWidget(label1,0,0);
    grid->addWidget(edit1,0,1);
    grid->addWidget(label2,1,0);
    grid->addWidget(edit2,1,1);
}

Widget::~Widget()
{

}
