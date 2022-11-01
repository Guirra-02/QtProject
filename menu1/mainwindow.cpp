#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include"archive.h"
#include<QSqlQuery>
#include <QMessageBox>
#include<QTextStream>
#include<QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/2eme annee/1ere semestre/projet c++/logo.png");
    QPixmap pix_ihome("D:/2eme annee/1ere semestre/projet c++/homew.png");
    QPixmap pix_iarchive("D:/2eme annee/1ere semestre/projet c++/archiverw.png");
    QPixmap pix_ijuge("D:/2eme annee/1ere semestre/projet c++/jugew.png");
    QPixmap pix_isalle("D:/2eme annee/1ere semestre/projet c++/sallew.png");
    QPixmap pix_iavocat("D:/2eme annee/1ere semestre/projet c++/avocatw.png");
     QPixmap pix_iaudience("D:/2eme annee/1ere semestre/projet c++/audiencew.png");
   // D:/2eme annee/1ere semestre/projet c++/home.png
    ui->logo->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));

ui->label_ihome->setPixmap(pix_ihome.scaled(50,50,Qt::KeepAspectRatio));
ui->label_iarchive->setPixmap(pix_iarchive.scaled(50,50,Qt::KeepAspectRatio));
ui->label_ijuge->setPixmap(pix_ijuge.scaled(50,50,Qt::KeepAspectRatio));
ui->label_isalle->setPixmap(pix_isalle.scaled(50,50,Qt::KeepAspectRatio));
ui->label_iavocat->setPixmap(pix_iavocat.scaled(50,50,Qt::KeepAspectRatio));
ui->label_iaudience->setPixmap(pix_iaudience.scaled(60,60,Qt::KeepAspectRatio));
    //ui->noir->setPixmap(pic.scaled(1000,800,Qt::KeepAspectRatio));
   ui->logo->show();
ui->label_home->show();
ui->label_j->hide();
ui->label_aud->hide();
ui->label_ar->hide();
ui->label_salle->hide();
ui->label_avocat->hide();
etmp.login_modifier_afficher_tab(ui);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_home_clicked()
{
    ui->pushButton_home->setChecked(true);
    ui->pushButton_juge->setChecked(false);
        ui->pushButton_audience->setChecked(false);
        ui->pushButton_affaires->setChecked(false);
        ui->pushButton_salles->setChecked(false);
        ui->pushButton_avocat->setChecked(false);
        ui->logo->show();
        ui->label_home->show();
        ui->label_j->hide();
        ui->label_aud->hide();
        ui->label_ar->hide();
        ui->label_salle->hide();
        ui->label_avocat->hide();

}

void MainWindow::on_pushButton_juge_clicked()
{
   ui->pushButton_home->setChecked(false);
    ui->pushButton_juge->setChecked(true);
        ui->pushButton_audience->setChecked(false);
        ui->pushButton_affaires->setChecked(false);
        ui->pushButton_salles->setChecked(false);
        ui->pushButton_avocat->setChecked(false);
        ui->logo->hide();
ui->label_home->hide();
ui->label_j->show();
ui->label_aud->hide();
ui->label_ar->hide();
ui->label_salle->hide();
ui->label_avocat->hide();

}

void MainWindow::on_pushButton_audience_clicked()
{
    ui->pushButton_home->setChecked(false);

    ui->pushButton_juge->setChecked(false);
        ui->pushButton_audience->setChecked(true);
        ui->pushButton_affaires->setChecked(false);
        ui->pushButton_salles->setChecked(false);
        ui->pushButton_avocat->setChecked(false);
        ui->logo->hide();
        ui->label_home->hide();
        ui->label_j->hide();
        ui->label_aud->show();
        ui->label_ar->hide();
        ui->label_salle->hide();
        ui->label_avocat->hide();


}

void MainWindow::on_pushButton_affaires_clicked()
{
    ui->pushButton_home->setChecked(false);

    ui->pushButton_juge->setChecked(false);
        ui->pushButton_audience->setChecked(false);
        ui->pushButton_affaires->setChecked(true);
        ui->pushButton_salles->setChecked(false);
        ui->pushButton_avocat->setChecked(false);
        ui->logo->hide();
         ui->label_home->hide();
        ui->label_j->hide();
        ui->label_aud->hide();
        ui->label_ar->show();
        ui->label_salle->hide();
        ui->label_avocat->hide();
        etmp.login_modifier_afficher_tab(ui);

}

