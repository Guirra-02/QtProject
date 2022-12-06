#ifndef AVOCAT_H
#define AVOCAT_H
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<string>
#include<list>

class Avocat
{private : QString audiance,nom,prenom,id,numtel;

public:
   QSqlQueryModel *  affichageASC();
   QSqlQueryModel *  affichageDSC();

    QString  getnom(){return  nom;}
   QString  getprenom(){return  prenom;}
   QString  getid(){return  id;}
   QString  getnumtel(){return  numtel;}
    QString  getaudiance(){return  audiance;}
   Avocat();
   Avocat(QString,QString,QString,QString,QString);
   void setnom(QString nom){this->nom=nom; }
   void setprenom(QString prenom){this->prenom=prenom; }
   void setid(QString id){this->id=id; }
   void setaudiance(QString audiance){this->audiance=audiance; }
   void setnumtel(QString numtel){this->numtel=numtel; }
   bool ajouter();
   bool modifier(QString);
   void statpie(int &numa);

   QSqlQueryModel * afficher();
  QSqlQueryModel* search_Avocat(QString id);

   bool supprimer(QString);

};


#endif // AVOCAT_H
