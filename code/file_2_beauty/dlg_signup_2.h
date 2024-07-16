#ifndef DLG_SIGNUP_2_H
#define DLG_SIGNUP_2_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class dlg_signup_2;
}

class dlg_signup_2 : public QWidget
{
    Q_OBJECT

public:
    explicit dlg_signup_2(QWidget *parent = nullptr);
    ~dlg_signup_2();

private slots:
    void paintEvent(QPaintEvent *event);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dlg_signup_2 *ui;
};

#endif // DLG_SIGNUP_2_H
