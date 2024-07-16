#include "dlg_welcome_2.h"
#include "ui_dlg_welcome_2.h"
#include"dlg_welcome.h"
#include "dlg_welcome_2.h"
#include"dlg_signup_2.h"
/*
 * #include"dlg_changepassword.h"
#include"inputbook.h"
#include"personal.h"*/
#include"sqlite3.h"
#include<QDebug>
#include<QWidget>
#include<QMessageBox>
#include<QPainterPath>
#include<QPainter>
extern char* nowaccount;
extern sqlite3* db;
const char * findcpp2sql2(char test[50])
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "SELECT password FROM manger where id='%s'", test);
    return buf;
}
const char * findreader2(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT password FROM reader where id='%s'",id);
    return buf;
}

dlg_welcome_2::dlg_welcome_2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dlg_welcome_2)
{
    ui->setupUi(this);
    setFixedSize(800,400);
    ui->LePassword->setEchoMode(QLineEdit::Password);
    ui->rdbtnUser->setChecked(1);
    ui->rdbtnAdmin->setChecked(0);
}
void dlg_welcome_2::paintEvent(QPaintEvent *event)
{
    // 调用基类的paintEvent（如果需要的话，但在这个例子中我们不需要）
    // QWidget::paintEvent(event);

    // 自定义绘图逻辑
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QColor color(56,42,64, 50); // 初始颜色，带有一定透明度
    for (int i = 0; i < 10; ++i) {
        // 注意：这里的透明度计算方式可能需要调整以避免负值
        // 这里我们简单地使用固定的透明度
        // color.setAlpha(150 - qSqrt(i) * 50); // 这可能导致透明度为负
        color.setAlpha(50 - i * 5); // 使用更安全的递减方式

        // 绘制一个稍微偏移和缩小的矩形来模拟阴影效果
        painter.setPen(Qt::NoPen); // 不绘制边框
        painter.setBrush(color);
        painter.drawRect(21-i, 21-i, this->width() - 2 * (21 - i), this->height() - 2 * (21 - i));
    }
}
dlg_welcome_2::~dlg_welcome_2()
{
    delete ui;
}


void dlg_welcome_2::on_btnSign_clicked()
{
    dlg_signup_2  *sgu_2 = new dlg_signup_2;
    sgu_2->show();
    hide();
}

/*
//忘记密码
void dlg_welcome_2::on_pushButton_clicked()
{
    Dlg_ChangePassword *cpw = new Dlg_ChangePassword;
    cpw->show();
    hide();
}


void dlg_welcome_2::on_btnLog_clicked()
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
        const char * sql = findcpp2sql2(idname);
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
                QMessageBox::warning(nullptr, "错误", "密码错误");
            }
        }
        else
        {
            QMessageBox::warning(nullptr, "错误", "账号错误");
            qDebug()<< "id wrong";
        }
    }
    else if (ui->rdbtnUser->isChecked())
    {
        const char * sql = findreader2(idname);
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
                QMessageBox::warning(nullptr, "错误", "密码错误");
            }
        }
        else
        {
            qDebug()<< "id wrong";
            QMessageBox::warning(nullptr, "错误", "账号错误");
        }
    }
}





void dlg_welcome_2::on_rdbtnAdmin_clicked(bool checked)
{
    if (ui->rdbtnAdmin && checked) {
        ui->rdbtnUser->setChecked(!checked);
    } else if (ui->rdbtnUser && checked) {
        ui->rdbtnAdmin->setChecked(!checked);
    }
}

*/


void dlg_welcome_2::on_pushButton_2_clicked()
{
    Dlg_Welcome *wcm = new Dlg_Welcome;
    wcm->show();
    hide();
}

