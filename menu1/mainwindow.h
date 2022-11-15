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
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    archive etmp;
    QStringList files;
    notepad *note;
    PopUp *popUp;
};
#endif // MAINWINDOW_H
