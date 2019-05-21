#include "fen_modificationedt.h"
#include "../SGF/SGF.h"
#include "../GenerateurEDT/GenerateurEDT.h"
#include "./Fenetres_ressources/fenetre_cours.h"
#include "./Fenetres_ressources/fenetre_enseignant.h"
#include "./Fenetres_ressources/fenetre_groupe.h"
#include "./Fenetres_ressources/fenetre_salle.h"

#include <QApplication>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QStringListModel>
#include <QListView>
#include <QVariant>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QHeaderView>
#include <QTableWidget>
#include <QString>
#include <QMessageBox>
#include <QStyleFactory>


void Fen_ModificationEDT::ressourceSelectionnee()
{
    QItemSelectionModel *selection=nullptr;
    QListWidget *modeleliste = nullptr;

    if(onglets->currentIndex() == 0)
    {
        modeleliste = this->listeCoursOnglet;
    }
    if(onglets->currentIndex() == 1)
    {
        modeleliste = this->listeEnseignantOnglet;
    }
    if(onglets->currentIndex() == 2)
    {
        modeleliste = this->listeSalleOnglet;
    }
    if(onglets->currentIndex() == 3)
    {
        modeleliste = this->listeGroupeOnglet;
    }

    QString ressourcesSelectionnes;

    for (int i = 0 ; i < modeleliste->selectedItems().size() ; i++)
    {
       QVariant elementSelectionne = modeleliste->item(i)->text();
       ressourcesSelectionnes += elementSelectionne.toString() + "<br />";
       if(onglets->currentIndex() < 3)
       {
           if(ajouter_dans_edt(onglets->currentIndex(),elementSelectionne.toString())== -1)
           {
               QMessageBox::warning(this, "Erreur", "<br /><br />Attention Emplois du temps plein cet élement de la liste n'a pas été ajoutés :" + elementSelectionne.toString());
           }
       }
       else
       {
           int c = 0;
           while( c < listeGroupe->count() && listeGroupe->itemText(c) != elementSelectionne.toString())c++;  //Eviter les doublons de groupe
           if(c == listeGroupe->count()) listeGroupe->addItem(elementSelectionne.toString());
           else {
               QMessageBox::warning (this, "Erreur", "<br/><br />Attention  " + elementSelectionne.toString() + "  déjà existant il n'a pas été rajouté ");
           }
       }
    }
    QMessageBox::information(this, "Eléments sélectionnés", ressourcesSelectionnes);
}
void Fen_ModificationEDT::affiche_cours()
{

       listeCoursOnglet->setSelectionMode(QAbstractItemView::ExtendedSelection);

       /*for( list<Cours*>::iterator it = f->get_matieres()->get_cours()->begin(); it!=  u->get_enseignants()->end(); ++it)
          {
              QString ens = QString::fromStdString((*it)->get_identifiant());
              listeCoursOnglet->addItem(ens);
          }*/
       vbox1->addWidget(listeCoursOnglet,0,0);

       buttonselection = new QPushButton("Ajouter la sélection");
       connect(buttonselection, SIGNAL(clicked()), this, SLOT(ressourceSelectionnee()));
       vbox1->addWidget(buttonselection,1,0);

       buttonressources = new QPushButton("+", this);
       connect(buttonressources, SIGNAL (clicked()), this, SLOT(cree_fen_ajout_cours()));
       vbox1->addWidget(buttonressources,0,1);

}
void Fen_ModificationEDT::affiche_enseignants()
{
       listeEnseignantOnglet->setSelectionMode(QAbstractItemView::ExtendedSelection);

          for( list<Enseignant*>::iterator it = u->get_enseignants()->begin(); it!=  u->get_enseignants()->end(); ++it)
           {
               QString ens = QString::fromStdString((*it)->get_identifiant());
               listeEnseignantOnglet->addItem(ens);
           }
       vbox2->addWidget(listeEnseignantOnglet,0,0);
       buttonselection = new QPushButton("Ajouter la sélection");
       connect(buttonselection, SIGNAL(clicked()), this, SLOT(ressourceSelectionnee()));
       vbox2->addWidget(buttonselection,1,0);

       buttonressources = new QPushButton("+", this);
       connect(buttonressources, SIGNAL (clicked()), this, SLOT(cree_fen_ajout_enseignant()));
       vbox2->addWidget(buttonressources,0,1);

}

