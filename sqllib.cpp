#include "postgresqlhelper.h"
#include <QDebug>
#include <QSqlError>

PostgresqlHelper::PostgresqlHelper(){
}

PostgresqlHelper::~PostgresqlHelper(){
    //closeConnection();
}

bool PostgresqlHelper::openConnection(const QString& host, const QString& dbName, const QString& user, const QString& password){
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(host);
    m_db.setDatabaseName(dbName);
    m_db.setUserName(user);
    m_db.setPassword(password);

    if(!m_db.open()){
        qDebug() << "Connection error:" << m_db.lastError().text();
        return false;
    }
    qDebug() << "Connection success!";
    return true;
}

QSqlQuery PostgresqlHelper::querySelect(const QString& strQuery)
{
    query = QSqlQuery(m_db);
    if(query.exec(strQuery)) {
        qDebug() << "Query error!";
    }
    return query;
}

void PostgresqlHelper::queryExec()
{
    query.exec();
}

void PostgresqlHelper::queryNext()
{
    query.next();
}

//void PostgresqlHelper::closeConnection(){
//    m_db.close();
//}

//bool PostgresqlHelper::executeQuery(const QString& query){
//    QSqlQuery q(m_db);
//    if(!q.prepare(query)){
//        qDebug() << "Prepare error:" << q.lastError().text() << q.lastQuery();
//        return false;
//    }
//    if(!q.exec()){
//        qDebug() << "Execute error:" << q.lastError().text() << q.lastQuery();
//        return false;
//    }
//    return true;
//}

//QSqlQuery PostgresqlHelper::select(const QString& query){
//    QSqlQuery q(m_db);
//    if(!q.exec(query)){
//        qDebug() << "Query error:" << q.lastError().text() << q.lastQuery();
//    }
//    return q;
//}
