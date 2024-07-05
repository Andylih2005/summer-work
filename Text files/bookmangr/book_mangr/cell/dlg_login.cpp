#include "dlg_login.h"
#include "ui_dlg_login.h"

DLG_Login::DLG_Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DLG_Login)
{
    ui->setupUi(this);
}

DLG_Login::~DLG_Login()
{
    delete ui;
}

void DLG_Login::on_btn_login_clicked()
{
    setResult(1);
    hide();
}


void DLG_Login::on_btn_exit_clicked()
{
    setResult(0);
    hide();
}

