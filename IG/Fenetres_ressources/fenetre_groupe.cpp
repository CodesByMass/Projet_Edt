#include "fenetre_groupe.h"
#include "classes/les_h/Data.h"

Fenetre_Groupe::Fenetre_Groupe(QWidget* parent, Universite* u, Filiere* f) : QWidget ()

{
    this->u=u;
    this->f=f;
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

    //Listes des filières
    filiere = new QComboBox;
   /* for(list<Filiere*>::iterator f = u->get_filieres()->begin(); f != u->get_filieres()->end(); ++f) {
        QString item = QString::fromStdString((*f)->get_nom()) ;
        filiere->addItem(item) ; }*/

    // Valeur par défault, la filière actuelle
    filiere->addItem(QString::fromStdString(f->get_nom())) ;
    // Identifiant
    identifiant = new QLineEdit;
    //identifiant->setInputMask("n");
    // Effectif du groupe
    effectif = new QSpinBox ;
    effectif->setMinimum(10);
    effectif->setMaximum(200);
    // Volume Horaire
    VH = new QSpinBox ;
    VH->setMaximum(40);
    formLayout = new QFormLayout;
    formLayout->addRow("&Fillière", filiere);
    formLayout->addRow("&Identifiant", identifiant);
    formLayout->addRow("&Effectif", effectif);
    formLayout->addRow("&Volume Horaire", VH);

    //Boutons

    ButtonsLayout = new QHBoxLayout ;

    boutonAnnuler = new QPushButton("Annuler");
    QWidget::connect(boutonAnnuler, SIGNAL(clicked()), this, SLOT(close()));
    ButtonsLayout->addWidget(boutonAnnuler); // Ajout du bouton annuler

    boutonAjouter = new QPushButton("Ajouter");
    QWidget::connect(boutonAjouter, SIGNAL(clicked()), this, SLOT(creer_groupe()));
    QWidget::connect(this, SIGNAL(actuListe()), parent, SLOT(actualise_groupe()));
    ButtonsLayout->addWidget(boutonAjouter); // Ajout du bouton ajouer


    // Création du layout principal de la fenêtre (vertical)


    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(titleLayout);
    layoutPrincipal->addLayout(formLayout); // Ajout du layout de formulaire
    layoutPrincipal->addLayout(ButtonsLayout) ;

    setLayout(layoutPrincipal);

}

void Fenetre_Groupe::creer_groupe() {
    // Récupérer les objets université et filière
    Universite* temp_universite = u ;
    Filiere* temp_filiere = f ;
    // Boite de dialogue pour confirmer les informations saisies
    int reponse = QMessageBox::question(this, "Confirmation", "Avez vous bien saisi les informations ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QString new_idef = identifiant->text();
        // Récupérer la filière
        QString new_filiere = filiere->currentText() ;
        Filiere* temp_f = temp_universite->get_filieres(new_filiere.toStdString());
        // Récupérer l'effectif
        QString new_effectif = effectif->cleanText() ;
        // Récupérer le volume horaire
        QString new_VH = VH->cleanText() ;

        if (!new_idef.isEmpty() && !new_filiere.isEmpty() && !new_effectif.isEmpty() && !new_VH.isEmpty() ) {
            // Créer groupe, lui ajouter la filière, et ajouter le groupe à la filière
            Groupe *g = new Groupe(u, new_idef.toStdString(), new_VH.toInt(), NULL, new_effectif.toInt());
            g->add_filiere(temp_filiere);
            f->add_groupe(g);
            QMessageBox::information(this, "Groupe créé", "Le nouveau groupe a bien été créé");
            emit actuListe();
        }
        else {
            QMessageBox::warning(this, "Formulaire incomplet", "Veuillez complétez tous les champs");
        }
    }
    else {

    }
}
