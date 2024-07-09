#ifndef BOOKMODE_H
#define BOOKMODE_H

#include <QWidget>

class personal;
class findbook;
class paymode;

namespace Ui {
class bookmode;
}

class bookmode : public QWidget
{
    Q_OBJECT

public:
     bookmode(QWidget *parent = nullptr);
    ~bookmode();

private slots:
    void on_PersonalMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

    void on_PayMode_Button_clicked();

private:
    Ui::bookmode *ui;
};

#endif // BOOKMODE_H
