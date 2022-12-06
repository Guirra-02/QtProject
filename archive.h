#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
class archive
{
    int numarch;
    QString typeCrime;
    QDate dateCrime;
    QString lieuCrime;
    QString jugementFinal;

public:
    archive();
   archive(int,QString,QDate,QString,QString);
   //getters
    int getNumarch(){return numarch;}
    QString getTypeCrime(){return typeCrime;}
    QString getlieuCrime(){return lieuCrime;}
    QString getJugementFinal(){return jugementFinal;}
    //setters
   void setNumarch(int numarch){this->numarch=numarch;}
   void setTypeCrime(QString typeCrime){this->typeCrime=typeCrime;}
     void setlieuCrime(QString lieuCrime){this->lieuCrime=lieuCrime;}
     void setJugementFinal(QString jugementFinal){this->jugementFinal=jugementFinal;}
     bool ajouter();
     QSqlQueryModel *afficher();
     bool supprimer(QString);
     void login_modifier_afficher_tab(Ui::MainWindow *ui);
     bool modifier(int id1);
     QSqlQueryModel *afficher_calendar(QDate x);

};

#endif // ARCHIVE_H
