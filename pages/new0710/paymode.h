#ifndef PAYMODE_H
#define PAYMODE_H

#include <QWidget>
#include<QPoint>
class bookmode;
class personal;
class findbook;

namespace Ui {
class paymode;
}

class paymode : public QWidget
{
    Q_OBJECT

public:
    explicit paymode(QWidget *parent = nullptr);
    ~paymode();

    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:
    void on_PersonalMode_Button_clicked();

    void on_BookMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_btnClose_clicked();

private:
    Ui::paymode *ui;
};

#endif // PAYMODE_H
