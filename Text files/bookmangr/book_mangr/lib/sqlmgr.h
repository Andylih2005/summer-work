#ifndef SQLMGR_H
#define SQLMGR_H

#include<QtDebug>
class SqlMgr
{
public:
    SqlMgr();
    ~SqlMgr();

    static SqlMgr*instance;//单例模式

    static SqlMgr* get_instance();
    void test();
    bool login(QString strUser,QString strPass);//login

    QVector<QStringList>getUser(QString strConditiion="");//reader infor
    void AddUser(QVector<QStringList>);//create reader account
    void delUSer(QString strId);//del reader account
    QVector<QStringList>getBooks(QString strCondition="");
    //get book
    void AddBooks(QVector<QStringList>);
    //add book
    void UdapteBooks(QVector<QStringList>);
    //changebook
    void delbook (QStringList);
    //delbook
    void AddBooks(QString strId);
    //return book
    void returnbook(QString strUserId,QString strBookid);
    //borrrow
    void borrowbook(QString strUserId,QString strBookid);
    //borrow record
    QVector<QStringList> getRecord(QString strCondition="");
    //del record
    QString clearRecord();
private:
};

#endif // SQLMGR_H
