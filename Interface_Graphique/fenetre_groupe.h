#ifndef FENETRE_GROUPE_H
#define FENETRE_GROUPE_H

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QWidget>

class Fenetre_Groupe : public QWidget

{
    public:
    Fenetre_Groupe();

    private:
    QComboBox *filiere ;
    QLineEdit *identifiant;
    QFormLayout *formLayout ;
    QHBoxLayout *titleLayout;
    QLabel *label;
    QHBoxLayout *ButtonsLayout;
    QPushButton *boutonQuitter;
    QPushButton *boutonAjouter;
    QVBoxLayout *layoutPrincipal;
};


#endif // FENETRE_GROUPE_H
