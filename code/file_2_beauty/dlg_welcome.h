#ifndef DLG_WELCOME_H
#define DLG_WELCOME_H

#include <QDialog>
#include<QPoint>
namespace Ui {
class Dlg_Welcome;
}

class Dlg_Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Welcome(QWidget *parent = nullptr);
    ~Dlg_Welcome();
    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

private slots:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_btnSign_clicked();

    void on_pushButton_clicked();

    void on_btnLog_clicked();

    void on_rdbtnAdmin_clicked(bool checked);


    void on_btnClose_clicked();

    void on_btnSign_2_clicked();

private:
    Ui::Dlg_Welcome *ui;

};

#endif // DLG_WELCOME_H
