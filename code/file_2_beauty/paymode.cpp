#include "paymode.h"
#include "ui_paymode.h"
#include "bookmode.h"
#include "findbook.h"
#include "personal.h"
#include"sqlite3.h"
#include<QGraphicsDropShadowEffect>
#include<QMouseEvent>
#include<QPainterPath>
#include<QPainter>
extern char* nowaccount;
extern sqlite3* db;
paymode::paymode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::paymode)
{
    ui->setupUi(this);
    judge();

    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground, true);//使得窗口透明


    ui->FindBookMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->PayMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->BookMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->PersonalMode_Button->setStyleSheet("QPushButton{text-align : left;}");

}
void paymode::paintEvent(QPaintEvent *event)
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
const char * getcreadit1(char * account)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT credit FROM reader WHERE id='%s'",account);
    return buf;
}
void paymode::judge(){
    //拉取reader数据库
    sqlite3_stmt* stmt;
    const char * sql;
    int rc;
    sql=getcreadit1(nowaccount);
    rc=sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
    rc=sqlite3_step(stmt);
    int credit=sqlite3_column_int(stmt,0);
    if(credit>0)
    {
        ui->Label_1->setText("书籍逾期未还，应缴纳");
        QString str=QString::number(credit);
        ui->Label_money->setText(str);
        ui->Label_2->setText("元");
    }
    else
    {
        ui->Label_1->setText("没有罚款");
        ui->Label_money->setText("");
        ui->Label_2->setText("");
    }
}

void paymode::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void paymode::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}


paymode::~paymode()
{
    delete ui;
}

//页面跳转按钮
void paymode::on_PersonalMode_Button_clicked()
{
    personal *p_personal_window=new personal;
    p_personal_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void paymode::on_BookMode_Button_clicked()
{
    bookmode *p_book_window = new bookmode;
    p_book_window->show();
    this->hide();
}

void paymode::on_FindBookMode_Button_clicked()
{
    findbook *p_find_window = new findbook;
    p_find_window->show();
    this->hide();
}


void paymode::on_btnClose_clicked()
{
    this->close();
}

