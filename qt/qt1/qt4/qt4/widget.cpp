#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QFrame>
#include <QGridLayout>
#include <QPixmap>
#include <QHBoxLayout>
#include <QTextEdit>
Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle(tr("用户信息"));

    UserNameLabel=new QLabel(tr("用户名:"));
    UserNameLineEdit=new QLineEdit;
    NameLabel=new QLabel(tr("姓名"));
    NameLineEdit=new QLineEdit;
    SexLabel =new QLabel(tr("性别:"));
    SexCombox =new QComboBox;
    SexCombox->addItem(tr("男"));
    SexCombox->addItem(tr("女"));
    DepartmentLabel=new QLabel(tr("部门:"));
    DepartTextEdit=new QTextEdit;
    AgeLabel=new QLabel(tr("年龄:"));
    AgeLineEdit=new QLineEdit;
    OtherLabel=new QLabel(tr("其他:"));
    OtherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    LeftLayout=new QGridLayout();
    LeftLayout->addWidget(UserNameLabel,0,0);
    LeftLayout->addWidget(UserNameLineEdit,0,1);

    LeftLayout->addWidget(NameLabel,1,0);
    LeftLayout->addWidget(NameLineEdit,1,1);

    LeftLayout->addWidget(SexLabel,2,0);
    LeftLayout->addWidget(SexCombox,2,1);

    LeftLayout->addWidget(DepartmentLabel,3,0);
    LeftLayout->addWidget(DepartTextEdit,3,1);

    LeftLayout->addWidget(AgeLabel,4,0);
    LeftLayout->addWidget(AgeLineEdit,4,1);

    LeftLayout->addWidget(OtherLabel,5,0,1,2);
    LeftLayout->setColumnStretch(0,1);//设置比例
    LeftLayout->setColumnStretch(1,3);
    /**************right panel***************/

    HeadLabel =new QLabel(tr("头像:"));
    HeadIconLabel=new QLabel;
    QPixmap icon("1.jpg");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(),icon.height());
    UpdateHeadBtn=new QPushButton(tr("更新"));

    TopRightLayout=new QHBoxLayout();
    TopRightLayout->setSpacing(20);
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLabel);
    TopRightLayout->addWidget(UpdateHeadBtn);

    IntroductionLabel=new QLabel(tr("个人说明:"));
    IntroductionTextEdit=new QTextEdit;

    RightLayout=new QVBoxLayout();
    RightLayout->setMargin(10);
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionTextEdit);

    /****bootom**/
    okbtn=new QPushButton(tr("确定"));
    cancelbtn=new QPushButton(tr("取消"));

    bottomlayout=new QHBoxLayout();
    bottomlayout->addStretch();//占位符
    bottomlayout->addWidget(okbtn);
    bottomlayout->addWidget(cancelbtn);


    /*******************/
    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(LeftLayout,0,0);
    mainLayout->addLayout(RightLayout,0,1);
    mainLayout->addLayout(bottomlayout,1,0,1,2);
    //mainLayout->setSizeConstraint(QLayout::SetFixedSize);//layout大小和控件大小适应
}

Widget::~Widget()
{

}
