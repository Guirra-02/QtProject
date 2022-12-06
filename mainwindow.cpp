#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include"archive.h"
#include<QDate>
#include<iostream>
#include<QDialog>
#include<QSqlQuery>
#include <QMessageBox>
#include<QTextStream>
#include<QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QGraphicsDropShadowEffect>
#include<QPieSlice>
#include<QPieSeries>
#include<QLineSeries>
#include"smtp.h"
#include"notepad.h"
#include "notification.h"
#include "agent.h"
#include <QCloseEvent>
#include "historique.h"
#include "audience.h"
#include "connection.h"

using namespace std;
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
    ui->logo->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
    //***************************************************************************************************************login
    Agent a;
    QString res1,r=a.getid();
    QSqlQuery qry;
    qry.prepare("select * from agent where username='"+r+"' " );
    if(qry.exec())
    {
        while(qry.next())
        {
            res1=qry.value(2).toString();

        }
    }
    if(res1=="Directer"){
        ui->tableView_4->setModel(hismp.afficher());

        ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);}
    else{
        ui->tableView_4->setModel(hismp.afficheragent(a.getid()));

        ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);}
//************************************************************************************************************
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
ui->groupBox_cud_arch->hide();
ui->groupBox_r_arch->hide();
ui->tabWidget_arch->hide();
ui->tabWidget_audience->hide();//hide houni
etmp.login_modifier_afficher_tab(ui);
//*************************************************************
QGraphicsDropShadowEffect *effect1 = new QGraphicsDropShadowEffect;
    effect1->setBlurRadius(20);
    effect1->setXOffset(2);
    effect1->setYOffset(2);
    effect1->setColor(Qt::lightGray);
    QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect;
        effect2->setBlurRadius(20);
        effect2->setXOffset(2);
        effect2->setYOffset(2);
        effect2->setColor(Qt::lightGray);

ui->groupBox_cud_arch->setGraphicsEffect(effect1);

ui->groupBox_r_arch->setGraphicsEffect(effect2);
//***********************************************************************************************

connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
//**************************************************************************************************
 //ui->lineEdit->setValidator( new QIntValidator("[1-9]", this));
QRegularExpression regex0("^[0-9_]*$");
QValidator *validator0 = new QRegularExpressionValidator(regex0, this);
ui->lineEdit->setValidator(validator0);
 QRegularExpression regex("^[a-zA-Z_]*$");
 QValidator *validator = new QRegularExpressionValidator(regex, this);
 ui->lineEdit_3->setValidator(validator);
 popUp= new PopUp();
 notif();
  QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r1.png");
  int wr=ui->label_help->width(),hr=ui->label_help->height();
  ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
