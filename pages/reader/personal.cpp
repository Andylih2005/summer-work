#include "personal.h"
#include "ui_personal.h"

#include "bookmode.h"
#include "findbook.h"
#include "paymode.h"

#include <QInputDialog>
#include <QLineEdit>
#include <QString>
#include <QMessageBox>

personal::personal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::personal)
    ,enterpassword("")

{
    ui->setupUi(this);
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
    static QString nickname_change;
    nickname_change=ui->NickName_input->toPlainText();//nickname输入框输入
    static QString password_change;
    password_change=ui->password_input->toPlainText();//password输入框输入
    if (nickname_change != "" && password_change != ""){
        bool ok;
        QString old_password_input = QInputDialog::getText(nullptr, "Password Input",
                                                 "Enter your password:", QLineEdit::Password,
                                                 "", &ok);
        if (ok && !old_password_input.isEmpty()) {
            QString Old_Nickname="nickname";
            QString Old_Password="password";
            if (Old_Password==old_password_input){//插入判断输入密码和原密码是否相等的判断
                QString new_password_double = QInputDialog::getText(nullptr, "Double check",
                                                                   "Enter your new password again:", QLineEdit::Password,
                                                                   "", &ok);
                if (new_password_double==password_change){
                    Old_Nickname=nickname_change;//更改数据库
                    Old_Password=password_change;
                    QMessageBox::information(nullptr, "Change", "Change Success");
                    //外部两个文本框显示新的
                }
                else {
                    QMessageBox::information(nullptr, "Change", "Change Failed, the new passwords you entered twice are different");
                    //外部两个文本框重新用数据库旧nickname/密码覆盖
                }
            }
            else{
                QMessageBox::warning(nullptr, "Change", "Wrong Password");
                //外部两个文本框重新用数据库旧nickname/密码覆盖
            }
        } else {
            QMessageBox::warning(nullptr, "No Password Entered", "No password was entered.");
            //外部两个文本框重新用数据库覆盖

        }
    }
}


void personal::on_password_input_textChanged()
{
    QString currentText = ui->password_input->toPlainText();
    if (currentText.length() > enterpassword.length()) {
        QChar newChar = currentText.right(1).at(0);
        enterpassword.append(newChar);
        ui->password_input->blockSignals(true);
        ui->password_input->setPlainText(QString('*').repeated(enterpassword.length()));
        ui->password_input->blockSignals(false);
        QTextCursor cursor = ui->password_input->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->password_input->setTextCursor(cursor);
    } else if (currentText.length() < enterpassword.length()) {
        enterpassword.chop(1);
    }
}
