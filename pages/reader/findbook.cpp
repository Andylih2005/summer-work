#include "findbook.h"
#include "ui_findbook.h"

#include "bookmode.h"
#include "personal.h"
#include "paymode.h"

findbook::findbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::findbook)
{
    ui->setupUi(this);
}

findbook::~findbook()
{
    delete ui;
}

//页面跳转按钮
void findbook::on_PersonalMode_Button_clicked()
{
    personal *p_personal_window=new personal;
    p_personal_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void findbook::on_BookMode_Button_clicked()
{
    bookmode *p_book_window = new bookmode;
    p_book_window->show();
    this->hide();
}

void findbook::on_PayMode_Button_clicked()
{
    paymode *p_pay_window = new paymode;
    p_pay_window->show();
    this->hide();
}

