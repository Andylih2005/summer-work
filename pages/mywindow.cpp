#include "mywindow.h"
#include "ui_mywindow.h"


MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
{
    ui->setupUi(this);
    connect(ui->Manager_Radio,&QRadioButton::toggled,this,&MyWindow::onRadioButtonToggled);//两个单选其中一个
    connect(ui->Reader_Radio,&QRadioButton::toggled,this,&MyWindow::onRadioButtonToggled);

}

MyWindow::~MyWindow()
{
    delete ui;
}

void MyWindow::onRadioButtonToggled(bool checked)
{
    QRadioButton *senderButton = qobject_cast<QRadioButton*>(sender());
    if (senderButton == ui->Manager_Radio && checked) {
        ui->Reader_Radio->setChecked(!checked);
    } else if (senderButton == ui->Reader_Radio && checked) {
        ui->Manager_Radio->setChecked(!checked);
    }
}


