#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , p_personal_window(new personal)
    , p_bookmode_window(new bookmode)
    , p_find_window(new findbook)
    , p_pay_window(new paymode)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete p_personal_window;   //在父画面关闭时全部子画面都关闭，清空new
    delete p_bookmode_window;
    delete p_find_window;
    delete p_pay_window;
}

void MainWindow::on_pushButton_clicked()
{
    p_personal_window->show();  // 显示新窗口
    this->hide();  // 关闭当前窗口
}


void MainWindow::on_BookMode_Button_clicked()
{
}

void MainWindow::on_PersonalMode_Button_clicked()
{

}

void MainWindow::on_PayMode_Button_clicked()
{

}

void MainWindow::on_FindBookMode_Button_clicked()
{

}

