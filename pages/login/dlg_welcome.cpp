#include "dlg_welcome.h"
#include "ui_dlg_welcome.h"

Dlg_Welcome::Dlg_Welcome(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_Welcome)
{
    ui->setupUi(this);
}

Dlg_Welcome::~Dlg_Welcome()
{
    delete ui;
}
