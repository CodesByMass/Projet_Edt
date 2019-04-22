#include "Salle.h"

Salle::Salle()
{
	cout << "Construction Salle" << endl;
	batiment = NULL;
	effectif = -1;
}

Salle::Salle(Universite* u, string id, int vh, int** h, list <Cours*> c, Batiment* b, list <Matiere*> l, int eff, Type t)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
	batiment = b;
	materiels = l;
	effectif = eff;
	type = t;
}

Salle::Salle(Salle const& autre)
{
	universite = autre.universite;
	identifiant = autre.identifiant;
	Vhoraire = autre.Vhoraire;
	copy(&autre.horaires[0][0],&autre.horaires[0][0]+6*2,&horaires[0][0]);
	cours = autre.cours;
	batiment = autre.batiment;
	materiels = autre.materiels;
	effectif = autre.effectif;
	type = autre.type;
}

Salle::Salle(string)
{
	// pour abdou et ali
}

Salle::~Salle()
{
	cout << "Destruction Salle" << endl;
	for(list<Matiere*>::iterator it = materiels.begin(); it!=materiels.end(); ++it){
		(*it)->get_salles().remove(this);}
}

Batiment* Salle::get_batiment()
{
	return batiment;
}

list <Matiere*> Salle::get_materiels()
{
	return materiels;
}

int Salle::get_effectif()
{
	return effectif;
}

Type Salle::get_type()
{
	return type;
}	

string Salle::to_string()
{
	// Pour abdou et ali
	return "rien";
}

void Salle::set_batiment(Batiment* b)
{
	batiment = b;
}

void Salle::set_materiels(list <Matiere*> l)
{
	materiels = l;
}

void Salle::set_effectif(int eff)
{
	effectif = eff;
}

void Salle::set_type(Type t)
{
	type = t;
}
