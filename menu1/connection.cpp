#include "connection.h"
#include <QMessageBox>
connection::connection()
{

}
bool connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("SYSTEM");//inserer nom de l'utilisateur
db.setPassword("ADMIN");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
void connection::closeconnection(){db.close();}
