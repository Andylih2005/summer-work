#include "pay_window.h"
#include "ui_pay_window.h"

pay_window::pay_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::pay_window)
{
    ui->setupUi(this);
}

pay_window::~pay_window()
{
    delete ui;
}
