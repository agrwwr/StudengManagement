#include "database.h"

QSqlDatabase Database::db = QSqlDatabase::addDatabase("QMYSQL");
QSqlQuery* Database::sql = NULL;


Database::Database()
{
    qDebug()<< "数据库实例已创建";
}

bool Database::getConnection()
{
    db.setHostName("localhost");
    db.setDatabaseName("cplusplus");
    db.setUserName("root");
    db.setPort(3306);
    db.setPassword("hxh123..");
    if(!db.open())
    {
        qDebug()<<"Database Error";
        qDebug()<<db.lastError().text();
        return false;
    }
    else
    {
        qDebug()<<"connect successfully";
        return true;
    }
}

void Database::quitConnection()
{
    db.close();
}
