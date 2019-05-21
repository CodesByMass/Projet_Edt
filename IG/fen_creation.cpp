#include "fen_creation.h"
#include "classes/les_h/Filiere.h"
#include "classes/les_h/Groupe.h"
#include "classes/les_h/Universite.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStringListModel>
#include <QListView>
#include <QLabel>
#include <QLineEdit>
#include <QFont>
#include <QStandardItemModel>
#include <QTableView>
#include <QStringBuilder>
#include <QMessageBox>
#include <QComboBox>
#include <QCheckBox>
#include <QThread>
#include <QListWidget>
#include <QList>

using namespace std;
fen_creation::fen_creation(){}



fen_creation::fen_creation(QWidget *parent,Universite *u) : QWidget()
{
    f=new Filiere();
    this->u=u;
    f->set_universite(u);

    formulaire = new QFormLayout ;

    this->setFixedSize(800,600);
    layoutf = new QVBoxLayout();
    ButtonsLayout = new QHBoxLayout();

    // Titre //

    QLabel *titre = new QLabel();
    titre->setText("Nouvel emploi du temps");
    QFont police("Times",20, QFont::Bold );
    titre->setFont(police);
    titre->setAlignment(Qt::AlignHCenter);
    titre->setMargin(20) ;

    // Liste des semestres //

    listeSem = new QComboBox(this);
    listeSem->addItem("1");
    listeSem->addItem("2");
    listeSem->addItem("3");
    listeSem->addItem("4");
    listeSem->addItem("5");
    listeSem->addItem("6");


    filliereEdit = new QLineEdit(this);
    filliereEdit->setValidator(new QRegExpValidator(QRegExp("[a-z,A-Z]*"), filliereEdit));
    filliereEdit->setAlignment(Qt::AlignLeft);


    matieres=u->get_matieres();

    listeMat = new QListWidget();
    listeMat->setSelectionMode(QAbstractItemView::ExtendedSelection);

       for( list<Matiere*>::iterator it = matieres.begin(); it!= matieres.end(); ++it)
        {
            QString item = QString::fromStdString((*it)->get_nom());
            listeMat->addItem(item);
        }

   // Boutons //

    QPushButton *matiereB=new QPushButton("Ajout Matières");
    QObject::connect(matiereB, SIGNAL (clicked()), this, SLOT(crea_fenetre_matiere()));
    ButtonsLayout->addWidget(matiereB);

    QPushButton *precedent=new QPushButton("Précédent");
    QObject::connect(precedent, SIGNAL (clicked()), parent, SLOT(show()));
    QObject::connect(precedent, SIGNAL (clicked()), this, SLOT(close()));
    ButtonsLayout->addWidget(precedent);

    QPushButton *suivant=new QPushButton("Suivant");
    QObject::connect(suivant, SIGNAL (clicked()), this, SLOT(cree_filiere()));
    QObject::connect(this, SIGNAL (ok()), parent, SLOT(show()));
    QObject::connect(this, SIGNAL (ok()), this, SLOT(close()));
    ButtonsLayout->addWidget(suivant);


    formulaire->addRow("&Nom de la fillière", filliereEdit);
    formulaire->addRow("&Selectionner le Semestre", listeSem);
    formulaire->addRow("&Choisir les matières",listeMat);

    layoutf->addWidget(titre);
    layoutf->addLayout(formulaire);
       // Ajout du layout de formulaire
    layoutf->addLayout(ButtonsLayout) ;

     this->setLayout(layoutf);
    this->show();
}

void fen_creation::crea_fenetre_matiere()
{
    this->fm = new fenetre_matiere(this,u,matieres);
    fm->resize(800, 600);
    fm->setWindowTitle("Creation Matiere");
    fm->show();
}

void fen_creation::actualise_List(Matiere* m)
{
    cout<<"Tailles listes dans fen_creation : "<< this->matieres.size() << "\n";

   matieres.push_front(m);
   list<Matiere*>::iterator it = matieres.begin();
   QString item = QString::fromStdString((*it)->get_nom());
   cout<< item.toStdString();
   listeMat->addItem(item);
   listeMat->update();
   formulaire->update();
   layoutf->update();
   this->show();
}

void fen_creation::cree_filiere()
{
    if (!filliereEdit->text().isEmpty())
    {
        string nom =filliereEdit->text().toStdString()+"S"+std::to_string(listeSem->currentIndex()+1);
     if(u->get_filieres(nom) != nullptr)
        {
         QMessageBox::warning(this, "Filiere déjà existante", "Veuillez changer le nom de la filière");
        }
     else
        {
            if (listeSem->currentIndex() != -1 && !listeMat->selectedItems().isEmpty() )
            {
                int sem=listeSem->currentIndex()+1;

                listeMat->selectedItems();

                QList<QListWidgetItem*> lmat =listeMat->selectedItems();

                for( int j=0; j != lmat.size(); ++j)
                 {
                     for( list<Matiere*>::iterator it = matieres.begin(); it!= matieres.end(); ++it)
                     {
                         if (lmat.at(j)->text().toStdString()==(*it)->get_nom() )
                         {
                            f->add_matiere(*it);
                         }
                      }
                 }

                f->set_semestre(sem);
                f->set_nom(nom);

               // EDT * e=new EDT(f, 2, 6, 40);

              //  f->set_edt(e);
                u->add_filiere(f);
             //   u->write_university(u);

                emit ok();
                emit ok2();
             }
            else
            {
                 QMessageBox::warning(this, "Formulaire incomplet", "Veuillez complétez tous les champs");
            }
        }
    }
}


fen_creation::~fen_creation(){}