void Fen_ModificationEDT::affiche_salles()
{
    list<string> listeSalles;
       listeSalleOnglet->setSelectionMode(QAbstractItemView::ExtendedSelection);

          for( list<Matiere*>::iterator i = f->get_matieres()->begin(); i!=  f->get_matieres()->end(); ++i)
           {
              for( list<Salle*>::iterator j = u->get_salles()->begin(); j!=  u->get_salles()->end(); ++j)
              {
                  if((*j)->get_materiels((*i)->get_nom()) )
                  {
                      listeSalles.push_front((*j)->get_identifiant());
                  }
               }
           }

          cout <<"TAILLE LISTE " << listeSalles.size() << "\n";

          listeSalles.sort();
          listeSalles.unique();

           cout <<"TAILLE LISTE " << listeSalles.size() << "\n";

          for (list<string>::iterator i=listeSalles.begin(); i!=listeSalles.end(); ++i)
          {
              QString salle = QString::fromStdString(*i);
              listeSalleOnglet->addItem(salle);
           }


       vbox3->addWidget(listeSalleOnglet,0,0);
       buttonselection = new QPushButton("Ajouter la sélection");
       connect(buttonselection, SIGNAL(clicked()), this, SLOT(ressourceSelectionnee()));
       vbox3->addWidget(buttonselection,1,0);


       buttonressources = new QPushButton("+", this);
       connect(buttonressources, SIGNAL (clicked()), this, SLOT(cree_fen_ajout_salle()));
       vbox3->addWidget(buttonressources,0,1);
}


void Fen_ModificationEDT::affiche_groupe()
{
    listeGroupeOnglet->setSelectionMode(QAbstractItemView::ExtendedSelection);

       for( list<Groupe*>::iterator it = f->get_groupes()->begin(); it!=  f->get_groupes()->end(); ++it)
        {
            QString groupe = QString::fromStdString((*it)->get_identifiant());
            listeGroupeOnglet->addItem(groupe);
        }

    vbox4->addWidget(listeGroupeOnglet,0,0);

    buttonselection = new QPushButton("Ajouter la sélection");
    connect(buttonselection, SIGNAL(clicked()), this, SLOT(ressourceSelectionnee()));
    vbox4->addWidget(buttonselection,1,0);


    buttonressources = new QPushButton("+", this);
    connect(buttonressources, SIGNAL (clicked()), this, SLOT(cree_fen_ajout_groupe()));
    vbox4->addWidget(buttonressources,0,1);
}

