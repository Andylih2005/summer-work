#ifndef DLG_SIGNUP_H
#define DLG_SIGNUP_H

#include <QDialog>
#include<QPoint>
namespace Ui {
class Dlg_SignUp;
}

class Dlg_SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_SignUp(QWidget *parent = nullptr);
    ~Dlg_SignUp();
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dlg_SignUp *ui;
};

#endif // DLG_SIGNUP_H
