#include "avocat.h"
#include<iostream>
#include <QApplication>
#include <QString>
#include <QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QObject>
#include"mainwindow.h"
using namespace std;

Avocat::Avocat()
{
nom="";
prenom="";
id="";
numtel="";
audiance="";
}
Avocat::Avocat(QString id,QString nom,QString premom,QString audiance,QString numtel)
{
this->nom=nom;
    this->id=id;
    this->prenom=premom;
    this->numtel=numtel;
    this->audiance=audiance;
}


bool Avocat::ajouter(){
    QSqlQuery q;
    q.prepare("INSERT INTO AVOCATS (ID_AVOCAT,PRENOM,NOM,AUDIANCE_REUSSI,NUM_TEL)" "VALUES (:ID_AVOCAT,:PRENOM,:NOM,:AUDIANCE_REUSSI,:NUM_TEL)");
    q.bindValue(":ID_AVOCAT",id);
    q.bindValue(":PRENOM",prenom);
    q.bindValue(":NOM",nom);
    q.bindValue(":AUDIANCE_REUSSI",audiance);
    q.bindValue(":NUM_TEL",numtel);
    return q.exec();
}
bool Avocat::modifier(QString id){
    QSqlQuery q;
    q.prepare("UPDATE AVOCATS SET ID_AVOCAT=:ID_AVOCAT ,PRENOM=:PRENOM,NOM=:NOM,AUDIANCE_REUSSI=:AUDIANCE_REUSSI,NUM_TEL=:NUM_TEL where ID_AVOCAT=:ID_AVOCAT");
    q.bindValue(":ID_AVOCAT",id);
    q.bindValue(":PRENOM",prenom);
    q.bindValue(":NOM",nom);
    q.bindValue(":AUDIANCE_REUSSI",audiance);
    q.bindValue(":NUM_TEL",numtel);
    return q.exec();
}

QSqlQueryModel * Avocat::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM AVOCATS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AVOCAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AUDIANCE_REUSSI"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_TEL"));
    return model; }
void Avocat::statpie(int &numa){

   QSqlQuery query  ;
   query.prepare("select count(ID_AVOCAT) from AVOCATS " );
           if(query.exec())
           {
               while (query.next())
               {
               numa=query.value(0).toInt();

               }
           }


}

bool Avocat::supprimer(QString id)
{ Avocat a;
    QSqlQuery q;

    q.prepare("DELETE FROM AVOCATS WHERE ID_AVOCAT=:id" );
    q.bindValue(0,id);

    return q.exec();
}
QSqlQueryModel * Avocat:: affichageASC()
{

    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM AVOCATS ORDER BY TO_NUMBER(AUDIANCE_REUSSI) ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AVOCAT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("AUDIANCE_REUSSI"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_TEL"));
     return  model;

}
QSqlQueryModel * Avocat:: affichageDSC()
{

    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM AVOCATS ORDER BY TO_NUMBER(AUDIANCE_REUSSI) DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AVOCAT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("AUDIANCE_REUSSI"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_TEL"));
  return  model;

}

QSqlQueryModel* Avocat ::search_Avocat(QString id)
{

    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;


     model->setQuery("SELECT * FROM AVOCATS WHERE  (ID_AVOCAT like '"+id+"%""')  ");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AVOCAT"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("AUDIANCE_REUSSI"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_TEL"));

    query.exec();
        return  model;
}


/***********Mailling**************/






