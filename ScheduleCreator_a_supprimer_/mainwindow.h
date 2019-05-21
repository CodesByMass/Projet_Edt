#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./IG/fen_modificationedt.h"
#include "./IG/fen_accueil.h"
#include "./IG/fen_creation.h"
#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

   // void affiche_accueil(); //Affiche les 3 boutons d'accueil : Création d'EDT, visualisation, modification. Et lance la bonne méthode en fonction du bouton cliqué.
    void affiche_EDT(); //Ouvre une page demandant la filière et le groupe dont on veut afficher l'EDT.

    ~MainWindow();



private:

    Universite *u;
    fen_accueil *accueil;
    fen_creation *creation;
    Fen_ModificationEDT *modificationwindow;




    //universite* u;
signals:

public slots:
     void creation_EDT();
     void affiche_accueil();
     void showFen_ModificationEDT();
private slots:
     // Lance la création d'un EDT en faisant la demande du nom de la filière et du choix des matières. Lorsque c'est validé envois sur la fenetre de modification d'EDT.


};

#endif // MAINWINDOW_H
