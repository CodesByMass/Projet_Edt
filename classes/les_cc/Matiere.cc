#include "Matiere.h"
#include "Enseignant.h"
#include "Salle.h"
#include "Cours.h"

Matiere::Matiere()
{
	cout << "Construction Matiere" << endl;
	nom = "";
	volume = -1;
}
		
Matiere::Matiere(list <Cours*> c, list <Filiere*> f, list <Salle*> s, int v, list <Enseignant*> e, string n)
{
		filieres = f;
		cours = c;
		nom = n;
		volume = v;
		salles = s;
		enseignants = e;
}

Matiere::Matiere(int v, string n)
{
		nom = n;
		volume = v;
}

Matiere::Matiere(Matiere const& autre)
{
		filieres = autre.filieres;
		cours = autre.cours;
		nom = autre.nom;
		volume = autre.volume;
		salles = autre.salles;
		enseignants = autre.enseignants;
}

Matiere::Matiere(string)
{
	// Pour abdou et ali
}

Matiere::~Matiere()
{
	cout << "Destruction Matiere" << endl;
	// supprimer la matiere des filieres
	for(list<Filiere*>::iterator it = filieres.begin(); it!= filieres.end(); ++it){
		(*it)->del_matiere(this);}
	// supprimer les cours qui lui sont associés
	for(list<Cours*>::iterator it = cours.begin(); it!= cours.end(); ++it){
		(*it)->set_matiere(NULL);}
	// supprimer la matiere des salles
	for(list<Salle*>::iterator it = salles.begin(); it!= salles.end(); ++it){
		(*it)->del_materiel(this);}
	// supprimer la qualification des professeurs 
	for(list<Enseignant*>::iterator it = enseignants.begin(); it!= enseignants.end(); ++it){
		(*it)->del_specialite(this);}
}

list <Filiere*> Matiere::get_filieres()
{
	return filieres;
}

list <Cours*> Matiere::get_cours()
{
	return cours;
}

list <Enseignant*> Matiere::get_enseignants()
{
	return enseignants;
}

list <Salle*> Matiere::get_salles()
{
	return salles;
}

string Matiere::get_nom()
{
	return nom;
}

int Matiere::get_volume()
{
	return volume;
}

string Matiere::to_string()
{
	// Pour abdou et ali
	return "rien";
}

void Matiere::add_filiere(Filiere* f)
{
	filieres.push_front(f);
}

void Matiere::del_filiere(Filiere* f)
{
	filieres.remove(f);
}

void Matiere::add_cours(Cours* c)
{
	cours.push_front(c);
}

void Matiere::del_cours(Cours* c)
{
	cours.remove(c);
}

void Matiere::add_salle(Salle* s)
{
	salles.push_front(s);
}

void Matiere::del_salle(Salle* s)
{
	salles.remove(s);
}

void Matiere::add_enseignant(Enseignant* e)
{
	enseignants.push_front(e);
}

void Matiere::del_enseignant(Enseignant* e)
{
	enseignants.remove(e);
}

void Matiere::set_nom(string n)
{
	nom = n;
}

void Matiere::set_volume(int v)
{
	volume = v;
}
