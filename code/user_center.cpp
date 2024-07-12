#include "user_center.h"
#include "ui_user_center.h"
#include "checkbook.h"
#include "usemmanagement.h"
#include "inputbook.h"
#include<vector>
#include"sqlite3.h"
extern sqlite3 *db;
extern char* nowaccount;
struct readcmd
{
    std::string cmd;
    std::string id;
};
std::vector<readcmd> savecmd;

User_Center::User_Center(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User_Center)
{
    ui->setupUi(this);
    qDebug()<<nowaccount;
    savecmd.clear();
    gettttt();
    showpages(1);
}

User_Center::~User_Center()
{
    delete ui;
}
void User_Center::on_BookMode_Button_clicked()
{
    checkbook *p_m_check_window=new checkbook;
    p_m_check_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void User_Center::on_FindBookMode_Button_clicked()
{
    usemmanagement *p_m_userM_window=new usemmanagement;
    p_m_userM_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}
void User_Center::on_PersonalMode_Button_clicked()
{
    inputbook *p_m_input_window=new inputbook;
    p_m_input_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void User_Center::gettttt()
{savecmd.clear();
    int rc;
    sqlite3_stmt* stmt;
    rc=sqlite3_prepare_v2(db,"SELECT * FROM feedback",-1,&stmt,NULL);
    while((rc=sqlite3_step(stmt))==SQLITE_ROW)
    {
        readcmd temp;
        temp.cmd=(char*)sqlite3_column_text(stmt,0);
        temp.id=(char*)sqlite3_column_text(stmt,1);
        savecmd.push_back(temp);
    }
}

void User_Center::showpages(int pagenumber){
    QString user=QString::fromStdString(savecmd[pagenumber-1].id);
    QString feedback=QString::fromStdString(savecmd[pagenumber-1].cmd);
    ui->user_name->setText(user);
    ui->feedback_Label->setText(feedback);
}

void User_Center::on_raise_button_clicked()
{
    QString pages_number=ui->pages->text();
    bool ok;
    int intValue = pages_number.toInt(&ok);
    int length=savecmd.size();//数据库长度
    int max_pages=length;
    if (intValue<max_pages){
        intValue += 1;
        ui->pages->setText(QString::number(intValue));
        showpages(intValue);
    }
    ui->pages->setAlignment(Qt::AlignCenter);
}

void User_Center::on_reduce_button_clicked()
{
    QString pages_number=ui->pages->text();
    bool ok;
    int intValue = pages_number.toInt(&ok);
    int length=savecmd.size();//数据库长度
    if (intValue>1){
        intValue -= 1;
        ui->pages->setText(QString::number(intValue));
        showpages(intValue);
    }
    else{
        ui->pages->setText(QString::number(intValue));
        ui->pages->setAlignment(Qt::AlignCenter);
    }
    ui->pages->setAlignment(Qt::AlignCenter);
}


void User_Center::on_pages_textChanged(const QString &arg1)
{
    QString pages_number=arg1;
    bool ok;
    int intValue = pages_number.toInt(&ok);
    int length=savecmd.size();//数据库长度
    int max_pages=length;
    if (intValue!=NULL){
        if (intValue>max_pages){
            intValue=max_pages;
            ui->pages->setText(QString::number(intValue));
            showpages(intValue);
        }
        else{
            showpages(intValue);
        }
        ui->pages->setAlignment(Qt::AlignCenter);
    }
    else if (intValue==NULL){
        qDebug()<<"HI";
    }
}
const char * delcmd(char * id,char * cmd)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"DELETE FROM feedback WHERE cmd='%s' AND id='%s'",cmd,id);
    return buf;
}

void User_Center::on_delete_2_clicked()
{    ui->pages->setAlignment(Qt::AlignCenter);
    std::string tempid=ui->user_name->text().toStdString();
    char * id=(char *)tempid.c_str();
    std::string tempcmd=ui->feedback_Label->text().toStdString();
    char * cmd=(char*)tempcmd.c_str();
    qDebug()<<id<<cmd;
    int rc=sqlite3_exec(db,delcmd(id,cmd),NULL,NULL,NULL);
    QString pages_number=ui->pages->text();
    gettttt();
    bool ok;
    int intValue = pages_number.toInt(&ok);
    int length=savecmd.size();//数据库长度
    if (intValue==length){
        intValue -= 1;
        ui->pages->setText(QString::number(intValue));
        showpages(intValue);
    }
    else{
        showpages(intValue);
    }


}

