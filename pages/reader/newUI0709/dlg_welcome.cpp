#include "dlg_welcome.h"
#include "ui_dlg_welcome.h"
#include"dlg_signup.h"
#include"dlg_changepassword.h"
#include"sqlite3.h"
#include<QDebug>
#include"inputbook.h"
#include"personal.h"
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>
#include<QMouseEvent>
extern char* nowaccount;
extern sqlite3* db;
const char * findcpp2sql(char test[50])
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "SELECT password FROM manger where id='%s'", test);
    return buf;
}
const char * findreader(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT password FROM reader where id='%s'",id);
    return buf;
}
Dlg_Welcome::Dlg_Welcome(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_Welcome)
{
            ui->setupUi(this);
        this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());//去掉标题栏
        this->setAttribute(Qt::WA_TranslucentBackground, true);//使得窗口透明
        //QWidget *pW = new QWidget(this);
        //pW->setGeometry(10,10,this->width() -20,this->height()-20);
        //pW->setStyleSheet("QWidget{background-color:rgb(0,0,0);border-radius:5px;}");
        QGraphicsDropShadowEffect *pShadow = new QGraphicsDropShadowEffect(this);
        pShadow->setOffset(0,0); //阴影偏移位置
        pShadow->setColor(qRgb(56,42,64)); //阴影的颜色
        pShadow->setBlurRadius(20);//阴影的范围
        this->setGraphicsEffect(pShadow);



    ui->LePassword->setEchoMode(QLineEdit::Password);
    ui->rdbtnUser->setChecked(1);
    ui->rdbtnAdmin->setChecked(0);


}

Dlg_Welcome::~Dlg_Welcome()
{
    delete ui;
}
void Dlg_Welcome::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void Dlg_Welcome ::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
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
    sqlite3_stmt* stmt;
    int rc;
    std::string str1=AccString.toStdString();
    std::string str2=PasswString.toStdString();
    idname=(char*)str1.c_str();
    password=(char*)str2.c_str();
    if (ui->rdbtnAdmin->isChecked())
    {
        const char * sql = findcpp2sql(idname);
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW)
        {
            const unsigned char* name = sqlite3_column_text(stmt, 0);
            if (strcmp((const char*)name, (const char*)password) == 0)
            {
                qDebug()<<"correct";
                strcpy(nowaccount,(const char*)idname);
                qDebug()<<nowaccount;
                inputbook *ipb = new inputbook;
                ipb->show();
                this->hide();
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
        else if (ui->rdbtnUser->isChecked())
    {
        const char * sql = findreader(idname);
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW)
        {
            const unsigned char* name = sqlite3_column_text(stmt, 0);
            if (strcmp((const char*)name, (const char*)password) == 0)
            {
                qDebug()<< "correct";
                strcpy(nowaccount,(const char*)idname);
                qDebug()<<nowaccount;
                personal *psn = new personal;
                psn->show();
                this->hide();
            }
            else
            {
                qDebug() << "password wrong";
                QMessageBox::warning(nullptr, "wrong", "Wrong Password");
            }
        }
        else
        {
            qDebug()<< "id wrong";
            QMessageBox::warning(nullptr, "wrong", "Wrong Account");
        }
    }
}





void Dlg_Welcome::on_rdbtnAdmin_clicked(bool checked)
{
    if (ui->rdbtnAdmin && checked) {
        ui->rdbtnUser->setChecked(!checked);
    } else if (ui->rdbtnUser && checked) {
        ui->rdbtnAdmin->setChecked(!checked);
    }
}




void Dlg_Welcome::on_btnClose_clicked()
{
    this->close();
}

