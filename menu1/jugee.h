#ifndef JUGEE_H
#define JUGEE_H
 #include "QString"
#include "QSqlQueryModel"
#include <QBarSet>
#include <QPieSeries>
#include <QtCharts/QLineSeries>
#include<QtCharts>

class jugee
{
private:

        QString nom , prenom , dateN , lieuN , grade,id,num;



public:
    //constructeurs
    jugee();
    jugee(QString,QString,QString,QString,QString,QString,QString);
     //getters
    QString getnom(){return nom;};
    QString getprenom(){return prenom;};
    QString getdaten(){return dateN;};
   QString getnum(){return num;};
    QString getid(){return id;};
    QString getlieun(){return lieuN;};
    QString getgrade(){return grade;};

    //setters
    void setnom(QString n){nom=n;}
    void setprenom(QString p){this->prenom=p;}
    void setdaten(QString daten){this->dateN=daten;}
    void setnum(QString nu){num=nu;}
    void setid(QString id){this->id=id;}
    void setlieun(QString li){lieuN=li;}
    void setgrade(QString g){grade=g;}

   //methods
   //fonctions CRUD
   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(QString id);
   bool modifier(QString id);
   QSqlQueryModel * combo_box();
//fonctions avancees
   QSqlQueryModel * recherche(const QString &);
   QSqlQueryModel * recherche_nom(const QString &);
   QSqlQueryModel * recherche_prenom(const QString &);
   QSqlQueryModel * recherche_dateN(const QString &);
   QSqlQueryModel * recherche_num(const QString &);
   QSqlQueryModel * recherche_id(const QString &);
   QSqlQueryModel * recherche_lieuN(const QString &);
   QSqlQueryModel * recherche_grade(const QString &);
   //up
    QSqlQueryModel * afficherup_id();
    QSqlQueryModel * afficherup_num();
   //down

   QSqlQueryModel * afficherdown_id();
   QSqlQueryModel * afficherdown_num();
   //trie
   QSqlQueryModel * trier_id_a();
   QSqlQueryModel * trier_id_d();













};

#endif // JUGEE_H
