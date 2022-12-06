#include "mainwindow.h"
#include "login.h"
#include"connection.h"
#include<QFontDatabase>
#include <QApplication>
#include<QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //**********************************************************languistic
    QTranslator t;
    QTranslator guitranslator;
    QStringList language;
    language <<"english"<<"arab";
    QString lang =QInputDialog::getItem(NULL,"select language",
                                             "language",language);

   if(lang== "arab")
    {
        t.load(":/new/prefix1/arab.qm");
        a.installTranslator(&t);
        a.installTranslator(&guitranslator);
     //   guitranslator.load("C:/Qt/Qt5.9.9/5.9.9/mingw53_32/translations/qtbase_ar.qm");


    }
     else if(lang !="anglais")
    {
       t.load(":/new/prefix1/english.qm");
         a.installTranslator(&t);
         a.installTranslator(&guitranslator);
        // guitranslator.load("");
    }


    //***********************************************************
    Login l;
    a.setQuitOnLastWindowClosed(false);
    connection c;
    bool test=c.createconnection();
    if(test){



        l.show();

    }

    return a.exec();
}
