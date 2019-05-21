#ifndef FEN_VISUALISATION_H
#define FEN_VISUALISATION_H

#include <QWidget>
#include "fen_modificationedt.h"
#include "classes/les_h/Universite.h"


class Fen_VisualisationEDT: public QWidget
{
    Q_OBJECT

    public:

    //fen_accueil();
    Fen_VisualisationEDT(Universite *u);
    void visualise_EDT();
    void remplir_edt();

    ~Fen_VisualisationEDT();

    private:
        Universite *u;
        QTableWidget *tableauEDTvisuel;
        QVBoxLayout *layoutvisuel;
        QComboBox *listeGroupe;
        QComboBox *listeFiliere;
        Filiere* f;

      private slots:
        void Actu(const QString nom);
        void changegroupe();



};

#endif // FEN_VISUALISATION_H
