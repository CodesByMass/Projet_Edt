#include "Groupe.h"

Groupe::Groupe()
{
	cout << "Construction Groupe" << endl;
}

Groupe::Groupe(Universite* u, string id, int vh, int** h, list <Cours*> c, list <Filiere*> f)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
	filieres = f;
}

Groupe::Groupe(Groupe const& autre)
{
	universite = autre.universite;
	identifiant = autre.identifiant;
	Vhoraire = autre.Vhoraire;
	copy(&autre.horaires[0][0],&autre.horaires[0][0]+6*2,&horaires[0][0]);
	cours = autre.cours;
	filieres = autre.filieres;
}

Groupe::Groupe(string)
{
	// Pour abdou et ali
}

Groupe::~Groupe()
{
	cout << "Destruction Groupe" << endl;
	for(list<Filiere*>::iterator it = filieres.begin(); it!=filieres.end(); ++it){
		(*it)->get_groupes().remove(this);}
}

list <Filiere*> Groupe::get_filieres()
{
	return filieres;
}

string Groupe::to_string()
{
	return "rien";
}

void Groupe::set_filieres(list <Filiere*> f)
{
	filieres = f;
}
