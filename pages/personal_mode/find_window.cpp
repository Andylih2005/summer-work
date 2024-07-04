#include "find_window.h"
#include "ui_find_window.h"
#include "book_window.h"


find_window::find_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::find_window)
    , book_window(new BookWindow)
{
    ui->setupUi(this);
    connect(ui->PersonalMode_Button, &QPushButton::clicked, this, &find_window::ChangeMode_persnal);

    connect(ui->BookMode_Button, &QPushButton::clicked, this, &find_window::ChangeMode_book);
    setFixedSize(900,600);

}

find_window::~find_window()
{
    delete ui;
}

void find_window::ChangeMode_book() {
    book_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void find_window::ChangeMode_persnal() {
    emit backToMainWindow();  // 发射返回主窗口的信号
}
