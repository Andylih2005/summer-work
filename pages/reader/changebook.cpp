#include "changebook.h"
#include "ui_changebook.h"

changebook::changebook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::changebook)
{
    ui->setupUi(this);
}

changebook::~changebook()
{
    delete ui;
}
