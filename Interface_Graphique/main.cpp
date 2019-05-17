#include "mainwindow.h"
#include "fen_modificationedt.h"
#include "fen_modificationressources.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Schedule Creator");

    w.show();


    return a.exec();
}