void Fen_ModificationEDT::affiche_onglets()
{
    QWidget fenetre;

    onglets = new QTabWidget(&fenetre);     // Créer le QTabWidget
    onglets->setGeometry(30, 20, 240, 160);

    // 2 : Créer les pages, en utilisant un widget parent pour contenir chacune des pages
    ongletPage1 = new QWidget;
    ongletPage2 = new QWidget;
    ongletPage4 = new QWidget;
    ongletPage3 = new QWidget;
    // 3 : Créer le contenu des pages de widgets
        // Page 1

    vbox1 = new QGridLayout;
    vbox2 = new QGridLayout;
    vbox3 = new QGridLayout;
    vbox4 = new QGridLayout;

    listeCoursOnglet = new QListWidget();
    listeEnseignantOnglet = new QListWidget();
    listeSalleOnglet = new QListWidget();
    listeGroupeOnglet = new QListWidget();
    affiche_cours();
    affiche_enseignants();
    affiche_salles();
    affiche_groupe();

    ongletPage1->setLayout(vbox1);
    ongletPage2->setLayout(vbox2);
    ongletPage3->setLayout(vbox3);
    ongletPage4->setLayout(vbox4);

    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(ongletPage1, "Cours");
    onglets->addTab(ongletPage2, "Enseignant");
    onglets->addTab(ongletPage3, "Salle");
    onglets->addTab(ongletPage4, "Groupe");

    layout->addWidget(onglets);
    setLayout(layout);
}
int Fen_ModificationEDT::ajouter_dans_edt(int nonglet ,QString s )
{
    for(int x=0; x < this->tableauEDT->rowCount();x+=3)
    {
       for(int y=1; y < this->tableauEDT->columnCount();y++)
        {
           if(nonglet==0 && this->tableauEDT->item(x,y)==nullptr)
            {
                tableauEDT->setItem(x, y, new QTableWidgetItem(s));
                return 1;
            }
           if(nonglet==1 && this->tableauEDT->item(x+1,y)==nullptr)
            {
                tableauEDT->setItem(x+1, y, new QTableWidgetItem(s));
                return 1;
            }
           if(nonglet==2 && this->tableauEDT->item(x+2,y)==nullptr)
            {
                tableauEDT->setItem(x+2, y, new QTableWidgetItem(s));
                return 1;
            }
      }
    }
return -1; //EDT plein
}
void Fen_ModificationEDT::sauvegarder()
{

    for(int x=0; x == this->tableauEDT->rowCount();x+=3)
   {
       for(int y=0; y == this->tableauEDT->columnCount();y++)
       {
          QString s = this->tableauEDT->item(x,y)->text();
          QString sa = this->tableauEDT->item(x,y+1)->text();
          QString e = this->tableauEDT->item(x,y+1)->text();

          for( list<Matiere*>::iterator it = f->get_matieres()->begin(); it!= f->get_matieres()->end(); ++it)
          {
              if((*it)->get_cours(s.toStdString()))
              {
                (*it)->get_cours(s.toStdString())->set_emplacement(x/3,y);

                Enseignant *enseignant = (*it)->get_cours(s.toStdString())->get_enseignant();
                enseignant->set_identifiant(e.toStdString());
                (*it)->get_cours(s.toStdString())->set_enseignant(enseignant);

                Salle* salle = (*it)->get_cours(s.toStdString())->get_salle();
                salle->set_identifiant(sa.toStdString());
                (*it)->get_cours(s.toStdString())->set_salle(   salle   );
              }
          }
       }
   }
    ecriture_universite(u);
}

void Fen_ModificationEDT::remplir_edt()
{
    for(int x=0; x < this->tableauEDT->rowCount();x+=3)
        {
           for(int y=0; y < this->tableauEDT->columnCount();y++)
            {
               for( list<Matiere*>::iterator it = f->get_matieres()->begin(); it!= f->get_matieres()->end(); ++it)
               {

                   for( list<Cours*>::iterator co = (*it)->get_cours()->begin(); co!= (*it)->get_cours()->end(); ++co)
                   {


                       if((*co)->get_emplacement()[1] ==x/3 && (*co)->get_emplacement()[0] ==y )
                       {
                           tableauEDT->setItem(x, y, new QTableWidgetItem(  QString::fromStdString((*co)->get_type_string() + (*co)->get_matiere()->get_nom()  )));
                           tableauEDT->setItem(x+1, y, new QTableWidgetItem( QString::fromStdString( (*co)->get_enseignant()->get_identifiant()   ) ));
                           tableauEDT->setItem(x+2, y, new QTableWidgetItem(QString::fromStdString( (*co)->get_salle()->get_identifiant()   )));

                       }
                   }
                }
            }
        }
}


void Fen_ModificationEDT::celluleSelectionnee(int nRow, int nCol)
{
    //QMessageBox::warning (this, "Erreur", "Attention  selected" + nRow.toString() + nCol.toString() ");
    this->tableauEDT->takeItem(nRow,nCol);
    qDebug() <<nRow<< nCol << this->tableauEDT->item(nRow,nCol) ;
}

