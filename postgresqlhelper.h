#ifndef POSTGRESQLHELPER_H
#define POSTGRESQLHELPER_H

#include <QSqlDatabase>
#include <QSqlQuery>
class PostgresqlHelper
{
public:
    PostgresqlHelper();
    ~PostgresqlHelper();

    //connection setup to database
    void setConnect( const QString& host,
                     const int& port,
                     const QString& dbName,
                     const QString& user,
                     const QString& password );

    void setConnect( const QString& host,
                     const QString& dbName,
                     const QString& user,
                     const QString& password );

    void setConnect( const QString& host,
                     const int& port,
                     const QString& dbName,
                     const QString& user );

    //open and close connection
    bool openConnect();
    void closeConnect();

    //query functions
    int queryExec(const QString& strQuery); //query execute
    void initQuery();                       //initialisation query
    void unInitQuery();                     //uninittialisation query
    bool queryNext();                       //cyclic data acquisition

    QVariant value(int i) const;
    QVariant value(const QString& name) const;

private:
    QSqlDatabase m_db;
    QSqlQuery *query;


};

#endif // POSTGRESQLHELPER_H
