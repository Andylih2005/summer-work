#include "sqlmgr.h"
SqlMgr* SqlMgr::instance= nullptr;
SqlMgr::SqlMgr() {}

SqlMgr::~SqlMgr()
{

}

void SqlMgr::test()
{
    qDebug()<<"test";
}

bool SqlMgr::login(QString strUser, QString strPass)
{

}
