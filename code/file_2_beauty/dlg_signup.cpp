#include "dlg_signup.h"
#include "ui_dlg_signup.h"
#include<QDebug>
#include"sqlite3.h"
#include"dlg_welcome.h"
#include<QMessageBox>
#include<QInputDialog>
#include<QGraphicsDropShadowEffect>
#include<QMouseEvent>
#include<QPainterPath>
#include<QPainter>
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

}


void Dlg_SignUp::paintEvent(QPaintEvent *event)
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


Dlg_SignUp::~Dlg_SignUp()
{
    delete ui;
}

void Dlg_SignUp::on_pushButton_clicked()
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
    bool scuess=false;
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
            scuess=true;
            }
        else if (ui->radioButton_2->isChecked())
        {//管理员选项
            qDebug()<<"管理员";
            QString text = QInputDialog::getText(this, tr("成为管理员"),tr("输入您的邀请码："));
            qDebug()<<text;
            if(text!="114514")
            {
                QMessageBox::StandardButton reply03;
                reply03 = QMessageBox::information(this,tr("成为管理员"),"邀请码错误<br>""请再次确认邀请码");
            }
            else
            {
                rc=sqlite3_exec(db,insertcpp2sql(nidname,npassword),NULL,NULL,NULL);
                scuess=true;
            }
        }
            if(scuess)
        {
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

