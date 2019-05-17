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
#include <QTableWidget>
#include <QTableWidgetItem>

class Fenetre_Enseignant : public QWidget
{
public:
    Fenetre_Enseignant();

private:
    QHBoxLayout *titleLayout;
    QHBoxLayout *ButtonsLayout;
    QVBoxLayout *layoutPrincipal;
    QFormLayout *formulaire ;
    QPushButton *boutonQuitter;
    QPushButton *boutonAjouter;
    QLabel *label;
    QLineEdit *nom ;
    QLineEdit *prenom ;
    QLineEdit *matiere ;
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


};
