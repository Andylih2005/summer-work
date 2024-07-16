#include "checkbook.h"
#include "ui_checkbook.h"
#include"sqlite3.h"
#include "inputbook.h"
#include "usemmanagement.h"
#include "changebook.h"
#include <QMessageBox>
#include "user_center.h"
#include<QGraphicsDropShadowEffect>
#include<QMouseEvent>
#include<QPainterPath>
#include<QPainter>
extern char* nowaccount;
extern sqlite3*db;
QString ISBN_E;

const char * getisbn6(char * id)
{
    static char buf[BUFSIZ]={0};
    sqlite3_snprintf(BUFSIZ,buf,"SELECT * FROM book WHERE IBSN='%s'",id);
    return buf;
}
checkbook::checkbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::checkbook)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground, true);//使得窗口透明

    ui->FindBookMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->BookMode_Button->setStyleSheet("QPushButton{text-align : left;}");
    ui->PersonalMode_Button->setStyleSheet("QPushButton{text-align : left;}");

}

void checkbook::paintEvent(QPaintEvent *event)
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

void checkbook::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void checkbook::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}


checkbook::~checkbook()
{
    delete ui;
}

void checkbook::on_PersonalMode_Button_clicked()
{
    inputbook *p_m_input_window=new inputbook;
    p_m_input_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


void checkbook::on_FindBookMode_Button_clicked()
{
    usemmanagement *p_m_userM_window=new usemmanagement;
    p_m_userM_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}











void checkbook::on_pushButton_4_clicked()
{
    usemmanagement *p_m_userM_window=new usemmanagement;
    p_m_userM_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


struct book
{
    QString name;
    QString author;
    QString isbn;
    QString press;
    QString type;
};

void checkbook::on_search_button_clicked()
{
    QString number=ui->ISBN_input->text();
    if (number.length() != 13) {
        QMessageBox::warning(this, "Wrong", "ISBN number is 13 digits");
        return;
    }
    else{
        sqlite3_stmt* stmt;
        int rc;
        std::string tmp=number.toStdString();
        char * isbn=(char*)tmp.c_str();
        const char * sql = getisbn6(isbn);
        book test;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK)
        {
            qDebug() << "准备语句失败:" << sqlite3_errmsg(db);        }
        else
        {
            rc=sqlite3_step(stmt);
            if (rc==SQLITE_ROW)
            {
                test.name=QString((char*)sqlite3_column_text(stmt, 0));
                test.author = QString((char*)sqlite3_column_text(stmt, 1));
                test.isbn = QString((char*)sqlite3_column_text(stmt, 2));
                test.press=QString((char*)sqlite3_column_text(stmt, 3));
                test.type=QString((char*)sqlite3_column_text(stmt, 4));
                ISBN_E=number;
                changebook *p_m_changebook_window=new changebook;
                p_m_changebook_window->show();  // 显示新窗口
                this->hide();
            } // 关闭当前窗口
            else
            {
                QMessageBox::warning(this, "Wrong", "No such book");
            }
        }
    }
}


void checkbook::on_Seen_Button_clicked()
{
    User_Center *p_m_see_window=new User_Center;
    p_m_see_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


void checkbook::on_btnClose_clicked()
{
    this->close();
}

