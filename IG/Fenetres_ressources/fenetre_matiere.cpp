#include "fenetre_matiere.h"
#include "classes/les_h/Data.h"
#include "../fen_creation.h"
#include <QApplication>
#include <QCheckBox>

fenetre_matiere::fenetre_matiere(QWidget* parent, Universite* u, std::list <Matiere*> matieres) : QWidget ()

{
    this->matieres=matieres;
    this->u=u;
    setFixedSize(400,200) ;
    setWindowTitle("Création de groupe");

    //Création du titre

    titleLayout = new QHBoxLayout ;
    label = new QLabel("Créer une matière");
    label->setAlignment(Qt::AlignHCenter);
    label->setMargin(20) ;
    QFont police( "Arial", 10, QFont::Bold);
    label->setFont(police) ;
    titleLayout->addWidget(label) ;

    // Création du layout de formulaire et de ses widgets

    volume = new QLineEdit;
    QRegExp r("[0-9]*");
    QRegExpValidator* valid = new QRegExpValidator(r,this);
    volume->setValidator(valid);
    nom = new QLineEdit;

    formLayout = new QFormLayout;
    formLayout->addRow("&Nom", nom);
    formLayout->addRow("&Volume horaire", volume);

    //Boutons

    ButtonsLayout = new QHBoxLayout ;

    boutonQuitter = new QPushButton("Annuler");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(close()));
    ButtonsLayout->addWidget(boutonQuitter); // Ajout du bouton

    boutonAjouter = new QPushButton("Ajouter");
    QWidget::connect(boutonAjouter, SIGNAL(clicked()), this, SLOT(creer_matiere()));
    QWidget::connect(this,SIGNAL(actualise(Matiere*)),parent, SLOT(actualise_List(Matiere*)));
    ButtonsLayout->addWidget(boutonAjouter); // Ajout du bouton


    // Création du layout principal de la fenêtre (vertical)


    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(titleLayout);
    layoutPrincipal->addLayout(formLayout); // Ajout du layout de formulaire
    layoutPrincipal->addLayout(ButtonsLayout) ;

    setLayout(layoutPrincipal);

}

void fenetre_matiere::creer_matiere() {

    QString new_nom = nom->text();
    QString new_vol = volume->text();


    if (!new_nom.isEmpty() && !new_vol.isEmpty()) {

               Matiere *g = new Matiere(volume->text().toInt(),nom->text().toStdString());

//               cout<<"Tailles listes dans fen_mat : "<< matieres.size() << "\n";
                QMessageBox::information(this, "Matière crée", "La nouvelle matière a été ajoutée");
               emit actualise(g);
               this->close();

    }
    else {
        QMessageBox::warning(this, "Formulaire incomplet", "Veuillez complétez tous les champs");
    }

}

fenetre_matiere::~fenetre_matiere(){}
