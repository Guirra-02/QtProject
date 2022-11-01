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

    QString rapport;
    QString jugementFinal;

public:
    archive();
   archive(int,QString,QString,QString);
   //getters
    int getNumarch(){return numarch;}
    QString getTypeCrime(){return typeCrime;}
    QString getRapport(){return rapport;}
    QString getJugementFinal(){return jugementFinal;}
    //setters
   void setNumarch(int numarch){this->numarch=numarch;}
   void setTypeCrime(QString typeCrime){this->typeCrime=typeCrime;}
     void setRapport(QString rapport){this->rapport=rapport;}
     void setJugementFinal(QString jugementFinal){this->jugementFinal=jugementFinal;}
     bool ajouter();
     QSqlQueryModel *afficher();
     bool supprimer(int);
     void login_modifier_afficher_tab(Ui::MainWindow *ui);
     bool modifier(int id1);
    /*etudiant(int,QString,QString);
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getID(){return id;}
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setID(int id){this->id=id;}
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int id);*/
};

#endif // ARCHIVE_H
