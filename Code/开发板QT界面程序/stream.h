#ifndef STREAM_H
#define STREAM_H

#include <QWidget>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Stream;
}

class Stream : public QWidget
{
    Q_OBJECT

public:
    explicit Stream(QWidget *parent = 0);
    ~Stream();
    QTimer *showTime;
    QNetworkAccessManager *manager;
    QImage *img,*scaledimg;
    QNetworkRequest request;

private slots:
    void on_btn_start_clicked();

    void on_btn_shot_clicked();

    void on_btn_quit_clicked();

    void replyFinished(QNetworkReply *);

    void flushPic();

    void on_Streamclose_clicked();

signals:
    void sesignal();

private:
    Ui::Stream *ui;
    bool btn_startisclick;
    QString pu;
    QProcess *openps,*closeps;

};

#endif // STREAM_H
