#include "Universite.h"
#include "Groupe.h"
#include "Salle.h"
#include "Enseignant.h"
#include "Filiere.h"


Universite::Universite()
{	
	cout << "Construction Universite" << endl;
	fermeture = -1;
	ouverture = -1;
	interclasse = -1;
	pauseDejeuner = -1;
	nom = "";
}
		
Universite::Universite(list <Filiere*> f, list <Groupe*> g, list <Salle*> s, list <Enseignant*> e, string new_nom)
{
	cout << "Construction Universite" << endl;
	filieres = f;
	groupes = g;
	salles = s;
	enseignants = e;		
	fermeture = -1;
	ouverture = -1;
	interclasse = -1;
	pauseDejeuner = -1;
	nom = new_nom;
}

Universite::Universite(int new_fermeture, int new_ouverture, int new_interclasse, int new_pauseDejeuner, string new_nom)
{
	fermeture = new_fermeture;
	ouverture = new_ouverture;
	interclasse = new_interclasse;
	pauseDejeuner = new_pauseDejeuner;
	nom = new_nom;
}
		
Universite::Universite(Universite const& autre)
{
	cout << "Construction Universite" << endl;
	filieres = autre.filieres;
	groupes = autre.groupes;
	salles = autre.salles;
	enseignants = autre.enseignants;		
	fermeture = autre.fermeture;
	ouverture = autre.ouverture;
	interclasse = autre.interclasse;
	pauseDejeuner = autre.pauseDejeuner;
	nom = autre.nom;
}
		
Universite::Universite(string)
{
	cout << "Construction Universite" << endl;
	//pour abdou & ali
}
		
Universite::~Universite()
{
	cout << "Destruction Universite" << endl;
	// On supprime l'université contenu dans les ressources
	for(list<Groupe*>::iterator it = groupes.begin(); it!=groupes.end(); ++it){
		(*it)->set_universite(NULL);}
	for(list<Salle*>::iterator it = salles.begin(); it!=salles.end(); ++it){
		(*it)->set_universite(NULL);}
	for(list<Enseignant*>::iterator it = enseignants.begin(); it!=enseignants.end(); ++it){
		(*it)->set_universite(NULL);}
	// On supprime les filieres qui lui sont associées
	for(list<Filiere*>::iterator it = filieres.begin(); it!=filieres.end(); ++it){
		(*it)->set_universite(NULL);}
}

list <Filiere*> Universite::get_filieres()
{
	return filieres;
}
		
list <Groupe*> Universite::get_groupes()
{
	return groupes;
}
		
list <Salle*> Universite::get_salles()
{
	return salles;
}
		
list <Enseignant*> Universite::get_enseignants()
{
	return enseignants;
}
		
string Universite::get_nom()
{
	return nom;
}

string Universite::to_string()
{
	// pour abdou & ali
	return "rien";
}

int Universite::get_fermeture()
{
	return fermeture;
}
		
int Universite::get_ouverture()
{
	return ouverture;
}
		
int Universite::get_interclasse()
{
	return interclasse;
}
		
int Universite::get_pauseDejeuner()
{
	return pauseDejeuner;
}

void Universite::add_filiere(Filiere* f)
{
	filieres.push_front(f);
}	

void Universite::del_filiere(Filiere* f)
{
	filieres.remove(f);
}

void Universite::add_groupe(Groupe* g)
{
	groupes.push_front(g);
}

void Universite::del_groupe(Groupe* g)
{
	groupes.remove(g);
}

void Universite::add_salle(Salle* s)
{
	salles.push_front(s);
}

void Universite::del_salle(Salle* s)
{
	salles.remove(s);
}

void Universite::add_enseignant(Enseignant* e)
{
	enseignants.push_front(e);
}

void Universite::del_enseignant(Enseignant* e)
{
	enseignants.remove(e);
}

void Universite::set_fermeture(int new_fermeture)
{
	fermeture = new_fermeture;
}
		
void Universite::set_ouverture(int new_ouverture)
{
	ouverture = new_ouverture;
}
		
void Universite::set_interclasse(int new_interclasse)
{
	interclasse = new_interclasse;
}
		
void Universite::set_pauseDejeuner(int new_pauseDejeuner)
{
	pauseDejeuner = new_pauseDejeuner;
}
		
void Universite::set_nom(string new_nom)
{
	nom = new_nom;
}
