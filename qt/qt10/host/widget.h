#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *btn1;
    QPushButton *btn2;
private slots:
    void on_click();
    void on_click2();
};

#endif // WIDGET_H
