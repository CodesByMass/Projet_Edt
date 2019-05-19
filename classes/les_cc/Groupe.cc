#include "../les_h/Groupe.h"

Groupe::Groupe()
{
	//cout << "Construction Groupe" << endl;
}

Groupe::Groupe(Universite* u, string id, int vh, int h[6][2], list <Cours*> c, list <Filiere*> f, int eff)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
	filieres = f;
	
	for(list<Filiere*>::iterator it = filieres.begin(); it!=filieres.end(); ++it){
		(*it)->add_groupe(this);
		(*it)->get_groupes()->unique();}
		
	effectif = eff;
}

Groupe::Groupe(Universite* u, string id, int vh, int h[6][2], int eff)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	
	effectif = eff;
}

Groupe::Groupe(Groupe const& autre)
{
	universite = autre.universite;
	identifiant = autre.identifiant;
	Vhoraire = autre.Vhoraire;
	copy(&autre.horaires[0][0],&autre.horaires[0][0]+6*2,&horaires[0][0]);
	cours = autre.cours;
	filieres = autre.filieres;
	effectif = autre.effectif;
}

Groupe::Groupe(string)
{
	// Pour abdou et ali
}

Groupe::~Groupe()
{
	//cout << "Destruction Groupe" << endl;
}

list <Filiere*>* Groupe::get_filieres()
{
	return &filieres;
}

int Groupe::get_effectif()
{
	return effectif;
}

Filiere* Groupe::get_filieres(string s)
{
	for(list<Filiere*>::iterator it = filieres.begin(); it!= filieres.end(); ++it)
		if((*it)->get_nom() == s) return (*it);
	return NULL;
}

string Groupe::to_string()
{
	string s = "Groupe " + Ressource::to_string() + " " + std::to_string(effectif) + " ";
	
	for(list<Filiere*>::iterator it = filieres.begin(); it!=filieres.end(); ++it)
		s = s + (*it)->get_nom() + " ";
	
	s = s + "\n";
	
	return s;
}

void Groupe::add_filiere(Filiere* f)
{
	filieres.push_front(f);
}
		
void Groupe::del_filiere(Filiere* f)
{
	filieres.remove(f);
}

void Groupe::set_effectif(int eff)
{
	effectif = eff;
}
