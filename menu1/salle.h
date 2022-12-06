#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class salle
{
public:
    salle();


    salle(int,int,QString,QString);


            int getid();
            int getnum();
              QString getplace();
            QString getbloc();


                 void getid(int);

                 void getnum(int);
                 void getplace(QString);

                 void getbloc(QString);


                 void setid(int);
                 void setnum(int);
                        void setplace(QString);
                        void setbloc(QString);

                 bool ajouter();
                        QSqlQueryModel * afficher();
                        bool supprimer(int);
                        bool modifierSalle(int id,int num,QString place,QString bloc);
                       int chercherSalle(int id);
                       QSqlQueryModel * trierSalleParid();
                       QSqlQueryModel * trierSalleParbloc();
                       QSqlQueryModel * trierSalleParnum();
                        QSqlQueryModel * Recherche(QString);




                               QSqlQueryModel* rechercher(QString place);






                    private:
                        int id,num;
                        QString place,bloc;
};

#endif // SALLE_H
