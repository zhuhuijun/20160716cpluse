#include "mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("记事本"));
    text=new QTextEdit;
    this->setCentralWidget(text);
    text->setFontPointSize(15);
    createActions();
    createmenu();
}

MainWindow::~MainWindow()
{


}
void MainWindow::createActions()
{
    openFileAction = new QAction(tr("打开"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(openfile()));

    newFileAction = new QAction(tr("新建"),this);
    newFileAction->setShortcut(tr("Ctrl+N"));
    connect(newFileAction,SIGNAL(triggered()),this,SLOT(newfile()));
}
void MainWindow::createmenu()
{
    filemenu=this->menuBar()->addMenu(tr("文件"));
    filemenu->addAction(openFileAction);
    filemenu->addAction(newFileAction);
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button=
            QMessageBox::question(this,tr("退出程序"),tr("是否退出?"),QMessageBox::Yes|QMessageBox::No);
    if(button==QMessageBox::Yes)
    {
        event->accept();
    }else
    {
        event->ignore();
    }

}
void MainWindow::newfile(){}
void MainWindow::openfile(){}
void MainWindow::savefile(){}
void MainWindow::exitfile(){}
void MainWindow::copyfile(){}
void MainWindow::cutfile(){}
void MainWindow::parsefile(){}
