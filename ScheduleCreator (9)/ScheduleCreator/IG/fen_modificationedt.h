#ifndef FEN_MODIFICATIONEDT_H
#define FEN_MODIFICATIONEDT_H
#include "./classes/les_h/Data.h"
#include <QWidget>
#include<QPushButton>
#include <QStringListModel>
#include <QListView>
#include <QTableView>
#include <QLabel>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QComboBox>
#include <QTableWidget>
#include <QListWidget>
//#include "classes/les_h/Universite.h"

class Fen_ModificationEDT : public QWidget
{
    Q_OBJECT
public:
    Fen_ModificationEDT(QWidget *parent,Universite* u);

    //Fen_ModificationEDT(&filiere f, &universite u, int groupe);
   // ~Fen_ModificationEDT();
    void affiche_EDT();
   //Affiche dans un tableau selon le groupe et la filière choisi l'emplois du temps correspondant.
    void affiche_onglets(); //Permet l'affichage des onglets, leurs comportement seront spécifier grâce au fonction suivantes : affiche_salles, affiche_cours, affiche_enseignants.
    void affiche_salles(); //Permet l'affichage des salles ainsi que des boutons permettant de lancer l'ajout, suppression de salles.
    void affiche_cours(); //Permet l'affichage des cours ainsi que des boutons permettant de lancer l'ajout, suppression de cours.
    void affiche_enseignants(); //Permet l'affichage des enseignants ainsi que des boutons permettant de lancer l'ajout, suppression d'ensaignants.
    void affiche_groupe();
    void bouton_generationEDT(); //Permet d'afficher le bouton "génération automatique". Lorsqu'il est cliqué, lance l'algorithme grâce aux fonctions du module Générateur d'EDT.
    void bouton_visualiser(); //Permet d'afficher le bouton "visualiser". Lorsqu'il est cliqué lance la visualisation depuis la class MainWindow de l'edt.
    void bouton_sauvegarde(); //Permet d'afficher le bouton "sauvegarde". Lorsqu'il est cliqué, lance la sauvegarde grâce à la fonction du module Système de gestion de fichier.
    void boutons_groupes(); //Permet d'afficher un bouton pour chaque groupe et pour la filière. Lorsqu'un bouton sera cliqué, on modifie le numéro du groupe de la classe et on réaffiche l'EDT.
    bool deplacement_cours(); //Permet le déplacement d'un cours dans un créneau différent. retourne 0 si le deplacement est impossible :
    //cela sera verifier grace aux fonctions du module générateur d'EDT (contraintes hard).
    //Renvoie 1 si le deplacement et possible et modifie l'EDT et les parametre de l'EDT de la filiere.
    bool changement_salle(); //Permet le changement d'une salle d'un cours selectionné. retourne 0 si le changement est impossible :
    //cela sera verifier grace aux fonctions du module générateur d'EDT (contraintes hard).
    //Renvoie 1 si le changement et possible et modifie l'EDT et les parametre de l'EDT de la filiere.
    bool changement_enseignant();//Permet le changement d'un enseignant d'un cours selectionné. retourne 0 si le changement est impossible :
    //cela sera verifier grace aux fonctions du module générateur d'EDT (contraintes hard).
    //Renvoie 1 si le changement et possible et modifie l'EDT et les parametre de l'EDT de la filiere.
     int ajouter_dans_edt(int nonglet,QString s );
    void remplir_edt();
     void bouton_generationLATEX();


    ~Fen_ModificationEDT();
private:
    QWidget *fenetre;

    QVBoxLayout *layout;
    QTableWidget *tableauEDT;
    QPushButton *buttonressources;
    QPushButton *buttonselection;
    QPushButton *buttonsauvegarder;
    QComboBox *listeGroupe;
    QComboBox *listeFiliere;
    QTabWidget *onglets;
    QWidget *ongletPage1;
    QWidget *ongletPage2;
    QWidget *ongletPage4;
    QWidget *ongletPage3;
    QListWidget* listeGroupeOnglet;
    QListWidget* listeSalleOnglet;
    QListWidget* listeEnseignantOnglet;
    QListWidget* listeCoursOnglet;
    QGridLayout *vbox1;
    QGridLayout *vbox2;
    QGridLayout *vbox3;
    QGridLayout *vbox4;



    int numeroGroup; //0 filière complète, ou numéro du groupe.
    //filiere* filiere;  // utilisation des matières et de l’edt
    //universite * u; // utilisation des ressources
    Universite *u;
    Filiere* f;

signals:
public:

public slots:

    void actualise_groupe();
    void actualise_enseignant(Enseignant* e);
    void actualise_cours(Cours* c);
    void actualise_salle();

private slots:

    void ressourceSelectionnee();
    void sauvegarder();
    void cree_fen_ajout_groupe();
    void cree_fen_ajout_enseignant();
    void cree_fen_ajout_salle();
    void cree_fen_ajout_cours();
    void celluleSelectionnee(int nRow, int nCol);
    void changefiliere();
    void exec_generationEDT();
    void conv();

};

#endif // FEN_MODIFICATIONEDT_H
