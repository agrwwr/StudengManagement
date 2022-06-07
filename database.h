#ifndef DATABASE_H
#define DATABASE_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include<QSql>
#include<QMessageBox>

class Database
{
public:
    Database();
    static bool getConnection();   //获取数据库连接
    static void quitConnection();   //断开数据库连接

private:
    static QSqlDatabase db;
    static QSqlQuery* sql;
};

#endif // DATABASE_H
