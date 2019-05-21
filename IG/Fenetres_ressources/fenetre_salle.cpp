#include "fenetre_salle.h"
#include "classes/les_h/Data.h"


Fenetre_Salle::Fenetre_Salle(QWidget* parent, Universite* u, Filiere* f) : QWidget ()

{
    this->u = u ;
    this->f = f ;
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
    //Définir les caractères acceptés ;

    // Choix du type
    type = new QComboBox ;
    type->addItem("CM");
    type->addItem("TP");
    type->addItem("TD");
    // Choix de la matière
    matiere = new QListWidget ;
    // On ajoute les matieres de la filière à la liste
    for(list<Matiere*>::iterator m = f->get_matieres()->begin(); m != f->get_matieres()->end(); ++m) {
        QString item = QString::fromStdString((*m)->get_nom()) ;
        matiere->addItem(item) ;
    }
    // Choix effectif
    effectif = new QSpinBox ;
    effectif->setMinimum(5);
    // Choix batiment
    batiment = new QComboBox ;
    // Pour créer un batiment
    batiment->setEditable(true);

    for(list<Salle*>::iterator s = u->get_salles()->begin(); s != u->get_salles()->end(); ++s) {
        QString item = QString::fromStdString((*s)->get_batiment()->nom) ;
        // On recupère tous le batiment de chaque salle, et on vérifie si il est déjà dans la salle
        if (!batiment->findText(item))
        {
            batiment->addItem(item) ;
        }
    }
    /*
     * On en a plus besoin
    batiment->addItem("Fermat");
    batiment->addItem("Descartes");
    batiment->addItem("Buffon");
    batiment->addItem("Batiment E");
    batiment->addItem("Germain");
    */
    // Ajouter les champs au formulaire
    formulaire = new QFormLayout ;
    formulaire->addRow("Nom", nom);
    formulaire->addRow("Type",type);
    formulaire->addRow("Matière(s)",matiere);
    formulaire->addRow("Effectif Max", effectif);
    formulaire->addRow("Batiment", batiment);

    // Boutons
    ButtonsLayout = new QHBoxLayout ;

    boutonAnnuler = new QPushButton("Annuler");
    QWidget::connect(boutonAnnuler, SIGNAL(clicked()), this, SLOT(close()));
    ButtonsLayout->addWidget(boutonAnnuler); // Ajout du bouton

    boutonAjouter = new QPushButton("Ajouter");
    QWidget::connect(boutonAjouter, SIGNAL(clicked()), this, SLOT(creer_salle()));
    QWidget::connect(this, SIGNAL(actualise()), parent, SLOT(actualise_salle()));

    ButtonsLayout->addWidget(boutonAjouter); // Ajout du bouton

    //Layout principal

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(titleLayout);
    layoutPrincipal->addLayout(formulaire); // Ajout du layout de formulaire
    layoutPrincipal->addLayout(ButtonsLayout) ;

    setLayout(layoutPrincipal);

}
// Fonction qui gère le formulaire
void Fenetre_Salle::creer_salle() {
    // Récupérer les objets université et filière
    Universite* temp_universite = u ;
    Filiere* temp_filiere = f ;

    // Boite de dialogue pour confirmer les informations saisies
    int reponse = QMessageBox::question(this, "Confirmation", "Avez vous bien saisi les informations ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        // Récupérer les input
        QString new_nom = nom->text() ;
        QString new_type = type->currentText() ;
        // Matière
        QList<QListWidgetItem*> liste_matieres = matiere->selectedItems() ;
        QString new_effectif = effectif->cleanText() ;
        QString new_batiment = batiment->currentText() ;

        // Si toutes les informations ont été saisies
        if(!new_nom.isEmpty() && !new_type.isEmpty() && !liste_matieres.isEmpty() && !new_effectif.isEmpty() && !new_batiment.isEmpty())
        {
            // On récupère le batiment
            Batiment new_b;
            if (temp_universite->get_batiment(new_batiment.toStdString()))
            {
               new_b = *temp_universite->get_batiment(new_batiment.toStdString()) ;
            } else
                new_b.nom = new_batiment.toStdString() ;
                new_b.salles= {};

            // Pareil pour type
            Type type ;
            if (new_type == "CM") { type = CM ; }
            else if (new_type == "TD") { type = TD ;}
            else { type = TP ; }
            // Récupérer les matières
            list <Matiere*> salle_materiel ;
            for(int i = 0; i < liste_matieres.count(); ++i)
            {
                //On récupère le premier item
                QString str = liste_matieres.value(i)->text();
                for(list<Matiere*>::iterator m = temp_filiere->get_matieres()->begin(); m != temp_filiere->get_matieres()->end(); ++m) {
                    // Si le nom d'une matière correspond bien à une matiere
                    if (str == QString::fromStdString((*m)->get_nom()))
                    {
                        // On ajoute la matière à la liste des matières de la salle
                        salle_materiel.push_back((*m)) ;
                    }
                }

            }
            // On crée la salle
            Salle *s = new Salle(u, new_nom.toStdString(), 100, NULL,{}, &new_b,salle_materiel, new_effectif.toInt(), type) ;
            // On ajoute la salle au batiment
            new_b.salles.push_back(s);
            // Elle est ajoutée à l'université
            temp_universite->add_salle(s);
             emit actualise();
        }
        // Si le formulaire est incomplet
        else {
            QMessageBox::warning(this, "Formulaire incomplet", "Veuillez complétez tous les champs");
        }

    }


}
