#ifndef LOGIN_H
#define LOGIN_H

#include "showmenu.h"
#include "ui_showmenu.h"
#include <QWidget>
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

extern QString nowname;

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    QString getHostMacAddress();

private slots:
    void on_btn_login_clicked();

    void on_btn_cancel_clicked();

    void replyfinish(QNetworkReply *);

    void on_username_textEdited(const QString &arg1);

    void on_password_textEdited(const QString &arg1);

signals:
    void sendsignal();

private:
    Ui::Login *ui;
    QNetworkAccessManager *manager;
    Showmenu sw;
};

#endif // LOGIN_H
