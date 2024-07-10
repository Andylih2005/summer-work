#include "bookmode.h"
#include "ui_bookmode.h"
#include "personal.h"
#include "findbook.h"
#include "paymode.h"
#include<QGraphicsDropShadowEffect>
#include<QMouseEvent>
extern char* nowaccount;
bookmode::bookmode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bookmode)
{
    ui->setupUi(this);
    qDebug()<<nowaccount;

    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground, true);//使得窗口透明
    //QWidget *pW = new QWidget(this);
    //pW->setGeometry(10,10,this->width() -20,this->height()-20);
    //pW->setStyleSheet("QWidget{background-color:rgb(0,0,0);border-radius:5px;}");
    QGraphicsDropShadowEffect *pShadow = new QGraphicsDropShadowEffect(this);
    pShadow->setOffset(0,0); //阴影偏移位置
    pShadow->setColor(qRgb(56,42,64)); //阴影的颜色
    pShadow->setBlurRadius(20);//阴影的范围
    this->setGraphicsEffect(pShadow);

    ui->FindBookMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->PayMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->BookMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->PersonalMode_Button->setStyleSheet("QPushButton{text-align : left;}");

}

bookmode::~bookmode()
{
    delete ui;
}

void bookmode::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void bookmode ::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
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


void bookmode::on_btnClose_clicked()
{
    this->close();
}

