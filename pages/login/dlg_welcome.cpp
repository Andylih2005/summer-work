#include "dlg_welcome.h"
#include "ui_dlg_welcome.h"
#include"dlg_signup.h"
#include"dlg_changepassword.h"
#include"sqlite3.h"
#include<QDebug>
const char * findcpp2sql(char test[50])
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "SELECT password FROM manger where id='%s'", test);
    return buf;
}
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


void Dlg_Welcome::on_btnLog_clicked()
{
    QString AccString = ui->LeAccount->text();
    QString PasswString = ui->LePassword->text();
    char* idname,*password;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;
    rc = sqlite3_open("test.db", &db);
    std::string str1=AccString.toStdString();
    std::string str2=PasswString.toStdString();
    idname=(char*)str1.c_str();
    password=(char*)str2.c_str();
    const char * sql = findcpp2sql(idname);
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        const unsigned char* name = sqlite3_column_text(stmt, 0);
        if (strcmp((const char*)name, (const char*)password) == 0)
        {
            qDebug()<< "correct";
        }
        else
        {
             qDebug() << "password wrong";
        }
    }
    else
    {
        qDebug()<< "id wrong";
    }
}

