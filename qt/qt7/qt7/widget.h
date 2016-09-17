#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLabel *label1;
    QPushButton *btn1;
    QTimer *tm;
    QStringList strlist;
private slots:
    void on_clicked();
    void on_timer();
};

#endif // WIDGET_H
