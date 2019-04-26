#include "../les_h/Groupe.h"

Groupe::Groupe()
{
	cout << "Construction Groupe" << endl;
}

Groupe::Groupe(Universite* u, string id, int vh, int** h, list <Cours*> c, list <Filiere*> f)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
	filieres = f;
}

Groupe::Groupe(Universite* u, string id, int vh, int** h)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
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
		(*it)->del_groupe(this);}
}

list <Filiere*>* Groupe::get_filieres()
{
	return &filieres;
}

Filiere* Groupe::get_filieres(string s)
{
	for(list<Filiere*>::iterator it = filieres.begin(); it!= filieres.end(); ++it)
		if((*it)->get_nom() == s) return (*it);
	return NULL;
}

string Groupe::to_string()
{
	return "rien";
}

void Groupe::add_filiere(Filiere* f)
{
	filieres.push_front(f);
}
		
void Groupe::del_filiere(Filiere* f)
{
	filieres.remove(f);
}
