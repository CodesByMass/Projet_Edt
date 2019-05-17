#include "fenetre_enseignant.h"

Fenetre_Enseignant::Fenetre_Enseignant() : QWidget ()
{

   // setFixedSize(400,200) ;
    setWindowTitle("Nouvel enseignant");

    //Création du titre

    titleLayout = new QHBoxLayout ;
    label = new QLabel("Nouvel enseignant");
    label->setAlignment(Qt::AlignHCenter);
    label->setMargin(20) ;
    label->setFont(QFont( "Arial", 10, QFont::Bold)) ;
    titleLayout->addWidget(label) ;

    //Formulaire

    formulaire = new QFormLayout ;
    nom = new QLineEdit ;
    prenom = new QLineEdit ;
    matiere = new QLineEdit ;
    VH = new QSpinBox ;
    formulaire->addRow("&Nom", nom) ;
    formulaire->addRow("&Prénom", prenom) ;
    formulaire->addRow("&Matière", matiere) ;
    formulaire->addRow("&Volume Horaire", VH) ;

    // Tableau de disponibilités

    dispos = new QTableWidget(7,3,this) ;
    jours = new QTableWidgetItem("Jours");
    heureMin = new QTableWidgetItem("Heure minimum");
    heureMax = new QTableWidgetItem("Heure Max");
    lundi = new QTableWidgetItem("lundi");
    mardi = new QTableWidgetItem("Mardi");
    mercredi = new QTableWidgetItem("Mercredi");
    jeudi = new QTableWidgetItem("Jeudi");
    vendredi = new QTableWidgetItem("Vendredi");
    samedi = new QTableWidgetItem("Samedi");
    dispos->setHorizontalHeaderItem(0,jours);
    dispos->setHorizontalHeaderItem(1,heureMin);
    dispos->setHorizontalHeaderItem(2,heureMax);
    dispos->setVerticalHeaderItem(0,jours);
    dispos->setVerticalHeaderItem(1,lundi);
    dispos->setVerticalHeaderItem(2,mardi);
    dispos->setVerticalHeaderItem(3,mercredi);
    dispos->setVerticalHeaderItem(4,jeudi);
    dispos->setVerticalHeaderItem(5,vendredi);
    dispos->setVerticalHeaderItem(6,samedi);

    // Boutons
    ButtonsLayout = new QHBoxLayout ;

    boutonQuitter = new QPushButton("Annuler");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(quit()));
    ButtonsLayout->addWidget(boutonQuitter); // Ajout du bouton

    boutonAjouter = new QPushButton("Ajouter");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(quit()));
    ButtonsLayout->addWidget(boutonAjouter); // Ajout du bouton

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(titleLayout);
    layoutPrincipal->addLayout(formulaire); // Ajout du layout de formulaire
    layoutPrincipal->addWidget(dispos);
    layoutPrincipal->addLayout(ButtonsLayout) ;

    setLayout(layoutPrincipal);

}