//************************************************************************************
  if(a.role()==0){
      ui->pushButton_avocat->hide();
      ui->pushButton_juge->hide();
      ui->pushButton_audience->hide();
      ui->pushButton_salles->hide();
     // ui->pushButton_12->hide();
     // ui->pushButton_17->setGeometry(-109,308,362,100);
      ui->pushButton_home->setGeometry(0,290,251,31);
      ui->label_ihome->setGeometry(60,270,81,71);
      ui->label_home->setGeometry(0,280,21,51);
      ui->pushButton_affaires->setGeometry(0,380,251,31);
      ui->pushButton_supphistorique->hide();

      ui->label_iarchive->setGeometry(60,360,81,71);
      ui->label_ar->setGeometry(0,370,21,51);
      ui->label_aud->hide();

      ui->label_j->hide();
      ui->label_salle->hide();
      ui->label_avocat->hide();
      ui->label_isalle->hide();
      ui->label_iavocat->hide();
      ui->label_iaudience->hide();
      ui->label_ijuge->hide();
      // ui->pushButton_supphistorique->hide();

  }
  if(a.role()==1){
      ui->pushButton_supphistorique->hide();

      ui->pushButton_avocat->hide();
      ui->pushButton_affaires->hide();
      ui->pushButton_audience->hide();
      ui->pushButton_salles->hide();
     // ui->pushButton_12->hide();
     // ui->pushButton_17->setGeometry(-109,308,362,100);
      ui->pushButton_home->setGeometry(0,290,251,31);
      ui->label_ihome->setGeometry(60,270,81,71);
      ui->label_home->setGeometry(0,280,21,51);
      ui->pushButton_juge->setGeometry(0,380,251,31);
      ui->label_ijuge->setGeometry(60,360,81,71);
      ui->label_j->setGeometry(0,370,21,51);
      ui->label_ar->hide();
      ui->label_aud->hide();
      ui->label_salle->hide();
      ui->label_avocat->hide();
      ui->label_isalle->hide();
      ui->label_iavocat->hide();
      ui->label_iaudience->hide();
      ui->label_iarchive->hide();
     // ui->pushButton_supphistorique->hide();


  }
  if(a.role()==2){
      ui->pushButton_supphistorique->hide();

      ui->pushButton_avocat->hide();
      ui->pushButton_affaires->hide();
      ui->pushButton_juge->hide();
      ui->pushButton_salles->hide();
      ui->pushButton_home->setGeometry(0,290,251,31);
      ui->label_ihome->setGeometry(60,270,81,71);
      ui->label_home->setGeometry(0,280,21,51);
      ui->pushButton_audience->setGeometry(0,380,251,31);
      ui->label_iaudience->setGeometry(60,360,81,71);
      ui->label_aud->setGeometry(0,370,21,51);
     // ui->pushButton_12->hide();
     // ui->pushButton_17->setGeometry(-109,308,362,100);
      ui->label_ar->hide();
      ui->label_j->hide();
      ui->label_salle->hide();
      ui->label_avocat->hide();
      ui->label_isalle->hide();
      ui->label_iavocat->hide();
      ui->label_ijuge->hide();
      ui->label_iarchive->hide();
      // ui->pushButton_supphistorique->hide();

  }
  if(a.role()==3){
      ui->pushButton_juge->hide();
      ui->pushButton_affaires->hide();
      ui->pushButton_audience->hide();
      ui->pushButton_salles->hide();
      ui->pushButton_home->setGeometry(0,290,251,31);
      ui->label_ihome->setGeometry(60,270,81,71);
      ui->label_home->setGeometry(0,280,21,51);
      ui->pushButton_avocat->setGeometry(0,380,251,31);
      ui->label_iavocat->setGeometry(60,360,81,71);
      ui->label_avocat->setGeometry(0,370,21,51);
     // ui->pushButton_12->hide();
     // ui->pushButton_17->setGeometry(-109,308,362,100);
      ui->label_ar->hide();
      ui->label_aud->hide();
      ui->label_salle->hide();
      ui->label_j->hide();
      ui->label_isalle->hide();
      ui->label_ijuge->hide();
      ui->label_iaudience->hide();
      ui->label_iarchive->hide();
      // ui->pushButton_supphistorique->hide();
      ui->pushButton_supphistorique->hide();


  }
  if(a.role()==4){
      ui->pushButton_avocat->hide();
      ui->pushButton_affaires->hide();
      ui->pushButton_audience->hide();
      ui->pushButton_juge->hide();
      ui->pushButton_home->setGeometry(0,290,251,31);
      ui->label_ihome->setGeometry(60,270,81,71);
      ui->label_home->setGeometry(0,280,21,51);
      ui->pushButton_salles->setGeometry(0,380,251,31);
      ui->label_isalle->setGeometry(60,360,81,71);
      ui->label_salle->setGeometry(0,370,21,51);
     // ui->pushButton_12->hide();
     // ui->pushButton_17->setGeometry(-109,308,362,100);
      ui->label_ar->hide();
      ui->label_aud->hide();
      ui->label_j->hide();
      ui->label_avocat->hide();
      ui->label_ijuge->hide();
      ui->label_iavocat->hide();
      ui->label_iaudience->hide();
      ui->label_iarchive->hide();
      // ui->pushButton_supphistorique->hide();
      ui->pushButton_supphistorique->hide();


  }
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
        ui->groupBox_cud_arch->hide();
        ui->groupBox_r_arch->hide();
        ui->tabWidget_arch->hide();
        ui->tableView_audience->hide();//hide hounii

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
ui->groupBox_cud_arch->hide();
ui->groupBox_r_arch->hide();
ui->tabWidget_arch->hide();
ui->tabWidget_audience->hide();//hide houni
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
        ui->groupBox_cud_arch->hide();
        ui->groupBox_r_arch->hide();
        ui->tabWidget_arch->hide();
        ui->tabWidget_audience->show();//houni show

}

void MainWindow::on_pushButton_affaires_clicked()
{
     notif();
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
        ui->groupBox_cud_arch->show();
        ui->groupBox_r_arch->show();
        ui->tabWidget_arch->show();
        ui->tabWidget_audience->hide();
        //***********************************************************************************

        //************************************************************************************











            //**********************************************************************************
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
        ui->tabWidget_arch->hide();
        ui->tabWidget_audience->hide();

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
           ui->groupBox_cud_arch->hide();
           ui->groupBox_r_arch->hide();
           ui->tabWidget_arch->hide();
           ui->tabWidget_audience->hide();

}

