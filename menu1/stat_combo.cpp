#include "stat_combo.h"
#include "ui_stat_combo.h"

stat_combo::stat_combo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_combo)
{
    ui->setupUi(this);
}

stat_combo::~stat_combo()
{
    delete ui;
}
void stat_combo::choix_bar()
{
QSqlQuery q1,q2,q3,q4;
qreal tot=0,c1=0,c2=0,c3=0;

q1.prepare("SELECT * FROM AVOCATS");
q1.exec();

q2.prepare("SELECT * FROM AVOCATS WHERE AUDIANCE_REUSSI='5'");
q2.exec();

q3.prepare("SELECT * FROM AVOCATS WHERE AUDIANCE_REUSSI='10'");
q3.exec();

q4.prepare("SELECT * FROM AVOCATS WHERE AUDIANCE_REUSSI='15' ");
q4.exec();

while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}
while (q4.next()){c3++;}

c1=c1/tot;
c2=c2/tot;
c3=c3/tot;



        QBarSet *set0 = new QBarSet("Avocats de 5 et plus");
        QBarSet *set1 = new QBarSet("Avocats de 10 et plus");
        QBarSet *set2 = new QBarSet("Avocats de 15 et plus");


        *set0 << c1;
        *set1 << c2;
        *set2 << c3;



        QBarSeries *series = new QBarSeries();


        series->append(set0);
        series->append(set1);
        series->append(set2);



        QChart *chart = new QChart();

        chart->addSeries(series);


        // Adds categories to the axes
       // QBarCategoryAxis *axis = new QBarCategoryAxis();



        // 1. Bar chart
       // chart->setAxisX(axis, series);

        // Used to change the palette
        QPalette pal = qApp->palette();

        // Change the color around the chart widget and text
        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));

        // Apply palette changes to the application
        qApp->setPalette(pal);


// Used to display the chart
chartView = new QChartView(chart,ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(400,400);

chartView->show();
}
void stat_combo::choix_pie()
{
QSqlQuery q1,q2,q3,q4;
qreal tot=0,c1=0,c2=0,c3=0;

q1.prepare("SELECT * FROM AVOCATS");
q1.exec();

q2.prepare("SELECT * FROM AVOCATS WHERE TO_NUMBER(AUDIANCE_REUSSI)<5 ");
q2.exec();

q3.prepare("SELECT * FROM AVOCATS WHERE (TO_NUMBER(AUDIANCE_REUSSI)>5 AND TO_NUMBER(AUDIANCE_REUSSI)<10)");
q3.exec();

q4.prepare("SELECT * FROM AVOCATS WHERE (TO_NUMBER(AUDIANCE_REUSSI)>15) ");
q4.exec();

while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}
while (q4.next()){c3++;}

c1=c1/tot;
c2=c2/tot;
c3=c3/tot;

// Define slices and percentage of whole they take up
QPieSeries *series = new QPieSeries();
series->append("Moins de 5",c1);
series->append("entre 5 et 10",c2);
series->append("15 et plus ",c3);



// Create the chart widget
QChart *chart = new QChart();

// Add data to chart with title and show legend
chart->addSeries(series);
chart->legend()->show();


// Used to display the chart
chartView = new QChartView(chart,ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(600,400);

chartView->show();
}
