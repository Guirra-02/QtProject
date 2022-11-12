#include "avocat.h"
#include<iostream>
#include <QApplication>
#include <QString>
#include <QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QObject>

using namespace std;

Avocat::Avocat()
{
nom="";
prenom="";
id="";
}
Avocat::Avocat(QString id,QString nom,QString premom)
{
this->nom=nom;
    this->id=id;
    this->prenom=premom;
}


bool Avocat::ajouter(){
    QSqlQuery q;
    q.prepare("INSERT INTO AVOCATS (ID_AVOCAT,PRENOM,NOM)" "VALUES (:ID_AVOCAT,:PRENOM,:NOM)" );
    q.bindValue(":ID_AVOCAT",id);
    q.bindValue(":PRENOM",prenom);
    q.bindValue(":NOM",nom);
    return q.exec();
}

QSqlQueryModel * Avocat::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM AVOCATS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AVOCAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));

    return model; }

bool Avocat::supprimer(QString id)
{ Avocat a;
    QSqlQuery q;

    q.prepare("DELETE FROM AVOCATS WHERE ID_AVOCAT=:id" );
    q.bindValue(0,id);

    return q.exec();
}

