#include "scriptdlg.h"
#include <QGridLayout>
#include <QLayout>
#include <QHBoxLayout>
scriptDlg::scriptDlg(QWidget *parent) :
    QDialog(parent)
{
    label0=new QLabel;
    label0->setText("请输入Sql:");
    textEditSql=new QTextEdit;
    okBtn=new QPushButton;
    okBtn->setText("执行");
    cancelBtn=new QPushButton;
    cancelBtn->setText("取消");

    QGridLayout *layout1=new QGridLayout(this);
    layout1->addWidget(label0,0,0);
    layout1->addWidget(textEditSql,0,1);

    QHBoxLayout *layout2=new QHBoxLayout();
    layout2->addWidget(okBtn);
    layout2->addWidget(cancelBtn);
    layout1->addLayout(layout2,1,1);

    setWindowTitle("脚本");
    layout1->setMargin(15);//设置边距
    layout1->setSpacing(10);//控件间的间隔
    layout1->setSizeConstraint(QLayout::SetFixedSize);//设置适合窗口的大小

    setWindowIcon(QIcon("main.png"));

    connect(okBtn,SIGNAL(clicked()),this,SLOT(on_exec()));
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(on_cancel()));
}

void scriptDlg::on_exec()
{
    isoklogin=true;
    SQL=textEditSql->toPlainText();
    close();
}

void scriptDlg::on_cancel()
{
    isoklogin=false;
    close();

}
