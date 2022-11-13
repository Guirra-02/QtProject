#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include "avocat.h"
#include<QSqlQueryModel>
#include <QtDebug>
#include <QPainter>
#include <QFile>

#include <QPdfWriter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_username_editingFinished()
{
ui->username->setStyleSheet("background:transparent;border-radius:14px;border:none;color:#b89d64;border-bottom:1px solid #b89d64;");
}

void MainWindow::on_username_textChanged(const QString &arg1)
{
    ui->username->setStyleSheet("border-bottom: 2px solid #b89d64 ;color:#b89d64;font-weight:600;border-radius:0px;");

}


void MainWindow::on_password_textChanged(const QString &arg1)
{
ui->password->setStyleSheet("border-bottom: 2px solid #b89d64 ;color:#b89d64;font-weight:600;border-radius:0px;");
}

void MainWindow::on_password_editingFinished()
{
    ui->password->setStyleSheet("background:transparent;border-radius:14px;border:none;color:#b89d64;border-bottom:1px solid #b89d64;");


}



void MainWindow::on_signup_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_signup_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_signin_clicked()
{QMessageBox msgBox;
    msgBox.setWindowTitle("Something Went Worng");
msgBox.setStyleSheet("background :#b89d64;border-bottom: 2px solid #b89d64 ; font-weight:600;");
    if(ui->username->text()=="admin" && ui->password->text()=="admin")
    {ui->stackedWidget->setCurrentIndex(1);
    }
    else {msgBox.setText("user or password is wrong");
    msgBox.exec();}


}

void MainWindow::on_pushButton_ajouter_clicked()
{QMessageBox msgBox;
    bool test;
    QString id=ui->identifiant->text();
            QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
Avocat a(id,nom,prenom);
test=a.ajouter();


    //msgBox.setText("id existant");


//msgBox.setText("Ajout fait ");
    QMessageBox::information(nullptr,"ajout","ajout faiiit");


ui->Tabetu->setModel(a.afficher());
QMessageBox msg;

}

void MainWindow::on_pushButton_2_clicked()
{
    Avocat a;
    ui->Tabetu->setModel(a.afficher());
    ui->Tabetu->setStyleSheet("background :#b89d64; font-weight:600;");
    ui->label_id->setText(a.getid());
    a.afficher();
}

void MainWindow::on_eliminer_clicked()
{
    Avocat a;
a.setid(ui->idsupp->text());
bool test=a.supprimer(a.getid());
ui->Tabetu->setModel(a.afficher());

}

void MainWindow::on_pushButton_modifier_clicked()
{
    {QMessageBox msgBox; bool test;
        QString id=ui->lineEdit_idup->text();
                QString nom=ui->nom_23->text();
        QString prenom=ui->prenom_24->text();
    Avocat a(id,nom,prenom);
    test=a.modifier(id);
    if(test==false)
    {
        //msgBox.setText("id existant");
        QMessageBox::information(nullptr,"ajout","non effectue");
    }
    else {//msgBox.setText("Ajout fait ");
        QMessageBox::information(nullptr,"modification","mdification faiiiteee");

    }
    ui->Tabetu->setModel(a.afficher());
    QMessageBox msg;

    }
}

void MainWindow::on_pushButton_8_clicked()
{QSqlQuery q;
    QString id,prenom,nom;
    q.exec("select * FROM AVOCATS " );
    id=q.value("ID_AVOCAT").toString();
    prenom=q.value("PRENOM").toString();
    nom=q.value("NOM").toString();

      //QString numtel=ui->space_description_office->text();
     // QString audiance=ui->position_description_office->text();

      QFile file("C:/Users/admin/Documents/qtprojet/22-10-2022/22-10-2022/"+nom+" "+id+""".pdf");
      QPdfWriter pdf("C:/Users/admin/Documents/qtprojet/22-10-2022/22-10-2022/"+nom+" "+id+".pdf");
      QPainter painter(&pdf);
      painter.setPen(Qt::black);
      painter.drawText(3500,1000,"ID_AVOCAT N°: "+ id+"" );
      painter.drawText(3500,1700,"PRENOM Avocat:"+ prenom+"");
      painter.drawText(3500,2500,"Nom Avocat:"+ nom+"");
      //painter.drawText(3500,2100,"Numero telephone :  "+numtel+"" );
     // painter.drawText(3500,2500,"Nombre d'audiance: :  "+audiance+"" );
      painter.end();
}

void MainWindow::on_pushButton_9_clicked()
{
    Avocat a;
    ui->Tabetu->setModel(a.affichageASC());
    ui->Tabetu->setStyleSheet("background :#b89d64; font-weight:600;");
    ui->label_id->setText(a.getid());
    a.affichageASC();

}
