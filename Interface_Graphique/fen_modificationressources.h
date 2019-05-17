#ifndef FEN_MODIFICATIONRESSOURCES_H
#define FEN_MODIFICATIONRESSOURCES_H

#include <QWidget>
#include <QPushButton>

class Fen_ModificationRessources : public QWidget
{
    Q_OBJECT
public:
    explicit Fen_ModificationRessources(QWidget *parent = nullptr);

    Fen_ModificationRessources();
    //Fen_ModificationRessources(&universite, int type);
    //~Fen_ModificationRessources();
    //Get_type();
    //Get_universite();
    void Set_type();
    void Set_universite();
    void message_fin (); //Soit l’ajout est possible soit il ne l’est pas, cela sera vérifié grâce à la fonction de vérification du module de SGF. On affichera le message en conséquence : soit les blocs contiennent des caractères non valides, soit la ressource existe déjà, soit la ressource est ajoutées. Les 3 ressources seront gérées.
    void affiche_formulaire(); //Appelera la bonne fonction d’affichage selon le paramètre type de la fenêtre.
    void affiche_formulaire_groupe(); //Affiche les blocs de textes et blocs d’entrées nécessaires pour ajouter un groupe et le titre de la fenêtre.
    void affiche_formulaire_enseignant(); //Affiche les blocs de textes et blocs d’entrées nécessaires pour ajouter un enseignant et le titre de la fenêtre.
    void affiche_formulaire_salle(); //Affiche les blocs de textes et blocs d’entrées nécessaires pour ajouter une salle et le titre de la fenêtre.
    QPushButton bouton_validation(); //Crée le bouton pour la validation du formulaire.
    void ajout_ressource(); //Appelera la bonne fonction d’ajout selon le paramètre type de la fenêtre.
    void ajout_enseignant(); //Ajoute un enseignant à l’université u.
    void ajout_salle();//Ajoute une salle à l’université u.
    void ajout_groupe(); //Ajoute un groupe à l’université u.
    void principale(); //Attend la validation du formulaire, lance la vérification (fonction de la gestion de fichier) selon i, lance message_fin puis on ajoute la ressource à l’université.

private:
    int type ;
    //universite *u;
signals:

public slots:
};

#endif // FEN_MODIFICATIONRESSOURCES_H
