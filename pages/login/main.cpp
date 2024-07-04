#include "user_center.h"
#include"dlg_welcome.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dlg_Welcome dlg;
    dlg.exec();
    User_Center w;
    w.show();
    return a.exec();
}