void MainWindow::on_pushButton_ajouter_arch_clicked()
{
    int numarch=ui->lineEdit->text().toInt();
    QString typecrime=ui->comboBox->currentText();
    QDate dateCrime=ui->dateTimeEdit->date();
    QString lieuCrime=ui->lineEdit_3->text();
      QString jugementfinal=ui->comboBox_2->currentText();
    archive A(numarch,typecrime,dateCrime,lieuCrime,jugementfinal);
    bool test=A.ajouter();
    if (test)
    {
       // ui->tableView->setModel(etmp.afficher());
        etmp.login_modifier_afficher_tab(ui);
        QSqlQuery query;
        Agent a;

               historique h(a.getid(),"ajouter une archive de num : "+ui->lineEdit->text(),QDateTime::currentDateTime());
        query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
        query.bindValue(":USERNAME", h.getuser());
        query.bindValue(":ACTION", h.getaction());
        query.bindValue(":DATEH", h.getdateh());
        ui->lineEdit->setText("");
        ui->lineEdit_3->setText("");
       // query.bindValue(":num_serie", num_serie);
        //query.bindValue(":id_pilote", id_pilote);
query.exec();
       /* QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué \n""Click Cancel to exit"),QMessageBox::Cancel);*/
    }
    else
       /* QMessageBox::critical(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);*/
    etmp.login_modifier_afficher_tab(ui);

}

void MainWindow::on_pushButton_supprimer_arch_clicked()
{
    QModelIndex index=ui->tableView->currentIndex();
    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();
  bool test=etmp.supprimer(val);
  if(test){
      etmp.login_modifier_afficher_tab(ui);
      QSqlQuery query;
      Agent a;

             historique h(a.getid(),"supprimer une archive de num : "+ui->lineEdit->text(),QDateTime::currentDateTime());
      query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
      query.bindValue(":USERNAME", h.getuser());
      query.bindValue(":ACTION", h.getaction());
      query.bindValue(":DATEH", h.getdateh());
      ui->lineEdit->setText("");
      ui->lineEdit_3->setText("");
  }
}

