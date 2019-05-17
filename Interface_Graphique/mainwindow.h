#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fen_modificationedt.h"
#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    void affiche_accueil(); //Affiche les 3 boutons d'accueil : Création d'EDT, visualisation, modification. Et lance la bonne méthode en fonction du bouton cliqué.
    void affiche_EDT(); //Ouvre une page demandant la filière et le groupe dont on veut afficher l'EDT.
    void creation(); // Lance la création d'un EDT en faisant la demande du nom de la filière et du choix des matières. Lorsque c'est validé envois sur la fenetre de modification d'EDT.

    ~MainWindow();
private:
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    Fen_ModificationEDT *modificationwindow;

    //universite* u;
signals:

public slots:
private slots:
    void showFen_ModificationEDT();

};

#endif // MAINWINDOW_H
