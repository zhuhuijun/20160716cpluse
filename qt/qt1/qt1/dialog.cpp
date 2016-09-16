#include "dialog.h"
#include "ui_dialog.h"
#include <QGridLayout>
#include <QDateTime>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    timer1=new QTimer(this);
   btn1=new QPushButton(this);
   label=new QLabel(this);
   label->setText("结果");
   btn1->setText("求和");
   edit1=new QLineEdit(this);
   edit2=new QLineEdit(this);
   QGridLayout *layout=new QGridLayout(this);
   layout->addWidget(edit1,0,0);
   layout->addWidget(edit2,0,1);
   layout->addWidget(btn1,1,0);
   layout->addWidget(label,1,1);
   connect(btn1,SIGNAL(clicked()),this,SLOT(add()));
   connect(timer1,SIGNAL(timeout()),this,SLOT(clicktimer()));//将超时事件和函数链接
}

Dialog::~Dialog()
{

}
void Dialog::add()
{
    QString s1=edit1->text();
    QString s2=edit2->text();
    int a=s1.toInt();
    int b=s2.toInt();
    label->setText(QString::number(a+b));
    //启动定时器
    timer1->start(1000);
}

void Dialog::clicktimer()
{
    QDateTime *time=new QDateTime(QDateTime::currentDateTime());
    setWindowTitle(time->date().toString());
}
