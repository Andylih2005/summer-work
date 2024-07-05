#ifndef CHECKBOOK_H
#define CHECKBOOK_H

#include <QWidget>

class inputbook;
class UseMmanagement;

namespace Ui {
class checkbook;
}

class checkbook : public QWidget
{
    Q_OBJECT

public:
    explicit checkbook(QWidget *parent = nullptr);
    ~checkbook();

private slots:
    void on_PersonalMode_Button_clicked();

    void on_FindBookMode_Button_clicked();


    void on_reduce_button_clicked();

    void on_raise_button_clicked();

    void on_pages_textChanged();

private:
    Ui::checkbook *ui;
};

#endif // CHECKBOOK_H
