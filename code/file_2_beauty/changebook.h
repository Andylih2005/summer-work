#ifndef CHANGEBOOK_H
#define CHANGEBOOK_H

#include <QWidget>
#include<QPoint>
namespace Ui {
class changebook;
}

class changebook : public QWidget
{
    Q_OBJECT

public:
    explicit changebook(QWidget *parent = nullptr);
    ~changebook();
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_back_button_clicked();


    void on_change_button_clicked();

    void on_None_button_clicked();

    void on_PersonalMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

    void on_btnClose_clicked();

private:
    Ui::changebook *ui;
};

#endif // CHANGEBOOK_H
