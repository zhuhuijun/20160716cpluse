#include "mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
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

    saveFileAction = new QAction(tr("保存"),this);
    saveFileAction->setShortcut(tr("Ctrl+S"));
    connect(saveFileAction,SIGNAL(triggered()),this,SLOT(savefile()));

    exitFileAction=new QAction(tr("退出"),this);
    exitFileAction->setShortcut(tr("Ctrl+Q"));
    connect(exitFileAction,SIGNAL(triggered()),this,SLOT(exitfile()));


    //编辑
    copyFileAction=new QAction(tr("复制"),this);
    copyFileAction->setShortcut(tr("Ctrl+C"));
    connect(copyFileAction,SIGNAL(triggered()),this,SLOT(copyfile()));

    parseFileAction=new QAction(tr("粘贴"),this);
    parseFileAction->setShortcut(tr("Ctrl+P"));
    connect(parseFileAction,SIGNAL(triggered()),this,SLOT(parsefile()));


    cutFileAction=new QAction(tr("剪切"),this);
    cutFileAction->setShortcut(tr("Ctrl+X"));
    connect(cutFileAction,SIGNAL(triggered()),this,SLOT(cutfile()));


    helpAction=new QAction(tr("关于"),this);
    helpAction->setShortcut(tr("Ctrl+H"));
    connect(helpAction,SIGNAL(triggered()),this,SLOT(helpabout()));
}
void MainWindow::createmenu()
{
    filemenu=this->menuBar()->addMenu(tr("文件"));
    filemenu->addAction(openFileAction);
    filemenu->addAction(newFileAction);
    filemenu->addAction(saveFileAction);
    filemenu->addSeparator();//分割线
    filemenu->addAction(exitFileAction);

    editmenu=this->menuBar()->addMenu(tr("编辑"));
    editmenu->addAction(copyFileAction);
    editmenu->addAction(parseFileAction);
    editmenu->addAction(cutFileAction);

    helpmenu=this->menuBar()->addMenu(tr("帮助"));
    helpmenu->addAction(helpAction);
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
void MainWindow::newfile(){
    text->clear();
}
void MainWindow::openfile(){
    QString filename=QFileDialog::getOpenFileName(this,tr("打开文件"));
    if(filename.isEmpty())
        return;
    QFile data(filename);
    if(data.open(QFile::ReadOnly))
    {
        text->clear();//清空文本
        QTextStream  stream(&data);
        while(!stream.atEnd())
        {
            text->append(stream.readLine());
        }
        data.close();
    }else{
        QMessageBox::critical(this,tr("错误"),data.errorString());
    }
}
void MainWindow::savefile(){
    QString filename=QFileDialog::getSaveFileName(this,tr("保存文件"));
    if(filename.isEmpty())
        return;
    QFile data(filename);
    if(data.open(QFile::WriteOnly|QFile::Truncate)){
        QTextStream stream(&data);
        stream<<text->toPlainText();//将text转换为QString写入文件
        data.close();
    }else{
        QMessageBox::critical(this,tr("错误"),data.errorString());

    }
}
void MainWindow::exitfile(){
    close();//不要用exit(0);
}
void MainWindow::copyfile(){
    text->copy();
}
void MainWindow::cutfile(){
    text->cut();
}
void MainWindow::parsefile(){
    text->paste();
}
void MainWindow::helpabout(){
    QMessageBox::about(this,"关于","这是我的第一个QT程序实例!");
}
