#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include "book_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWindow;
}
QT_END_NAMESPACE

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();
    void ChangeMode_book();
    void ChangeMode_pay();
    void ChangeMode_find();
    void showMainWindow();  // 添加显示主窗口的函数


private:
    Ui::MyWindow *ui;
    BookWindow *book_window;  // 声明 book_window 指针

};
#endif // MYWINDOW_H
