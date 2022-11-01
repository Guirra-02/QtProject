#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "archive.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    archive etmp;
};
#endif // MAINWINDOW_H
