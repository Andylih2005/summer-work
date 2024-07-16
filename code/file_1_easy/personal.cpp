#include "personal.h"
#include "ui_personal.h"
#include "bookmode.h"
#include "findbook.h"
#include "paymode.h"
#include <QInputDialog>
#include <QLineEdit>
#include<QDebug>
#include <QString>
#include <QMessageBox>
#include "Dlg_Welcome.h"
#include"sqlite3.h"
extern char* nowaccount;
QString Old_Password;
QString Old_Nickname;
extern sqlite3 *db;
const char * getnickname(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT nickname FROM reader WHERE id='%s'",id);
    return buf;
}
const char * getpassword(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT password FROM reader WHERE id='%s'",id);
    return buf;
}
const char* updateNickname(char* id, char* newNickname)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "UPDATE reader SET nickname='%s' WHERE id='%s'", newNickname, id);
    return buf;
}

const char* updatePassword(char* id, char* newPassword)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "UPDATE reader SET password='%s' WHERE id='%s'", newPassword, id);
    return buf;
}

personal::personal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::personal)
    ,enterpassword("")

{
    sqlite3_stmt* stmt,*stmt1;
    char* account=new char[50];
    int rc;
    const char * findnick = getnickname(nowaccount);
    const char * findpassword=getpassword(nowaccount);
    rc = sqlite3_prepare_v2(db, findnick, -1, &stmt, nullptr);
    const unsigned char* nickname;
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        nickname = sqlite3_column_text(stmt, 0);
    }
    rc = sqlite3_prepare_v2(db, findpassword, -1, &stmt1, nullptr);
    rc = sqlite3_step(stmt1);
    const unsigned char* password;
    if (rc == SQLITE_ROW)
    {
        password = sqlite3_column_text(stmt1, 0);
    }
    Old_Password=(char *)password;
    Old_Nickname=(char *)nickname;
    ui->setupUi(this);
    ui->nickname_label->setText(Old_Nickname);
    ui->acc_label->setText(nowaccount);
    if (Old_Nickname==nowaccount){
        QMessageBox::warning(nullptr,nullptr,"为了你的账号安全，请尽快修改昵称");
    }
    qDebug()<<Old_Nickname<<nowaccount;
}

personal::~personal()
{
    delete ui;
}

//页面跳转按钮
void personal::on_BookMode_Button_clicked()
{
    bookmode *p_book_window = new bookmode;
    p_book_window->show();
    this->hide();
}

void personal::on_FindBookMode_Button_clicked()
{
    findbook *p_find_window = new findbook;
    p_find_window->show();
    this->hide();
}

void personal::on_PayMode_Button_clicked()
{
    paymode *p_pay_window = new paymode;
    p_pay_window->show();
    this->hide();
}


void personal::on_Update_Button_clicked()
{
    bool ok;
    QString old_password_input = QInputDialog::getText(this, "检查",
                                                "输入你的旧密码", QLineEdit::Normal,
                                                "", &ok);
    if (old_password_input==Old_Password){
        QMessageBox msgBox;
        msgBox.setWindowTitle("更改");
        msgBox.setText("选择你要更改的项目：");
        QAbstractButton* pButtonNickname = msgBox.addButton("更改昵称", QMessageBox::YesRole);
        QAbstractButton* pButtonPassword = msgBox.addButton("更改密码", QMessageBox::NoRole);
        QAbstractButton* pButtonCancel = msgBox.addButton("取消", QMessageBox::RejectRole);
        msgBox.exec();
        int rc;
        if (msgBox.clickedButton() == pButtonNickname) {
            // 用户选择了修改昵称
            bool ok;
            QString newNickname = QInputDialog::getText(this, "更改昵称",
                                                        "输入你的新昵称：", QLineEdit::Normal,
                                                        "", &ok);
            if (ok && !newNickname.isEmpty()) {
                ui->nickname_label->setText(newNickname);
                // 上传去数据库1
                char* nidname = nowaccount;
                std::string strNewNickname = newNickname.toStdString();
                char* newNicknameCStr = (char*)strNewNickname.c_str();
                const char* sql = updateNickname(nidname, newNicknameCStr);
                qDebug() << "Executing SQL:" << sql;  // 新增部分：调试信息
                rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
                if (rc != SQLITE_OK) {
                    qDebug() << "SQL error (nickname update):" << sqlite3_errmsg(db);  // 新增部分：调试信息
                    QMessageBox::warning(this, "错误", "系统错误，无法更新新昵称");
                } else {
                    QMessageBox::information(this, "成功", "昵称更新成功");
                }
            }
            else{
                QMessageBox::warning(nullptr, "输入为空", "输入为空，未更新");
            }
        } else if (msgBox.clickedButton() == pButtonPassword) {// 用户选择了修改密码
            bool ok;
            QString newPassword = QInputDialog::getText(this, "更改密码",
                                                        "输入你的新密码：", QLineEdit::Password,
                                                        "", &ok);
            if (ok && !newPassword.isEmpty()) {
                // 上传去数据库2
                char* nidname = nowaccount;
                std::string strNewPassword = newPassword.toStdString();
                char* newPasswordCStr = (char*)strNewPassword.c_str();
                const char* sql = updatePassword(nidname, newPasswordCStr);
                qDebug() << "Executing SQL:" << sql;  // 新增部分：调试信息
                rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
                if (rc != SQLITE_OK) {
                    qDebug() << "SQL error (password update):" << sqlite3_errmsg(db);  // 新增部分：调试信息
                    QMessageBox::warning(this, "错误", "系统错误，无法更新新密码");
                } else
                {
                    Old_Password=newPassword;
                    QMessageBox::information(this, "成功", "密码更新成功");
                }

            }
            else{
                QMessageBox::warning(nullptr, "输入为空", "输入为空，未更新");
            }
        } else if (msgBox.clickedButton() == pButtonCancel) {// 用户选择了取消修改，不执行任何操作
        }
        sqlite3_close(db); // 关闭数据库连接

    }
    else{
        QMessageBox::warning(nullptr, "错误", "旧密码输入错误");
    }
}


void personal::on_password_input_textChanged()
{
}

const char * putcmd(char* cmd,char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"INSERT INTO feedback (cmd,id) VALUES('%s','%s')",cmd,id);
    return buf;
}

void personal::on_pushButton_2_clicked()
{
    std::string temp=ui->textEdit->toPlainText().toStdString();
    char * cmd=(char*)temp.c_str();
    int rc;
    if (temp.size()>0)
    {
        rc=sqlite3_exec(db,putcmd(cmd,nowaccount),NULL,NULL,NULL);
    }
    ui->textEdit->setText("");
}


void personal::on_pushButton_clicked()
{
    Dlg_Welcome *wcm = new Dlg_Welcome;
    sqlite3_close(db);
    wcm->show();
    this->hide();
}

