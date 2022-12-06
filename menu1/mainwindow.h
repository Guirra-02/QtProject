#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "archive.h"
#include <QMainWindow>
#include <QPieSeries>
#include <QPieSlice>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>
#include <QDebug>
#include <QSslSocket>
#include"notepad.h"
#include "notification.h"
#include "historique.h"
#include "jugee.h"
#include "audience.h"
#include "avocat.h"
#include "stat_combo.h"
#include "camera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent (QCloseEvent *event);

private slots:
    void on_pushButton_juge_clicked();

    void on_pushButton_audience_clicked();

    void on_pushButton_affaires_clicked();

    void on_pushButton_salles_clicked();


    void on_pushButton_home_clicked();

    void on_pushButton_avocat_clicked();

    void on_pushButton_ajouter_arch_clicked();

    void on_pushButton_supprimer_arch_clicked();

    void on_pushButton_modifier_arch_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_comboBox_3_currentTextChanged(const QString &arg1);



    void on_tabWidget_arch_currentChanged(int index);



    void on_pushButton_2_clicked();
    void browse();
void sendMail();
void mailSent(QString status);
void on_pushButton_3_clicked();

void on_calendarWidget_selectionChanged();

void on_pushButton_4_clicked();
void notif();

void on_pushButton_5_clicked();

void on_disconecter_clicked();

void on_pushButton_pdfhistorique_clicked();

void on_pushButton_supphistorique_clicked();

void on_comboBox_trihistorique_currentTextChanged(const QString &arg1);

void on_lineEdit_rechhistoriqe_textChanged(const QString &arg1);

void on_pushButton_ajout_clicked();

void on_pushButton_modifier_clicked();

void on_tableViewjuge_activated(const QModelIndex &index);

void on_pushButton_supp_clicked();

void on_lineEdit_rech_textChanged(const QString &arg1);

void on_pushButton_asc_clicked();



void on_pushButton_pdf_clicked();

void on_pushButton_im_clicked();

void on_tableViewjuge_clicked(const QModelIndex &index);
void browsemaram();
void sendMailmaram();

void mailSentmaram(QString status);


void on_tabWidget_juge_currentChanged(int index);

void on_pushButton_font_clicked();

void on_pushButton_submit_clicked();

void on_pushButton_6_clicked();

void on_pushButton_8_clicked();

void on_pushButton_7_clicked();

void on_pushButton_tri_clicked();

void on_lineEdit_recherche_textChanged(const QString &arg1);

void on_pushButton_pdf_2_clicked();

void on_stat_clicked();

void on_radioButton_geo_clicked();

void on_pushButton_insererimage_clicked();

void on_pushButton_QRcode_clicked();

void on_pushButton_ajouter_clicked();

void on_pushButton_16_clicked();


void on_eliminer_clicked();

void on_pushButton_modifier_2_clicked();

void on_pushButton_9_clicked();



void on_pushButton_11_clicked();

void on_pushButton_10_clicked();

void on_identifiant_textChanged(const QString &arg1);

void on_pushButton_13_clicked();

void on_pushButton_15_clicked();
void browsemelek();
void sendMailmelek();

void mailSentmelek(QString status);

void on_ajouter_salle_clicked();

void on_Push_Button_Afficher_2_clicked();

void on_supprimer_salle_clicked();

void on_modifier_salle_clicked();

void on_imprimer_clicked();

void on_pushButton_17_clicked();

void on_trier_salle_activated();

void on_rechercher_salle_textChanged(const QString &arg1);

void on_fichier_xl_clicked();

void on_salleAfich_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    archive etmp;
    QStringList files;
    notepad *note;
    PopUp *popUp;
    historique hismp;
    jugee j;
    stat_combo *s;
    camera *c;
   // audience aud;
};
#endif // MAINWINDOW_H
