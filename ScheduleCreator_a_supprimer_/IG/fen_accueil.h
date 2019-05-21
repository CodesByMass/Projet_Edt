#ifndef FEN_ACCUEIL_H
#define FEN_ACCUEIL_H
#include <QWidget>
#include "fen_modificationedt.h"
#include "classes/les_h/Universite.h"

class fen_accueil : public QWidget
{
    Q_OBJECT

    public:

    //fen_accueil();
    explicit fen_accueil(QWidget *parent);
    ~fen_accueil();

    private:
        Universite *u;
};

#endif // FEN_ACCUEIL_H
