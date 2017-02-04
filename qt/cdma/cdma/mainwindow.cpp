#include "mainwindow.h"
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QIcon>
#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>
#include "logindialog.h"
#include "scriptdlg.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("CDMA无线基站管理系统");
    setWindowIcon(QIcon("main.png"));
    mdiArea =new QMdiArea;
    setCentralWidget(mdiArea);
    createActions();//创建行为
    createMenus();

    //设置窗口的背景色
    mdiArea->setBackground(Qt::NoBrush);
    mdiArea->setStyleSheet("background-image:url(2.jpg);");
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}


void MainWindow::createMenus(){
    adminMenu = menuBar()->addMenu(tr("管理"));
    adminMenu->addAction(loginAction);
    adminMenu->addAction(logoutAction);
    adminMenu->addSeparator();
    adminMenu->addAction(exitAction);

    dataMenu=menuBar()->addMenu(tr("数据"));
    dataMenu->addAction(scriptAction);


    windowMenu=menuBar()->addMenu(tr("窗口"));
    windowMenu->addAction(cascadeAction);
    windowMenu->addAction(tileAction);

    helpMenu=menuBar()->addMenu(tr("帮助"));
    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutActiion);


}
/*创建行为*/
void MainWindow::createActions(){
    loginAction =new QAction(tr("登录"),this);
    loginAction->setShortcut(tr("Ctrl+u"));
    connect(loginAction,SIGNAL(triggered()),this,SLOT(on_login()));

    logoutAction=new QAction(tr("注销"),this);
    logoutAction->setShortcut(tr("Ctrl+b"));
    connect(logoutAction,SIGNAL(triggered()),this,SLOT(on_logout()));


    exitAction=new QAction(tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+w"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(on_exit()));

    scriptAction=new QAction(tr("执行脚本"),this);
    scriptAction->setShortcut(tr("Ctrl+t"));
    scriptAction->setEnabled(false);//不可用
    connect(scriptAction,SIGNAL(triggered()),this,SLOT(on_script()));


    cascadeAction=new QAction(tr("层叠"),this);
    cascadeAction->setShortcut(tr("Ctrl+Q"));
    connect(cascadeAction,SIGNAL(triggered()),this,SLOT(cascadeWindow()));

    tileAction=new QAction(tr("并列"),this);
    tileAction->setShortcut(tr("Ctrl+R"));
    connect(tileAction,SIGNAL(triggered()),this,SLOT(tilWindow()));


    helpAction=new QAction(tr("帮助"),this);
    helpAction->setShortcut(tr("Ctrl+H"));
    connect(helpAction,SIGNAL(triggered()),this,SLOT(on_help()));


    aboutActiion=new QAction(tr("关于"),this);
    aboutActiion->setShortcut(tr("Ctrl+A"));
    connect(aboutActiion,SIGNAL(triggered()),this,SLOT(on_about()));

}
//登录
void MainWindow::on_login(){
    loginDialog dlg;
    dlg.exec();//模态 show();不是
    if(dlg.islogin){
        int res = db.sql_connect(dlg.hostip.toStdString().data(),
                                 dlg.userid.toStdString().data(),
                                 dlg.passwd.toStdString().data(),
                                 dlg.dbname.toStdString().data());
        if(res==-1){
            QMessageBox::information(this,"登录失败",db.geterror());
        }else{
            scriptAction->setEnabled(true);
            QMessageBox::information(this,"","登录成功");
        }
    }

}
//注销
void MainWindow::on_logout(){
    QMessageBox::StandardButton button;
    button =  QMessageBox::question(this,tr("提示"),"是否注销?",QMessageBox::Yes|QMessageBox::Cancel);
    if(button==QMessageBox::Yes)
    {
        scriptAction->setEnabled(false);
        db.sql_disconnect();
    }

}
//退出
void MainWindow::on_exit(){
    this->close();
}
//执行脚本
void MainWindow::on_script()
{
    //showsub();
    //showview();
    scriptDlg sc;
    sc.exec();
    /*
    if(db.sql_exec("delete from table1 where name='1'")==-1)
    {
        QMessageBox::information(this,"exec error",db.geterror());
    }else{
         QMessageBox::information(this,"成功","恭喜你,操作执行成功!");
    }
    */
    if(sc.isoklogin){
        scriptMsg(sc.SQL.toStdString().data());
    }
}

void MainWindow::scriptMsg(const char *SQL)
{
    int ret=0;
    if((strncmp(SQL,"SELECT",6)==0)||(strncmp(SQL,"select",6)==0))
    {
        QStandardItemModel *model=NULL;
        ret=db.sql_open(SQL,&model);
        QTableView  *view=new QTableView;
        view->setAttribute(Qt::WA_DeleteOnClose);
        mdiArea->addSubWindow(view);
        view->setStyleSheet("border-image:url(3.jpg);");
        view->setModel(model);
        view->show();
        mdiArea->activeSubWindow()->resize(width()-100,height()-100);
    }else
    {
        ret=db.sql_exec(SQL);
    }
    if(ret==-1)
    {
        QMessageBox::information(this,"失败",db.geterror());
    }else{
        QMessageBox::information(this,"成功","恭喜你,操作执行成功!");
    }
}


void MainWindow::showsub()
{
    QWidget *w1=new QWidget;
    w1->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动释放
    mdiArea->addSubWindow(w1);
    w1->setWindowTitle("SSSSSSSSS");
    w1->setStyleSheet("border-image:url(3.jpg);");
    w1->show();
    mdiArea->activeSubWindow()->resize(width()-100,height()-100);

}
//层叠
void MainWindow::cascadeWindow()
{
    mdiArea->cascadeSubWindows();
}
//并列
void MainWindow::tilWindow()
{
    mdiArea->tileSubWindows();
}
void MainWindow::on_help()
{
    QMessageBox::information(this,"帮助","版权所有,盗版必究!");
}
//关于
void MainWindow::on_about()
{
    QMessageBox::about(this,"关于","版权所有,盗版必究!");
}
//退出提示
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
    button =  QMessageBox::question(this,tr("退出程序"),"是否退出程序?",QMessageBox::Yes|QMessageBox::Cancel);
    if(button==QMessageBox::Yes)
    {
        event->accept();
    }else{
        event->ignore();
    }

}
void MainWindow::showview()
{
    QStandardItemModel *model=new QStandardItemModel(5,3);
    QTableView *view1=new QTableView;
    view1->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动释放
    mdiArea->addSubWindow(view1);
    view1->setWindowTitle("SSSSSSSSS");
    view1->setStyleSheet("border-image:url(3.jpg);");
    view1->setModel(model);
    view1->show();
    mdiArea->activeSubWindow()->resize(width()-100,height()-100);

}
MainWindow::~MainWindow()
{

}
