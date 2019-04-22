#include "Filiere.h"
#include "Groupe.h"
#include "Matiere.h"
#include "Universite.h"

Filiere::Filiere()
{
	cout << "Construction Filiere" << endl;
	nom = "";
	universite = NULL;
	edt = NULL;
}

Filiere::Filiere(list <Matiere*> m, list<Groupe*> g, Universite* u, string new_nom, EDT* e)
{
	matieres = m;
	groupes = g;
	universite = u;
	nom = new_nom;
	edt = e;
}

Filiere::Filiere(Filiere const& autre)
{
	matieres = autre.matieres;
	groupes = autre.groupes;
	universite = autre.universite;
	nom = autre.nom;
	edt = autre.edt;
}

Filiere::Filiere(string)
{
	// pour abdou et ali
}

Filiere::~Filiere()
{
	cout << "Destruction Filiere" << endl;
	// Supprimer la filiere des groupe et si le groupe n'a plus de filiere le supprimer
	for(list<Groupe*>::iterator it = groupes.begin(); it!=groupes.end(); ++it){
		(*it)->get_filieres().remove(this);
		if ((*it)->get_filieres().size() == 0)
			delete (*it);}
	// Supprimer la filiere des matieres qui lui sont associés et si elle n'est plus associé a aucune filiere l'a supprimer
	for(list<Matiere*>::iterator it = matieres.begin(); it!=matieres.end(); ++it){
		(*it)->get_filieres().remove(this);
		if ((*it)->get_filieres().size() == 0)
			delete (*it);}
	// Supprimer la filiere dans l'universite 
	if(universite != NULL)
		universite->get_filieres().remove(this);
	// sans filiere plus d'edt de filiere
	delete[] edt;
}

list <Matiere*> Filiere::get_matieres()
{
	return matieres;
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

list<Groupe*> Filiere::get_groupes()
{
	return groupes;
}

string Filiere::to_string()
{
	// pour abdou et ali
	return "rien";
}

void Filiere::set_matieres(list <Matiere*> m)
{
	matieres = m;
}

void Filiere::set_nom(string new_nom)
{
	nom = new_nom;
}

void Filiere::set_groupes(list<Groupe*> g)
{
	groupes = g;
}

void Filiere::set_universite(Universite* u)
{
	universite = u;
}

void Filiere::set_edt(EDT* e)
{
	edt = e;
}
