#include "salle.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDate>

#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
salle::salle()
{



id=0; num=0;bloc="";place="";
}

salle::salle(int i,int n,QString bl,QString et)
{
   id=i;
   num=n;
   bloc=bl;
   place=et;

}
int salle::getid(){return id;}
int salle::getnum(){return num;}
QString salle::getplace(){return bloc;}
QString salle::getbloc(){return place;}


void salle::setid(int id){this->id=id;}
void salle::setnum(int num){this->num=num;}
void salle::setplace(QString place){this->place=place;}
void salle::setbloc(QString bloc){this->bloc=bloc;}




bool salle::ajouter()
{


QSqlQuery query;
QString id_string= QString::number(id);
query.prepare("INSERT INTO salle (id,num,place,bloc) "
              "VALUES (:id, :num, :place,:bloc)");

 query.bindValue(":id", id);
 query.bindValue(":num", num);
 query.bindValue(":place",place);
 query.bindValue(":bloc",bloc);



return query.exec();

}
QSqlQueryModel * salle::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from salle");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("place"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("bloc"));


    return  model;

}


bool salle::supprimer(int id)
{

    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM salle WHERE ID= :id");
    query.bindValue(":id",res);
    return query.exec();

}
bool salle::modifierSalle(int id, int num, QString place, QString bloc)

{



    QSqlQuery query;

    query.prepare("update salle set num=:num,place=:place,bloc=:bloc where id=:id");

    query.bindValue(":id",id);
    query.bindValue(":num",num);

    query.bindValue(":place",place);

    query.bindValue(":bloc",bloc);



    return query.exec();



}






//Trie Par id
QSqlQueryModel * salle::trierSalleParid()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM salle order by id ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par bloc
QSqlQueryModel * salle::trierSalleParbloc()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM salle order by bloc ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par num
QSqlQueryModel * salle::trierSalleParnum()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM salle order by num ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


//-------------------------------------------------------------------------

QSqlQueryModel * salle::Recherche(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM salle WHERE (ID LIKE '%"+a+"%' OR num LIKE '%"+a+"%' OR bloc LIKE '%"+a+"%' OR place LIKE '%"+a+"%' ) ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("bloc"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("place"));


    return model;
}

















