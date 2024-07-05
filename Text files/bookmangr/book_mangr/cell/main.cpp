#include "cell_main.h"

#include <QApplication>
#include "dlg_login.h"
#include "lib/sqlmgr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DLG_Login dlg;
    int ret=dlg.exec();

    if(1==ret)
    {
        Cell_Main w;
        w.show();
            return a.exec();
    }
    if(0==ret)
    {
        exit(0);
        return 0;
    }
    return 0;
}
