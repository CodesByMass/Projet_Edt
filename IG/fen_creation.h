#ifndef FEN_CREATION_H
#define FEN_CREATION_H

#include <QWidget>
#include<QVBoxLayout>
#include <QLineEdit>
#include<QListView>
#include "classes/les_h/Filiere.h"
#include<QStringListModel>
#include<QStandardItemModel>
#include<QComboBox>
#include<QListWidget>
#include "Fenetres_ressources/fenetre_matiere.h"

class fen_creation : public QWidget
{
    Q_OBJECT

    public:

    fen_creation();
    fen_creation(QWidget *parent,Universite *u);
    ~fen_creation();

     private:
     Universite *u;
     Filiere *f;
     QVBoxLayout *layoutf;
     int nb_groupe;
     int* effectifs;
     QListView *vueliste;
     QStringListModel *modeleliste;
     QComboBox *listeSem ;
     QComboBox *listeEns ;
     QListWidget *listeMat ;
     QLineEdit* filliereEdit;
     fenetre_matiere* fm;
     QFormLayout *formulaire ;
     QHBoxLayout *ButtonsLayout;
     std::list<Matiere*> matieres;

    signals :
     void ok();
     void ok2();

     public slots:

     void actualise_List(Matiere* m);

     private slots:

     void cree_filiere();
     void crea_fenetre_matiere();

};

#endif // FEN_CREATION_H
