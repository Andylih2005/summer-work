#include "checkbook.h"
#include "ui_checkbook.h"
#include"sqlite3.h"
#include "inputbook.h"
#include "usemmanagement.h"
#include "changebook.h"
#include "Dlg_Welcome.h"
#include <QMessageBox>
#include "user_center.h"
extern char* nowaccount;
extern sqlite3*db;
QString ISBN_E;

const char * getisbn6(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT * FROM book WHERE IBSN='%s'",id);
    return buf;
}
checkbook::checkbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::checkbook)
{
    ui->setupUi(this);
}

checkbook::~checkbook()
{
    delete ui;
}

void checkbook::on_PersonalMode_Button_clicked()
{
    inputbook *p_m_input_window=new inputbook;
    p_m_input_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


void checkbook::on_FindBookMode_Button_clicked()
{
    usemmanagement *p_m_userM_window=new usemmanagement;
    p_m_userM_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


void checkbook::on_pushButton_4_clicked()
{
    usemmanagement *p_m_userM_window=new usemmanagement;
    p_m_userM_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


struct book
{
    QString name;
    QString author;
    QString isbn;
    QString press;
    QString type;
};

void checkbook::on_search_button_clicked()
{
    QString number=ui->ISBN_input->text();
    if (number.length() != 13) {
        QMessageBox::warning(this, "错误", "输入的ISBN码不足13位");
        return;
    }
    else{
        sqlite3_stmt* stmt;
        int rc;
        std::string tmp=number.toStdString();
        char * isbn=(char*)tmp.c_str();
        const char * sql = getisbn6(isbn);
        book test;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            qDebug() << "准备语句失败:" << sqlite3_errmsg(db);        }
        else
        {
            rc=sqlite3_step(stmt);
            if (rc==SQLITE_ROW)
            {
                test.name=QString((char*)sqlite3_column_text(stmt, 0));
                test.author = QString((char*)sqlite3_column_text(stmt, 1));
                test.isbn = QString((char*)sqlite3_column_text(stmt, 2));
                test.press=QString((char*)sqlite3_column_text(stmt, 3));
                test.type=QString((char*)sqlite3_column_text(stmt, 4));
                ISBN_E=number;
                changebook *p_m_changebook_window=new changebook;
                p_m_changebook_window->show();  // 显示新窗口
                this->hide();
            } // 关闭当前窗口
            else
            {
                QMessageBox::warning(this, "错误", "没有这本书");
            }
        }
    }
}


void checkbook::on_Seen_Button_clicked()
{
    User_Center *p_m_see_window=new User_Center;
    p_m_see_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


void checkbook::on_pushButton_clicked()
{
    Dlg_Welcome *wcm = new Dlg_Welcome;
    sqlite3_close(db);
    wcm->show();
    this->hide();
}

