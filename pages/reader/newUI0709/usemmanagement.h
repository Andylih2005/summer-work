#ifndef USEMMANAGEMENT_H
#define USEMMANAGEMENT_H

#include <QWidget>

class inputbook;
class checkbook;

namespace Ui {
class usemmanagement;
}

class usemmanagement : public QWidget
{
    Q_OBJECT

public:
    explicit usemmanagement(QWidget *parent = nullptr);
    ~usemmanagement();

private slots:
    void on_PersonalMode_Button_clicked();

    void on_BookMode_Button_clicked();

    void on_reduce_button_clicked();

    void on_raise_button_clicked();

    void on_pages_textChanged();

private:
    Ui::usemmanagement *ui;
};

#endif // USEMMANAGEMENT_H
