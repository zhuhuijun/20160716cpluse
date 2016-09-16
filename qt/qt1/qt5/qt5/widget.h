#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *btn;
private slots:
    void on_clicked();
};

#endif // WIDGET_H
