#ifndef DLG_WELCOME_H
#define DLG_WELCOME_H

#include <QDialog>

namespace Ui {
class Dlg_Welcome;
}

class Dlg_Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Welcome(QWidget *parent = nullptr);
    ~Dlg_Welcome();

private:
    Ui::Dlg_Welcome *ui;
};

#endif // DLG_WELCOME_H