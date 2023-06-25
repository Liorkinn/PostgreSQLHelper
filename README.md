# PostgreSQLHelper
Динамическая библиотека взаимодействия с БД PostgreSQL.

### Функции подключения.
Для подключения и открытие/закрытие соединения к базе данных используется следующие функции:
- setConnect( const QString &host, const int &port, const QString &dbName, const QString &user, const QString &password ) 
- setConnect( const QString &host, const QString &dbName, const QString &user, const QString &password )
- setConnect( const QString &host, const int &port, const QString &dbName, const QString &user )
- openConnect()
- closeConnect()
Пример: helper.setConnect("localhost", 5432, "postgres", "postgres");

### Функции запросов.
Для работы с запросами используются следующие функции:
- queryExec(const QString& strQuery)
- initQuery() - используется для инициализации QSqlQuery и присвоения подключенной БД.
- unInitQuery() - используется для удаления инициализации QSqlQuery.
- queryNext() - используется цикличного получения данных выполненного запроса.
- value(int i) const - используется для получения данных выполненного запроса.
- value(const QString &name) const - используется для получения данных выполненного запроса.

Пример выполнения запроса:<br>
helper.setConnect("localhost", 5432, "postgres", "postgres");<br>
helper.initQuery();<br>
helper.queryExec("SELECT 1");<br>
