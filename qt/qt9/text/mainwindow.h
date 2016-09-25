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
    QMenu *helpmenu;
    QAction *openFileAction,*newFileAction,*saveFileAction,*exitFileAction,*copyFileAction,*cutFileAction,
    *parseFileAction;
    QAction *helpAction;
    void closeEvent(QCloseEvent *event);
    void createActions();
    void createmenu();
private slots:
    void openfile();
    void newfile();
    void savefile();
    void exitfile();
    void copyfile();
    void cutfile();
    void parsefile();
    void helpabout();
};

#endif // MAINWINDOW_H
