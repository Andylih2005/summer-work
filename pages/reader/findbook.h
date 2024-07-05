#ifndef FINDBOOK_H
#define FINDBOOK_H

#include <QWidget>

class bookmode;
class personal;
class paymode;

namespace Ui {
class findbook;
}

class findbook : public QWidget
{
    Q_OBJECT

public:
    explicit findbook(QWidget *parent = nullptr);
    ~findbook();

private slots:
    void on_PersonalMode_Button_clicked();

    void on_BookMode_Button_clicked();

    void on_PayMode_Button_clicked();

    void on_reduce_button_clicked();

private:
    Ui::findbook *ui;
};

#endif // FINDBOOK_H
