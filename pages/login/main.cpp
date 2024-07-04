#include "user_center.h"
#include"dlg_welcome.h"
#include"dlg_signup.h"
#include"dlg_changepassword.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dlg_Welcome dlg;
    dlg.show();
    return a.exec();

}
