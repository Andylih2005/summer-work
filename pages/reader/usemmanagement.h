#ifndef USEMMANAGEMENT_H
#define USEMMANAGEMENT_H

#include <QWidget>

class inputbook;
class checkbook;

namespace Ui {
class UseMmanagement;
}

class UseMmanagement : public QWidget
{
    Q_OBJECT

public:
    explicit UseMmanagement(QWidget *parent = nullptr);
    ~UseMmanagement();

private slots:
    void on_PersonalMode_Button_clicked();

    void on_BookMode_Button_clicked();

    void on_reduce_button_clicked();

    void on_raise_button_clicked();

    void on_pages_textChanged();

private:
    Ui::UseMmanagement *ui;
};

#endif // USEMMANAGEMENT_H
