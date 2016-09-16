#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLineEdit *edit1,*edit2;
    QLabel *label1,*label2;
    QPushButton *btn1,*btn2;

};

#endif // WIDGET_H
