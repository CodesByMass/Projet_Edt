// Fen_ModificationRessources.h

#ifndef FEN_MODIFICATIONRESSOURCES
#define FEN_MODIFICATIONRESSOURCES

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QErrorMessage>
#include <QSpinBox>
// Crée un champ de texte pour nombres.
#include <QLineEdit>
// Crée un champ de texte à une ligne.
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QTableWidget> // Permet de créer un widget tableau.
// Class Fen_ModificationRessources : QWidget
class Fen_ModificationRessources {

private:
int typeRessource ;
université *u ;

public:
Fen_ModificationRessources() ;
Fen_ModificationRessources(université &u, int type) ;
// ∼Fen_ModificationRessources() ;
get_typeRessource() ;
get_université() ;
set_typeRessource() ;
set_université() ;
void message_fin () ;
/* Soit l’ajout est possible soit il ne l’est pas, cela sera vérifié grâce à la fonction de vérification du module de SGF.
On affichera le message en conséquence : soit les blocs contiennent des caractères non valides, soit la ressource
existe déjà, soit la ressource est ajoutées. Les 3 ressources seront gérées. */
void affiche_formulaire() ;
// Appelera la bonne fonction d’affichage selon le paramètre type de la fenêtre.
void affiche_formulaire_groupe() ;
// Affiche le formulaire nécessaire pour ajouter un groupe et le titre de la fenêtre.
void affiche_formulaire_enseignant() ;
// Affiche le formulaire nécessaire pour ajouter un enseignant et le titre de la fenêtre.
void affiche_formulaire_salle() ;
// Affiche le formulaire nécessaire pour ajouter une salle et le titre de la fenêtre.
QPushButton bouton_validation() ;
// Crée le bouton pour la validation du formulaire. ;
void ajout_ressource() ;
// Appelera la bonne fonction d’ajout selon le paramètre type de la fenêtre.
void ajout_enseignant() ;
// Ajoute un enseignant à l’université u.
void ajout_salle() ;
// Ajoute une salle à l’université u. ;
void ajout_groupe() ;
// Ajoute un groupe à l’université u. ;
void principale() ;
/* Attend la validation du formulaire, lance la vérification (fonction de la gestion de
fichier) selon i, lance message_fin puis on ajoute la ressource à l’université.
*/
};
#endif
