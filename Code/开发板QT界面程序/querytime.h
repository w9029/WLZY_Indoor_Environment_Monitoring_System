#ifndef QUERYTIME_H
#define QUERYTIME_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QApplication>
#include <QCoreApplication>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QSqlError>
#include <QDateTime>

namespace Ui {
class Querytime;
}

class Querytime : public QWidget
{
    Q_OBJECT

public:
    explicit Querytime(QWidget *parent = 0);
    ~Querytime();
    void dbopen();
    void dbclose();

private slots:
    void on_btn_back_clicked();

    void on_btn_query_clicked();

signals:
    void qtsend();

private:
    Ui::Querytime *ui;
    QSqlDatabase db;
};

#endif // QUERYTIME_H
