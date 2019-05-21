#ifndef FEN_VISUALISATION_H
#define FEN_VISUALISATION_H

#include <QWidget>
#include "fen_modificationedt.h"
#include "classes/les_h/Universite.h"


class fen_visualisation: public QWidget
{
    Q_OBJECT

    public:

    //fen_accueil();
    fen_visualisation(QWidget *parent, Universite *u);
    ~fen_visualisation();

    private:
        Universite *u;
};

#endif // FEN_VISUALISATION_H
