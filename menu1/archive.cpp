#include "archive.h"
#include <QSqlQuery>
#include <QDate>


archive::archive()
{
    this->numarch =-1;
    this->typeCrime ="";

    this-> lieuCrime="";
    this-> jugementFinal="";

}
archive::archive(int numarch,QString typeCrime,QDate dateCrime,QString lieuCrime,QString jugementFinal){

    this->numarch =numarch;
    this->typeCrime =typeCrime;
    this->dateCrime = dateCrime;
    this-> lieuCrime=lieuCrime;
    this-> jugementFinal=jugementFinal;

}
bool archive:: ajouter(){

    QSqlQuery query;
    QString res=QString::number(numarch);

    query.prepare("insert into AFFAIRE (numarch,typeCrime,dateCrime,lieuCrime,jugementFinal )""values(:numarch,:typeCrime,:dateCrime,:lieuCrime,:jugementFinal)");
    query.bindValue(":numarch", res);
    query.bindValue(":typeCrime", typeCrime);
     query.bindValue(":dateCrime", dateCrime);
    query.bindValue(":lieuCrime", lieuCrime);
    query.bindValue(":jugementFinal", jugementFinal);
return query.exec();

}

/*QSqlQueryModel *archive::afficher(){

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from AFFAIRE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DateCrime"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("lieuCrime"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("jugementFinal"));

    return model;
}*/
void archive::login_modifier_afficher_tab(Ui::MainWindow *ui)
{

    QSqlQueryModel * model= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from AFFAIRE");
    qry->exec();
    model->setQuery(*qry);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("dateCrime"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("lieuCrime"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("jugementFinal"));
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
bool archive::supprimer(QString numarch){
    QSqlQuery query;
    query.prepare("Delete from AFFAIRE where numarch=:numarch");
    query.bindValue(":numarch",numarch);
    return query.exec();
}

bool archive::modifier(int id1)
{

    QSqlQuery query;
    QString res=QString::number(numarch);
   // QString id2=QString::number(id1);

          query.prepare("UPDATE AFFAIRE "" SET numarch=:numarch, TypeCrime=:TypeCrime, dateCrime=:dateCrime,lieuCrime=:lieuCrime, jugementFinal=:jugementFinal where numarch='"+res+"' ");


            query.bindValue(":numarch", res);
            query.bindValue(":TypeCrime", typeCrime);
            query.bindValue(":dateCrime", dateCrime);
            query.bindValue(":lieuCrime", lieuCrime);
            query.bindValue(":jugementFinal", jugementFinal);
        return    query.exec();
}
//*************************************************************calander
QSqlQueryModel * archive:: afficher_calendar(QDate x)
{QSqlQueryModel * model= new QSqlQueryModel();
QString x1=QString::number(x.month()),x2=QString::number(x.day()),x3=QString::number(x.year());
model->setQuery("select * from AFFAIRE where(extract(day  from dateCrime)='"+x2+"' and extract(month  from dateCrime)='"+x1+"' and extract(year  from dateCrime)='"+x3+"')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numarch"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TypeCrime"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateCrime"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieuCrime"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("jugementFinal"));

    return model;
}