void Fen_ModificationEDT::affiche_EDT()
{

   tableauEDT = new QTableWidget(this);
    tableauEDT->setRowCount(24);
    tableauEDT->setColumnCount(6);

    QStringList      m_TableHeaderH ;
    m_TableHeaderH <<"Lundi"<<"Mardi"<<"Mercredi"<<"Jeudi"<<"Vendredi"<<"Samedi";
    tableauEDT->setHorizontalHeaderLabels(m_TableHeaderH);

    QStringList      m_TableHeaderV ;
    m_TableHeaderV <<"8h 9h30"<< "" <<""<<"9h40 11h10"<< "" <<"" <<"11h20 12h50"<< "" <<""<<"13h 13h30"<<""
                  <<""<<"13h40 15h10"<< "" <<""<<"15h20 16h50"<< "" <<""<<"17h 18h30" <<""<<""<< "18h40 20h10"<<""<<"";
    tableauEDT->setVerticalHeaderLabels(m_TableHeaderV);

    tableauEDT->setAlternatingRowColors(1);

    tableauEDT->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableauEDT->setSelectionBehavior(QAbstractItemView::SelectItems);
    tableauEDT->setAcceptDrops(false);
    tableauEDT->setDragDropMode(QAbstractItemView::InternalMove);
    tableauEDT->setDropIndicatorShown(true);
    tableauEDT->setDragDropOverwriteMode(false);
    tableauEDT->setShowGrid(true);
    tableauEDT->verticalHeader()->setStyle(QStyleFactory::create("CleanLooks"));

    tableauEDT->setStyleSheet("QTableView {selection-background-color: red;}");

    tableauEDT->setSelectionMode(QAbstractItemView::ExtendedSelection);

    tableauEDT->setDropIndicatorShown(false);  //Evite l'insertion en drag&drop entre les lignes


    //insert data
    tableauEDT->setItem(0, 1, new QTableWidgetItem("Hello"));

    connect( tableauEDT, SIGNAL( cellDoubleClicked (int, int) ),this, SLOT( celluleSelectionnee( int, int ) ) );
    layout->addWidget(tableauEDT);
}

void Fen_ModificationEDT::bouton_sauvegarde()
{
    QPushButton *buttonSauvegarder;

    // Create the button, make "this" the parent
    buttonSauvegarder = new QPushButton("Sauvegarder");
    // set size and location of the button
    buttonSauvegarder->setObjectName("buttonsauvegarder");
    buttonSauvegarder->setStyleSheet("QWidget#buttonsauvegarder {background-color: green}");

    layout->addWidget(buttonSauvegarder);
    connect(buttonSauvegarder, SIGNAL (clicked()), this, SLOT(sauvegarder()));

}

void Fen_ModificationEDT::exec_generationEDT()
{
       f->set_edt(GenereEDT(u,f, f->get_edt(), 3));

        //EvalueEDT(u,f->get_edt(),2);

        AfficheEDT(u->get_filieres("S6INFO")->get_edt()); //Affichage terminal pour tester

        //conv_latex(u->get_filieres("S6INFO")->get_edt());

        ecriture_universite(u);
        remplir_edt();
}

void Fen_ModificationEDT::bouton_generationEDT()
{
    QPushButton *buttonGenererEDT;

    buttonGenererEDT = new QPushButton("Générer un emplois du temps");
    buttonGenererEDT->setObjectName("bouton_generationEDT");
    buttonGenererEDT->setStyleSheet("QWidget#bouton_generationEDT {background-color: red}");

    layout->addWidget(buttonGenererEDT);
    connect(buttonGenererEDT, SIGNAL (clicked()), this, SLOT(exec_generationEDT()));

}

void Fen_ModificationEDT::bouton_generationLATEX()
{
    QPushButton *bouton_generationLATEX;

    bouton_generationLATEX = new QPushButton("Générer un emplois du temps LaTeX");
    bouton_generationLATEX->setObjectName("bouton_generationLATEX");
    bouton_generationLATEX->setStyleSheet("QWidget#bouton_generationLATEX {background-color: blue}");

    layout->addWidget(bouton_generationLATEX);
    connect(bouton_generationLATEX, SIGNAL (clicked()), this, SLOT(conv()));

}

