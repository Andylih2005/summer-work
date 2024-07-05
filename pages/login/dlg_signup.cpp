#include "dlg_signup.h"
#include "ui_dlg_signup.h"
#include<QDebug>
#include"sqlite3.h"
#include"dlg_welcome.h"
#include<QMessageBox>
const char * insertcpp2sql(char* id,char* password)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "INSERT INTO manger(id,password) VALUES('%s','%s')", id, password);
    return buf;
}
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

void Dlg_SignUp::on_pushButton_clicked()
{
    QString AccString = ui->lineEdit_2->text();
    QString PasswString = ui->lineEdit_3->text();
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;
    rc = sqlite3_open("test.db", &db);
    char* nidname, *npassword;
    std::string str1=AccString.toStdString();
    std::string str2=PasswString.toStdString();
    nidname=(char*)str1.c_str();
    npassword=(char*)str2.c_str();
    rc = sqlite3_exec(db, insertcpp2sql(nidname, npassword), NULL, NULL, NULL);
    if(!rc)
    {
        qDebug()<<"Scuess";
        Dlg_Welcome *wcm = new Dlg_Welcome;
        wcm->show();
        this->hide();
    }
    else
    {
        qDebug()<<"Failed";
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this,tr("学生管理系统"),"账号重复<br>""请重新输入");

    }
}

