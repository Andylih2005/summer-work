#include "personal_window.h"
#include "ui_personal_window.h"
#include "book_window.h"

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
    , book_window(new BookWindow)  // 初始化 book_window
{
    ui->setupUi(this);
    setFixedSize(900,600);

    connect(ui->BookMode_Button, &QPushButton::clicked, this, &MyWindow::ChangeMode_book);
    connect(ui->FindBookMode_Button, &QPushButton::clicked, this, &MyWindow::ChangeMode_find);
    connect(ui->PayMode_Button, &QPushButton::clicked, this, &MyWindow::ChangeMode_pay);

    connect(book_window, &BookWindow::backToMainWindow, this, &MyWindow::showMainWindow);

}

MyWindow::~MyWindow()
{
    delete ui;
    delete book_window;  // 释放 book_window

}

void MyWindow::ChangeMode_book() {
    book_window->show();  // 显示新窗口
    this->close();  // 关闭当前窗口
}

void MyWindow::ChangeMode_find() {
    book_window->show();  // 显示新窗口
    this->close();  // 关闭当前窗口
}

void MyWindow::ChangeMode_pay() {
    book_window->show();  // 显示新窗口
    this->close();  // 关闭当前窗口
}

void MyWindow::showMainWindow() {
    this->show();  // 显示主窗口
    book_window->hide();  // 隐藏 BookWindow
}
