#ifndef BOOK_WINDOW_H
#define BOOK_WINDOW_H

#include <QWidget>

class find_window;

namespace Ui {
class BookWindow;
}

class BookWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BookWindow(QWidget *parent = nullptr);
    ~BookWindow();
    void ChangeMode_find();

signals:
    void backToMainWindow();  // 声明返回主窗口的信号

private slots:
    void ChangeMode_persnal();  // 声明返回按钮的槽函数

private:
    Ui::BookWindow *ui;
    find_window *p_find_window;  // 声明 book_window 指针

};

#endif // BOOK_WINDOW_H
