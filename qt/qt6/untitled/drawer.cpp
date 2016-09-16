#include "drawer.h"
#include  <QGroupBox>
#include <QVBoxLayout>

drawer::drawer(QWidget *parent) :
    QToolBox(parent)
{
    w=new Widget();
    w->resize(300,400);
    w->setWindowTitle("AAAAAAAA");
    setWindowTitle("工具栏");
    toolbtn1=new QToolButton;
    toolbtn1->setText(tr("张三"));
    toolbtn1->setIcon(QPixmap("1.png"));
    toolbtn1->setIconSize(QPixmap("1.png").size());
    toolbtn1->setAutoRaise(true);
    toolbtn1->setToolButtonStyle( Qt::ToolButtonTextBesideIcon);


    toolbtn2=new QToolButton;
    toolbtn2->setText(tr("张三2"));
    toolbtn2->setIcon(QPixmap("1.png"));
    toolbtn2->setIconSize(QPixmap("1.png").size());
    toolbtn2->setAutoRaise(true);
    toolbtn2->setToolButtonStyle( Qt::ToolButtonTextBesideIcon);


    toolbtn3=new QToolButton;
    toolbtn3->setText(tr("张三3"));
    toolbtn3->setIcon(QPixmap("1.png"));
    toolbtn3->setIconSize(QPixmap("1.png").size());
    toolbtn3->setAutoRaise(true);
    toolbtn3->setToolButtonStyle( Qt::ToolButtonTextBesideIcon);


    toolbtn4=new QToolButton;
    toolbtn4->setText(tr("张三4"));
    toolbtn4->setIcon(QPixmap("1.png"));
    toolbtn4->setIconSize(QPixmap("1.png").size());
    toolbtn4->setAutoRaise(true);
    toolbtn4->setToolButtonStyle( Qt::ToolButtonTextBesideIcon);


    QGroupBox *groupbox1=new QGroupBox;
    QVBoxLayout *vlayout1=new QVBoxLayout(groupbox1);

    vlayout1->setMargin(15);
    vlayout1->setAlignment(Qt::AlignHCenter);
    vlayout1->addWidget(toolbtn1);
    vlayout1->addWidget(toolbtn2);
    vlayout1->addStretch();



    QGroupBox *groupbox2=new QGroupBox;
    QVBoxLayout *vlayout2=new QVBoxLayout(groupbox2);

    vlayout2->setMargin(15);
    vlayout2->setAlignment(Qt::AlignHCenter);
    vlayout2->addWidget(toolbtn3);
    vlayout2->addWidget(toolbtn4);
    vlayout2->addStretch();

    this->addItem((QWidget *)groupbox1 ,tr("我的好友"));
     this->addItem((QWidget *)groupbox2 ,tr("陌生人"));
    connect(toolbtn1,SIGNAL(clicked()),this, SLOT(showmyWidget()));
    connect(toolbtn2,SIGNAL(clicked()),this, SLOT(showmyWidget()));
    connect(toolbtn3,SIGNAL(clicked()),this, SLOT(showmyWidget()));
    connect(toolbtn4,SIGNAL(clicked()),this, SLOT(showmyWidget()));
}


void drawer::showmyWidget()
{
    w->show();
}
