#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include "avocat.h"
#include<QSqlQueryModel>
#include <QtDebug>
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
{QString id=ui->identifiant->text();
            QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
Avocat a(id,nom,prenom);
a.ajouter();
ui->Tabetu->setModel(a.afficher());
QMessageBox msg;
msg.setText("Ajout fait ");
msg.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Avocat a;
    ui->Tabetu->setModel(a.afficher());
    ui->Tabetu->setStyleSheet("background :#b89d64; font-weight:600;");
    a.afficher();

}

void MainWindow::on_eliminer_clicked()
{
    Avocat a;
a.setid(ui->idsupp->text());
bool test=a.supprimer(a.getid());
ui->Tabetu->setModel(a.afficher());

}
