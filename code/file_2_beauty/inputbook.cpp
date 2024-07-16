#include "inputbook.h"
#include "ui_inputbook.h"
#include "checkbook.h"
#include "usemmanagement.h"
#include"sqlite3.h"
#include <QMessageBox>
#include "user_center.h"
#include<QGraphicsDropShadowEffect>
#include<QMouseEvent>
#include<QPainterPath>
#include<QPainter>
extern sqlite3*db;

const char * getisbn2(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT * FROM book WHERE IBSN='%s'",id);
    return buf;
}

inputbook::inputbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inputbook)
{
    ui->setupUi(this);

    ui->Type_Name_chose->setCurrentIndex(0);

    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground, true);//使得窗口透明


    ui->FindBookMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->Seen_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->BookMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->PersonalMode_Button->setStyleSheet("QPushButton{text-align : left;}");

}

void inputbook::paintEvent(QPaintEvent *event)
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
void inputbook::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void inputbook ::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}


inputbook::~inputbook()
{
    delete ui;
}

void inputbook::on_BookMode_Button_clicked()
{
    checkbook *p_m_check_window=new checkbook;
    p_m_check_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void inputbook::on_FindBookMode_Button_clicked()
{
    usemmanagement *p_m_userM_window=new usemmanagement;
    p_m_userM_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}
const char * putbook(char * bookname,char * author,char * ibsn,char*press,char * type)
{
    static char buf[BUFSIZ] = { 0 };
    sqlite3_snprintf(BUFSIZ,buf,"INSERT INTO book(name,author,IBSN,press,type,number) VALUES('%s','%s','%s','%s','%s',1)",bookname,author,ibsn,press,type);
    return buf;
}

struct book
{
    QString name;
    QString author;
    QString isbn;
    QString press;
    QString type;
};

void inputbook::on_pushButton_clicked()
{
    QString BookName=ui->BOOK_INPUT->text();
    QString AutorName=ui->AUTHOR_INPUT->text();
    //QString BookName=ui->Book_Name_input->toPlainText();
    QString ISBNName=ui->isbnnn->text();
    QString PressName=ui->PRESS_INPUT->text();
    QString TypeName=ui->Type_Name_chose->currentText();
    qDebug()<<TypeName;

    std::string str1=AutorName.toStdString();
    std::string str2=BookName.toStdString();
    std::string str3=ISBNName.toStdString();
    std::string str4=PressName.toStdString();
    std::string str5=TypeName.toStdString();
    char* author,*bookname,*ibsn,*press,*type;
    author=(char*)str1.c_str();
    bookname=(char*)str2.c_str();
    ibsn=(char*)str3.c_str();
    press=(char*)str4.c_str();
    type=(char*)str5.c_str();
    if (AutorName.isEmpty() || BookName.isEmpty() || ISBNName.isEmpty() || PressName.isEmpty() || TypeName.isEmpty()){
        QMessageBox::warning(nullptr, nullptr, "Something is empty");
    }
    else{
        if (ISBNName.size()<13){
            QMessageBox::warning(nullptr,nullptr,"ISBN不足13位");
        }
        else
        {
        sqlite3_stmt* stmt;
        int rc;
        rc=sqlite3_exec(db,putbook(bookname,author,ibsn,press,type),NULL,NULL,NULL);
        qDebug()<<bookname<<author<<ibsn<<press<<type;
        if (!rc)
        {
            QMessageBox::warning(nullptr, nullptr, "添加成功");
            ui->BOOK_INPUT->clear();
            ui->AUTHOR_INPUT->clear();
            ui->PRESS_INPUT->clear();
            ui->isbnnn->clear();
            ui->Type_Name_chose->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::warning(nullptr, "Wrong", "该ISBN已有对应书籍，请检查");

        }
        }
    }
}



void inputbook::on_Seen_Button_clicked()
{
    User_Center *p_m_see_window=new User_Center;
    p_m_see_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


void inputbook::on_btnClose_clicked()
{
    this->close();
}