void MainWindow::on_pushButton_salles_clicked()
{
   ui->pushButton_home->setChecked(false);

    ui->pushButton_juge->setChecked(false);
        ui->pushButton_audience->setChecked(false);
        ui->pushButton_affaires->setChecked(false);
        ui->pushButton_salles->setChecked(true);
        ui->pushButton_avocat->setChecked(false);
        ui->logo->hide();
        ui->label_home->hide();
        ui->label_j->hide();
        ui->label_aud->hide();
        ui->label_ar->hide();
        ui->label_salle->show();
        ui->label_avocat->hide();

}




void MainWindow::on_pushButton_avocat_clicked()
{
    ui->pushButton_home->setChecked(false);

       ui->pushButton_juge->setChecked(false);
           ui->pushButton_audience->setChecked(false);
           ui->pushButton_affaires->setChecked(false);
           ui->pushButton_salles->setChecked(false);
           ui->pushButton_avocat->setChecked(true);
            ui->logo->hide();
           ui->label_home->hide();
           ui->label_j->hide();
           ui->label_aud->hide();
           ui->label_ar->hide();
           ui->label_salle->hide();
           ui->label_avocat->show();

}

void MainWindow::on_pushButton_ajouter_arch_clicked()
{
    int numarch=ui->lineEdit->text().toInt();
    QString typecrime=ui->comboBox->currentText();
    QString rapport="GAGAGAG";
      QString jugementfinal=ui->comboBox_2->currentText();
    archive A(numarch,typecrime,rapport,jugementfinal);
    bool test=A.ajouter();
    if (test)
    {
       // ui->tableView->setModel(etmp.afficher());
        etmp.login_modifier_afficher_tab(ui);

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    etmp.login_modifier_afficher_tab(ui);

}

void MainWindow::on_pushButton_supprimer_arch_clicked()
{
  int numarch=ui->lineEdit_2->text().toInt();
  bool test=etmp.supprimer(numarch);
  if(test){
      etmp.login_modifier_afficher_tab(ui);
  }
}

void MainWindow::on_pushButton_modifier_arch_clicked()
{
    int id1=44;  //indice
    int numarch=ui->lineEdit->text().toInt();
        QString typeCrime=ui->comboBox->currentText();
        QString rapport="sbehelkhir";
        QString jugementFinal=ui->comboBox_2->currentText();
        archive ar(numarch,typeCrime,rapport,jugementFinal);
        bool test=ar.modifier(id1);



    etmp.login_modifier_afficher_tab(ui);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();

        QSqlQuery qry;
        qry.prepare("select * from AFFAIRE_JURIDIQUE1 where numarch='"+val+"' ");


        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit->setText(qry.value(0).toString());
                ui->comboBox_2->setCurrentText(qry.value(3).toString());
                ui->textEdit->setText(qry.value(2).toString());
                ui->comboBox->setCurrentText(qry.value(1).toString());

            }
    }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString text=ui->lineEdit_2->text();

        if(text.isEmpty())
        {
            etmp.login_modifier_afficher_tab(ui);

        }
        else
        {
            qry->prepare("select * from AFFAIRE_JURIDIQUE1 where numarch='"+text+"'"); //like
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView->setModel(modal);
        }
}

void MainWindow::on_pushButton_clicked()
{




            QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView->model()->rowCount();
            const int columnCount = ui->tableView->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("col1")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<table border=1 cellspacing=0 cellpadding=2>\n";

            // headers
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView->isColumnHidden(column)) {
                        QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;

}

void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString type=ui->comboBox_3->currentText();
        if (type=="Par defaut"){
            qry->prepare("select * from AFFAIRE_JURIDIQUE1");
            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("rapport"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("jugementFinal"));
            ui->tableView->setModel(model);}
            else if (type=="Numero archive"){
            qry->prepare("select * from AFFAIRE_JURIDIQUE1 order by numarch");
            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("rapport"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("jugementFinal"));
                ui->tableView->setModel(model);


            }
            else if (type=="type crime"){
            qry->prepare("select * from AFFAIRE_JURIDIQUE1 order by typeCrime");
            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("rapport"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("jugementFinal"));
                ui->tableView->setModel(model);


            }
            else if (type=="jugement Final"){
            qry->prepare("select * from AFFAIRE_JURIDIQUE1 order by jugementFinal");
            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("rapport"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("jugementFinal"));
                ui->tableView->setModel(model);


            }
}
