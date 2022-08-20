#include "threshold.h"
#include "ui_threshold.h"
#include "login.h"
#include "ui_login.h"

extern QString nowname;

Threshold::Threshold(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Threshold)
{
    ui->setupUi(this);
    setWindowTitle("Threshold");
    setAttribute(Qt::WA_StyledBackground);
    ui->tmin->setValue(18.0);
    ui->tmax->setValue(26.0);
    ui->hmax->setValue(65.0);
    ui->hmin->setValue(35.0);
    ui->amax->setValue(0.0);
    ui->amin->setValue(0.0);
}

Threshold::~Threshold()
{
    delete ui;
    delete manager;

}

void Threshold::on_btn_sub_clicked()
{
    QString name = nowname;
    qDebug() << "threshold " << name;
    if (QString::compare(name,"NULL") == 0)
    {
        qWarning() << "set failed!";
        QMessageBox::information(this,tr("set"),tr("Offline mode can't use this feature"));
        return;
    }
    QString tmax = ui->tmax->text();
    //qDebug()<< tmax;
    QString tmin = ui->tmin->text();
    QString hmax = ui->hmax->text();
    QString hmin = ui->hmin->text();
    QString amax = ui->amax->text();
    QString amin = ui->amin->text();
    /******************set mod**********************/
    // 构建 JSON 对象
    QJsonObject json;
    json.insert("name",name);
    json.insert("tmax",tmax);
    json.insert("tmin",tmin);
    json.insert("hmax",hmax);
    json.insert("hmin",hmin);
    json.insert("amax",amax);
    json.insert("amin",amin);
    // 构建 JSON 文档
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    qDebug() << byteArray;
    //连接服务器
    QUrl url("http://192.168.100.61:8080/dev/setthd");
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyfinish(QNetworkReply *)));
    manager->post(request,byteArray);
    /****************************************************/
}

void Threshold::on_btn_back_clicked()
{
    emit stsend();
    this->close();
}

void Threshold::replyfinish(QNetworkReply * reply)
{
    QString strJsonText = reply->readAll();//这个返回的JSON包所携带的所有信息
    qDebug()<<"The information returned: " <<strJsonText;
    if (QString::compare(strJsonText,"success") == 0)
    {
        qDebug() << "set success!";
        QMessageBox::information(this,tr("set"),tr("set success"));
    }
    else
    {
        qWarning() << "set failed!";
        QMessageBox::information(this,tr("set"),tr("set failed"));
    }
    reply->deleteLater();
}
