#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu> //菜单
#include <QMenuBar> //菜单栏
#include <QAction> //行为
#include <QCloseEvent>
#include <QMdiArea>
#include "yourmysql.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    yourmysql db;
    void showsub();
    void createMenus();
    void createActions();
    void showview();
    void closeEvent(QCloseEvent *event);
    QMenu *adminMenu;
    QMenu *dataMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;

    QAction *loginAction;
    QAction *logoutAction;
    QAction *exitAction;


    QAction *scriptAction;

    QAction *cascadeAction;
    QAction *tileAction;

    QAction *helpAction;
    QAction *aboutActiion;

    QMdiArea *mdiArea;
private slots:
    void on_login();
    void on_logout();
    //alt+回车键
    void on_exit();
    void on_script();

    void cascadeWindow();
    void tilWindow();

    void on_help();
    void on_about();
};













#endif // MAINWINDOW_H
