#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "audience.h"
#include <QtGui/QIntValidator>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDoubleValidator>
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QTabWidget>
#include <QtDebug>
#include <QIntValidator>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QPieSlice>
#include "Exel.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{    QString id,type,date;
     id=ui->id->text();
      date=ui->dateEdit->text();

       if(ui->radioButton->isChecked())
           type="Contravention";
       if(ui->radioButton_2->isChecked())
                  type="Delit";
        if(ui->radioButton_3->isChecked())
                   type="Crime";


   audience a(id,date,type);
      bool test=a.ajouter();
       QMessageBox msgBox;
       if(test)
       {
       msgBox.setText("ajout avec succes.");
       ui->tab_etudiant->setModel(a.afficher());
       }
       else
            msgBox.setText("échec d'ajout");
            msgBox.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
QString id=ui->idsupp->text();
qDebug()<<id;
audience a;
bool test=a.supprimer(id);
 QMessageBox msgBox;
 if(test)
 {
 msgBox.setText("supp avec succes.");
 ui->tab_etudiant->setModel(a.afficher());
 }
 else
      msgBox.setText("échec de suppression");

 msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString id,type,date;
         id=ui->id->text();
          date=ui->dateEdit->text();

           if(ui->radioButton->isChecked())
               type="Contravention";
           if(ui->radioButton_2->isChecked())
                      type="Délit";
            if(ui->radioButton_3->isChecked())
                       type="Crime";


       audience a(id,date,type);
          bool test=a.modifier();
           QMessageBox msgBox;
           if(test)
           {
           msgBox.setText("Modification avec succes.");
           ui->tab_etudiant->setModel(a.afficher());
           }
           else
                msgBox.setText("échec de modification");
                msgBox.exec();
}

void MainWindow::on_pushButton_tri_clicked()
{

    audience a;
          ui->tab_etudiant->setModel(a.tri_cin());
         QMessageBox::information(nullptr, QObject::tr("Ok"),
              QObject::tr("tri effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_etudiant->setModel(a.tri_cin());
}

void MainWindow::on_pushButton_Retour_clicked()
{       audience a ;
     ui->tab_etudiant->setModel(a.afficher());
}

void MainWindow::on_pushButton_afficher_clicked()
{    audience a ;
    ui->tab_etudiant->setModel(a.afficher());
}

void MainWindow::on_pushButton_pdf_clicked()
{
QString id ,type,date ;
 id=ui->id->text();
 date=ui->dateEdit->text();
 if(ui->radioButton->isChecked())
     type="Contravention";
 if(ui->radioButton_2->isChecked())
            type="Délit";
  if(ui->radioButton_3->isChecked())
             type="Crime";

  QPdfWriter pdf("C:/Users/oumayma/Documents/CRUD2/audience.pdf");
  QPainter painter(&pdf);


 painter.setPen(Qt::red);
 painter.drawText(4000,400,"Audience N:"+id+"");
 painter.setPen(Qt::black);
 painter.drawText(3000,1500,"type:"+type+"");
 painter.drawText(2000,1000,"Date:"+date+"");
 painter.end();

}




void MainWindow::on_lineEdit_recherche_textChanged()
{   audience a;
    QString rech=ui->lineEdit_recherche->text();
    ui->tab_etudiant->setModel(a.recherche(rech));

}



void MainWindow::on_pushButton_insererimage_clicked()
{


    QFileDialog dialog(this);
        dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
        dialog.setViewMode(QFileDialog::Detail);
        QString fileName = QFileDialog::getOpenFileName(this,
           tr("Open Images"), "", tr("Image Files (*.png *.jpg *.bmp)"));
        if (!fileName.isEmpty())
        {
             QImage image(fileName);
             ui->label5->setPixmap(QPixmap::fromImage(image));

        }
}

void MainWindow::on_pushbuttonExcel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                            tr("Fichiers d'extension Excel (*.xls)"));
            if (fileName.isEmpty())
                return;

            EXCEL obj(fileName, "mydata", ui->tab_etudiant);

            // you can change the column order and
            // choose which colum to export
            obj.addField(0, "id", "char(20)");
            obj.addField(1, "type", "char(20)");
            obj.addField(2, "date", "char(20)");

          int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("FAIS!"),
                                         QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                         );
            }
}

void MainWindow::on_pushButton_QRcode_clicked()
{
    QDesktopServices::openUrl(QUrl("https://qrcode.tec-it.com/fr"));
     QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png )"));
     if (QString::compare(filename,QString()) !=0)
     {
         QImage image;
         bool valid = image.load(filename);
         if(valid)
         {
             image=image.scaledToWidth(ui->label_QR->width(), Qt::SmoothTransformation);
                     ui->label_QR->setPixmap(QPixmap::fromImage(image));
         }
         else
         {
             //ERROR HANDLING
         }
     }
}



void MainWindow::on_radioButton_geo_clicked()
{
    audience a;
    QSqlQueryModel* model=new QSqlQueryModel();
a.geo();
}


void MainWindow::on_stat_clicked()
{

        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from AUDIANCE where ID >= 100");
            float dispo1=model->rowCount();

            model->setQuery("select * from AUDIANCE where ID <100");
            float dispo=model->rowCount();

            float total=dispo1+dispo;
                QString a=QString(" crime. " +QString::number((dispo1*100)/total,'f',2)+"%" );
                QString b=QString(" delit et contravention.  "+QString::number((dispo*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,dispo1);
                series->append(b,dispo);
            if (dispo1!=0)
            {QPieSlice *slice = series->slices().at(0);
                slice->setLabelVisible();
                slice->setPen(QPen());}
            if ( dispo!=0)
            {
                QPieSlice *slice1 = series->slices().at(1);
                slice1->setLabelVisible();
            }

            QChart *chart = new QChart();

            chart->addSeries(series);
            chart->setTitle("type des audiances  par rapport nombre d'id : "+ QString::number(total));
            chart->legend()->hide();

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();


        }
