#include "logindialog.h"
#include <QGridLayout>
#include <QPalette>
#include <QMessageBox>
loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent)
{

    islogin=false;
    label0=new QLabel;
    label0->setText(tr("用户名:"));


    label1=new QLabel;
    label1->setText(tr("密码:"));


    label2=new QLabel;
    label2->setText(tr("数据库名:"));


    label3=new QLabel;
    label3->setText(tr("服务器 Ip:"));

    lineEditUserId=new QLineEdit;

    lineEditPwd=new QLineEdit;
    lineEditPwd->setEchoMode(QLineEdit::Password);
    lineEditdbname=new QLineEdit;
    lineEditHostIp=new QLineEdit;


    loginbtn=new QPushButton;
    loginbtn->setText(tr("登录"));
    logoutbtn=new QPushButton;
    logoutbtn->setText(tr("退出"));


    QGridLayout *layout1=new QGridLayout(this);
    layout1->addWidget(label0,0,0);
    layout1->addWidget(lineEditUserId,0,1);

    layout1->addWidget(label1,1,0);
    layout1->addWidget(lineEditPwd,1,1);

    layout1->addWidget(label2,2,0);
    layout1->addWidget(lineEditdbname,2,1);


    layout1->addWidget(label3,3,0);
    layout1->addWidget(lineEditHostIp,3,1);

    layout1->addWidget(loginbtn,4,0);
    layout1->addWidget(logoutbtn,4,1);

    layout1->setColumnStretch(0,1);
    layout1->setColumnStretch(1,1);

    setWindowTitle("登录");
    layout1->setMargin(15);//设置边距
    layout1->setSpacing(10);//控件间的间隔
    layout1->setSizeConstraint(QLayout::SetFixedSize);//设置适合窗口的大小

    setWindowIcon(QIcon("main.png"));

    //设置背景色
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("2.jpg")));
    setPalette(palette);

    connect(loginbtn,SIGNAL(clicked()),this,SLOT(loginbtnclick()));
    connect(logoutbtn,SIGNAL(clicked()),this,SLOT(cancelbtnclick()));
}

void loginDialog::loginbtnclick()
{
    this->userid=lineEditUserId->text();
    this->passwd=lineEditPwd->text();
    this->dbname=lineEditdbname->text();
    this->hostip=lineEditHostIp->text();
    this->islogin=true;
    close();
}

void loginDialog::cancelbtnclick()
{
    islogin=false;
    close();
}
