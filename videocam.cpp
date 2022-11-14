#include "videocam.h"
#include "ui_videocam.h"

videocam::videocam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::videocam)

    {
        ui->setupUi(this);

         setCamera(QCameraInfo::defaultCamera());
    }




videocam::~videocam()
{
    delete ui;
}

void videocam::setCamera(const QCameraInfo &cameraInfo)
{
 camera = new QCamera(cameraInfo);
imageCapture = new QCameraImageCapture(camera);
camera->setViewfinder(ui->
connect(imageCapture, &QCameraImageCapture::readyForCaptureChanged, this, &camera::readyForCapture);
camera->start();

}
