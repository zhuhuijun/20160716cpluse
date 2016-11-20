#ifndef SCRIPTDLG_H
#define SCRIPTDLG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
class scriptDlg : public QDialog
{
    Q_OBJECT
public:
    explicit scriptDlg(QWidget *parent = 0);
    QString SQL;
    bool isoklogin;
signals:

private slots:
    void on_exec();
    void on_cancel();
private:
    QLabel *label0;
    QTextEdit *textEditSql;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

};

#endif // SCRIPTDLG_H
