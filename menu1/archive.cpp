#include "archive.h"
#include <QSqlQuery>
archive::archive()
{
    this->numarch =-1;
    this->typeCrime ="";
    this-> rapport="";
    this-> jugementFinal="";

}
archive::archive(int numarch,QString typeCrime,QString rapport,QString jugementFinal){

    this->numarch =numarch;
    this->typeCrime =typeCrime;
    this-> rapport=rapport;
    this-> jugementFinal=jugementFinal;

}
bool archive:: ajouter(){

    QSqlQuery query;
    QString res=QString::number(numarch);

    query.prepare("insert into AFFAIRE_JURIDIQUE1 (numarch,typeCrime,rapport,jugementFinal )""values(:numarch,:typeCrime,:rapport,:jugementFinal)");
    query.bindValue(":numarch", res);
    query.bindValue(":typeCrime", typeCrime);
    query.bindValue(":rapport", rapport);
    query.bindValue(":jugementFinal", jugementFinal);
return query.exec();

}

QSqlQueryModel *archive::afficher(){

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from AFFAIRE_JURIDIQUE1");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DateCrime"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("rapport"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("jugementFinal"));

    return model;

 }
void archive::login_modifier_afficher_tab(Ui::MainWindow *ui)
{

    QSqlQueryModel * model= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from AFFAIRE_JURIDIQUE1");
    qry->exec();
    model->setQuery(*qry);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("rapport"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("jugementFinal"));
    ui->tableView->setModel(model);
}
bool archive::supprimer(int numarch){
    QSqlQuery query;
    QString res=QString::number(numarch);
    query.prepare("Delete from AFFAIRE_JURIDIQUE1 where numarch=:numarch");
    query.bindValue(":numarch",res);
    return query.exec();
}

bool archive::modifier(int id1)
{

    QSqlQuery query;
    QString res=QString::number(numarch);
   // QString id2=QString::number(id1);

          query.prepare("UPDATE AFFAIRE_JURIDIQUE1 "" SET numarch=:numarch, TypeCrime=:TypeCrime, rapport=:rapport, jugementFinal=:jugementFinal where numarch='"+res+"' ");


            query.bindValue(":numarch", res);
            query.bindValue(":TypeCrime", typeCrime);
            query.bindValue(":rapport", rapport);
            query.bindValue(":jugementFinal", jugementFinal);
        return    query.exec();
}
