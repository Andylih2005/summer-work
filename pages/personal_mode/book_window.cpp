#include "book_window.h"
#include "ui_book_window.h"
#include "find_window.h"

BookWindow::BookWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookWindow)
{
    ui->setupUi(this);
    connect(ui->PersonalMode_Button, &QPushButton::clicked, this, &BookWindow::ChangeMode_persnal);

    connect(ui->FindBookMode_Button, &QPushButton::clicked, this, &BookWindow::ChangeMode_find);

    setFixedSize(900,600);
}

BookWindow::~BookWindow()
{
    delete ui;
}

void BookWindow::ChangeMode_persnal() {
    emit backToMainWindow();  // 发射返回主窗口的信号
}

void BookWindow::ChangeMode_find() {
    p_find_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}
