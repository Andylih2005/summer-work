#include "user_center.h"
#include"dlg_welcome.h"
#include"dlg_signup.h"
#include"dlg_changepassword.h"
#include <QApplication>
#include"sqlite3.h"
int main(int argc, char *argv[])
{
    int rc;
    sqlite3 *db;
    QApplication a(argc, argv);
    sqlite3_open("test.db",&db);
    rc = sqlite3_exec(db, "CREATE TABLE manger(id VARCHAR(50) PRIMARY KEY,password VARCHAR(50))", NULL, NULL, NULL);
    Dlg_Welcome dlg;
    dlg.show();
    return a.exec();

}
