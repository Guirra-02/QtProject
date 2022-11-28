#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include <QMainWindow>
#include "avocat.h"
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"camera.h"
#include<QMediaPlayer>
#include <QtCharts>
#include<QChartView>
#include<QLineSeries>
#include <QAbstractTableModel>
#include <QObject>
#include<QPieSeries>
#include <QString>
#include <QMessageBox>
#include "avocat.h"
#include<QSqlQueryModel>
#include <QtDebug>
#include <QPainter>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include"camera.h"
#include "smtp.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <ActiveQt/QAxWidget>
#include "axwidget.h"
#include <QAbstractTableModel>
#include<QAbstractItemModel>
#include <QObject>
#include<QPieSlice>
#include "arduino.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getCardUid();
    void authRFID();
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_editingFinished();

    void on_password_textChanged(const QString &arg1);

    void on_password_editingFinished();

    void on_username_editingFinished();

    void on_username_textChanged(const QString &arg1);

    void on_signup_clicked();

    void on_signup_2_clicked();

    void on_signin_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_eliminer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();
    void sendMail();
    void mailSent(QString);
    void browse();


    void on_browseBtn_clicked();

    void on_pushButton_12_clicked();

    void on_lineEditch_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Avocat a;
    camera *c;
    QVideoWidget* vw;
    QStringList files;
    QMediaPlayer* player;
    Avocat etmp;
    Arduino A;
   QString test1;


};
#endif // MAINWINDOW_H
