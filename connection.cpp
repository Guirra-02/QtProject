#include "connection.h"
#include <QMessageBox>
connection::connection()
{

}
bool connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("SOURCE");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("admin");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
void connection::closeconnection(){db.close();}
