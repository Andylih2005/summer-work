#ifndef BOOKMODE_H
#define BOOKMODE_H

#include <QWidget>
#include<QPoint>
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

     //记录鼠标，窗口位置
     QPoint windowPos;
     QPoint mousePos;
     QPoint dPos;

private slots:
    void on_PersonalMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

    void on_PayMode_Button_clicked();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_btnClose_clicked();

private:
    Ui::bookmode *ui;
};

#endif // BOOKMODE_H
