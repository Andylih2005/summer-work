#include "dlg_welcome.h"
#include "ui_dlg_welcome.h"
#include"dlg_signup.h"
#include"dlg_changepassword.h"
#include"sqlite3.h"
#include<QDebug>
#include"inputbook.h"
#include"personal.h"
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>
#include<QMouseEvent>
#include "dlg_welcome_2.h"
#include<QPainterPath>
#include<QPainter>
#include<QProcess>
extern char* nowaccount;
extern sqlite3* db;
const char * findcpp2sql(char test[50])
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ, buf, "SELECT password FROM manger where id='%s'", test);
    return buf;
}
const char * findreader(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT password FROM reader where id='%s'",id);
    return buf;
}
Dlg_Welcome::Dlg_Welcome(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_Welcome)
{
    ui->setupUi(this);
    ui->LePassword->setEchoMode(QLineEdit::Password);
    ui->rdbtnUser->setChecked(1);
    ui->rdbtnAdmin->setChecked(0);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground, true);//使得窗口透明


}

void Dlg_Welcome::paintEvent(QPaintEvent *event)
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
void Dlg_Welcome::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void Dlg_Welcome ::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

Dlg_Welcome::~Dlg_Welcome()
{
    delete ui;
}

void Dlg_Welcome::on_btnSign_clicked()
{
   Dlg_SignUp  *sgu = new Dlg_SignUp;
    sgu->show();
    hide();
}

//忘记密码
void Dlg_Welcome::on_pushButton_clicked()
{
    Dlg_ChangePassword *cpw = new Dlg_ChangePassword;
    cpw->show();
    hide();
}


void Dlg_Welcome::on_btnLog_clicked()
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
        const char * sql = findcpp2sql(idname);
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
                QMessageBox::warning(nullptr, "wrong", "Wrong Password");
            }
        }
        else
        {
            QMessageBox::warning(nullptr, "wrong", "Wrong Account");
            qDebug()<< "id wrong";
        }
    }
        else if (ui->rdbtnUser->isChecked())
    {
        const char * sql = findreader(idname);
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
                QMessageBox::warning(nullptr, "wrong", "Wrong Password");
            }
        }
        else
        {
            qDebug()<< "id wrong";
            QMessageBox::warning(nullptr, "wrong", "Wrong Account");
        }
    }
}





void Dlg_Welcome::on_rdbtnAdmin_clicked(bool checked)
{
    if (ui->rdbtnAdmin && checked) {
        ui->rdbtnUser->setChecked(!checked);
    } else if (ui->rdbtnUser && checked) {
        ui->rdbtnAdmin->setChecked(!checked);
    }
}




void Dlg_Welcome::on_btnClose_clicked()
{
    this->close();
}


void Dlg_Welcome::on_btnSign_2_clicked()
{
    QString program = "BookManagementSystem";

    // 启动外部程序并使其脱离当前进程
    QProcess::startDetached(program);

    // 退出当前应用程序
    qApp->quit();
}

