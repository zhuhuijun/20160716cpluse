#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class loginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit loginDialog(QWidget *parent = 0);
private:
    QLabel *label0;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

    QLineEdit *lineEditUserId,*lineEditPwd,*lineEditdbname,*lineEditHostIp;
    QPushButton *loginbtn,*logoutbtn;
signals:

public slots:

};

#endif // LOGINDIALOG_H
