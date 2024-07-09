#include<QMouseEvent>
#include "dlg_signup.h"
#include "ui_dlg_signup.h"
#include<QDebug>
#include"sqlite3.h"
#include"dlg_welcome.h"
#include<QMessageBox>
#include<QInputDialog>

#include<QGraphicsDropShadowEffect>
const char * insertcpp2sql(char* id,char* password)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "INSERT INTO manger(id,password) VALUES('%s','%s')", id, password);
    return buf;
}
const char * insertreader(char* id,char * password)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "INSERT INTO reader(id,password,nickname,credit) VALUES('%s','%s','%s',0)", id, password, id);
    return buf;
}
Dlg_SignUp::Dlg_SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_SignUp)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(1);
    ui->radioButton_2->setChecked(0);
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
}

Dlg_SignUp::~Dlg_SignUp()
{
    delete ui;
}

void Dlg_SignUp::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void Dlg_SignUp ::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void Dlg_SignUp::on_pushButton_clicked()
{
    QString AccString = ui->lineEdit_3->text();
    QString PasswString = ui->lineEdit_4->text();
    QString ConfirmPasswString = ui->lineEdit_2->text();
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;
    rc = sqlite3_open("data.db", &db);
    char* nidname, *npassword;
    std::string str1=AccString.toStdString();
    std::string str2=PasswString.toStdString();
    nidname=(char*)str1.c_str();
    npassword=(char*)str2.c_str();
    if(PasswString!=ConfirmPasswString)
    {
        QMessageBox::StandardButton reply02;
        reply02 = QMessageBox::information(this,tr("学生管理系统"),"密码不相同<br>""请再次确认密码");
    }
    else
    {
        if (ui->radioButton->isChecked())
            {//用户选项
            qDebug()<<"用户";
            rc = sqlite3_exec(db, insertreader(nidname, npassword), NULL, NULL, NULL);
            }
        else if (ui->radioButton_2->isChecked())
        {//管理员选项
            qDebug()<<"管理员";
            QString text = QInputDialog::getText(this, tr("成为管理员"),tr("输入您的邀请码："));
            qDebug()<<text;
            if(text!="114514")
            {
                rc=5;
            }
            else
            {
                rc=sqlite3_exec(db,insertcpp2sql(nidname,npassword),NULL,NULL,NULL);
            }
        }
            if (!rc)
            {
            qDebug()<<"Scuess";
            Dlg_Welcome *wcm = new Dlg_Welcome;
            sqlite3_close(db);
            wcm->show();
            this->hide();
            }
            else
            {
                if (rc==5)
                {
                    QMessageBox::StandardButton reply03;
                    reply03 = QMessageBox::information(this,tr("成为管理员"),"邀请码错误<br>""请再次确认邀请码");
                }
                else
                {
                    qDebug()<<"Failed";
                    QMessageBox::StandardButton reply;
                    reply = QMessageBox::information(this,tr("学生管理系统"),"账号重复<br>""请重新输入");
                }
            }
        }
}
void Dlg_SignUp::on_pushButton_2_clicked()
{
    Dlg_Welcome *wcm = new Dlg_Welcome;
    wcm->show();
    this->hide();
}

