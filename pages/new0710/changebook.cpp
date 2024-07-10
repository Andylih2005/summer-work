#include "changebook.h"
#include "ui_changebook.h"
#include "checkbook.h"

extern char* nowaccount;

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

void changebook::on_back_button_clicked()
{
    checkbook *p_m_check_window=new checkbook;
    p_m_check_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}



void changebook::on_None_button_clicked()
{

}

