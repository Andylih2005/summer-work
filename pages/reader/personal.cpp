#include "personal.h"
#include "ui_personal.h"

#include "bookmode.h"
#include "findbook.h"
#include "paymode.h"

personal::personal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::personal)

{
    ui->setupUi(this);
}

personal::~personal()
{
    delete ui;
}

//页面跳转按钮
void personal::on_BookMode_Button_clicked()
{
    bookmode *p_book_window = new bookmode;
    p_book_window->show();
    this->hide();
}

void personal::on_FindBookMode_Button_clicked()
{
    findbook *p_find_window = new findbook;
    p_find_window->show();
    this->hide();
}

void personal::on_PayMode_Button_clicked()
{
    paymode *p_pay_window = new paymode;
    p_pay_window->show();
    this->hide();
}

