#include "mainwindow.h"
#include "login.h"
#include"connection.h"
#include<QFontDatabase>
#include <QApplication>
#include<QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    connection c;
    bool test=c.createconnection();
    if(test){



        l.show();

    }

    return a.exec();
}
