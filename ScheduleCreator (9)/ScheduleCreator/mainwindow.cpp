#include "mainwindow.h"
#include "./IG/fen_modificationedt.h"
#include "classes/les_h/Universite.h"
#include "./SGF/SGF.h"
#include <QApplication>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    u=lecture_universite();
   /* u=new Universite(18,8,10,12,"UVSQ");
    u->add_filiere(new Filiere());*/
    this->affiche_accueil();
    this->resize(800, 600);
}

void MainWindow::creation_EDT()
{
    this->creation=new fen_creation(this,u);
    creation->resize(800, 600);
    creation->setWindowTitle("Creation Filiere");
    creation->show();
}

void MainWindow::affiche_accueil()
{
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;

    QWidget* centralWidget = new QWidget(this);

    QHBoxLayout *widgetLayout = new QHBoxLayout(centralWidget);


    QLabel *m_texte = new QLabel();
    m_texte->setText("Schedule Creator");
    QFont police("Times",25, QFont::Bold );
    m_texte->setFont(police);
    widgetLayout->addWidget(m_texte);


      QVBoxLayout *buttonsLayout = new QVBoxLayout;
      // Create the button, make "this" the parent
      button1 = new QPushButton("Créer un nouvel emploi du temps", centralWidget);
      // set size and location of the button
      button1->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
      buttonsLayout->addWidget(button1);
      QObject::connect(button1, SIGNAL (clicked()), this, SLOT(creation_EDT()));
    //  QObject::connect(button1, SIGNAL (clicked()), this, SLOT(hide()));

      button2 = new QPushButton("Afficher un emploi du temps", centralWidget);
      button2->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));
      buttonsLayout->addWidget(button2);
       QObject::connect(button2, SIGNAL (clicked()), this, SLOT(showFen_VisualisationEDT()));

      button3 = new QPushButton("Modifier emploi du temps", centralWidget);
      button3->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
      buttonsLayout->addWidget(button3);
      // Connect button signal to appropriate slot

     //this->showFen_ModificationEDT();

      QObject::connect(button3, SIGNAL (clicked()), this, SLOT(showFen_ModificationEDT())); // Connect button signal to appropriate slot


      widgetLayout->addLayout(buttonsLayout);


      setCentralWidget(centralWidget);

}

void MainWindow::showFen_ModificationEDT()
{
    this->modificationwindow = new Fen_ModificationEDT(this,u);
    modificationwindow->resize(800, 600);
    modificationwindow->setWindowTitle("Modification d'un emploi du temps");
    modificationwindow->show();
}

void MainWindow::showFen_VisualisationEDT()
{
    this->visualisationwindow = new Fen_VisualisationEDT(this,u);
    visualisationwindow->resize(630, 770);
    visualisationwindow->setWindowTitle("Modification d'un emploi du temps");
    visualisationwindow->show();
}


MainWindow::~MainWindow()
{}
