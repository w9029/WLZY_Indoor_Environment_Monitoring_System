#ifndef HISTORY_H
#define HISTORY_H

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
#include "querytime.h"
#include "ui_querytime.h"
//#include <QScrollBar>

namespace Ui {
class History;
}

class History : public QWidget
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = 0);
    ~History();
    void dbopen();
    void dbclose();
    void search(int,int);

signals:
    void sesignal();

private slots:
    void on_btn_back_clicked();

    void on_btn_si_clicked();

    void on_btn_tw_clicked();

    void on_btn_tt_clicked();

    void on_btn_qte_clicked();

    void reshow();

private:
    Ui::History *ui;
    QSqlDatabase db;
    Querytime qte;
};

#endif // HISTORY_H
