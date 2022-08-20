#include "login.h"
#include "ui_login.h"

extern QString nowname;

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_DeleteOnClose,0);
    setWindowTitle("Login");
    this->ui->username->setText("wjh9029");
    this->ui->password->setText("111111");
}

Login::~Login()
{
    delete ui;
    delete manager;
}

void Login::on_btn_login_clicked()
{
    QString username;
    QString password,strmd5;
    QByteArray md5;
    QString mac;
    username = this->ui->username->text();
    password = this->ui->password->text();
    nowname = username;
    /*进行md5加密*/
    md5 = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);
    strmd5.append(md5.toHex());
    qDebug() << strmd5;
    mac = getHostMacAddress();
    /******************login mod**********************/
    // 构建 JSON 对象
    QJsonObject json;
    json.insert("name",username);
    json.insert("password",strmd5);
    json.insert("mac",mac);
    // 构建 JSON 文档
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    qDebug() << byteArray;
    //连接服务器
    QUrl url("http://192.168.100.61:8080/dev/login");
    QNetworkRequest request;
    request.setUrl(url);
    //request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyfinish(QNetworkReply*)));
    QNetworkReply *reply = manager->post(request,byteArray);
    /*****************************************************/
    connect(&sw,SIGNAL(sendsignal()),this,SLOT(on_btn_cancel_clicked()));

}

void Login::on_btn_cancel_clicked()
{
    //this->ui->username->clear();
    //this->ui->password->clear();
    //this->ui->lab_status->clear();
    emit sendsignal();
    this->close();   
}

QString Login::getHostMacAddress()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    return strMacAddr;
}



void Login::replyfinish(QNetworkReply * reply)
{
    QString strJsonText = reply->readAll();//这个返回的JSON包所携带的所有信息
    qDebug()<<"The information returned: " <<strJsonText;
    if (QString::compare(strJsonText,"success") == 0)
    {
        this->ui->password->clear();
        this->ui->username->clear();
        this->ui->lab_status->clear();
        qDebug() << "login success";
        this->close();
        sw.show();

    }
    else if(QString::compare(strJsonText,"name_error") == 0)
    {
        this->ui->password->clear();
        this->ui->username->clear();
        this->ui->lab_status->setText("Can not find this username!");
        qWarning() << "Can not find this username!";
    }
    else
    {
        this->ui->password->clear();
        this->ui->lab_status->setText("Password is wrong!");
        qWarning() << "Password is wrong!";

    }
    reply->deleteLater();
}


void Login::on_username_textEdited(const QString &arg1)
{
    this->ui->lab_status->clear();
}

void Login::on_password_textEdited(const QString &arg1)
{
    this->ui->lab_status->clear();
}
