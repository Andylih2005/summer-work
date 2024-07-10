#include "bookmode.h"
#include "ui_bookmode.h"
#include "personal.h"
#include "findbook.h"
#include "paymode.h"
extern char* nowaccount;
bookmode::bookmode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bookmode)
{
    ui->setupUi(this);
}

bookmode::~bookmode()
{
    delete ui;
}

//页面跳转按钮
void bookmode::on_PersonalMode_Button_clicked()
{
    personal *p_personal_window=new personal;
    p_personal_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void bookmode::on_FindBookMode_Button_clicked()
{

    findbook *p_find_window = new findbook;
    p_find_window->show();
    this->hide();
}

void bookmode::on_PayMode_Button_clicked()
{
    paymode *p_pay_window = new paymode;
    p_pay_window->show();
    this->hide();
}

