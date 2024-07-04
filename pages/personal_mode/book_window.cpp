#include "book_window.h"
#include "ui_book_window.h"

BookWindow::BookWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookWindow)
{
    ui->setupUi(this);
    connect(ui->PersonalMode_Button, &QPushButton::clicked, this, &BookWindow::ChangeMode_persnal);
    setFixedSize(900,600);
}

BookWindow::~BookWindow()
{
    delete ui;
}

void BookWindow::ChangeMode_persnal() {
    emit backToMainWindow();  // 发射返回主窗口的信号
}
