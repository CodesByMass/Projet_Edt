#ifndef FENETRE_SALLE_H
#define FENETRE_SALLE_H

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QWidget>
#include <QSpinBox>

class Fenetre_Salle : public QWidget

{
    public:
    Fenetre_Salle();

    private:
    QLineEdit *nom;
    QComboBox *type ;
    QComboBox *matiere ;
    QSpinBox *effectif ;
    QComboBox *batiment ;
    QFormLayout *formulaire ;
    QHBoxLayout *titleLayout;
    QLabel *label;
    QHBoxLayout *ButtonsLayout;
    QPushButton *boutonQuitter;
    QPushButton *boutonAjouter;
    QVBoxLayout *layoutPrincipal;
};

#endif // FENETRE_SALLE_H
