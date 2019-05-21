#ifndef FENETRE_SALLE_H
#define FENETRE_SALLE_H

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QWidget>
#include <QSpinBox>
#include <QMessageBox>

#include "classes/les_h/Data.h"

class Fenetre_Salle : public QWidget

{
    Q_OBJECT

public:
    Fenetre_Salle(QWidget* parent, Universite* u, Filiere* f);
signals :
    void actualise();
public slots :
    void creer_salle();

private:
    Universite* u;
    Filiere* f ;
    QLineEdit *nom;
    QComboBox *type ;
    QListWidget *matiere ;
    QSpinBox *effectif ;
    QComboBox *batiment ;
    QFormLayout *formulaire ;
    QHBoxLayout *titleLayout;
    QLabel *label;
    QHBoxLayout *ButtonsLayout;
    QPushButton *boutonAnnuler;
    QPushButton *boutonAjouter;
    QVBoxLayout *layoutPrincipal;
};

#endif // FENETRE_SALLE_H
