#include "../les_h/EDT.h"
#include "../les_h/Filiere.h"
#include "../les_h/Cours.h"
#include "../les_h/Enseignant.h"
#include "../les_h/Groupe.h"
#include "../les_h/Matiere.h"
#include "../les_h/Salle.h"


EDT::EDT()
{
	//cout << "Construction EDT" << endl;
	cours = NULL;
	filiere = NULL;
	dureeCreneau = -1;
	nbJours = -1;
	nbCreneau = -1;
	modif[0] = NULL;
	modif[1] = NULL;
}

EDT::EDT(list <Cours*>** c, Filiere* f, int d, int nbJ, int nbC)
{
	//cout << "Construction EDT" << endl;
	// creation de l'EDT
	cours = new list <Cours*>* [nbJ];
	for(int i = 0; i<nbJ; i++){
		cours[i] = new list<Cours*> [nbC];
		for(int j = 0; j < nbC; j++){
			cours[i][j]={};}}
	
	// remplissage
	if(c != NULL)	copy(&c[0][0],&c[0][0]+nbJ*nbC,&cours[0][0]);
	
	filiere = f;
	dureeCreneau = d;
	nbJours = nbJ;
	nbCreneau = nbC;
	modif[0] = NULL;
	modif[1] = NULL;
}

EDT::EDT(Filiere* f, int d, int nbJ, int nbC)
{
	//cout << "Construction EDT" << endl;
	// creation de l'EDT
	cours = new list <Cours*>* [nbJ];
	for(int i = 0; i<nbJ; i++){
		cours[i] = new list<Cours*> [nbC];
		for(int j = 0; j < nbC; j++){
			cours[i][j]={};}}
	
	filiere = f;
	dureeCreneau = d;
	nbJours = nbJ;
	nbCreneau = nbC;
	modif[0] = NULL;
	modif[1] = NULL;
}

EDT::EDT(EDT const& autre)
{
	//cout << "Construction EDT" << endl;
	// creation de l'EDT
	//cout << "creation du tableau" << endl;
	cours = new list <Cours*>* [autre.nbJours];
	for(int i = 0; i<autre.nbJours; i++)
		cours[i] = new list<Cours*> [autre.nbCreneau];
	
	
	//cout << "Recopie du tableau" << endl;
	// remplissage
	for(int i=0; i<autre.nbJours;i++){
		for(int j=0; j<autre.nbCreneau; j++){
				for(list<Cours*>::iterator it = autre.cours[i][j].begin(); it!= autre.cours[i][j].end(); ++it){
					cours[i][j].push_back(*it);
					(*it)->get_edt()->push_front(this);}}}
	
	filiere = autre.filiere;
	dureeCreneau = autre.dureeCreneau;
	nbJours = autre.nbJours;
	nbCreneau = autre.nbCreneau;
	modif[0] = NULL;
	modif[1] = NULL;
}

EDT::EDT(string)
{
	//pour abdou et ali
}

EDT::~EDT()
{
	//cout << "Destruction EDT " << endl;
	
	for(int i = 0; i < nbJours; i++){
		for(int j = 0; j < nbCreneau; j++){
			for(list<Cours*>::iterator c = cours[i][j].begin(); c != cours[i][j].end(); ++c){
				(*c)->get_edt()->remove(this);}}}
				

	// Si c'est un voisin d'un autre edt
	if(modif[1] != NULL && modif[0] != NULL){
		if(modif[1]->get_enseignant() != NULL) modif[1]->get_enseignant()->get_cours()->remove(modif[1]);
		if(modif[1]->get_salle() != NULL) modif[1]->get_salle()->get_cours()->remove(modif[1]);
		if(modif[1]->get_matiere() != NULL) modif[1]->get_matiere()->get_cours()->remove(modif[1]);
		for(list<Groupe*>::iterator g = modif[1]->get_groupes()->begin(); g != modif[1]->get_groupes()->end(); ++g)
			if((*g) != NULL) (*g)->get_cours()->remove(modif[1]);
		
		if(modif[0]->get_enseignant() != NULL) modif[0]->get_enseignant()->get_cours()->push_front(modif[0]);
		if(modif[0]->get_salle() != NULL) modif[0]->get_salle()->get_cours()->push_front(modif[0]);
		if(modif[0]->get_matiere() != NULL) modif[0]->get_matiere()->get_cours()->push_front(modif[0]);
		for(list<Groupe*>::iterator g = modif[0]->get_groupes()->begin(); g != modif[0]->get_groupes()->end(); ++g)
			if((*g) != NULL) (*g)->get_cours()->push_front(modif[0]);

		delete modif[1];}
			
	// On supprime toute les listes
	for(int i = 0; i<nbJours; i++)
		delete[] cours[i];
	delete[] cours;

	//cout << "Fin Destruction EDT " << endl;
}

list <Cours*>** EDT::get_cours()
{
	return cours;
}

Filiere* EDT::get_filiere()
{
	return filiere;
}

int EDT::get_dureeCreneau()
{
	return dureeCreneau;
}

int EDT::get_nbJours()
{
	return nbJours;
}

int EDT::get_nbCreneau()
{
	return nbCreneau;
}

string EDT::to_string()
{
	//Pour abdou et ali
	return "rien";
}

Cours** EDT::get_modif()
{
	return modif;
}

void EDT::add_cours(Cours* c, int x, int y)
{
	if(x >= 0 && x< nbJours && y >= 0 && y < nbCreneau)
		cours[x][y].push_front(c);
}
		
void EDT::del_cours(Cours* c, int x, int y)
{
	if(x >= 0 && x< nbJours && y >= 0 && y < nbCreneau)
		cours[x][y].remove(c);
}

void EDT::set_filiere(Filiere* f)
{
	filiere = f;
}

void EDT::set_dureeCreneau(int d)
{
	dureeCreneau = d;
}

void EDT::set_nbJours(int nbJ)
{
	nbJours = nbJ;
}

void EDT::set_nbCreneau(int nbC)
{
	nbCreneau = nbC;
}

void EDT::set_modif(Cours* temp1, Cours* temp2)
{
	modif[0] = temp1;
	modif[1] = temp2;
}
