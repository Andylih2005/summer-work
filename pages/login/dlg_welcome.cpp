#include "dlg_welcome.h"
#include "ui_dlg_welcome.h"
#include"dlg_signup.h"
#include"dlg_changepassword.h"
Dlg_Welcome::Dlg_Welcome(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_Welcome)
{
    ui->setupUi(this);
    setFixedSize(800,400);
}

Dlg_Welcome::~Dlg_Welcome()
{
    delete ui;
}

void Dlg_Welcome::on_btnSign_clicked()
{
   Dlg_SignUp  *sgu = new Dlg_SignUp;
    sgu->show();
    hide();
}

//忘记密码
void Dlg_Welcome::on_pushButton_clicked()
{
    Dlg_ChangePassword *cpw = new Dlg_ChangePassword;
    cpw->show();
    hide();
}

