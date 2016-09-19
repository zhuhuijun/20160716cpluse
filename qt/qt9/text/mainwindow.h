#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QTextEdit>
#include <QMenuBar>
#include <QCloseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QTextEdit *text;
    QMenu *filemenu;
    QMenu *editmenu;
    QAction *openFileAction,*newFileAction,*saveFileAction,*exitFileAction,*copyFileAction,*cutFileAction,
    *parseFileAction;
    void closeEvent(QCloseEvent *event);

};

#endif // MAINWINDOW_H
