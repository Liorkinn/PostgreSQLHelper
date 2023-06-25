#include "sqllib.h"

Sqllib::Sqllib()
{
}

//QString Sqllib::print()
//{
//    return "Hello!";
//}

int Sqllib::PQConnectDB(const QString &hostName, const int &port, const QString &dbName, const QString &password, const QString &userName)
{
    qDebug() << "fsfaf";
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(hostName);
    db.setPort(port);
    db.setDatabaseName(dbName);
    db.setPassword(password);
    db.setUserName(userName);

    if(!db.open()) {
        qDebug() << "Database is not open!";
        return 1;
    }
    qDebug() << "Database is open!";
    return 0;
}

//int Sqllib::PQOpenConnect()
//{
//    if(!db.open()){
//        qDebug() << "Database is not open!";
//        return 1;
//    }
//    return 0;
//}

//int Sqllib::PQCloseConnect()
//{
//    db.close();
//    return 0;
//}

//int Sqllib::setQuery(QString strQuery)
//{
//    query = new QSqlQuery(db);

//    if(!query->exec(strQuery)){
//        qDebug() << "Query is not exec!";
//        return 1;
//    }
//    return 0;
//}
