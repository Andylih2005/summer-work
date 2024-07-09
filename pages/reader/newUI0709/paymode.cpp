#include "paymode.h"
#include "ui_paymode.h"
#include "bookmode.h"
#include "findbook.h"
#include "personal.h"
extern char* nowaccount;
paymode::paymode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::paymode)
{
    ui->setupUi(this);
    qDebug()<<nowaccount;
}

paymode::~paymode()
{
    delete ui;
}

//页面跳转按钮
void paymode::on_PersonalMode_Button_clicked()
{
    personal *p_personal_window=new personal;
    p_personal_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void paymode::on_BookMode_Button_clicked()
{
    bookmode *p_book_window = new bookmode;
    p_book_window->show();
    this->hide();
}

void paymode::on_FindBookMode_Button_clicked()
{
    findbook *p_find_window = new findbook;
    p_find_window->show();
    this->hide();
}

