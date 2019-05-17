#include "mainwindow.h"
#include "fen_modificationedt.h"

#include <QApplication>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

void MainWindow::showFen_ModificationEDT()
{
    this->modificationwindow = new Fen_ModificationEDT();
    modificationwindow->resize(800, 400);
    modificationwindow->setWindowTitle("Modification d'un emploi du temps");
    modificationwindow->show();
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QWidget *centralWidget = new QWidget(this /* the main window */);
    QHBoxLayout *widgetLayout = new QHBoxLayout(centralWidget);
    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    // Create the button, make "this" the parent
    button1 = new QPushButton("Créer un nouvel emploi du temps", centralWidget);
    // set size and location of the button
    button1->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    buttonsLayout->addWidget(button1);
    QObject::connect(button1, SIGNAL (clicked()), qApp, SLOT(quit()));

    button2 = new QPushButton("Afficher un emploi du temps", centralWidget);
    button2->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));
    buttonsLayout->addWidget(button2);

    button3 = new QPushButton("Modifier emploi du temps", centralWidget);
    button3->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    buttonsLayout->addWidget(button3);
    // Connect button signal to appropriate slot

   //this->showFen_ModificationEDT();
   connect(button3, SIGNAL (clicked()), this, SLOT(showFen_ModificationEDT()));

    widgetLayout->addLayout(buttonsLayout);
    setCentralWidget(centralWidget);

}

MainWindow::~MainWindow()
{
    delete button1;
    delete button2;
    delete button3;
    delete modificationwindow;
}
