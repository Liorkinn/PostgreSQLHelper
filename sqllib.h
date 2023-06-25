#ifndef SQLLIB_H
#define SQLLIB_H

#include "sqllib_global.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
class SQLLIB_EXPORT Sqllib
{

public:
    Sqllib();
  //  QString print();
    QSqlDatabase db;
    int PQConnectDB(const QString& hostName, const int& port, const QString& dbName, const QString& password,const QString& userName);

private:

   // QSqlDatabase db;
//    int PQOpenConnect();
//    int PQCloseConnect();
//    int setQuery(QString strQuery);
};

#endif // SQLLIB_H
