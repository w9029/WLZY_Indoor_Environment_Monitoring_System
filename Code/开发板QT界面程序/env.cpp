#include "env.h"
#include "ui_env.h"
#include "login.h"
#include "ui_login.h"

extern QString nowname;

Env::Env(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Env)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_DeleteOnClose,0);
    setWindowTitle("Environment");
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("/workspace/AirDataBase/AirData.db");

    }
    if (!db.open())
    {
        qDebug() << "can not open db" << endl;
        return;
    }
    else
    {
        qDebug() << "can open db" << endl;
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(queryTable())); // queryTable()是我们需要执行的响应函数
    timer->start(500); // 每隔0.5s
    tmin = 18.0;
    tmax = 26.0;
    hmin = 30.0;
    hmax = 65.0;
    amin = 0.0;
    amax = 0.3;
    /********************************************/
    QString name = nowname;
    qDebug() << name;
    /******************set mod**********************/
    // 构建 JSON 对象
    QJsonObject json;
    json.insert("name",name);
    // 构建 JSON 文档
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    qDebug() << byteArray;
    //连接服务器
    QUrl url("http://192.168.100.61:8080/dev/getthd");
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyfinish(QNetworkReply *)));
    manager->post(request,byteArray);
    /****************************************************/
}

Env::~Env()
{
    delete ui;
    delete this;
    delete manager;
    db.close();

}

void Env::on_btn_back_clicked()
{
    emit sesignal();
    this->close();
}

//查询和显示结果
void Env::queryTable()
{
    QDateTime mytime = QDateTime::currentDateTime();
    QLocale locale = QLocale::English;//指定英文显示
    QString strFormat = "yyyy.MM.dd hh:mm:ss ap";//指定显示时间的格式
    QString strDateTime = locale.toString(mytime, strFormat);
    ui->lcd_time->display(strDateTime);
    QSqlQuery query(db);
    //构建创建数据库的sql语句字符串
    query.prepare("SELECT * FROM Data WHERE time = (SELECT MAX(time) FROM Data)");
    //query.prepare("SELECT * FROM Data");
    //执行sql语句
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    if(query.next())
    {
        //QString de =  query.value(0).toString();
        //将float类型转化为非科学计数法('f')且保留1位小数
        if (query.value(1).toDouble() < tmin || query.value(1).toDouble() > tmax)
        {
            ui->lcd_temp->setStyleSheet("QLCDNumber{color:red}");
        }
        else
        {
            ui->lcd_temp->setStyleSheet("QLCDNumber{color: rgb(255, 248, 0)}");
        }
        if (query.value(3).toDouble()  < amin || query.value(3).toDouble() > amax)
        {
            ui->lcd_amm->setStyleSheet("QLCDNumber{color:red}");
        }
        else
        {
            ui->lcd_amm->setStyleSheet("QLCDNumber{color: rgb(255, 248, 0)}");
        }
        if (query.value(2).toDouble() < hmin || query.value(2).toDouble() > hmax)
        {
            ui->lcd_hum->setStyleSheet("QLCDNumber{color:red}");
        }
        else
        {
             ui->lcd_hum->setStyleSheet("QLCDNumber{color: rgb(255, 248, 0)}");
        }
        QString temp = QString::number(query.value(1).toDouble(),'f',1);
        QString hum = QString::number(query.value(2).toDouble(),'f',1);
        QString amm = QString::number(query.value(3).toDouble(),'f',1);
        ui->lcd_temp->display(temp);
        ui->lcd_hum->display(hum);
        ui->lcd_amm->display(amm);
        //qDebug() << temp << hum << amm << endl;
    }
}

void Env::replyfinish(QNetworkReply *reply)
{
    QString strJsonText = reply->readAll();//这个返回的JSON包所携带的所有信息
    qDebug()<<"The information returned: " <<strJsonText;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(strJsonText.toLocal8Bit().data());
    if(jsonDocument.isNull())
    {
        qWarning()<< "String NULL"<< strJsonText;
    }
    QJsonObject object = jsonDocument.object();
    /********************/
    if (object.contains("temp_min"))
    {
        // 包含指定的 key
        QJsonValue value = object.value("temp_min");  // 获取指定 key 对应的 value
        qDebug() << "value" << value;
        tmin = value.toDouble(); // 将 value 转化为字符串
        qDebug() << "tmin: " << tmin;

    }
    if (object.contains("temp_max"))
    {
        // 包含指定的 key
        QJsonValue value = object.value("temp_max");  // 获取指定 key 对应的 value
        qDebug() << "value" << value;
        tmax = value.toDouble(); // 将 value 转化为字符串
        qDebug() << "tmax: " << tmax;

     }
    if (object.contains("hum_min"))
    {
        // 包含指定的 key
        QJsonValue value = object.value("hum_min");  // 获取指定 key 对应的 value
        qDebug() << "value" << value;
        hmin = value.toDouble(); // 将 value 转化为字符串
        qDebug() << "hmin: " << hmin;

     }
    if (object.contains("hum_max"))
    {
        // 包含指定的 key
        QJsonValue value = object.value("hum_max");  // 获取指定 key 对应的 value
        qDebug() << "value" << value;
        hmax = value.toDouble(); // 将 value 转化为字符串
        qDebug() << "hmax: " << hmax;

     }
    if (object.contains("amm_min"))
    {
        // 包含指定的 key
        QJsonValue value = object.value("amm_min");  // 获取指定 key 对应的 value
        qDebug() << "value" << value;
        amin = value.toDouble(); // 将 value 转化为字符串
        qDebug() << "amin: " << amin;
     }
    if (object.contains("amm_max"))
    {
        // 包含指定的 key
        QJsonValue value = object.value("amm_max");  // 获取指定 key 对应的 value
        qDebug() << "value" << value;
        amax = value.toDouble(); // 将 value 转化为字符串
        qDebug() << "amax: " << amax;
     }
    /********************/
    reply->deleteLater();
}

void Env::on_btn_th_clicked()
{
    this->close();
    connect(&td,SIGNAL(stsend()),this,SLOT(reshow()));
    td.show();
}

void Env::reshow()
{
    this->show();
}
