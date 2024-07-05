#include "inputbook.h"
#include "ui_inputbook.h"

#include "checkbook.h"
#include "usemmanagement.h"

inputbook::inputbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inputbook)
{
    ui->setupUi(this);
}

inputbook::~inputbook()
{
    delete ui;
}

void inputbook::on_BookMode_Button_clicked()
{
    checkbook *p_m_check_window=new checkbook;
    p_m_check_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void inputbook::on_FindBookMode_Button_clicked()
{
    UseMmanagement *p_m_userM_window=new UseMmanagement;
    p_m_userM_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

