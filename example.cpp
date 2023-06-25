#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/postgresqlhelper.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PostgresqlHelper helper;
    helper.openConnection("localhost", "abi", "postgres", "lostdox1");

    QSqlQuery q = helper.querySelect("SELECT * FROM _abi.ask");
    while(q.next()) {
        qDebug() << q.value(0).toString();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

