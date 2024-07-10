#include "bookmode.h"
#include "ui_bookmode.h"
#include "personal.h"
#include "findbook.h"
#include "paymode.h"
#include"sqlite3.h"
#include <QMessageBox>

extern char* nowaccount;

#include<vector>
extern sqlite3 *db;
const char * getall(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT * FROM record WHERE userid='%s'",id);
    return buf;
}

std::vector<UserRecord> records;

bookmode::bookmode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bookmode)
{
    ui->setupUi(this);

    const char * sql=getall(nowaccount);
    sqlite3_stmt *stmt;
    int rc;
    rc=sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        UserRecord temp;
        temp.username=QString((char*)sqlite3_column_text(stmt, 2));
        temp.bookname=QString((char*)sqlite3_column_text(stmt, 0));
        temp.isbn=QString((char*)sqlite3_column_text(stmt, 1));
        temp.intime=sqlite3_column_int(stmt,5);;
        temp.outtime=sqlite3_column_int(stmt,4);
        records.push_back(temp);
    }
    sqlite3_finalize(stmt);
    int length = records.size();
    qDebug() << "Number of records for user:" << length;

}
void b_timeint(int  intime,int outtime){

}


bookmode::~bookmode()
{
    delete ui;
}

//页面跳转按钮
void bookmode::on_PersonalMode_Button_clicked()
{
    personal *p_personal_window=new personal;
    p_personal_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void bookmode::on_FindBookMode_Button_clicked()
{

    findbook *p_find_window = new findbook;
    p_find_window->show();
    this->hide();
}

void bookmode::on_PayMode_Button_clicked()
{
    paymode *p_pay_window = new paymode;
    p_pay_window->show();
    this->hide();
}

