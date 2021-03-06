#include "widget.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QFont>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("幸运大抽奖"));
    label1=new QLabel;
    label1->setText("开始幸运大抽奖");
    QFont font;
    font.setBold(true);
    font.setPointSize(50);
    label1->setFont(font);
    btn1=new QPushButton;
    btn1->setText(tr("开始"));

    QVBoxLayout *layout1=new QVBoxLayout(this);
    layout1->addWidget(label1,0,Qt::AlignHCenter);
    layout1->addWidget(btn1);
   // this->layout(layout1);
    QFile file("student.txt");
    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            strlist.append(stream.readLine());
        }
        file.close();
    }else{
        QMessageBox::critical(this,tr("错误"),file.errorString());
        exit(0);
    }
    tm=new QTimer(this);
    connect(tm,SIGNAL(timeout()),this,SLOT(on_timer()));
    connect(btn1,SIGNAL(clicked()),this,SLOT(on_clicked()));
}

Widget::~Widget()
{

}

void Widget::on_clicked(){
    static bool status=true;
    if(status)
    {
        btn1->setText("停止");
        tm->start(50);
        status=false;
    }else
    {
        btn1->setText("开始");
        tm->stop();
        status=true;
    }
}

void Widget::on_timer()
{
    if(strlist.count()==0)
    {
        return;//退出
    }static int i=0;
    label1->setText(strlist[i]);
    i++;
    if(i>=strlist.count())
        i=0;
}