Fen_ModificationEDT::Fen_ModificationEDT(QWidget *parent, Universite* u) : QWidget()
{
    this->u=u;
    this->f=new Filiere();
    EDT*e = new EDT(f, 90,6,8);
    this->f->set_edt(e);

     layout = new QVBoxLayout;
    affiche_onglets();

    affiche_EDT();

   bouton_sauvegarde();
   bouton_generationEDT();
   bouton_generationLATEX();

   listeFiliere = new QComboBox(this);
    for( list<Filiere*>::iterator it = u->get_filieres()->begin(); it!= u->get_filieres()->end(); ++it)
     {
        string filieres =(*it)->get_nom();
        listeFiliere->addItem(QString::fromStdString(filieres));
     }
     layout->addWidget(listeFiliere);

     connect(listeFiliere,SIGNAL(currentTextChanged(const QString)),this, SLOT(changefiliere()));

    listeGroupe = new QComboBox(this);

    string nomfil=(listeFiliere->currentText()).toStdString();
    f=u->get_filieres(nomfil);

   for( list<Groupe*>::iterator it = f->get_groupes()->begin(); it!=  f->get_groupes()->end(); ++it)
     {
        string groupe =(*it)->get_identifiant();
        listeGroupe->addItem(QString::fromStdString(groupe));
     }
    layout->addWidget(listeGroupe);

}

void Fen_ModificationEDT::cree_fen_ajout_groupe()
{
     cout<< "NOM DE LA FILIERE :" << f->get_nom()<< "STOP \n";
    Fenetre_Groupe *fg = new Fenetre_Groupe(this,u,f);
    fg->setWindowTitle("Ajout groupe");
    fg->show();
}
void Fen_ModificationEDT::actualise_groupe()
{
     string groupe =f->get_groupes()->front()->get_identifiant();
     listeGroupeOnglet->addItem(QString::fromStdString(groupe));
}

void Fen_ModificationEDT::cree_fen_ajout_cours()
{
    Fenetre_cours *fc = new Fenetre_cours(this,u,f);
    fc->setWindowTitle("Ajout cours");
    fc->show();
}

void Fen_ModificationEDT::actualise_cours(Cours* c)
{
    string cours;
    switch (c->get_type()) {
    case TD: cours= "TD"; break;
    case TP:cours= "TP"; break;
    case CM:cours= "CM"; break;
    }
     cours += c->get_matiere()->get_nom() ;
     listeCoursOnglet->addItem(QString::fromStdString(cours));
}

void Fen_ModificationEDT::cree_fen_ajout_enseignant()
{
    Fenetre_Enseignant *fe= new Fenetre_Enseignant(this,u,f);
    fe->setWindowTitle("Ajout enseignant");
    fe->show();
}

void Fen_ModificationEDT::actualise_enseignant(Enseignant* e)
{
     string enseignant =e->get_identifiant();
     listeEnseignantOnglet->addItem(QString::fromStdString(enseignant));
}

void Fen_ModificationEDT::cree_fen_ajout_salle()
{
    Fenetre_Salle *fs= new Fenetre_Salle(this,u,f);
    fs->setWindowTitle("Ajout salle");
    fs->show();
}

void Fen_ModificationEDT::actualise_salle()
{
    string salle =u->get_salles()->front()->get_identifiant();
    listeSalleOnglet->addItem(QString::fromStdString(salle));
}
void Fen_ModificationEDT::changefiliere ()
{
    string nomfil=(listeFiliere->currentText()).toStdString();
    this->f=u->get_filieres(nomfil);

    listeCoursOnglet->clear();
    affiche_cours();
    listeSalleOnglet->clear();
    affiche_salles();
    listeEnseignantOnglet->clear();
    affiche_enseignants();
    listeGroupeOnglet->clear();
    affiche_groupe();
    tableauEDT->clearContents();

    listeGroupe->clear();

    for( list<Groupe*>::iterator it = f->get_groupes()->begin(); it!=  f->get_groupes()->end(); ++it)
      {
         string groupe =(*it)->get_identifiant();
         listeGroupe->addItem(QString::fromStdString(groupe));
      }
     layout->addWidget(listeGroupe);



}

void Fen_ModificationEDT::conv()
{
    conv_latex(this->f->get_edt());
}

Fen_ModificationEDT::~Fen_ModificationEDT()
{

}
