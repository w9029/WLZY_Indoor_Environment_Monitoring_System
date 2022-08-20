#include "stream.h"
#include "ui_stream.h"

Stream::Stream(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stream)
{
    setWindowTitle("Camera");
    setAttribute(Qt::WA_StyledBackground);
    ui->setupUi(this);
    btn_startisclick = false;
    img = new QImage;
    scaledimg = new QImage;
    showTime=new QTimer;
    showTime->setInterval(42);
    connect(showTime, SIGNAL(timeout()), this, SLOT(flushPic()));
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    openps = new QProcess();
    closeps = new QProcess();
    //openps->start("/workspace/VideoSwitch/open.sh");
}

Stream::~Stream()
{
    delete ui;
    delete openps;
    delete closeps;
}

void Stream::on_btn_start_clicked()
{
    pu = "http://127.0.0.1:8080/?action=snapshot/";
    if(btn_startisclick == false)
    {
        ui->lab_camera->clear();
        btn_startisclick = true;
        openps->start("/workspace/VideoSwitch/open.sh");
        qDebug() << "Now start camera!";
        ui->btn_start->setText("Stop");
        showTime->start();
    }
    else
    {
        ui->lab_camera->clear();
        btn_startisclick = false;
        ui->btn_start->setText("Start");
        showTime->stop();
        qDebug() << "Now stop camera";
    }

}

void Stream::on_btn_shot_clicked()
{
    if(!QDir("photo").exists())
    {
        QDir dir;
        dir.mkpath("photo");
        qDebug() << "mkdir photo";
    }
    QString str_time,path;
    QDateTime time = QDateTime::currentDateTime();
    str_time = time.toString("yyyy-MM-dd_hh-mm-ss");
    path="./photo/"+str_time+".jpg";
    QPixmap::fromImage(*img).save(path, "JPG", 100);
    *scaledimg=img->scaled(160,120,Qt::KeepAspectRatio);
    ui->lab_pic->setPixmap(QPixmap::fromImage(*scaledimg));
    QMessageBox::information(this,tr("save"),tr("PICTURE has been saved to folder 'photo!'"));
    qDebug() << "PICTURE has been saved to folder 'photo!'";
}

void Stream::on_btn_quit_clicked()
{
    showTime->stop();
    ui->lab_camera->clear();
    ui->lab_pic->clear();
    emit sesignal();
    this->close();

}

void Stream::flushPic()
{
    request.setUrl(QUrl(pu));
    manager->get(request);
}

void Stream::replyFinished(QNetworkReply* reply)
{       //save the picture
    QPixmap pix;
    QByteArray data = reply->readAll();
    pix.loadFromData(data, "JPG");
    if(!QDir("temp").exists())
    {
        QDir dir;
        dir.mkpath("temp");
        qDebug() << "mkdir temp.";
    }
    pix.save("temp/temp1.jpg", "JPG", 50);
    if(! ( img->load("temp/temp1.jpg") ) ) //加载图像
    {
        showTime->stop();
        QMessageBox::information(this,tr("warning!"),tr("The image loaded failure!"));
        qWarning() << "The image loaded failure!";
        btn_startisclick = false;
        return;
    }
    *scaledimg=img->scaled(640,480,Qt::KeepAspectRatio);
    ui->lab_camera->setPixmap(QPixmap::fromImage(*scaledimg));
}

void Stream::on_Streamclose_clicked()
{
    closeps->start("/workspace/VideoSwitch/close.sh");
    QMessageBox::information(this,tr("close"),tr("stream closed!"));
}
