#ifndef DLG_LOGIN_H
#define DLG_LOGIN_H

#include <QDialog>

namespace Ui {
class DLG_Login;
}

class DLG_Login : public QDialog
{
    Q_OBJECT

public:
    explicit DLG_Login(QWidget *parent = nullptr);
    ~DLG_Login();

private slots:
    void on_btn_login_clicked();

    void on_btn_exit_clicked();

private:
    Ui::DLG_Login *ui;
};

#endif // DLG_LOGIN_H
