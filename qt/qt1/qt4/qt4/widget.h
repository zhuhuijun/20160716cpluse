#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLabel *UserNameLabel;
    QLineEdit *UserNameLineEdit;
    QLabel *NameLabel;
    QLineEdit *NameLineEdit;
    QLabel *SexLabel;
    QComboBox *SexCombox;
    QLabel *DepartmentLabel;
    QTextEdit *DepartTextEdit;
    QLabel *AgeLabel,*OtherLabel;
    QLineEdit *AgeLineEdit;
    QGridLayout *LeftLayout;

    /*************右侧******/
    QLabel *HeadLabel,*HeadIconLabel;
    QPushButton  *UpdateHeadBtn;
    QHBoxLayout *TopRightLayout;
    QLabel *IntroductionLabel;
    QTextEdit *IntroductionTextEdit;
    QVBoxLayout *RightLayout;
    /************底部************/
    QPushButton *okbtn,*cancelbtn;
    QHBoxLayout *bottomlayout;



};

#endif // WIDGET_H
