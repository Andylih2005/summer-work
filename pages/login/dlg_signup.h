#ifndef DLG_SIGNUP_H
#define DLG_SIGNUP_H

#include <QDialog>

namespace Ui {
class Dlg_SignUp;
}

class Dlg_SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_SignUp(QWidget *parent = nullptr);
    ~Dlg_SignUp();

private:
    Ui::Dlg_SignUp *ui;
};

#endif // DLG_SIGNUP_H
