#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
//#include "login.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QApplication>
#include <QNetworkInterface>
#include <QList>
#include <QNetworkRequest>
#include <QtNetwork>
#include <QNetworkReply>
#include <QSslSocket>
#include <QCryptographicHash>
#include <QByteArray>


namespace Ui {
class Threshold;
}

class Threshold : public QWidget
{
    Q_OBJECT

public:
    explicit Threshold(QWidget *parent = 0);
    ~Threshold();

private slots:
    void on_btn_sub_clicked();

    void on_btn_back_clicked();

    void replyfinish(QNetworkReply *);

signals:
    void stsend();

private:
    Ui::Threshold *ui;
    QNetworkAccessManager *manager;
};

#endif // THRESHOLD_H
