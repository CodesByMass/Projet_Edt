#include "../les_h/Salle.h"

Salle::Salle()
{
	//cout << "Construction Salle" << endl;
	batiment = NULL;
	effectif = -1;
}

Salle::Salle(Universite* u, string id, int vh, int h[6][2], list <Cours*> c, Batiment* b, list <Matiere*> l, int eff, Type t)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
	batiment = b;
	materiels = l;
	
	for(list<Matiere*>::iterator it = materiels.begin(); it!=materiels.end(); ++it){
		(*it)->add_salle(this);
		(*it)->get_salles()->unique();}	
		
	effectif = eff;
	type = t;
}

Salle::Salle(Universite* u, string id, int vh, int h[6][2], Batiment* b, int eff, Type t){
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	batiment = b;
	effectif = eff;
	type = t;
	cours = {};
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
	//cout << "Destruction Salle" << endl;
}

Batiment* Salle::get_batiment()
{
	return batiment;
}

list <Matiere*>* Salle::get_materiels()
{
	return &materiels;
}

Matiere* Salle::get_materiels(string s)
{
	for(list<Matiere*>::iterator it = materiels.begin(); it!=materiels.end(); ++it)
		if((*it)->get_nom() == s) return *it;
	return NULL;
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
	
	string s = "Salle " + Ressource::to_string();
	
	if(type == CM)
		s = s + "CM";
	if(type == TD)
		s = s + "TD";
	if(type == TP)
		s = s + "TP";
	
	 s = s + " " + std::to_string(effectif) + " " + batiment->nom + " ";
	
	for(list<Matiere*>::iterator it = materiels.begin(); it!=materiels.end(); ++it)
		s = s + (*it)->get_nom() + " ";
	
	s = s + "\n";
	
	return s;
}

void Salle::set_batiment(Batiment* b)
{
	batiment = b;
}

void Salle::add_materiel(Matiere* m)
{
	materiels.push_front(m);
}

void Salle::del_materiel(Matiere* m)
{
	materiels.remove(m);
}

void Salle::set_effectif(int eff)
{
	effectif = eff;
}

void Salle::set_type(Type t)
{
	type = t;
}