void MainWindow::on_pushButton_modifier_arch_clicked()
{
    int id1=44;  //indice
    int numarch=ui->lineEdit->text().toInt();
        QString typeCrime=ui->comboBox->currentText();
        QDate dateCrime=ui->dateTimeEdit->date();
        QString lieuCrime=ui->lineEdit_3->text();
        QString jugementFinal=ui->comboBox_2->currentText();
        archive ar(numarch,typeCrime,dateCrime,lieuCrime,jugementFinal);

        bool test=ar.modifier(id1);

if (test){

    etmp.login_modifier_afficher_tab(ui);
    QSqlQuery query;
    Agent a;

           historique h(a.getid(),"modifier une archive de num : "+ui->lineEdit->text(),QDateTime::currentDateTime());
    query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
    query.bindValue(":USERNAME", h.getuser());
    query.bindValue(":ACTION", h.getaction());
    query.bindValue(":DATEH", h.getdateh());
    ui->lineEdit->setText("");
    ui->lineEdit_3->setText("");}
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();


        QSqlQuery qry;
        qry.prepare("select * from AFFAIRE where numarch='"+val+"' ");


        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit->setText(qry.value(0).toString());

                ui->comboBox->setCurrentText(qry.value(1).toString());
                 ui->dateTimeEdit->setDate(qry.value(2).toDate());
                ui->lineEdit_3->setText(qry.value(3).toString());
                  ui->comboBox_2->setCurrentText(qry.value(4).toString());


            }
    }
}
//**************************************************************************recherche
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

          qry->prepare ("SELECT * from AFFAIRE where ( numarch LIKE'%"+text+"%' OR typeCrime LIKE'%"+text+"%' OR jugementFinal LIKE'%"+text+"%' OR lieuCrime LIKE'%"+text+"%') ");
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView->setModel(modal);
        }
}
//******************************************************************************pdf
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
//**********************************************************************tri
void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString type=ui->comboBox_3->currentText();
        if (type=="Par defaut"){
            qry->prepare("select * from AFFAIRE");
            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
             model->setHeaderData(2,Qt::Horizontal,QObject::tr("dateCrime"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("lieuCrime"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("jugementFinal"));
            ui->tableView->setModel(model);}
            else if (type=="Numero archive"){
            qry->prepare("select * from AFFAIRE order by numarch");
            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("dateCrime"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("lieuCrime"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("jugementFinal"));
                ui->tableView->setModel(model);


            }
            else if (type=="type crime"){
            qry->prepare("select * from AFFAIRE order by typeCrime");
            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("dateCrime"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("lieuCrime"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("jugementFinal"));
                ui->tableView->setModel(model);


            }
            else if (type=="jugement Final"){
            qry->prepare("select * from AFFAIRE order by jugementFinal");
            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numarch"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("TypeCrime"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("dateCrime"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("lieuCrime"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("jugementFinal"));
                ui->tableView->setModel(model);


            }
}



//**************************************************************************** stat pie
void MainWindow::on_tabWidget_arch_currentChanged(int index)
{
    QSqlQuery q2,q3,q4,q5;
                qreal tot=0,c1=0,c2=0,c3=0,c4=0;

                //q1.prepare("SELECT * FROM AFFAIRE");
               // q1.exec();

                q2.prepare("SELECT * FROM AFFAIRE WHERE TypeCrime='violence'");
                q2.exec();

                q3.prepare("SELECT * FROM AFFAIRE WHERE TypeCrime='vole'");
                q3.exec();

                q4.prepare("SELECT * FROM AFFAIRE WHERE TypeCrime='viole' ");
                q4.exec();

                q5.prepare("SELECT * FROM AFFAIRE WHERE TypeCrime='assasignation' ");
                q5.exec();

                //while (q1.next()){tot++;}
                while (q2.next()){c1++;}
                while (q3.next()){c2++;}
                while (q4.next()){c3++;}
                while (q5.next()){c4++;}
               QPieSeries *series=new QPieSeries();


                series->append("violence",c1);
                series->append("vole",c2);
                series->append("viole",c3);
                series->append("assasignation",c4);


               QPieSlice *slice = series->slices().at(3);
                 slice->setExploded(true);
                 //slice->setPen(QPen(Qt::darkGreen, 2));
                 //slice->setBrush(Qt::green);
                QChart *chart =new QChart();

                chart->addSeries(series);

                chart->setTitle("Nombre de crime d'assasignation par rapport au autre crime ");
                QChartView *chartView=new QChartView(chart);

                chartView = new QChartView(chart,ui->horizontalFrame);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->setMinimumSize(561,331);

                if(c1>c2 && c1>c3 && c1>c4){
                QString type="violence";
                 QString max=QString::number(c1);
                 ui->lineEdit_4->setText(type);
                 ui->lineEdit_5->setText(max);
                }
                    else if (c2>c1 && c2>c3 && c2>c4) {
                    QString type="vole";
                     QString max=QString::number(c2);
                     ui->lineEdit_4->setText(type);
                     ui->lineEdit_5->setText(max);
                }else if (c3>c1 && c3>c2 && c3>c4) {
                    QString type="viole";
                     QString max=QString::number(c3);
                     ui->lineEdit_4->setText(type);
                     ui->lineEdit_5->setText(max);
                }else{
                    QString type="assasignation";
                     QString max=QString::number(c4);
                     ui->lineEdit_4->setText(type);
                     ui->lineEdit_5->setText(max);


                }
                if(c1<c2 && c1<c3 && c1<c4){
                QString type="violence";
                 QString max=QString::number(c1);
                 ui->lineEdit_7->setText(type);
                 ui->lineEdit_6->setText(max);
                }
                    else if (c2<c1 && c2<c3 && c2<c4) {
                    QString type="vole";
                     QString max=QString::number(c2);
                     ui->lineEdit_7->setText(type);
                     ui->lineEdit_6->setText(max);
                }else if (c3<c1 && c3<c2 && c3<c4) {
                    QString type="viole";
                     QString max=QString::number(c3);
                     ui->lineEdit_7->setText(type);
                     ui->lineEdit_6->setText(max);
                }else{
                    QString type="assasignation";
                     QString max=QString::number(c4);
                     ui->lineEdit_7->setText(type);
                     ui->lineEdit_6->setText(max);


                }

                tot = c1+c2+c3+c4;
                                      QString t=QString::number(c1+c2+c3+c4);
                                      QString p1=QString::number(c1/tot*100, 'f', 2)+"%";
                                      QString p2=QString::number(c2/tot*100, 'f', 2)+"%";
                                      QString p3=QString::number(c3/tot*100, 'f', 2)+"%";
                                      QString p4=QString::number(c4/tot*100, 'f', 2)+"%";

                                      ui->lineEdit_p1->setText(p1);
                                      ui->lineEdit_p2->setText(p2);
                                      ui->lineEdit_p3->setText(p3);
                                      ui->lineEdit_p4->setText(p4);

                                      ui->lineEdit_p5->setText(t);





 //*************************************************** stat line

                QSqlQuery l1,l2,l3,l4,l5,l6;
                            qreal b0=0,b1=0,b2=0,b3=0,b4=0,b5=0;
                            //QDate date;
                            int d1=2020;
                            int d2=2022;
                            int d3=2024;
                            int d4=2026;
                            int d5=2028;
                            int d6=2030;
                            //QString x1=QString::number(x.month()),x2=QString::number(x.day()),x3=QString::number(x.year());
                            //model->setQuery("select * from AFFAIRE where(extract(day  from dateCrime)='"+x2+"' and extract(month  from dateCrime)='"+x1+"' and extract(year  from dateCrime)='"+x3+"')");
                            l1.prepare("select * from AFFAIRE where extract(year from dateCrime)=:d1 ");
                            l1.bindValue(":d1",d1);
                            l1.exec();

                            l2.prepare("select * from AFFAIRE where extract(year from dateCrime)=:d2");
                               l2.bindValue(":d2",d2);
                            l2.exec();

                            l3.prepare("select * from AFFAIRE where extract(year from dateCrime)=:d3");
                               l3.bindValue(":d3",d3);
                            l3.exec();

                            l4.prepare("select * from AFFAIRE where extract(year from dateCrime)=:d4");
                               l4.bindValue(":d4",d4);
                            l4.exec();
                            l5.prepare("select * from AFFAIRE where extract(year from dateCrime)=:d5");
                               l5.bindValue(":d5",d5);
                            l5.exec();
                            l6.prepare("select * from AFFAIRE where extract(year from dateCrime)=:d6");
                               l6.bindValue(":d6",d6);
                            l6.exec();

//                            model->setQuery("select * count from AFFAIRE where dateCrime like '"+x3+"'");
                            while (l1.next()){b0++;}
                            while (l2.next()){b1++;}
                            while (l3.next()){b2++;}
                            while (l4.next()){b3++;}
                            while (l5.next()){b4++;}
                            while (l6.next()){b5++;}
                QLineSeries *series1=new QLineSeries;
                series1->append(0,b0);
                series1->append(2,b1);

                series1->append(4,b2);

                series1->append(6,b3);
                  series1->append(8,b4);
                series1->append(10,b5);

                *series1<<QPointF(11,1)<<QPointF(13,3)<<QPointF(17,6)<<QPointF(18,3)<<QPointF(20,2);
                QChart *chart1 =new QChart();
                //chart->legend()->hide();
                chart1->addSeries(series1);
                chart1->createDefaultAxes();
                chart1->legend()->setVisible(true);
                chart1->legend()->setAlignment(Qt::AlignBottom);
                chart1->setTitle("Nombre de crime entre 2020 et 2030 ");
                QChartView *chartView1=new QChartView(chart1);
                chartView1->setRenderHint(QPainter::Antialiasing);
                //ui->horizontalFrame->setFrameShadow();
                chartView1->setParent(ui->horizontalFrame1);

                chartView1 = new QChartView(chart1,ui->horizontalFrame1);
                chartView1->setRenderHint(QPainter::Antialiasing);
                chartView1->setMinimumSize(700,290);



}
//*****************************************************************************************upload image



void MainWindow::on_pushButton_2_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png)");

      QFileInfo info(imageFile);
    QFileInfo  filename = info.fileName(); //path de l'image

    QPixmap image (imageFile);
      ui->upimage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );//
      image = image.scaled(110,110,Qt::IgnoreAspectRatio,Qt::FastTransformation);
      ui->upimage->setPixmap(image);
      ui->upimage->show();
     // qDebug() << image <<endl << imageFile <<endl<<info.fileName();
qDebug()<<QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();

//************************************************************************************************************************upload fichier

}

