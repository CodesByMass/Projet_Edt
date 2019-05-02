#include "../les_h/Enseignant.h"
#include "../les_h/Matiere.h"

Enseignant::Enseignant()
{
	//cout << "Construction Enseignant" << endl;
}

Enseignant::Enseignant(Universite* u, string id, int vh, int h[6][2], list <Cours*> c, list<Matiere*> l)
{
	//cout << "Construction Enseignant" << endl;
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
	specialites = l;
	for(list<Matiere*>::iterator it = specialites.begin(); it!=specialites.end(); ++it){
		(*it)->add_enseignant(this);
		(*it)->get_enseignants()->unique();}
}

Enseignant::Enseignant(Universite* u, string id, int vh, int h[6][2])
{
	//cout << "Construction Enseignant" << endl;
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
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
	//cout << "Destruction Enseignant" << endl;
}

list <Matiere*>* Enseignant::get_specialites()
{
	return &specialites;
}

Matiere* Enseignant::get_specialites(string s)
{
	for(list<Matiere*>::iterator it = specialites.begin(); it!= specialites.end(); ++it)
		if((*it)->get_nom() == s) return (*it);
	return NULL;
}

string Enseignant::to_string()
{
	// Pour abdou et ali
	return "rien";
}

void Enseignant::add_specialite(Matiere* m)
{
	specialites.push_front(m);
}
		
void Enseignant::del_specialite(Matiere* m)
{
	specialites.remove(m);
}
