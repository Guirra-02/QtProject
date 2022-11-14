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

private:
    Ui::MainWindow *ui;
    Avocat a;
    camera *c;
    QVideoWidget* vw;
    QStringList files;
    QMediaPlayer* player;


};
#endif // MAINWINDOW_H
