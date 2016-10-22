#include "mainwindow.h"
#include <QMessageBox>
#include <QIcon>
#include "logindialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Cdma无线基站管理系统");
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
}
//登录
void MainWindow::on_login(){
    loginDialog dlg;
    dlg.exec();//模态 show();不是
}
//注销
void MainWindow::on_logout(){
    QMessageBox::information(this,"","hello world");
}
//退出
void MainWindow::on_exit(){
    this->close();
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
