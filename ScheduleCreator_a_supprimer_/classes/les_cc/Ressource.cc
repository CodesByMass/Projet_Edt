#include "../les_h/Ressource.h"
#include "../les_h/Cours.h"
#include "../les_h/Groupe.h"
#include "../les_h/Enseignant.h"
#include "../les_h/Salle.h"

Ressource::Ressource()
{
	//cout << "Construction Ressource" << endl;
	universite = NULL;
	identifiant = "";
	Vhoraire = -1;
	int tab[6][2] = {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
	copy(&tab[0][0],&tab[0][0]+6*2,&horaires[0][0]);
	cours = {};
}

Ressource::Ressource(Universite* u, string id, int vh, int h[6][2], list <Cours*> c)
{
	//cout << "Construction Ressource" << endl;
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h != NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
}

Ressource::Ressource(Universite* u, string id, int vh, int h[6][2])
{
	//cout << "Construction Ressource" << endl;
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h != NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
}

Ressource::Ressource(Ressource const& autre)
{
	universite = autre.universite;
	identifiant = autre.identifiant;
	Vhoraire = autre.Vhoraire;
	copy(&autre.horaires[0][0],&autre.horaires[0][0]+6*2,&horaires[0][0]);
	cours = autre.cours;
}

Ressource::~Ressource()
{
	//cout << "Destruction Ressource" << endl;
}

Universite* Ressource::get_universite()
{
	return universite;
}

string Ressource::get_identifiant()
{
	return identifiant;
}

int Ressource::get_Vhoraire()
{
	return Vhoraire;
}

int Ressource::get_horaires(int i, int j)
{
	return horaires[i][j];
}

list <Cours*>* Ressource::get_cours()
{
	return &cours;
}

Cours* Ressource::get_cours(string s)
{
	for(list<Cours*>::iterator it = cours.begin(); it!= cours.end(); ++it){
		if((*it)->get_groupes(s) != NULL)	return (*it);}
	return NULL;
}

string Ressource::to_string()
{
	string s = identifiant + "_" + std::to_string(Vhoraire) + "_";
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 2; j++){
			s = s + std::to_string(horaires[i][j]) + "_";}}
	
	return s;
}

void Ressource::set_universite(Universite* u)
{
	universite = u;
}

void Ressource::set_identifiant(string id)
{
	identifiant = id;
}

void Ressource::set_Vhoraire(int vh)
{
	Vhoraire = vh;
}

void Ressource::add_cours(Cours* c)
{
	cours.push_front(c);
}

void Ressource::del_cours(Cours* c)
{
	cours.remove(c);
}

void Ressource::set_horaires(int** h)
{
	copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
}

void Ressource::from_string(string)
{
	// pour abdou et ali
}
