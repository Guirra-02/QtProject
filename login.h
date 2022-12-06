#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QString,QString);
    bool auth();

    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    MainWindow *mainwindow;
    QString username,password;
protected :
};

#endif // LOGIN_H
