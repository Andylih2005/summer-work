#include "dlg_signup_2.h"
#include "ui_dlg_signup_2.h"
#include<QDebug>
#include"sqlite3.h"
#include"dlg_welcome.h"
#include<QMessageBox>
#include<QInputDialog>
#include "dlg_welcome_2.h"
#include<QPainterPath>
#include<QPainter>
const char * insertcpp2sql2(char* id,char* password)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "INSERT INTO manger(id,password) VALUES('%s','%s')", id, password);
    return buf;
}
const char * insertreader2(char* id,char * password)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "INSERT INTO reader(id,password,nickname,credit) VALUES('%s','%s','%s',0)", id, password, id);
    return buf;
}
dlg_signup_2::dlg_signup_2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dlg_signup_2)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(1);
    ui->radioButton_2->setChecked(0);
}

void dlg_signup_2::paintEvent(QPaintEvent *event)
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
dlg_signup_2::~dlg_signup_2()
{
    delete ui;
}

void dlg_signup_2::on_pushButton_clicked()
{
    QString AccString = ui->lineEdit_2->text();
    QString PasswString = ui->lineEdit_3->text();
    QString ConfirmPasswString = ui->lineEdit_4->text();
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
            rc = sqlite3_exec(db, insertreader2(nidname, npassword), NULL, NULL, NULL);
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
                rc=sqlite3_exec(db,insertcpp2sql2(nidname,npassword),NULL,NULL,NULL);
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
void dlg_signup_2::on_pushButton_2_clicked()
{
    dlg_welcome_2 *wcm_2 = new dlg_welcome_2;
    wcm_2->show();
    this->hide();
}

