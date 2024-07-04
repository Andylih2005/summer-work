#ifndef FIND_WINDOW_H
#define FIND_WINDOW_H

#include <QWidget>
class BookWindow;

namespace Ui {
class find_window;
}

class find_window : public QWidget
{
    Q_OBJECT

public:
    explicit find_window(QWidget *parent = nullptr);
    ~find_window();
    void ChangeMode_book();

signals:
    void backToMainWindow();  // 声明返回主窗口的信号

private slots:
    void ChangeMode_persnal();  // 声明返回按钮的槽函数

private:
    Ui::find_window *ui;
    BookWindow *book_window;  // 声明 book_window 指针

};

#endif // FIND_WINDOW_H
