#include "fenetre_enseignant.h"

Fenetre_Enseignant::Fenetre_Enseignant(QWidget* parent, Universite* u, Filiere* f) : QWidget ()
{
    this->u = u ;
    this->f = f ;
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
    //prenom = new QLineEdit ;
    matiere = new QListWidget ;
    // On ajoute les matieres de la filière à la liste
    list<Matiere*> matieres = u->get_matieres() ;
    for(list<Matiere*>::iterator m = matieres.begin(); m != matieres.end(); ++m) {
        QString item = QString::fromStdString((*m)->get_nom()) ;
        matiere->addItem(item) ;
    }
    // Volume horaire
    VH = new QSpinBox ;
    formulaire->addRow("&Nom", nom) ;
    //formulaire->addRow("&Prénom", prenom) ;
    formulaire->addRow("&Matière", matiere) ;
    formulaire->addRow("&Volume Horaire", VH) ;

    // Tableau de disponibilités
    QLabel* disponibilites = new QLabel("Disponibilités");
    disponibilites->setAlignment(Qt::AlignLeft);
    disponibilites->setMargin(20) ;
    disponibilites->setFont(QFont( "Arial", 8, QFont::Bold)) ;
    dispos = new QTableWidget(6,2,this) ;
    jours = new QTableWidgetItem("Jours");
    heureMin = new QTableWidgetItem("Heure minimum");
    heureMax = new QTableWidgetItem("Heure Max");
    lundi = new QTableWidgetItem("lundi");
    mardi = new QTableWidgetItem("Mardi");
    mercredi = new QTableWidgetItem("Mercredi");
    jeudi = new QTableWidgetItem("Jeudi");
    vendredi = new QTableWidgetItem("Vendredi");
    samedi = new QTableWidgetItem("Samedi");
    //dispos->setHorizontalHeaderItem(0,jours);
    dispos->setHorizontalHeaderItem(0,heureMin);
    dispos->setHorizontalHeaderItem(1,heureMax);
    //    dispos->setVerticalHeaderItem(0,jours);
    dispos->setVerticalHeaderItem(0,lundi);
    dispos->setVerticalHeaderItem(1,mardi);
    dispos->setVerticalHeaderItem(2,mercredi);
    dispos->setVerticalHeaderItem(3,jeudi);
    dispos->setVerticalHeaderItem(4,vendredi);
    dispos->setVerticalHeaderItem(5,samedi);
    // Insérer les champs
    QStringList creneaux = { "Non disponible","8h", "9h40", "11h20", "13h40","15h20", "17h", "18h40" } ;
    heureMin0 = new QComboBox;
    heureMin0->addItems(creneaux);
    dispos->setCellWidget(0,0 , heureMin0);
    heureMin1 = new QComboBox;
    heureMin1->addItems(creneaux);
    dispos->setCellWidget(1,0 , heureMin1);
    heureMin2 = new QComboBox;
    heureMin2->addItems(creneaux);
    dispos->setCellWidget(2,0 , heureMin2);
    heureMin3 = new QComboBox;
    heureMin3->addItems(creneaux);
    dispos->setCellWidget(3,0 , heureMin3);
    heureMin4 = new QComboBox;
    heureMin4->addItems(creneaux);
    dispos->setCellWidget(4,0 , heureMin4);
    heureMin5 = new QComboBox;
    heureMin5->addItems(creneaux);
    dispos->setCellWidget(5,0 , heureMin5);
    heureMax0 = new QComboBox;
    heureMax0->addItems(creneaux) ;
    dispos->setCellWidget(0,1 , heureMax0);
    heureMax1 = new QComboBox;
    heureMax1->addItems(creneaux);
    dispos->setCellWidget(1,1 , heureMax1);
    heureMax2 = new QComboBox;
    heureMax2->addItems(creneaux);
    dispos->setCellWidget(2,1 , heureMax2);
    heureMax3 = new QComboBox;
    heureMax3->addItems(creneaux) ;
    dispos->setCellWidget(3,1 , heureMax3);
    heureMax4 = new QComboBox;
    heureMax4->addItems(creneaux);
    dispos->setCellWidget(4,1 , heureMax4);
    heureMax5 = new QComboBox;
    heureMax5->addItems(creneaux);
    dispos->setCellWidget(5,1 , heureMax5);

    // Boutons
    ButtonsLayout = new QHBoxLayout ;

    boutonAnnuler = new QPushButton("Annuler");
    QWidget::connect(boutonAnnuler, SIGNAL(clicked()), this, SLOT(close()));
    ButtonsLayout->addWidget(boutonAnnuler); // Ajout du bouton annuler

    boutonAjouter = new QPushButton("Ajouter");
    QWidget::connect(boutonAjouter, SIGNAL(clicked()), this, SLOT(creer_enseignant()));
    QWidget::connect(this, SIGNAL(actuListe(Enseignant *)), parent, SLOT(actualise_enseignant(Enseignant *)));

    ButtonsLayout->addWidget(boutonAjouter); // Ajout du bouton ajouter

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(titleLayout);
    layoutPrincipal->addLayout(formulaire); // Ajout du layout de formulaire
    layoutPrincipal->addWidget(disponibilites);
    layoutPrincipal->addWidget(dispos);
    layoutPrincipal->addLayout(ButtonsLayout) ;

    setLayout(layoutPrincipal);

}

