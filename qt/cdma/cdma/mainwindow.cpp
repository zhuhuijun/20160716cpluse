#include "mainwindow.h"
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QIcon>
#include <QWidget>
#include "logindialog.h"
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
}

MainWindow::~MainWindow()
{

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
        if(dlg.userid=="abc"){
            QMessageBox::information(this,"","登录成功");
        }else{
            QMessageBox::information(this,"","登录失败");
        }
    }

}
//注销
void MainWindow::on_logout(){
    QMessageBox::information(this,"","hello world");
}
//退出
void MainWindow::on_exit(){
    this->close();
}
//执行脚本
void MainWindow::on_script()
{
    showsub();
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
