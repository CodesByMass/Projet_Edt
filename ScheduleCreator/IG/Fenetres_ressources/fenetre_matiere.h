#ifndef FENETRE_MATIERE_H
#define FENETRE_MATIERE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QMessageBox>
#include "classes/les_h/Data.h"

class fenetre_matiere : public QWidget
{
    Q_OBJECT

    public:
    fenetre_matiere(QWidget* parent,Universite* u,std::list <Matiere*> matieres);
    ~fenetre_matiere();

    signals:
    void actualise(Matiere* g);

    public slots :
    void creer_matiere();

    private:
    Universite* u;
    QLineEdit *volume;
    QLineEdit *nom;
    QHBoxLayout *titleLayout;
    QLabel *label;
    QHBoxLayout *ButtonsLayout;
    QPushButton *boutonQuitter;
    QPushButton *boutonAjouter;
    QVBoxLayout *layoutPrincipal;
    QFormLayout *formLayout ;
    std::list <Matiere*> matieres;

};

#endif // FENETRE_MATIERE_H
