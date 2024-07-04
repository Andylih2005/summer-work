#ifndef BOOK_WINDOW_H
#define BOOK_WINDOW_H

#include <QWidget>

namespace Ui {
class BookWindow;
}

class BookWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BookWindow(QWidget *parent = nullptr);
    ~BookWindow();

signals:
    void backToMainWindow();  // 声明返回主窗口的信号

private slots:
    void ChangeMode_persnal();  // 声明返回按钮的槽函数

private:
    Ui::BookWindow *ui;
};

#endif // BOOK_WINDOW_H
