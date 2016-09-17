#include "mainwindow.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("记事本");
    open=new QAction(tr("打开"),this);
    fileexit=new QAction(tr("退出"),this);
    open->setShortcut(tr("Ctrl+O"));
    fileexit->setShortcut(tr("Ctrl+X"));

    menu=menuBar()->addMenu(tr("文件"));
    menu->addAction(open);
    menu->addSeparator();
    menu->addAction(fileexit);
    text=new QTextEdit();
    setCentralWidget(text);
    connect(open,SIGNAL(triggered()),this,SLOT(openfile()));
    connect(fileexit,SIGNAL(triggered()),this,SLOT(exitfile()));
}

MainWindow::~MainWindow()
{

}
void MainWindow::openfile()
{
    QFileDialog::getOpenFileName();
}

void MainWindow::exitfile()
{
    this->close();
}
