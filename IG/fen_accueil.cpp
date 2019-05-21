#include"fen_accueil.h"
#include "fen_modificationedt.h"

#include <QApplication>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

fen_accueil::fen_accueil(QWidget *parent) : QWidget(parent)
{
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QVBoxLayout *widgetLayout = new QVBoxLayout();

    QLabel *m_texte = new QLabel();
    m_texte->setText("Schedule Creator");
    QFont police("Times",25, QFont::Bold );
    m_texte->setFont(police);
    widgetLayout->addWidget(m_texte);

    // Create the button, make "this" the parent
    button1 = new QPushButton("Créer un nouvel emploi du temps", parent);
    // set size and location of the button
    button1->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    widgetLayout->addWidget(button1);
    QObject::connect(button1, SIGNAL (clicked()), parentWidget(), SLOT(creation_EDT()));

    button2 = new QPushButton("Afficher un emploi du temps", parent);
    button2->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));
    widgetLayout->addWidget(button2);
    QObject::connect(button2, SIGNAL (clicked()), qApp, SLOT(quit()));

    button3 = new QPushButton("Modifier emploi du temps", parent);
    button3->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    widgetLayout->addWidget(button3);
    QObject::connect(button3, SIGNAL (clicked()), parentWidget(), SLOT(showFen_ModificationEDT())); // Connect button signal to appropriate slot

    widgetLayout->setAlignment(Qt::AlignHCenter);
    setLayout(widgetLayout);
}

fen_accueil::~fen_accueil(){}
