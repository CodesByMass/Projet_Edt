#include "fen_modificationedt.h"
#include "fen_modificationressources.h"

#include <QApplication>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include<QPushButton>
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


void Fen_ModificationEDT::showFen_ModificationRessources()
{
    this->modificationressourceswindow = new Fen_ModificationRessources(parentWidget());
    modificationressourceswindow->resize(800, 400);
    modificationressourceswindow->setWindowTitle("Modification des Ressources");
    modificationressourceswindow->show();
}
void Fen_ModificationEDT::ressourceSelectionnee()
{
    QItemSelectionModel *selection = vueliste->selectionModel();
    QModelIndexList listeSelections = selection->selectedIndexes();
    QString ressourcesSelectionnes;
    for (int i = 0 ; i < listeSelections.size() ; i++)
    {
       QVariant elementSelectionne = modeleliste->data(listeSelections[i], Qt::DisplayRole);
       ressourcesSelectionnes += elementSelectionne.toString() + "<br />";
    }
    QMessageBox::information(this, "Eléments sélectionnés", ressourcesSelectionnes);
}
void Fen_ModificationEDT::affiche_salles()
{
    QVBoxLayout *vbox2 = new QVBoxLayout;
       QStringList listePays;
       listePays << "France" << "Espagne" << "Italie" << "Portugal" << "Suisse";
       modeleliste = new QStringListModel(listePays);

       vueliste = new QListView ;
       vueliste->setModel(modeleliste);
       vueliste->setSelectionMode(QAbstractItemView::ExtendedSelection);
       buttonselection = new QPushButton("Afficher la sélection");

       vbox2->addWidget(buttonselection);

       setLayout(layout);

       connect(buttonselection, SIGNAL(clicked()), this, SLOT(ressourceSelectionnee()));

     vbox2->addWidget(vueliste);
    ongletPage2->setLayout(vbox2);

}
void Fen_ModificationEDT::affiche_onglets()
{
    QWidget fenetre;


    QTabWidget *onglets = new QTabWidget(&fenetre);     // Créer le QTabWidget
    onglets->setGeometry(30, 20, 240, 160);

    // 2 : Créer les pages, en utilisant un widget parent pour contenir chacune des pages
    ongletPage1 = new QWidget;
    ongletPage2 = new QWidget;
    ongletPage4 = new QWidget;
    ongletPage3 = new QLabel; // Comme un QLabel est aussi un QWidget (il en hérite), on peut aussi s'en servir de page

    // 3 : Créer le contenu des pages de widgets
        // Page 1
    affiche_salles();

    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(ongletPage1, "Cours");
    onglets->addTab(ongletPage2, "Salle");
    onglets->addTab(ongletPage3, "Enseignant");
    onglets->addTab(ongletPage4, "Groupe");

    layout->addWidget(onglets);

}
Fen_ModificationEDT::Fen_ModificationEDT(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout;
    affiche_onglets();


    QStandardItemModel *modele = new QStandardItemModel(8, 6);
   modele->setHorizontalHeaderItem(0, new QStandardItem("Lundi"));
   modele->setHorizontalHeaderItem(1, new QStandardItem("Mardi"));
   modele->setHorizontalHeaderItem(2, new QStandardItem("Mercredi"));
   modele->setHorizontalHeaderItem(3, new QStandardItem("Jeudi"));
   modele->setHorizontalHeaderItem(4, new QStandardItem("Vendredi"));
   modele->setHorizontalHeaderItem(5, new QStandardItem("Samedi"));
   modele->setVerticalHeaderItem(0, new QStandardItem("8h 9h30"));
   modele->setVerticalHeaderItem(1, new QStandardItem("9h40 11h10"));
   modele->setVerticalHeaderItem(2, new QStandardItem("11h20 12h50"));
   modele->setVerticalHeaderItem(3, new QStandardItem("13h 13h30"));
   modele->setVerticalHeaderItem(4, new QStandardItem("13h40 15h10"));
   modele->setVerticalHeaderItem(5, new QStandardItem("15h20 16h50"));
   modele->setVerticalHeaderItem(6, new QStandardItem("17h 18h30"));
   modele->setVerticalHeaderItem(7, new QStandardItem("18h40 20h10"));

    modele->setItem(0, 0, new QStandardItem("Cours OO !"));
    vue = new QTableView;
    vue->setModel(modele);
    layout->addWidget(vue);

    setLayout(layout);

    // Create the button, make "this" the parent
    buttonressources = new QPushButton("Modifier les Ressources", parent);
    // set size and location of the button
    buttonressources->setGeometry(QRect(QPoint(50, 100),
    QSize(200, 50)));
    layout->addWidget(buttonressources);
    // Connect button signal to appropriate slot

   connect(buttonressources, SIGNAL (clicked()), this, SLOT(showFen_ModificationRessources()));

   QComboBox *liste = new QComboBox(this);
       liste->addItem("Groupe 1");
       liste->addItem("Groupe 2");
       liste->addItem("Groupe 3");

       layout->addWidget(liste);
}
Fen_ModificationEDT::~Fen_ModificationEDT()
{
    delete fenetre;
    delete vue;
    delete modificationressourceswindow;
    delete buttonressources;
    delete buttonselection;
    delete modeleliste;
    delete vueliste;
    delete ongletPage1;
    delete ongletPage2;
    delete ongletPage4;
    delete ongletPage3;
}
