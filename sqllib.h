#ifndef POSTGRESQLHELPER_H
#define POSTGRESQLHELPER_H

#include <QSqlDatabase>
#include <QSqlQuery>
class PostgresqlHelper
{
public:
    PostgresqlHelper();
    ~PostgresqlHelper();

    QSqlDatabase m_db;
    QSqlQuery query;
    bool openConnection(const QString& host, const QString& dbName, const QString& user, const QString& password);
    QSqlQuery querySelect(const QString& strQuery);
    void queryExec();
    void queryNext();
  //  void closeConnection();

    // функции для взаимодействия с базой данных
   // bool executeQuery(const QString& query);
   // QSqlQuery select(const QString& query);


};

#endif // POSTGRESQLHELPER_H
