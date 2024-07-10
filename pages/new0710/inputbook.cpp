#include "inputbook.h"
#include "ui_inputbook.h"
#include "checkbook.h"
#include "usemmanagement.h"
#include"sqlite3.h"
#include <QMessageBox>

extern sqlite3*db;
inputbook::inputbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::inputbook)
{
    ui->setupUi(this);

    ui->Type_Name_chose->setCurrentIndex(0);

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

void inputbook::on_pushButton_clicked()
{
    QString AutorName=ui->Author_Name_input->toPlainText();
    QString BookName=ui->Book_Name_input->toPlainText();
    QString ISBNName=ui->ISBN_Name_input->toPlainText();
    QString PressName=ui->Press_Name_input->toPlainText();
    QString TypeName=ui->Type_Name_chose->currentText();
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
        int rc;
        rc=sqlite3_exec(db,putbook(bookname,author,ibsn,press,type),NULL,NULL,NULL);
        qDebug()<<bookname<<author<<ibsn<<press<<type;
        QMessageBox::warning(nullptr, nullptr, "添加成功");
        ui->Author_Name_input->setText("");
        ui->Book_Name_input->setText("");
        ui->ISBN_Name_input->setText("");
        ui->Press_Name_input->setText("");
        ui->Type_Name_chose->setCurrentIndex(0);
    }
}

