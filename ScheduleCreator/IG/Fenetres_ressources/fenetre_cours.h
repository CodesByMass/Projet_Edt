#ifndef FENETRE_COURS_H
#define FENETRE_COURS_H

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QListWidget>
#include <QWidget>
#include <QMessageBox>

#include "classes/les_h/Data.h"

#include <QWidget>

class Fenetre_cours : public QWidget
{
    Q_OBJECT

private:
    Universite* u ;
    Filiere * f ;
    QComboBox *type ;
    QComboBox *duree ;
    QComboBox *enseignants ;
    QComboBox *salles ;
    QComboBox *matiere ;
    QListWidget *groupes ;
    QFormLayout *formulaire ;
    QHBoxLayout *titleLayout;
    QLabel *label;
    QHBoxLayout *ButtonsLayout;
    QPushButton *boutonAnnuler;
    QPushButton *boutonAjouter;
    QVBoxLayout *layoutPrincipal;

public:
    Fenetre_cours(QWidget* parent, Universite* u, Filiere* f);

signals :
    void actualiseOnglet(Cours* c);

public slots:
    void creer_Cours() ;
    void actualiser_listes(const QString &matiere_actuelle) ;
};

#endif // FENETRE_COURS_H
