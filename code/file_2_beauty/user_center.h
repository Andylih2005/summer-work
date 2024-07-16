#ifndef USER_CENTER_H
#define USER_CENTER_H

#include <QWidget>
#include<QPoint>
QT_BEGIN_NAMESPACE
namespace Ui {
class User_Center;
}
QT_END_NAMESPACE

class User_Center : public QWidget
{
    Q_OBJECT

public:
    User_Center(QWidget *parent = nullptr);
    ~User_Center();
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_raise_button_clicked();

    void on_reduce_button_clicked();
    void showpages(int pagenumber);
    void gettttt();

    void on_pages_textChanged(const QString &arg1);

    void on_delete_2_clicked();
    void on_BookMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

    void on_PersonalMode_Button_clicked();

    void on_btnClose_clicked();

private:
    Ui::User_Center *ui;
};
#endif // USER_CENTER_H
