#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personal.h"
#include "bookmode.h"
#include "findbook.h"
#include "paymode.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_BookMode_Button_clicked();

    void on_PersonalMode_Button_clicked();

    void on_PayMode_Button_clicked();

    void on_FindBookMode_Button_clicked();

private:
    Ui::MainWindow *ui;
    personal *p_personal_window;
    bookmode *p_bookmode_window;
    findbook *p_find_window;
    paymode *p_pay_window;
};
#endif // MAINWINDOW_H
