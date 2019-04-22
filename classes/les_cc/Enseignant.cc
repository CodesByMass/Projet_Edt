#include "Enseignant.h"
#include "Matiere.h"

Enseignant::Enseignant()
{
	cout << "Construction Enseignant" << endl;
}

Enseignant::Enseignant(Universite* u, string id, int vh, int** h, list <Cours*> c, list<Matiere*> l)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
	specialites = l;
}

Enseignant::Enseignant(Enseignant const& autre)
{
	universite = autre.universite;
	identifiant = autre.identifiant;
	Vhoraire = autre.Vhoraire;
	copy(&autre.horaires[0][0],&autre.horaires[0][0]+6*2,&horaires[0][0]);
	cours = autre.cours;
	specialites = autre.specialites;
}

Enseignant::Enseignant(string)
{
	// pour abdou et ali
}

Enseignant::~Enseignant()
{
	cout << "Destruction Enseignant" << endl;
	for(list<Matiere*>::iterator it = specialites.begin(); it!=specialites.end(); ++it){
		(*it)->get_enseignants().remove(this);}
}

list <Matiere*> Enseignant::get_specialites()
{
	return specialites;
}

string Enseignant::to_string()
{
	// Pour abdou et ali
	return "rien";
}

void Enseignant::set_specialites(list <Matiere*> l)
{
	specialites = l;
}
