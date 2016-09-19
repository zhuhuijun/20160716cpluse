#include "mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("记事本"));
    text=new QTextEdit;
    this->setCentralWidget(text);
        filemenu=this->menuBar()->addMenu(tr("文件"));
    openFileAction = new QAction(tr("打开"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    filemenu->addAction(openFileAction);
}

MainWindow::~MainWindow()
{

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
