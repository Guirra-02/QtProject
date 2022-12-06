
#include "agent.h"
#include <QSqlQuery>
Agent::Agent()
{
username="";
pass="";
type="";
action="";
}
Agent::Agent(QString u ,QString p,QString t,QString a)
{
username=u;
pass=p;
type=t;
action=a;
}
QString Agent::getid(){
    QSqlQuery qry;
    int action=1;
    QString res1,res=QString::number(action);

    qry.prepare("select * from agent where action='"+res+"' " );
    if(qry.exec())
    {
        while(qry.next())
        {
            res1=qry.value(0).toString();

        }
    }


    return res1;
}
int Agent::role(){
                  QString res1,r=getid();
                  QSqlQuery qry;
                  qry.prepare("select * from agent where username='"+r+"' " );
                  if(qry.exec())
                  {
                      while(qry.next())
                      {
                          res1=qry.value(2).toString();

                      }
                  }
if(res1=="ae"){
return 0;



}
if(res1=="mn"){
    return 1;


}
if(res1=="od"){
    return 2;



}
if(res1=="mg"){
    return 3;



}
if(res1=="db"){
    return 4;



}
else
    return -1;
}
