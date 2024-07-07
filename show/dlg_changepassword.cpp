#include "dlg_changepassword.h"
#include "ui_dlg_changepassword.h"
#include"dlg_welcome.h"
#include <QMessageBox>
#include <sqlite3.h>
#include <QDebug>

extern char* nowaccount;
const char * findreader3(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT password FROM reader where id='%s'",id);
    return buf;
}
const char* updatePassword2(char* id, char* newPassword)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "UPDATE reader SET password='%s' WHERE id='%s'", newPassword, id);
    return buf;
}

Dlg_ChangePassword::Dlg_ChangePassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_ChangePassword)
{
    ui->setupUi(this);

}

Dlg_ChangePassword::~Dlg_ChangePassword()
{
    delete ui;
}
/*
void Dlg_ChangePassword::on_pushButton_clicked()
{
    Dlg_Welcome *wcm = new Dlg_Welcome;
    wcm->show();
    hide();
}
*/

void Dlg_ChangePassword::on_password_input_1_textChanged(const QString &arg1)
{/*
    QString currentText = ui->password_input_1->text();
    if (currentText.length() > enterpassword.length()) {
        QChar newChar = currentText.right(1).at(0);
        enterpassword.append(newChar);
        ui->password_input_1->blockSignals(true);
        ui->password_input_1->setPlainText(QString('*').repeated(enterpassword.length()));
        ui->password_input_1->blockSignals(false);
        QTextCursor cursor = ui->password_input_1->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->password_input_1->setTextCursor(cursor);
    } else if (currentText.length() < password_input_1.length()) {
        enterpassword.chop(1);
    }
*/
}




void Dlg_ChangePassword::on_enter_button_clicked()
{
    QString nickname = ui->nickname_input->text();
    QString account = ui->account_input->text();
    QString newPassword = ui->password_input_1->text();
    QString confirmPassword = ui->password_input_2->text();

    // 检查新密码和确认新密码是否一致
    if (newPassword != confirmPassword) {
        QMessageBox::warning(this, "错误", "新密码和确认密码不一致。");
        return;
    }

    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc = sqlite3_open("data.db", &db);
    if (rc) {
        qDebug() << "无法打开数据库:" << sqlite3_errmsg(db);
        return;
    }
    std::string acc_str=account.toStdString();
    char* acc_c=(char*)acc_str.c_str();
    nowaccount = (char*)acc_str.c_str();
    const char * sql = findreader3(acc_c);
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW){

        char* nidname = nowaccount;
        std::string strNewPassword = newPassword.toStdString();
        char* newPasswordCStr = (char*)strNewPassword.c_str();

        const char* sql = updatePassword2(nidname, newPasswordCStr);
        qDebug() << "Executing SQL:" << sql;  // 新增部分：调试信息
        rc = sqlite3_exec(db, sql, NULL, NULL, NULL);

        if (rc != SQLITE_DONE) {
            qDebug() << "执行更新语句失败:" << sqlite3_errmsg(db);
        } else {
            sqlite3_close(db);

            QMessageBox::information(this, "成功", "密码修改成功。");
        }
    }
    else{
        qDebug()<< "id wrong";
        sqlite3_close(db);

        QMessageBox::warning(nullptr, "wrong", "Wrong Account");
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    Dlg_Welcome *wcm = new Dlg_Welcome;
    wcm->show();
    hide();
}

