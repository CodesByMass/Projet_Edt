#include "../les_h/Filiere.h"
#include "../les_h/Groupe.h"
#include "../les_h/Matiere.h"
#include "../les_h/Universite.h"

Filiere::Filiere()
{
	//cout << "Construction Filiere" << endl;
	nom = "";
	universite = NULL;
	edt = NULL;
	matieres = {};
	groupes = {};
	semestre = -1;
}

Filiere::Filiere(list <Matiere*> m, list<Groupe*> g, Universite* u, string new_nom, EDT* e, int sem)
{
	//cout << "Construction Filiere" << endl;
	matieres = m;
	groupes = g;
	universite = u;
	nom = new_nom;
	edt = e;
	semestre = sem;
}

Filiere::Filiere(string new_nom, Universite* u, EDT* e, int sem)
{
	//cout << "Construction Filiere" << endl;
	nom = new_nom;
	universite = u;
	edt = e;
	matieres = {};
	groupes = {};
	semestre = sem;
}

Filiere::Filiere(Filiere const& autre)
{
	//cout << "Construction Filiere" << endl;
	matieres = autre.matieres;
	groupes = autre.groupes;
	universite = autre.universite;
	nom = autre.nom;
	edt = autre.edt;
	semestre = autre.semestre;
}

Filiere::Filiere(string to_construct)
{
	// pour abdou et ali
}

Filiere::~Filiere()
{
	//cout << "Destruction Filiere" << endl;
	// Supprimer la filiere des matieres qui lui sont associés et si elle n'est plus associé a aucune filiere l'a supprimer
	for(list<Matiere*>::iterator it = matieres.begin(); it!=matieres.end(); ++it){
		if((*it) != NULL)delete (*it);}
	// sans filiere plus d'edt de filiere
	if(edt != NULL){
		delete edt;}
}

list <Matiere*>* Filiere::get_matieres()
{
	return &matieres;
}

Matiere* Filiere::get_matieres(string s)
{
	for(list<Matiere*>::iterator it = matieres.begin(); it!=matieres.end(); ++it)
		if((*it)->get_nom() == s) return *it;
	return NULL;
}

string Filiere::get_nom()
{
	return nom;
}

Universite* Filiere::get_universite()
{
	return universite;
}

EDT* Filiere::get_edt()
{
	return edt;
}

list<Groupe*>* Filiere::get_groupes()
{
	return &groupes;
}

Groupe* Filiere::get_groupes(string s)
{
	for(list<Groupe*>::iterator it = groupes.begin(); it!= groupes.end(); ++it)
		if((*it)->get_identifiant() == s) return (*it);
	return NULL;
}

int Filiere::get_semestre()
{
	return semestre;
}

string Filiere::to_string()
{
	// pour abdou et ali
	return "rien";
}

void Filiere::add_matiere(Matiere* m)
{
	matieres.push_back(m);
}
		
void Filiere::del_matiere(Matiere* m)
{
	matieres.remove(m);
}

void Filiere::set_nom(string new_nom)
{
	nom = new_nom;
}

void Filiere::add_groupe(Groupe* g)
{
	groupes.push_front(g);
}

void Filiere::del_groupe(Groupe* g)
{
	groupes.remove(g);
}

void Filiere::set_semestre(int sem)
{
	semestre = sem;
}

void Filiere::set_universite(Universite* u)
{
	universite = u;
}

void Filiere::set_edt(EDT* e)
{
	edt = e;
}
