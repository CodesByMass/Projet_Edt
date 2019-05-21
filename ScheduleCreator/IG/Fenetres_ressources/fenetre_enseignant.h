#ifndef FENETRE_ENSEIGNANT_H
#define FENETRE_ENSEIGNANT_H

#endif // FENETRE_ENSEIGNANT_H

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QWidget>
#include <QSpinBox>
#include <QListWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>

#include "classes/les_h/Data.h"

class Fenetre_Enseignant : public QWidget
{
    Q_OBJECT
public:
    Fenetre_Enseignant(QWidget* parent, Universite* u, Filiere* f);

signals :
 void actuListe(Enseignant *e);

public slots :
   void creer_enseignant();

private:
    Universite* u ;
    Filiere* f ;
    QHBoxLayout *titleLayout;
    QHBoxLayout *ButtonsLayout;
    QVBoxLayout *layoutPrincipal;
    QFormLayout *formulaire ;
    QPushButton *boutonAnnuler;
    QPushButton *boutonAjouter;
    QLabel *label;
    QLineEdit *nom ;
    QLineEdit *prenom ;
    QListWidget *matiere ;
    QSpinBox *VH ;
    QTableWidget *dispos ;
    QTableWidgetItem *jours ;
    QTableWidgetItem *heureMin ;
    QTableWidgetItem *heureMax ;
    QTableWidgetItem *lundi ;
    QTableWidgetItem *mardi ;
    QTableWidgetItem *mercredi ;
    QTableWidgetItem *jeudi ;
    QTableWidgetItem *vendredi ;
    QTableWidgetItem *samedi ;
    QComboBox *heureMin0 ;
    QComboBox *heureMin1 ;
    QComboBox *heureMin2 ;
    QComboBox *heureMin3 ;
    QComboBox *heureMin4 ;
    QComboBox *heureMin5 ;
    QComboBox *heureMax0 ;
    QComboBox *heureMax1 ;
    QComboBox *heureMax2 ;
    QComboBox *heureMax3 ;
    QComboBox *heureMax4 ;
    QComboBox *heureMax5 ;


};
