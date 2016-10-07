#include "widget.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QList>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn1=new QPushButton(tr("获得主机"));
    btn2=new QPushButton(tr("获得主机2"));
    QHBoxLayout *hlayout=new QHBoxLayout(this);
    hlayout->addWidget(btn1);
    hlayout->addWidget(btn2);
    connect(btn1,SIGNAL(clicked()),this,SLOT(on_click()));
    connect(btn2,SIGNAL(clicked()),this,SLOT(on_click2()));
}

Widget::~Widget()
{

}
void Widget::on_click(){
    QString localhostName=QHostInfo::localHostName();
    QHostInfo hostinfo=QHostInfo::fromName(localhostName);
    QList<QHostAddress> list=hostinfo.addresses();
    if(!list.isEmpty()){
        QList<QHostAddress>::iterator i;
        for(i=list.begin();i!=list.end();i++)
        {
            QMessageBox::information(this,"提示",(*i).toString());
        }
    }
    QMessageBox::information(this,"提示",localhostName);
}
void Widget::on_click2(){
    QString detail="";
    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces();
    QList<QNetworkInterface>::iterator i;
    for(i=list.begin();i!=list.end();i++)
    {
        QNetworkInterface interface=*i;
        detail=tr("设备:")+interface.name()+"\n";
        detail=detail+tr("硬件地址")+interface.hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entrylist=interface.addressEntries();
        QList<QNetworkAddressEntry>::iterator j;
        for(j=entrylist.begin();j!=entrylist.end();j++)
        {
            QNetworkAddressEntry entry=*j;
            detail=detail+"\t"+tr("ip地址:")+entry.ip().toString()+"\n";
            detail=detail+"\t"+tr("子网掩码:")+entry.netmask().toString()+"\n";
            detail=detail+"\t"+tr("广播地址:")+entry.broadcast().toString()+"\n";

        }
        QMessageBox::information(this,tr("detail"),detail);
    }
}
