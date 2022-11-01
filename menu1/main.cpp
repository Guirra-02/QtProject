#include "mainwindow.h"
#include"connection.h"
#include<QFontDatabase>
#include <QApplication>
#include<QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    bool test=c.createconnection();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


        w.show();

    }
    else
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    return a.exec();
}
