#include "fenetre_salle.h"

Fenetre_Salle::Fenetre_Salle() : QWidget ()

{
    //setFixedSize(400,200) ;
    setWindowTitle("Création de Salle");

    //Création du titre

    titleLayout = new QHBoxLayout ;
    label = new QLabel("Nouvelle salle");
    label->setAlignment(Qt::AlignHCenter);
    label->setMargin(20) ;
    label->setFont(QFont( "Arial", 10, QFont::Bold)) ;
    titleLayout->addWidget(label) ;

    //Création du formulaire

    nom = new QLineEdit ;
    type = new QComboBox ;
    type->addItem("CM");
    type->addItem("TP");
    type->addItem("TD");
    matiere = new QComboBox ;
    effectif = new QSpinBox ;
    batiment = new QComboBox ;
    batiment->addItem("Fermat");
    batiment->addItem("Descartes");
    batiment->addItem("Buffon");
    batiment->addItem("Batiment E");
    batiment->addItem("Germain");
    formulaire = new QFormLayout ;
    formulaire->addRow("Nom", nom);
    formulaire->addRow("Type",type);
    formulaire->addRow("Matière(s)",matiere);
    formulaire->addRow("Effectif Max", effectif);
    formulaire->addRow("Batiment", batiment);

    // Boutons
    ButtonsLayout = new QHBoxLayout ;

    boutonQuitter = new QPushButton("Annuler");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(quit()));
    ButtonsLayout->addWidget(boutonQuitter); // Ajout du bouton

    boutonAjouter = new QPushButton("Ajouter");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(quit()));
    ButtonsLayout->addWidget(boutonAjouter); // Ajout du bouton

    //Layout principal

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(titleLayout);
    layoutPrincipal->addLayout(formulaire); // Ajout du layout de formulaire
    layoutPrincipal->addLayout(ButtonsLayout) ;

    setLayout(layoutPrincipal);


}
