#include "dlg_signup.h"
#include "ui_dlg_signup.h"

Dlg_SignUp::Dlg_SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_SignUp)
{
    ui->setupUi(this);
}

Dlg_SignUp::~Dlg_SignUp()
{
    delete ui;
}
