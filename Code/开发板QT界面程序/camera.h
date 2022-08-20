#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
#include <QCameraInfo>

namespace Ui {
class Camera;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;

class Camera : public QWidget
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

signals:
    void sesignal();

private slots:
    void captureImage();

    void displayImage(int,QImage);

    void saveImage();

    void myquit();

private:
    Ui::Camera *ui;
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
};

#endif // CAMERA_H