void Fenetre_Enseignant::creer_enseignant() {
    // Récupérer les objets université et filière
    Universite* temp_universite = u ;
    Filiere* temp_filiere = f ;

    // Boite de dialogue pour confirmer les informations saisies
    int reponse = QMessageBox::question(this, "Confirmation", "Avez vous bien saisi les informations ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        // Récupérer les input
        QString new_nom = nom->text() ;
        // Matière
        QList<QListWidgetItem*> liste_matieres = matiere->selectedItems() ;
        // Vh
        QString new_VH = VH->cleanText() ;
        // Les disponibilites
        // Diminuer de -1 pour faire correspondre avec les valeurs du module générateur
        int hmin0 = heureMin0->currentIndex() - 1 ;
        int hmin1 = heureMin1->currentIndex() - 1 ;
        int hmin2 = heureMin2->currentIndex() - 1 ;
        int hmin3 = heureMin4->currentIndex() - 1 ;
        int hmin4 = heureMin4->currentIndex() - 1 ;
        int hmin5 = heureMin5->currentIndex() - 1 ;
        int hmax0 = heureMax0->currentIndex() - 1 ;
        int hmax1 = heureMax1->currentIndex() - 1 ;
        int hmax2 = heureMax2->currentIndex() - 1 ;
        int hmax3 = heureMax4->currentIndex() - 1 ;
        int hmax4 = heureMax4->currentIndex() - 1 ;
        int hmax5 = heureMax5->currentIndex() - 1 ;
        // Si toutes les informations ont été saisies
        if(!new_nom.isEmpty() && !new_VH.isEmpty())
        {
            if (hmin0 > hmax0 || hmin1 > hmax1 || hmin2 > hmax2 || hmin3 > hmax3 || hmin4 > hmax4 || hmin5 > hmax5)
            {
                QMessageBox::warning(this, "Disponibilités incorrectes", "Un créneau maximal ne peut pas être avant un créneau minimal");
            }
            else {
                // Ajouter la liste de matières
                list <Matiere*> enseignant_matieres ;
                for(int i = 0; i < liste_matieres.count(); ++i)
                {
                    //On récupère le premier item
                    list<Matiere*> matieres = u->get_matieres() ;
                    QString str = liste_matieres.value(i)->text();
                    for(list<Matiere*>::iterator m = matieres.begin(); m != matieres.end(); ++m) {
                        // Si le nom d'une matière correspond bien à une matiere
                        if (str == QString::fromStdString((*m)->get_nom()))
                        {
                            // On ajoute la matière à la liste des matières de l'enseignant
                            enseignant_matieres.push_back((*m)) ;
                        }
                    }
                }
                //On remplit le tableau de disponiblités
                int dispos_array[6][2] ;
                dispos_array[0][0] = hmin0 ;
                dispos_array[0][1] = hmax0 ;
                dispos_array[1][0] = hmin1 ;
                dispos_array[1][1] = hmax1 ;
                dispos_array[2][0] = hmin2 ;
                dispos_array[2][1] = hmax2 ;
                dispos_array[3][0] = hmin3 ;
                dispos_array[3][1] = hmax3 ;
                dispos_array[4][0] = hmin4 ;
                dispos_array[4][1] = hmax4 ;
                dispos_array[5][0] = hmin5 ;
                dispos_array[5][1] = hmax5 ;

                // On crée l'enseignant
                Enseignant *e = new Enseignant(temp_universite,new_nom.toStdString(), new_VH.toInt(), dispos_array, {},enseignant_matieres) ;
                // L'ajouter à l'université
                temp_universite->add_enseignant(e);
                //Ajouter l'enseignant à ses matières
                for(list<Matiere*>::iterator m = enseignant_matieres.begin(); m != enseignant_matieres.end(); ++m) {
                    (*m)->add_enseignant(e);
                QMessageBox::information(this, "Enseignant ajouté", "Le nouvel enseignant est correctement ajouté");
                 emit actuListe(e);
                }
            }
        }
        else {
            QMessageBox::warning(this, "Formulaire incomplet", "Veuillez complétez tous les champs");
        }
    }

}
