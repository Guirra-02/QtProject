#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDoubleValidator>
#include"audience.h"
#include <QtCharts/QLineSeries>
#include<QtCharts>
#include<QPieSeries>
#include "Exel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_Retour_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_pdf_clicked();

    //void on_pushButton_statistique_clicked();

    void on_lineEdit_recherche_textChanged();

    void on_pushButton_insererimage_clicked();

    void on_pushbuttonExcel_clicked();

    void on_pushButton_QRcode_clicked();

    void on_radioButton_geo_clicked();



    //void on_stat_clicked();

    void on_stat_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

