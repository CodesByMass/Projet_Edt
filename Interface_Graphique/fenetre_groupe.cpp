#include "fenetre_groupe.h"

Fenetre_Groupe::Fenetre_Groupe() : QWidget ()

{

    setFixedSize(400,200) ;
    setWindowTitle("Création de groupe");

    //Création du titre

    titleLayout = new QHBoxLayout ;
    label = new QLabel("Créer un Groupe");
    label->setAlignment(Qt::AlignHCenter);
    label->setMargin(20) ;
    QFont police( "Arial", 10, QFont::Bold);
    label->setFont(police) ;
    titleLayout->addWidget(label) ;

    // Création du layout de formulaire et de ses widgets

    filiere = new QComboBox;
    filiere->addItem("INFO S6") ;
    filiere->addItem("BIO S6") ;
    identifiant = new QLineEdit;

    formLayout = new QFormLayout;
    formLayout->addRow("&Fillière", filiere);
    formLayout->addRow("&Identifiant", identifiant);

    //Boutons

    ButtonsLayout = new QHBoxLayout ;

    boutonQuitter = new QPushButton("Annuler");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(quit()));
    ButtonsLayout->addWidget(boutonQuitter); // Ajout du bouton

    boutonAjouter = new QPushButton("Ajouter");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(quit()));
    ButtonsLayout->addWidget(boutonAjouter); // Ajout du bouton


    // Création du layout principal de la fenêtre (vertical)


    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(titleLayout);
    layoutPrincipal->addLayout(formLayout); // Ajout du layout de formulaire
    layoutPrincipal->addLayout(ButtonsLayout) ;

    setLayout(layoutPrincipal);


}
