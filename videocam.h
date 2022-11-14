#ifndef VIDEOCAM_H
#define VIDEOCAM_H

#include <QDialog>
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>

#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QMediaMetaData>

#include <QPalette>
namespace Ui {
class videocam;
}

class videocam : public QDialog
{
    Q_OBJECT

public:
    explicit videocam(QWidget *parent = nullptr);
    ~videocam();
    void setCamera(const QCameraInfo &cameraInfo);
    void readyForCapture(bool ready);

    void on_takeImageButton_clicked();

private:
    Ui::videocam *ui;
    QCamera *camera = nullptr;
    QCameraImageCapture *imageCapture = nullptr;
    QMediaRecorder* mediaRecorder = nullptr;

    QImageEncoderSettings imageSettings;
    QAudioEncoderSettings audioSettings;
    QVideoEncoderSettings videoSettings;
    QString videoContainerFormat;
    bool isCapturingImage = false;
    bool applicationExiting = false;
};

#endif // VIDEOCAM_H
