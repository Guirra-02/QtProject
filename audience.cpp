#include "audience.h"

audience::audience()
{

}


bool audience::ajouter(){

    QSqlQuery query;

          query.prepare("INSERT INTO AUDIANCE (ID , DATEE , TYPE ) "
                        "VALUES (:ID, :DATEE, :TYPE)");
          query.bindValue(0, id);
          query.bindValue(1, date);
          query.bindValue(2, type);


    return  query.exec();
}

QSqlQueryModel* audience::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel();



          model->setQuery("SELECT* FROM AUDIANCE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));


  return model;
}
bool audience::supprimer(QString id_donnee)
{
    QSqlQuery query;

          query.prepare("Delete from AUDIANCE where id=:id" );

          query.bindValue(0, id_donnee);
 return query.exec();
}
bool audience ::modifier()
{
    QSqlQuery query;
 query.prepare("update AUDIANCE set datee=:datee,type=:type where id=:id");
 query.bindValue(":id", id);
 query.bindValue(":datee", date);
 query.bindValue(":type", type);




     return  query.exec();


}

QSqlQueryModel * audience::tri_cin()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from AUDIANCE order by id ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));


   return model;
    }
QSqlQueryModel* audience::recherche(QString recherche)
 {

         QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM AUDIANCE WHERE id LIKE '"+recherche+"%'" );
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));


    return model;




 }
QSqlQueryModel * audience::geo()
{
    QString link="https://www.bing.com/maps?q=Smart-Court+Tunisie%2C+09.Rue+Hedi+Khefecha+Ariana+2080%2C+Ariana%2C+Tunis%2C+Tunisiemap&cvid=d31c6d30fe8a434c99d88c90876c1c74&aqs=edge..69i57.2098j0j4&FORM=ANAB01&PC=U531";
    QDesktopServices::openUrl(link);
}

/*int audience::calculer(QString operateur) {
  QSqlQuery query;
  query.prepare("select * from AUDIANCE where operateur = :operateur");
  query.bindValue(":operateur", operateur);

  query.exec();
  int total = 0;
  while (query.next()) {
    total++;
  }

  return total;
}*/