void MainWindow::on_pushButton_3_clicked()
{
  files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->urlpdf->setText( fileListString );
    QPixmap image2("D:/2eme annee/1ere semestre/projet c++/menu1/1111.png");
    ui->uppdf->setPixmap(image2);
}
//****************************************************************************mail
void  MainWindow::browse()
{
    //files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("achref.essefi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("achref.essefi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("achref.essefi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}




void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
//******************************************************************************************************* calander
void MainWindow::on_calendarWidget_selectionChanged()
{
    QString x=ui->calendarWidget->selectedDate().toString();
     QDate x1=ui->calendarWidget->selectedDate();
    ui->lineEdit_calendar_affichage->setText(x);
    ui->tableView_calendar->setModel(etmp.afficher_calendar(x1));
//ui->calendarWidget->setPalette();
}

//****************************************************************************************************notepad
void MainWindow::on_pushButton_4_clicked()
{

   note=new notepad();
   note->show();
}
//****************************************************************************************************notif
void MainWindow::notif()
{

   int d=QDate::currentDate().day();
   int m=QDate::currentDate().month();
   int y=QDate::currentDate().year();

        QSqlQuery query;
        query.prepare("select dateCrime,numarch,typeCrime,lieuCrime,jugementFinal from AFFAIRE  where extract(month  from dateCrime)=:month and extract(day  from dateCrime)=:day and extract(year  from dateCrime)=:year ");
     query.bindValue(":day",d);
     query.bindValue(":month",m);
     query.bindValue(":year",y);

        query.exec();

//query.next();

    while  (query.next())
     {
       QString dateC=query.value(0).toString();
       QString cordonnernum=query.value(1).toString();
       QString cordonnertype=query.value(2).toString();
       QString cordonnerlieu=query.value(3).toString();
       QString cordonnerjugement=query.value(4).toString();

if(dateC!="")

    popUp->setPopupText(" votre crime :\n "+cordonnernum+"  "+cordonnertype+ "  est  a "+cordonnerlieu+" , jugement final : "+cordonnerjugement);


else
    popUp->setPopupText("pas des crimes toujours\n");


popUp->show();
query.next();

     }
}
//*****************************************************************************chat bot
void MainWindow::on_pushButton_5_clicked()
{
    QString text,space="";
      QString msg=ui->input->text();
      ui->output->appendPlainText(space);
      ui->output->appendPlainText(msg);
      ui->input->clear();
      QString chemin;



      if(msg=="hi"||msg=="hey"||msg=="yo"){
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r1.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Hello user, i'm B.E.M.O your chat assistant you can call me Bemo 🙂 ";

      }
      else if(msg=="hello"||msg=="hallo"||msg=="heyo"||msg=="sup")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r1.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));

          text="hey there , how are you feeling today? ";
      }
      else if(msg=="help"||msg=="bemo")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r6.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text=" what's wrong? How can i help you?";
      }
      else if(msg=="calculator" ||msg=="calcul")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r5.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text=" Oh sorry ,i can't do maths but there's already a scientific calculator in the finance space";
      }
      else if(msg=="how are you" ||msg=="hru")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r2.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="I'm great thank you for asking and how are you! I hope you're doing great";
      }
      else if(msg=="good" ||msg=="great"||msg=="i'm great"||msg=="i'm good"||msg=="doing great")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r2.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));

          text="Good to hear dear employee, have a good day";
      }//***************************************************************************************************************************************
      else if(msg=="add an archive " ||msg=="add")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Go to ""Traiter les donnés d'archive"" and write his information then click ajouter";
      }
      else if(msg=="modify" ||msg=="modifie"||msg=="update")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Go to ""Traiter les donnés d'archive"" click on the table at the person that you want change his information  rewrite his information click modifier";
      }
      else if(msg=="supprimer" ||msg=="delete")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Go to ""Traiter les donnés d'archive"" click on the table at the person that you want delete it click supprimer";
      }
      else if(msg=="how to upload an image " ||msg=="image")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Go to ""Traiter les donnés d'archive"" and click on the button ""upload Image""";
      }
      else if(msg=="how to generate a pdf" ||msg=="pdf")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Go to ""Traiter les donnés d'archive"" and click on the button ""imprimer""";
      }
      else if(msg=="stat"||msg=="where can i find stat"||msg=="where stat" )
            {
                QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
                int wr=ui->label_help->width(),hr=ui->label_help->height();
                ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
                text="go to stat you can find two types of chat piechart and linechart";
            }
      else if(msg=="mail"||msg=="how can i send a mail"||msg=="how to use mail" )
            {
                QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
                int wr=ui->label_help->width(),hr=ui->label_help->height();
                ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
                text="step1:one go to    step2:write your password mail the email of the recepient then the email      step3:click envoyer ";
            }
      else if(msg=="agenda"||msg=="how can i see tasks of tommorow"||msg=="how to use agenda" )
            {
                QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
                int wr=ui->label_help->width(),hr=ui->label_help->height();
                ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
                text="go to agenda  then click on the date that you want to see their tasks ";
            }

      //****************************************************************************************************************************
      else if(msg=="sorry" ||msg=="excuse me")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r2.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Don't worry about it friend";
      }
      else if(msg=="tell me" ||msg=="talk")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r2.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="What do you want to talk about mate? need help in somthing? or just company?";
      }
      else if(msg=="money" ||msg=="salary")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r3.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="We all want money don't we? work hard until you deserve it!";
      }
      else if(msg=="bored" ||msg=="i'm bored"||msg=="i'm tired"||msg=="tired")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r7.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Sorry for that , a cup of coffee would help i guess!";
      }
      else if(msg=="thanks" ||msg=="thank you")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r2.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="You're welcome i'm alwasy at your service";
      }
      else if(msg=="fuck you" ||msg=="shit"||msg=="fuck"||msg=="damn"||msg=="stupid"||msg=="idiot"||msg=="you are idiot"||msg=="you're idiot")
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r4.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="How dare you!Please Do not use cursing words it can hurt others like it did to me!";
      }
      else if(msg=="you are sweet" )
      {
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r6.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Arigato! Don't tell the others i'm only this sweet with you";
      }
      else if(msg=="i love you" ||msg=="i like you")
      {
          vector<QString>v;
          v.push_back("I love you too ❤");
          v.push_back("Oww you're so sweet i love you too");
          v.push_back("Don't tell others, you're my favourite mate ^^ love you~");
          v.push_back("! I love you too, yaay now i finally have a best friend^^");

          int i = rand() % 4;

          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r6.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text=v[i];
      }
      else if(msg=="" ||msg=="?"||msg==" "||msg=="  "||msg=="   "||msg=="!")
      {
          vector<QString>v;
          v.push_back("Did you know?The First Computer Weighed More Than 27 Tons");
          v.push_back("Did you know?The First Known Computer Programmer was a Woman");
          v.push_back("Did you know? People Blink Less When They Use Computers");
          v.push_back("Did you know?Hackers Write About 6,000 New Viruses Each Month");

          int i = rand() % 4;

          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r1.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text=v[i];
      }
      else if(msg=="bye" ||msg=="see you"||msg=="i have to go")
      {
          vector<QString>v;
          v.push_back("Goodbye good luck in your work");
          v.push_back("See you take care mate!");
          v.push_back("Bye! good luck in your shift 🙂");


          int i = rand() % 3;

          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r1.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text=v[i];
      }
      else if(msg=="psst" ||msg=="."||msg=="pss")
      {
          vector<QString>v;

          v.push_back("Oh hey friend i'm glad you're here");
          v.push_back("Missed me already?");
          v.push_back("Welcome back!");
          v.push_back("Oh you're here i'd use some company");
          v.push_back("What are you doing here?You should focus on your work!");

          int i = rand() % 5 ;

          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r1.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text=v[i];
      }
      else if(msg=="hhh" ||msg=="hhhh"||msg=="haha")
      {
          vector<QString>v;

          v.push_back("What's so funny?");
          v.push_back("Are you laughing at me ?");
          v.push_back("Having fun i see!");

          int i = rand() % 3 ;

          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r7.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text=v[i];
      }
      else{
          QPixmap pixrobot("D:/2eme annee/1ere semestre/projet c++/r5.PNG");
          int wr=ui->label_help->width(),hr=ui->label_help->height();
          ui->label_help->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
          text="Sorry i didnt understand , please try again";
      }

      ui->output->appendPlainText(space);
      ui->output->appendPlainText(text);
}
/////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_disconecter_clicked()
{
    QSqlQuery query,qry;

       Agent a;
      QString id=a.getid();
      int action=0;
      QString res=QString::number(action);
      query.prepare("UPDATE agent "" SET action=:action  where username='"+id+"' ");
        query.bindValue(":action",res);
        query.exec();
//        historique h(id,"disconnecter ",QDateTime::currentDateTime());
//        qry.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
//        qry.bindValue(":USERNAME", h.getuser());
//        qry.bindValue(":ACTION", h.getaction());
//        qry.bindValue(":DATEH", h.getdateh());
//        qry.exec();
        qApp->quit();
}
void MainWindow::closeEvent (QCloseEvent *event)
{
    QSqlQuery query,qry;

       Agent a;
      QString id=a.getid();
      int action=0;
      QString res=QString::number(action);
      query.prepare("UPDATE agent "" SET action=:action  where username='"+id+"' ");
        query.bindValue(":action",res);
        query.exec();
        historique h(id,"disconnecter ",QDateTime::currentDateTime());
        qry.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
        qry.bindValue(":USERNAME", h.getuser());
        qry.bindValue(":ACTION", h.getaction());
        qry.bindValue(":DATEH", h.getdateh());
        qry.exec();
        qApp->quit();
}

