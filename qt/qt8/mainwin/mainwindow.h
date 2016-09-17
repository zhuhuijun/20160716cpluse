#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QTextEdit>
#include <QMenuBar>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QAction *open,*fileexit;
    QMenu *menu;
    QTextEdit *text;
private slots:
    void openfile();
    void exitfile();

};

#endif // MAINWINDOW_H
