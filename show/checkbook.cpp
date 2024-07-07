#include "checkbook.h"
#include "ui_checkbook.h"
extern char* nowaccount;
checkbook::checkbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::checkbook)
{
    ui->setupUi(this);
}

checkbook::~checkbook()
{
    delete ui;
}
