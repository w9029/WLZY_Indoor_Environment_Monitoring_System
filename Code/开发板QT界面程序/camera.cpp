#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    setAttribute(Qt::WA_DeleteOnClose,0);
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras)
    {
        if (cameraInfo.deviceName() == "/dev/video0")
            camera = new QCamera(cameraInfo);
        qDebug() << cameraInfo.deviceName();
    }
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);


    ui->ImageView->addWidget(viewfinder);
    ui->ImageCapture->setScaledContents(true);

    camera->setViewfinder(viewfinder);
    camera->start();

    /*QCameraViewfinderSettings set;
    //设置分辨率
    set.setResolution(320,240);
    //设置最大帧率
    set.setMaximumFrameRate(20);
    camera->setViewfinderSettings(set);*/
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    connect(ui->buttonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(ui->buttonSave, SIGNAL(clicked()), this, SLOT(saveImage()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(myquit()));
}

Camera::~Camera()
{
    delete ui;
    delete camera;
    delete viewfinder;
    delete imageCapture;
    delete this;
}

void Camera::myquit()
{
    camera->stop();
    emit sesignal();
    this->close();
}

void Camera::captureImage()
{
    //ui->statusBar->showMessage(tr("capturing..."), 1000);
    ui->lab_status->setText("capturing...");
    imageCapture->capture();
}

void Camera::displayImage(int , QImage image)
{
    ui->ImageCapture->setPixmap(QPixmap::fromImage(image));
    //ui->statusBar->showMessage(tr("capture OK!"), 5000);
    ui->lab_status->setText("capture OK!");
}

void Camera::saveImage()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), QDir::homePath(), tr("image png(*.png)"));
    if(fileName.isEmpty())
    {
        //ui->statusBar->showMessage(tr("save cancel"), 5000);
        ui->lab_status->setText("save cancel");
        return;
    }
    const QPixmap *pixmap=ui->ImageCapture->pixmap();
    if(pixmap)
    {
        pixmap->save(fileName);
        ui->lab_status->setText("save OK");
        //ui->statusBar->showMessage(tr("save OK"), 5000);
    }
}

