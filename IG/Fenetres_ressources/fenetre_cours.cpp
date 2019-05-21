#include "fenetre_cours.h"
#include <QDebug>
Fenetre_cours::Fenetre_cours(QWidget* parent, Universite* u, Filiere* f) : QWidget()
{
    this->u = u ;
    this->f = f ;
    //setFixedSize(400,200) ;
    setWindowTitle("Création d'un cours");

    //Création du titre

    titleLayout = new QHBoxLayout ;
    label = new QLabel("Créer un cours");
    label->setAlignment(Qt::AlignHCenter);
    label->setMargin(20) ;
    QFont police( "Arial", 10, QFont::Bold);
    label->setFont(police) ;
    titleLayout->addWidget(label) ;

    // Création du layout de formulaire et de ses widgets
    // Durée
    duree = new QComboBox ;
    duree->addItem("1h30");
    duree->addItem("3h00");
    // Choix du type
    type = new QComboBox ;
    type->addItem("CM");
    type->addItem("TP");
    type->addItem("TD");
    // Choix des groupes
    groupes = new QListWidget ;
    // On ajoute les groupes de la filière
    for(list<Groupe*>::iterator g = f->get_groupes()->begin(); g != f->get_groupes()->end(); ++g) {
        QString item = QString::fromStdString((*g)->get_identifiant()) ;
        groupes->addItem(item) ;
    }
    // Matieres
    matiere = new QComboBox ;
    // Liste des matières de la filière
    list<Matiere*>* filiere_liste = f->get_matieres() ;
    // On ajoute les matieres de la filière à la liste
    for(list<Matiere*>::iterator m = filiere_liste->begin(); m != filiere_liste->end(); ++m) {
        QString item = QString::fromStdString((*m)->get_nom()) ;
        matiere->addItem(item) ;
    }
    // Enseignants
    enseignants = new QComboBox ;
    enseignants->addItem("Non Défini") ;
    // Enseignants qui enseignent les matières de la filiere
    for(list<Enseignant*>::iterator e = u->get_enseignants()->begin(); e != u->get_enseignants()->end(); ++e) {
        //Pour chaque enseignant de l'université, vérifie si il enseigne une matière de la filière
        for(list<Matiere*>::iterator m = filiere_liste->begin(); m != filiere_liste->end(); ++m)
        {


            // Si la matière est bien enseignée par l'enseignant
            if  ((*e)->get_specialites( (*m)->get_nom()) != NULL)
            {
                QString item = QString::fromStdString((*e)->get_identifiant()) ;
                //Si il n'est pas dans la combo box
                if (enseignants->findText(item)== -1)
                {
                    enseignants->addItem(item) ;
                }
            }
        }
    }
    // Salles
    salles = new QComboBox ;
    salles->addItem("Non Définie") ;
    for(list<Salle*>::iterator s = u->get_salles()->begin(); s != u->get_salles()->end(); ++s) {
        //Pour chaque salle, vérifier si elle est bien dans la liste des matières
        for(list<Matiere*>::iterator m = filiere_liste->begin(); m != filiere_liste->end(); ++m) {
            // Si la matière est bien prise en charge par la salle
            if  ((*s)->get_materiels((*m)->get_nom()) != NULL) {
               QString item = QString::fromStdString((*s)->get_identifiant()) ;
                if (salles->findText(item)== -1)
                    salles->addItem(item) ;
            }
        }
            }
            // Layout formulaire
            formulaire = new QFormLayout;
            formulaire->addRow("&Durée", duree);
            formulaire->addRow("&Type", type);
            formulaire->addRow("&Matiere", matiere);
            formulaire->addRow("&Enseignant", enseignants);
            formulaire->addRow("&Salle", salles);
            formulaire->addRow("&Groupes", groupes);

            // Boutons
            ButtonsLayout = new QHBoxLayout ;

            boutonAnnuler = new QPushButton("Annuler");
            QWidget::connect(boutonAnnuler, SIGNAL(clicked()), this, SLOT(close()));
            ButtonsLayout->addWidget(boutonAnnuler); // Ajout du bouton

            boutonAjouter = new QPushButton("Ajouter");
            QWidget::connect(boutonAjouter, SIGNAL(clicked()), this, SLOT(creer_Cours()));
            QWidget::connect(this, SIGNAL(actualiseOnglet(Cours* )), parent, SLOT(actualise_cours(Cours* )));
            ButtonsLayout->addWidget(boutonAjouter); // Ajout du bouton

            // Connexion choix de matières avec actualisation de la liste des enseignants et des salles disponibles
            QWidget::connect(matiere, SIGNAL(currentTextChanged(QString)), this, SLOT(actualiser_listes(QString))) ;
                       //Layout principal

            QVBoxLayout *layoutPrincipal = new QVBoxLayout;
            layoutPrincipal->addLayout(titleLayout);
            layoutPrincipal->addLayout(formulaire); // Ajout du layout de formulaire
            layoutPrincipal->addLayout(ButtonsLayout) ;

            setLayout(layoutPrincipal);
}

        void Fenetre_cours::actualiser_listes(const QString &matiere_actuelle)
        {

            // Actualiser salles
            salles->clear() ;
            salles->addItem("Non Définie");
            Matiere* temp_matiere = f->get_matieres(matiere_actuelle.toStdString()) ;
            for(list<Salle*>::iterator s = u->get_salles()->begin(); s != u->get_salles()->end(); ++s)
            {

                //Pour chaque salle, vérifier si elle est bien dans la liste des matières
                    // Si la matière est bien prise en charge par la salle

                    if  ((*s)->get_materiels(temp_matiere->get_nom()) != NULL)
                    {
                        QString item = (QString::fromStdString((*s)->get_identifiant()) );
                        if (salles->findText(item) == -1)
                            salles->addItem(item) ;
                    }
            }



            //Actualiser enseignants
            enseignants->clear() ;
            enseignants->addItem("Non Défini") ;
            for(list<Enseignant*>::iterator e = u->get_enseignants()->begin(); e != u->get_enseignants()->end(); ++e)
                    // Si la matière est bien enseignée par l'enseignant
                    if  ((*e)->get_specialites(temp_matiere->get_nom()) != NULL)
                    {
                        QString item = QString::fromStdString((*e)->get_identifiant()) ;
                       // qDebug() << QString::fromStdString((*e)->get_identifiant());
                        //Si il n'est pas dans la combo box
                        if (enseignants->findText(item) == -1)
                        {
                            enseignants->addItem(item) ;
                        }
                }
        }

        void Fenetre_cours::creer_Cours()
        {
            Universite* temp_universite = u ;
            Filiere* temp_filiere = f ;
            // Boite de dialogue pour confirmer les informations saisies
            int reponse = QMessageBox::question(this, "Confirmation", "Avez vous bien saisi les informations ?", QMessageBox ::Yes | QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                // Récupérer les input ;
                // Récupérer la durée en ajoutant 1 car le générateur utilise 1 ou 2, pas 0 ou 1
                int c_duree = duree->currentIndex() + 1 ;
                QString new_type = type->currentText() ;
                // Récupérer enseignant, matiere et salle
                QString new_enseignant = enseignants->currentText() ;
                QString new_salle = salles->currentText() ;
                QString new_matiere = matiere->currentText() ;
                // Récuperer la liste de groupes choisis
                QList<QListWidgetItem*> liste_groupes = groupes->selectedItems() ;

                if (!new_type.isEmpty() && !liste_groupes.isEmpty() && !new_enseignant.isEmpty() && !new_salle.isEmpty() && !new_matiere.isEmpty()) {
                    // prendre le type
                    Type c_type ;
                    if (new_type == "CM") { c_type = CM ; }
                    else if (new_type == "TD") { c_type = TD ;}
                    else { c_type = TP ; }
                    // récupérer enseignant
                    Enseignant* c_enseignant = temp_universite->get_enseignants(new_enseignant.toStdString()) ;
                    // récupérer salle
                    Salle* c_salle = temp_universite->get_salles(new_salle.toStdString());
                    // Récupérer la matière
                    Matiere* c_matiere = temp_filiere->get_matieres(new_matiere.toStdString());
                    // transformer la liste saisie en liste de groupes
                    list <Groupe*> groupes_cours ;
                    for(int i = 0; i < liste_groupes.count(); ++i)
                    {
                        //On récupère le premier item
                        list<Groupe*>* groupes = temp_filiere->get_groupes() ;
                        QString str = liste_groupes.value(i)->text();
                        for(list<Groupe*>::iterator m = groupes->begin(); m != groupes->end(); ++m) {
                            // Si le nom d'une matière correspond bien à une matiere
                            if (str == QString::fromStdString((*m)->get_identifiant()))
                            {
                                // On ajoute la matière à la liste des matières de l'enseignant
                                groupes_cours.push_back((*m)) ;
                            }
                        }
                    }
                    // Créer le cours
                    //Dernière vérification pour la matiere
                    if (c_matiere == NULL)
                    {
                        QMessageBox::critical(this, "Erreur", "Une erreur s'est produit, veuillez réessayer");
                    }
                    else {

                    }
                    Cours *c = new Cours(c_salle, groupes_cours, c_enseignant, c_type, c_matiere, {},c_duree,-1,-1);
                    c_matiere->add_cours(c);
                    c_enseignant->add_cours(c);
                    c_salle->add_cours(c);
                    QMessageBox::information(this, "Cours créé", "Le nouveau cours a bien été créé");
                    emit actualiseOnglet(c);
                }
                }
                else {
                    QMessageBox::warning(this, "Formulaire incomplet", "Veuillez complétez tous les champs");
                }
            }

