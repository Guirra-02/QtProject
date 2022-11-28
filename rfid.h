#ifndef RFID_H
#define RFID_H
#include <QObject>
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSettings>

namespace Ui {
class RFID;
}

class RFID : public QMainWindow
{
    Q_OBJECT

public:
    explicit RFID(QWidget *parent = 0);
    ~RFID();
signals:
    void dataready(QString data);

private slots:
    void dataread();
    void cleardata(QByteArray data);

private:
    Ui::RFID *ui;
    QSerialPort *port;
    void initPort();


};

#endif // RFID_H
