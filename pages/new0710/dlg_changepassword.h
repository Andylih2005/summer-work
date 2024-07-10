#ifndef DLG_CHANGEPASSWORD_H
#define DLG_CHANGEPASSWORD_H

#include <QDialog>
#include<QPoint>
namespace Ui {
class Dlg_ChangePassword;
}

class Dlg_ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_ChangePassword(QWidget *parent = nullptr);
    ~Dlg_ChangePassword();

    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:

    void on_password_input_1_textChanged(const QString &arg1);

    void on_enter_button_clicked();

    void on_pushButton_2_clicked();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
private:
    Ui::Dlg_ChangePassword *ui;
};

#endif // DLG_CHANGEPASSWORD_H
