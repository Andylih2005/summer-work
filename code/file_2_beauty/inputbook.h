#ifndef INPUTBOOK_H
#define INPUTBOOK_H

#include <QWidget>
#include<QPoint>
class checkbook;
class UseMmanagement;

namespace Ui {
class inputbook;
}

class inputbook : public QWidget
{
    Q_OBJECT

public:
    explicit inputbook(QWidget *parent = nullptr);
    ~inputbook();
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_BookMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

    void on_pushButton_clicked();

    void on_Seen_Button_clicked();

    void on_btnClose_clicked();

private:
    Ui::inputbook *ui;
};

#endif // INPUTBOOK_H
