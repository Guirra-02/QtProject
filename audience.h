#ifndef AUDIENCE_H
#define AUDIENCE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class audience
{
private:
    QString id,type,date;

public:
    audience();
    audience(QString id,QString date,QString type){

     this->id=id;
        this->date=date;
        this->type=type;
    }
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString id_donnee);
    bool modifier();
   QSqlQueryModel* tri_cin();
   QSqlQueryModel* recherche(QString);
   QSqlQueryModel * geo();
   int calculer(QString operateur) ;
};

#endif // AUDIENCE_H

