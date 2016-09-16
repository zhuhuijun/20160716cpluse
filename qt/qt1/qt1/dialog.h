#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTimer>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QPushButton *btn1;
    QLineEdit *edit1,*edit2;
    QLabel *label;
    QTimer *timer1;
private slots:
    void add();
    void clicktimer();
};

#endif // DIALOG_H
