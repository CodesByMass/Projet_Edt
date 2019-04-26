#include "../les_h/EDT.h"
#include "../les_h/Filiere.h"
#include "../les_h/Cours.h"


EDT::EDT()
{
	cout << "Construction EDT" << endl;
	cours = NULL;
	filiere = NULL;
	dureeCreneau = -1;
	nbJours = -1;
	nbCreneau = -1;
}

EDT::EDT(list <Cours*>** c, Filiere* f, int d, int nbJ, int nbC)
{
	cout << "Construction EDT" << endl;
	// creation de l'EDT
	cours = new list <Cours*>* [nbJ];
	for(int i = 0; i<nbJ; i++)
		cours[i] = new list<Cours*> [nbC];
	
	// remplissage
	if(c != NULL)	copy(&c[0][0],&c[0][0]+nbJ*nbC,&cours[0][0]);
	
	filiere = f;
	dureeCreneau = d;
	nbJours = nbJ;
	nbCreneau = nbC;
}

EDT::EDT(Filiere* f, int d, int nbJ, int nbC)
{
	cout << "Construction EDT" << endl;
	// creation de l'EDT
	cours = new list <Cours*>* [nbJ];
	for(int i = 0; i<nbJ; i++)
		cours[i] = new list<Cours*> [nbC];
	
	filiere = f;
	dureeCreneau = d;
	nbJours = nbJ;
	nbCreneau = nbC;
}

EDT::EDT(EDT const& autre)
{
	cout << "Construction EDT" << endl;
	// creation de l'EDT
	cours = new list <Cours*>* [autre.nbJours];
	for(int i = 0; i<autre.nbJours; i++)
		cours[i] = new list<Cours*> [autre.nbCreneau];
		
	// remplissage
	if(autre.cours != NULL)	copy(&autre.cours[0][0],&autre.cours[0][0]+autre.nbJours*autre.nbCreneau,&cours[0][0]);
	
	filiere = autre.filiere;
	dureeCreneau = autre.dureeCreneau;
	nbJours = autre.nbJours;
	nbCreneau = autre.nbCreneau;
}

EDT::EDT(string)
{
	//pour abdou et ali
}

EDT::~EDT()
{
	cout << "Destruction EDT " << endl;
	// On supprime toute les listes
	for(int i = 0; i<nbJours; i++)
		delete[] cours[i];
	delete[] cours;
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
