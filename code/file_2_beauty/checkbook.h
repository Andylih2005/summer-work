#ifndef CHECKBOOK_H
#define CHECKBOOK_H

#include <QWidget>
#include<QPoint>
class inputbook;
class UseMmanagement;

extern QString ISBN_E;
extern char* isbnE;

namespace Ui {
class checkbook;
}

class checkbook : public QWidget
{
    Q_OBJECT

public:
    explicit checkbook(QWidget *parent = nullptr);
    ~checkbook();
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_PersonalMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

    void on_pushButton_4_clicked();

    void on_search_button_clicked();

    void on_Seen_Button_clicked();

    void on_btnClose_clicked();

private:
    Ui::checkbook *ui;
};

#endif // CHECKBOOK_H
