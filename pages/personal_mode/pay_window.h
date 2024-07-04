#ifndef PAY_WINDOW_H
#define PAY_WINDOW_H

#include <QWidget>

namespace Ui {
class pay_window;
}

class pay_window : public QWidget
{
    Q_OBJECT

public:
    explicit pay_window(QWidget *parent = nullptr);
    ~pay_window();

private:
    Ui::pay_window *ui;
};

#endif // PAY_WINDOW_H
