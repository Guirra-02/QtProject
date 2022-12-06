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
    language <<"english"<<"french"<<"arab";
    QString lang =QInputDialog::getItem(NULL,"select language",
                                             "language",language);
    if(lang =="french")
    {
        t.load(":/frensh.qm");
        guitranslator.load("C:/Qt/Qt5.9.9/5.9.9/mingw53_32/translations/qtbase_fr.qm");
    }
    else if(lang== "arab")
    {
        t.load(":/arab.qm");
        guitranslator.load("C:/Qt/Qt5.9.9/5.9.9/mingw53_32/translations/qtbase_ar.qm");


    }
    if(lang !="anglais")
    {
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
