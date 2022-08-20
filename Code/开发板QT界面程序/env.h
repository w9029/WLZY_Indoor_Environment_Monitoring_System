#ifndef ENV_H
#define ENV_H

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
#include "threshold.h"
#include "ui_threshold.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QApplication>
#include <QDebug>
#include <QNetworkInterface>
#include <QList>
#include <QNetworkRequest>
#include <QtNetwork>
#include <QNetworkReply>
#include <QSslSocket>
#include <QCryptographicHash>
#include <QByteArray>


namespace Ui {
class Env;
}

class Env : public QWidget
{
    Q_OBJECT

public:
    explicit Env(QWidget *parent = 0);
    ~Env();



signals:
    void sesignal();

private slots:
    void on_btn_back_clicked();
    //查询和显示结果
    void queryTable();

    void on_btn_th_clicked();

    void reshow();

    void replyfinish(QNetworkReply *);

private:
    Ui::Env *ui;
    QSqlDatabase db;
    Threshold td;
    QNetworkAccessManager *manager;
    double tmin;
    double tmax;
    double hmax;
    double hmin;
    double amax;
    double amin;
};

#endif // ENV_H
