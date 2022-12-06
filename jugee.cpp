#include "jugee.h"
#include "QString"
#include "QSqlQueryModel"
#include "QSqlQuery"
#include "QDebug"
#include "juge.h"
#include "connection.h"
#include <QIntValidator>
#include <QObject>
#include <QBarSet>

jugee::jugee()
{
 nom=" " ;
 prenom=" " ;
 dateN=" " ;
 num=" " ;
 id=" " ;
 grade=" " ;
 lieuN=" ";
}

jugee::jugee(QString nom,QString prenom,QString daten,QString num,QString id,QString grade,QString lieun){
   this->nom=nom;
     this->prenom=prenom;
    this->dateN=daten;
    this->num=num;
    this->id=id;
    this->grade=grade;
    this->lieuN=lieun;
}

bool jugee::ajouter(){



        QSqlQuery query;

              query.prepare("INSERT INTO JUGESS (ID_JUGES ,NOM,PRENOM,DATEN,LIEUN,GRADE,NUM ) "
                            "VALUES (:ID_JUGES, :NOM, :PRENOM ,:DATEN,:LIEUN,:GRADE,:NUM)");
              query.bindValue(":ID_JUGES",id);
              query.bindValue(":NOM", nom);
              query.bindValue(":PRENOM", prenom);
              query.bindValue(":DATEN", dateN);
               query.bindValue(":LIEUN", lieuN);
               query.bindValue(":GRADE", grade);
              query.bindValue(":NUM", num);

        return  query.exec();
    }


QSqlQueryModel * jugee::afficher()
{

     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM JUGESS");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JUGES"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEN"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("LIEUN"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("GRADE"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM"));


     return model;
    }
bool jugee::supprimer(QString id){

    QSqlQuery query;

    query.prepare("DELETE FROM JUGESS WHERE ID_JUGES=:id");
    //QString r=QString::number(n);
    query.bindValue(":id",id);
    return query.exec();

}

bool jugee::modifier(QString id){
    QSqlQuery query;

       QString nom;
       QString prenom;
       QString grade;
       QString daten;
       QString lieun;

       query.prepare("UPDATE JUGESS SET ID_JUGES=:id,NOM=:nom,PRENOM=:prenom,daten=:daten,LIEUN=:lieun ,GRADE=:grade,NUM=:num WHERE ID_JUGES=:id");
       query.bindValue(":id",id);
       query.bindValue(":nom",nom);
       query.bindValue(":prenom",prenom);
       query.bindValue("daten",dateN);
       query.bindValue(":grade",grade);
       query.bindValue(":lieun",lieuN);
       query.bindValue(":num",num);
       return query.exec();
}
QSqlQueryModel * jugee::combo_box(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select ID_JUGES from JUGESS");
    return model;
}
QSqlQueryModel *jugee::recherche(const QString &rech)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from JUGESS where (ID_JUGES LIKE '"+rech+"%' OR NOM LIKE '"+rech+"%' OR PRENOM LIKE '"+rech+"%' OR DATEN LIKE '"+rech+"%' OR LIEUN LIKE '"+rech+"%' OR GRADE LIKE '"+rech+"%' OR NUM LIKE '"+rech+"%') ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateN "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieuN "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("grade "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("num "));


return model;
}
QSqlQueryModel * jugee::afficherup_id()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM JUGESS  ORDER BY ID_JUGES ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("lieuN"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("grade"));
return model;
}
QSqlQueryModel *jugee::afficherdown_id()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM JUGESS ORDER BY ID_JUGES DSC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("lieuN"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("grade"));
return model;
}
//


QSqlQueryModel * jugee::afficherup_num()
{QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM JUGESS  ORDER BY NUM ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("lieuN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("grade"));
    return model;
}
QSqlQueryModel * jugee::afficherdown_num()
{QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM JUGESS  ORDER BY NUM DSC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("lieuN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("grade"));
    return model;
}
QSqlQueryModel * jugee::trier_id_a()//asc
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM JUGESS\
                         ORDER BY ID_JUGES ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("lieuN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("garde"));

    return model;
}
QSqlQueryModel * jugee::trier_id_d()//desc
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM JUGESS\
                         ORDER BY ID_JUGES DSC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("lieuN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("garde"));

    return model;
}
