#ifndef FENETRE_GROUPE_H
#define FENETRE_GROUPE_H

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QWidget>
#include <QMessageBox>

#include "../../classes/les_h/Data.h"

class Fenetre_Groupe : public QWidget

{
    Q_OBJECT

    public:
    Fenetre_Groupe(QWidget* parent,Universite* u, Filiere* f);

    signals :
     void actuListe();

    public slots :
    void creer_groupe();

    private:
    Universite* u ;
    Filiere* f ;
    QComboBox *filiere ;
    QLineEdit *identifiant;
    QFormLayout *formLayout ;
    QHBoxLayout *titleLayout;
    QLabel *label;
    QSpinBox *VH ;
    QSpinBox *effectif ;
    QHBoxLayout *ButtonsLayout;
    QPushButton *boutonAnnuler;
    QPushButton *boutonAjouter;
    QVBoxLayout *layoutPrincipal;
};


#endif // FENETRE_GROUPE_H
