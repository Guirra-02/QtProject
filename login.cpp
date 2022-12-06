#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "QSqlQuery"
#include "historique.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix_e("D:/2eme annee/1ere semestre/projet c++/menu1/image/ec 1.png");
    ui->label_e->setPixmap(pix_e.scaled(55,55,Qt::KeepAspectRatio));
}

Login::~Login()
{
    delete ui;
}
Login::Login(QString user,QString pass){
    username=user;
    password=pass;


}
void Login::on_pushButton_clicked()
{
    QString user = ui->username->text();
    QString pass = ui->password->text();
    Login L(user,pass);
    if (L.auth()){
        hide();
        mainwindow = new MainWindow(this);
        mainwindow->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

      mainwindow ->show();
        }

}



bool Login::auth(){
    bool test = false;
    QSqlQuery query1,qry;
    printf("possible");
query1.prepare("select * from agent where username=:email");
query1.bindValue(":email",username);
if(query1.exec()){
    query1.next();
    if(query1.value(1).toString() == password){
         test = 2;
         int action=1;
         QString res=QString::number(action);
         query1.prepare("UPDATE agent "" SET action=:action  where username='"+username+"' ");
           query1.bindValue(":action",res);
           query1.exec();
           historique h(username,"connecter ",QDateTime::currentDateTime());
           qry.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
           qry.bindValue(":USERNAME", h.getuser());
           qry.bindValue(":ACTION", h.getaction());
           qry.bindValue(":DATEH", h.getdateh());
           qry.exec();

    }else {
         test = 0;

    }
}else {
    test = 0;
}
return test;

}
//***********************************************************ec/eo
void Login::on_pushButton_2_clicked()
{
    if(ui->password->echoMode()==2){
       ui->password->setEchoMode(QLineEdit::Normal);
       QPixmap pix_e("D:/2eme annee/1ere semestre/projet c++/menu1/image/ec 1.png");
       ui->label_e->setPixmap(pix_e.scaled(55,55,Qt::KeepAspectRatio));
    }
    else{
        ui->password->setEchoMode(QLineEdit::Password);
        QPixmap pix_e("D:/2eme annee/1ere semestre/projet c++/menu1/image/eo 1.png");
        ui->label_e->setPixmap(pix_e.scaled(55,55,Qt::KeepAspectRatio));
    }
}
//************************************************************
