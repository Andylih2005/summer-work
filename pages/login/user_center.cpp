#include "user_center.h"
#include "ui_user_center.h"

User_Center::User_Center(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User_Center)
{
    ui->setupUi(this);
}

User_Center::~User_Center()
{
    delete ui;
}
