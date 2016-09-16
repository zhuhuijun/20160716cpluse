#include "widget.h"
#include <QHBoxLayout>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn=new QPushButton;
    btn->setText("对话框");
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(btn);
    connect(btn,SIGNAL(clicked()),this,SLOT(on_clicked()));
}

Widget::~Widget()
{

}
//单击事件
void Widget::on_clicked()
{
    QString s=QFileDialog::getOpenFileName(this,"打开文件");
    if(!s.isEmpty())
    setWindowTitle(s);
}
