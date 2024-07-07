#include "inputbook.h"
#include "ui_inputbook.h"
extern char* nowaccount;
inputbook::inputbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inputbook)
{
    ui->setupUi(this);
    QString qstr(nowaccount);
    ui->label_6->setText(qstr);
}

inputbook::~inputbook()
{
    delete ui;
}
