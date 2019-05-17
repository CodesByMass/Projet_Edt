#ifndef FEN_MODIFICATIONEDT_H
#define FEN_MODIFICATIONEDT_H
#include "fen_modificationressources.h"
#include <QWidget>
#include<QPushButton>
#include <QStringListModel>
#include <QListView>
#include <QTableView>
#include <QLabel>
#include <QVBoxLayout>
class Fen_ModificationEDT : public QWidget
{
    Q_OBJECT
public:
    explicit Fen_ModificationEDT(QWidget *parent = nullptr);

    //Fen_ModificationEDT(&filiere f, &universite u, int groupe);
   // ~Fen_ModificationEDT();
    void affiche_EDT();
   //Affiche dans un tableau selon le groupe et la filière choisi l'emplois du temps correspondant.
    void affiche_onglets(); //Permet l'affichage des onglets, leurs comportement seront spécifier grâce au fonction suivantes : affiche_salles, affiche_cours, affiche_enseignants.
    void affiche_salles(); //Permet l'affichage des salles ainsi que des boutons permettant de lancer l'ajout, suppression de salles.
    void affiche_cours(); //Permet l'affichage des cours ainsi que des boutons permettant de lancer l'ajout, suppression de cours.
    void affiche_enseignants(); //Permet l'affichage des enseignants ainsi que des boutons permettant de lancer l'ajout, suppression d'ensaignants.
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
    ~Fen_ModificationEDT();
private:
    QWidget *fenetre;

    QVBoxLayout *layout;
    QTableView *vue;
    Fen_ModificationRessources *modificationressourceswindow;
    QPushButton *buttonressources;
    QPushButton *buttonselection;

    QStringListModel *modeleliste;
    QListView *vueliste;

    QWidget *ongletPage1;
    QWidget *ongletPage2;
    QWidget *ongletPage4;
    QLabel *ongletPage3;

    int numeroGroup; //0 filière complète, ou numéro du groupe.
    //filiere* filiere;  // utilisation des matières et de l’edt
    //universite * u; // utilisation des ressources

signals:

public slots:
private slots:
    void showFen_ModificationRessources();

    void ressourceSelectionnee();

};

#endif // FEN_MODIFICATIONEDT_H
