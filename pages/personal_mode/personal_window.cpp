#include "personal_window.h"
#include "ui_personal_window.h"
#include "book_window.h"
#include "find_window.h"

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
    , book_window(new BookWindow)  // 初始化 book_window
    , p_find_window(new find_window)

{
    ui->setupUi(this);
    setFixedSize(900,600);

    connect(ui->BookMode_Button, &QPushButton::clicked, this, &MyWindow::ChangeMode_book);
    connect(ui->FindBookMode_Button, &QPushButton::clicked, this, &MyWindow::ChangeMode_find);
    connect(ui->PayMode_Button, &QPushButton::clicked, this, &MyWindow::ChangeMode_pay);

    connect(book_window, &BookWindow::backToMainWindow, this, &MyWindow::showPersonalWindow);
    connect(p_find_window, &find_window::backToMainWindow, this, &MyWindow::showPersonalWindow);

}

MyWindow::~MyWindow()
{
    delete ui;
    delete book_window;  // 释放 book_window
    delete p_find_window;  // 释放 book_window

}

void MyWindow::ChangeMode_book() {
    book_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void MyWindow::ChangeMode_find() {
    p_find_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void MyWindow::ChangeMode_pay() {
    book_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}

void MyWindow::showPersonalWindow() {
    this->show();  // 显示主窗口
    book_window->hide();  // 隐藏 BookWindow
    p_find_window->hide();
}
