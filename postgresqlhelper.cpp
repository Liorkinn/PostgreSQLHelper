#include "postgresqlhelper.h"
#include <QDebug>
#include <QSqlError>

PostgresqlHelper::PostgresqlHelper(){
}

PostgresqlHelper::~PostgresqlHelper(){

}

void PostgresqlHelper::setConnect( const QString &host,
                                   const int &port,
                                   const QString &dbName,
                                   const QString &user,
                                   const QString &password ) {

    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(host);
    m_db.setPort(port);
    m_db.setDatabaseName(dbName);
    m_db.setUserName(user);
    m_db.setPassword(password);

    openConnect();
}

void PostgresqlHelper::setConnect( const QString& host,
                                   const QString& dbName,
                                   const QString& user,
                                   const QString& password ) {

    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(host);
    m_db.setDatabaseName(dbName);
    m_db.setUserName(user);
    m_db.setPassword(password);

    openConnect();
}

void PostgresqlHelper::setConnect( const QString &host,
                                   const int &port,
                                   const QString &dbName,
                                   const QString &user ) {

    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(host);
    m_db.setPort(port);
    m_db.setDatabaseName(dbName);
    m_db.setUserName(user);

    openConnect();
}

int PostgresqlHelper::queryExec(const QString& strQuery)
{
    if(!query->exec(strQuery)) {
        qDebug() << "Ошибка запроса:" << m_db.lastError().text();
        return 1;
    }
    return 0;
}

bool PostgresqlHelper::openConnect()
{
    if(!m_db.open()){
        qDebug() << "Ошибка соединения:" << m_db.lastError().text();
        return false;
    }
    qDebug() << "Успешное подключение!";
    return true;
}

void PostgresqlHelper::closeConnect()
{
    m_db.close();

}

void PostgresqlHelper::initQuery()
{
    query = new QSqlQuery(m_db);
}

void PostgresqlHelper::unInitQuery()
{
    query->clear();
}

bool PostgresqlHelper::queryNext()
{
    bool isCheck = query->next();
    return isCheck;
}

QVariant PostgresqlHelper::value(int i) const
{
    return query->value(i);
}

QVariant PostgresqlHelper::value(const QString &name) const
{
    return query->value(name);
}
