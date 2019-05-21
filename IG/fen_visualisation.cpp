#include "fen_visualisation.h"
#include <QDebug>
#include <QApplication>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QStringListModel>
#include <QListView>
#include <QVariant>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QString>
#include <QHeaderView>
#include <QAbstractItemView>
void Fen_VisualisationEDT::visualise_EDT()
{
    tableauEDTvisuel = new QTableWidget(this);
    tableauEDTvisuel->setRowCount(24);
    tableauEDTvisuel->setColumnCount(6);

    QStringList      m_TableHeaderH ;
    m_TableHeaderH <<"Jour/Horaire"<<"Lundi"<<"Mardi"<<"Mercredi"<<"Jeudi"<<"Vendredi"<<"Samedi";
    tableauEDTvisuel->setHorizontalHeaderLabels(m_TableHeaderH);
    tableauEDTvisuel->verticalHeader()->setVisible(false);
    tableauEDTvisuel->setItem(0, 0, new QTableWidgetItem("8h 9h30"));
    tableauEDTvisuel->setItem(3, 0, new QTableWidgetItem("9h40 11h10"));
    tableauEDTvisuel->setItem(6, 0, new QTableWidgetItem("11h20 12h50"));
    tableauEDTvisuel->setItem(9, 0, new QTableWidgetItem("13h 13h30"));
    tableauEDTvisuel->setItem(12, 0, new QTableWidgetItem("13h40 15h10"));
    tableauEDTvisuel->setItem(15, 0, new QTableWidgetItem("15h20 16h50"));
    tableauEDTvisuel->setItem(18, 0, new QTableWidgetItem("17h 18h30"));
    tableauEDTvisuel->setItem(21, 0, new QTableWidgetItem("18h40 20h10"));

    for(int z = 0; z<24; z+=3 )tableauEDTvisuel->setSpan(z, 0, 3, 1);
    tableauEDTvisuel->setAlternatingRowColors(1);

    tableauEDTvisuel->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableauEDTvisuel->setShowGrid(true);
    tableauEDTvisuel->setStyleSheet("QTableView {selection-background-color: red;}");
    tableauEDTvisuel->setSelectionMode(QAbstractItemView::NoSelection);
    tableauEDTvisuel->resizeColumnsToContents();



    layoutvisuel->addWidget(tableauEDTvisuel);

    listeFiliere = new QComboBox(this);
     for( list<Filiere*>::iterator it = u->get_filieres()->begin(); it!= u->get_filieres()->end(); ++it)
      {
         string filieres =(*it)->get_nom();
         listeFiliere->addItem(QString::fromStdString(filieres));
      }
      layoutvisuel->addWidget(listeFiliere);

      connect(listeFiliere,SIGNAL(currentTextChanged(const QString)),this, SLOT(Actu(const QString)));

     listeGroupe = new QComboBox(this);

     connect(listeGroupe,SIGNAL(currentTextChanged(const QString)),this, SLOT(changegroupe()));


     string nomfil=(listeFiliere->currentText()).toStdString();
     f=u->get_filieres(nomfil);

    for( list<Groupe*>::iterator it = f->get_groupes()->begin(); it!=  f->get_groupes()->end(); ++it)
      {
         string groupe =(*it)->get_identifiant();
         listeGroupe->addItem(QString::fromStdString(groupe));
      }
     layoutvisuel->addWidget(listeGroupe);

}

void Fen_VisualisationEDT::Actu(const QString nom)
{
     string nomfil= nom.toStdString();
    this->f=u->get_filieres(nomfil);
     listeGroupe->clear();

   for( list<Groupe*>::iterator it = f->get_groupes()->begin(); it!=  f->get_groupes()->end(); ++it)
     {
        string groupe =(*it)->get_identifiant();
        listeGroupe->addItem(QString::fromStdString(groupe));
     }
}

Fen_VisualisationEDT::Fen_VisualisationEDT(Universite *u)
{
    this->u=u;
    this->f=new Filiere();
    layoutvisuel = new QVBoxLayout;

    visualise_EDT();
    setLayout(layoutvisuel);
}
void Fen_VisualisationEDT::remplir_edt()
{
    for(int x=0; x < this->tableauEDTvisuel->rowCount();x+=3)
        {
           for(int y=1; y < this->tableauEDTvisuel->columnCount();y++)
            {
               for( list<Matiere*>::iterator it = f->get_matieres()->begin(); it!= f->get_matieres()->end(); ++it)
               {

                   for( list<Cours*>::iterator co = (*it)->get_cours()->begin(); co!= (*it)->get_cours()->end(); ++co)
                   {
                       if((*co)->get_emplacement()[1] ==x/3 && (*co)->get_emplacement()[0] ==y &&  (*co)->get_groupes(listeGroupe->currentText().toStdString()) !=nullptr)
                       {
                           tableauEDTvisuel->setItem(x, y, new QTableWidgetItem(QString::fromStdString( (*co)->get_type_string() + (*co)->get_matiere()->get_nom()   ) ));
                           tableauEDTvisuel->setItem(x+1, y, new QTableWidgetItem( QString::fromStdString( (*co)->get_enseignant()->get_identifiant()   ) ));
                           tableauEDTvisuel->setItem(x+2, y, new QTableWidgetItem(QString::fromStdString( (*co)->get_salle()->get_identifiant()   )));
                           if ((*co)->get_duree()==2)
                           {
                               tableauEDTvisuel->setItem(x+3, y, new QTableWidgetItem(QString::fromStdString( (*co)->get_type_string() + (*co)->get_matiere()->get_nom()   ) ));
                               tableauEDTvisuel->setItem(x+4, y, new QTableWidgetItem( QString::fromStdString( (*co)->get_enseignant()->get_identifiant()   ) ));
                               tableauEDTvisuel->setItem(x+5, y, new QTableWidgetItem(QString::fromStdString( (*co)->get_salle()->get_identifiant()   )));
                           }
                       }
                   }
                }
            }
        }
}


void Fen_VisualisationEDT::changegroupe()
{


    tableauEDTvisuel->clearContents();
    tableauEDTvisuel->setItem(0, 0, new QTableWidgetItem("8h 9h30"));
    tableauEDTvisuel->setItem(3, 0, new QTableWidgetItem("9h40 11h10"));
    tableauEDTvisuel->setItem(6, 0, new QTableWidgetItem("11h20 12h50"));
    tableauEDTvisuel->setItem(9, 0, new QTableWidgetItem("13h 13h30"));
    tableauEDTvisuel->setItem(12, 0, new QTableWidgetItem("13h40 15h10"));
    tableauEDTvisuel->setItem(15, 0, new QTableWidgetItem("15h20 16h50"));
    tableauEDTvisuel->setItem(18, 0, new QTableWidgetItem("17h 18h30"));
    tableauEDTvisuel->setItem(21, 0, new QTableWidgetItem("18h40 20h10"));

    if (f->get_edt()!=nullptr)
        remplir_edt();

}
Fen_VisualisationEDT::~Fen_VisualisationEDT(){

    delete tableauEDTvisuel;
    delete layoutvisuel;
    delete listeGroupe;
    delete listeFiliere;
}
