#ifndef FINDBOOK_H
#define FINDBOOK_H

#include <QWidget>
#include<QPoint>
class bookmode;
class personal;
class paymode;

namespace Ui {
class findbook;
}

class findbook : public QWidget
{
    Q_OBJECT

public:
    explicit findbook(QWidget *parent = nullptr);
    ~findbook();

    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;


private slots:
    void on_PersonalMode_Button_clicked();

    void on_BookMode_Button_clicked();

    void on_PayMode_Button_clicked();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);


private:
    Ui::findbook *ui;
};

#endif // FINDBOOK_H