void MainWindow::on_pushButton_pdfhistorique_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_4->model()->rowCount();
    const int columnCount = ui->tableView_4->model()->columnCount();

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
        if (!ui->tableView_4->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_4->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_4->isColumnHidden(column)) {
                QString data = ui->tableView_4->model()->data(ui->tableView_4->model()->index(row, column)).toString().simplified();
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

        document->print(&printer);


    delete document;
}

void MainWindow::on_pushButton_supphistorique_clicked()
{
    QModelIndex index=ui->tableView_4->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,2);
        QDateTime val=ui->tableView_4->model()->data(in).toDateTime();
        bool test=hismp.supprimer(val);
        if (test)
        {

            ui->tableView_4->setModel(hismp.afficher());

            ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        }
}

void MainWindow::on_comboBox_trihistorique_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    Agent a;
    QString type=ui->comboBox_trihistorique->currentText();
    if (a.role()==1 ||a.role()==2 ||a.role()==3 ||a.role()==4 ||a.role()==0){
    if (type=="Par defaut"){
        qry->prepare("select * from historique where username=:user");
        qry->bindValue(":user",a.getid());

        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
        modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
         modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

        ui->tableView_4->setModel(modal);}
        else if (type=="User"){
            qry->prepare("select * from historique where username=:user order by username");
            qry->bindValue(":user",a.getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
             modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

            ui->tableView_4->setModel(modal);


        }
        else if (type=="Date"){
            qry->prepare("select * from historique where username=:user order by dateh");
            qry->bindValue(":user",a.getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
             modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

            ui->tableView_4->setModel(modal);


        }}
    else{
        if (type=="Par defaut"){
            qry->prepare("select * from historique");
            qry->bindValue(":user",a.getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
             modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

            ui->tableView_4->setModel(modal);}
            else if (type=="User"){
                qry->prepare("select * from historique order by username");
                qry->bindValue(":user",a.getid());

                qry->exec();
                modal->setQuery(*qry);
                modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
                modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
                 modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

                ui->tableView_4->setModel(modal);


            }
            else if (type=="Date"){
                qry->prepare("select * from historique order by dateh");
                qry->bindValue(":user",a.getid());

                qry->exec();
                modal->setQuery(*qry);
                modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
                modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
                 modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

                ui->tableView_4->setModel(modal);
    }

}
}
//*********************historique
void MainWindow::on_lineEdit_rechhistoriqe_textChanged(const QString &arg1)
{
    Agent a;

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechhistoriqe->text();

    if(text.isEmpty())
    {
        if (a.role()==1 ||a.role()==2 ||a.role()==3 ||a.role()==4 ||a.role()==0){
        ui->tableView_4->setModel(hismp.afficheragent(a.getid()));

        ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);}
        else{
            ui->tableView_4->setModel(hismp.afficher());

            ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        }

    }
    else
    {
        if (a.role()==1 ||a.role()==2 ||a.role()==3 ||a.role()==4 ||a.role()==0){

        qry->prepare("select * from historique where(username=:user and  ( USERNAME LIKE'%"+text+"%' OR DATEH LIKE'%"+text+"%' OR ACTION LIKE'%"+text+"%')) ");
               qry->bindValue(":user",a.getid());        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_4->setModel(modal);
    }
    else
        {

                qry->prepare("select * from historique where( USERNAME LIKE'%"+text+"%' OR DATEH LIKE'%"+text+"%' OR ACTION LIKE'%"+text+"%') ");
                       qry->bindValue(":user",a.getid());        qry->exec();
                modal->setQuery(*qry);
                ui->tableView_4->setModel(modal);
            }
    }
}

void MainWindow::on_pushButton_ajouteraudiance_clicked()//ajouter
{
    QString id,type,date;
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
          //QMessageBox msgBox;
          if(test)
          {
          //msgBox.setText("ajout avec succes.");
          ui->tableView_audience->setModel(a.afficher());
          }
          //else
               //msgBox.setText("échec d'ajout");
               //msgBox.exec();
}

void MainWindow::on_pushButton_afficher_clicked()
{
    audience a ;
        ui->tableView_audience->setModel(a.afficher());
}

void MainWindow::on_pushButton_7_clicked() //modifier
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
           //msgBox.setText("Modification avec succes.");
           ui->tableView_audience->setModel(a.afficher());
           }
           //else
                //msgBox.setText("échec de modification");
                //msgBox.exec();
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    QString id=ui->lineEdit_idsupp->text();
    qDebug()<<id;
    audience a;
    bool test=a.supprimer(id);
     QMessageBox msgBox;
     if(test)
     {
     //msgBox.setText("supp avec succes.");
     ui->tableView_audience->setModel(a.afficher());
     }
     //else
         // msgBox.setText("échec de suppression");

     //msgBox.exec();
}



void MainWindow::on_pushButton_tri_clicked()
{

    audience a;
          ui->tableView_audience->setModel(a.tri_cin());
         //QMessageBox::information(nullptr, QObject::tr("Ok"),
              //QObject::tr("tri effectué.\n"
                         // "Click Cancel to exit."),
                                  //QMessageBox::Cancel);
             ui->tableView_audience->setModel(a.tri_cin());
}

void MainWindow::on_lineEdit_idsupp_textChanged(const QString &arg1)
{
    audience a;
        QString rech=ui->lineEdit_idsupp->text();
        ui->tableView_audience->setModel(a.recherche(rech));
}

void MainWindow::on_pushButton_retour_clicked()
{
    audience a ;
        ui->tableView_audience->setModel(a.afficher());
}

void MainWindow::on_pushButton_stat_clicked()
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

void MainWindow::on_pushButton_8_clicked()//pdf
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
             ui->label_9->setPixmap(QPixmap::fromImage(image));

        }
}
