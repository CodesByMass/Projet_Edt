#include "Ressource.h"
#include "Cours.h"
#include "Groupe.h"
#include "Enseignant.h"
#include "Salle.h"

Ressource::Ressource()
{
	cout << "Construction Ressource" << endl;
	universite = NULL;
	identifiant = "";
	Vhoraire = -1;
	int tab[6][2] = {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
	copy(&tab[0][0],&tab[0][0]+6*2,&horaires[0][0]);
}

Ressource::Ressource(Universite* u, string id, int vh, int** h, list <Cours*> c)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
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
	cout << "Destruction Ressource" << endl;
	for(list<Cours*>::iterator it = cours.begin(); it!=cours.end(); ++it){
		if((*it)->get_enseignant()->get_identifiant() == identifiant)
			(*it)->set_enseignant(NULL);
		if((*it)->get_salle()->get_identifiant() == identifiant)
			(*it)->set_salle(NULL);
		for(list<Groupe*>::iterator iit = (*it)->get_groupes().begin(); iit!=(*it)->get_groupes().end(); ++iit){
			if((*iit)->get_identifiant() == identifiant)
				(*it)->get_groupes().erase(iit);}}
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

int** Ressource::get_horaires()
{
	return (int**)horaires;
}

list <Cours*> Ressource::get_cours()
{
	return cours;
}

string Ressource::to_string()
{
	// pour abdou et ali
	return "rien";
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

void Ressource::set_cours(list <Cours*> )
{

}

void Ressource::set_horaires(int** h)
{
	copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
}

void Ressource::from_string(string)
{
	// pour abdou et ali
}
