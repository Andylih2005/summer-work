#ifndef DLG_WELCOME_2_H
#define DLG_WELCOME_2_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class dlg_welcome_2;
}

class dlg_welcome_2 : public QWidget
{
    Q_OBJECT

public:
    explicit dlg_welcome_2(QWidget *parent = nullptr);
    ~dlg_welcome_2();

private slots:
    void on_btnSign_clicked();
    void paintEvent(QPaintEvent *event);

    //void on_pushButton_clicked();

    //void on_btnLog_clicked();

    //void on_rdbtnAdmin_clicked(bool checked);


    void on_pushButton_2_clicked();

private:
    Ui::dlg_welcome_2 *ui;

};

#endif // DLG_WELCOME_2_H
