#ifndef PERSONAL_H
#define PERSONAL_H

#include <QWidget>
#include<QPoint>
class bookmode;
class findbook;
class paymode;

namespace Ui {
class personal;
}

class personal : public QWidget
{
    Q_OBJECT

public:
    personal(QWidget *parent = nullptr);
    ~personal();

    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:
    void on_BookMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

    void on_PayMode_Button_clicked();

    void on_Update_Button_clicked();

    void on_password_input_textChanged();

    void on_PersonalMode_Button_clicked();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_btnClose_clicked();

private:
    Ui::personal *ui;
    QString enterpassword; // 用于存储实际密码


};

#endif // PERSONAL_H
