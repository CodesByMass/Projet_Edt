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
		(*it)->get_matieres().remove(this);}
	// supprimer les cours qui lui sont associés
	for(list<Cours*>::iterator it = cours.begin(); it!= cours.end(); ++it){
		delete[] (*it);}
	// supprimer la matiere des salles
	for(list<Salle*>::iterator it = salles.begin(); it!= salles.end(); ++it){
		(*it)->get_materiels().remove(this);}
	// supprimer la qualification des professeurs 
	for(list<Enseignant*>::iterator it = enseignants.begin(); it!= enseignants.end(); ++it){
		(*it)->get_specialites().remove(this);}
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

void Matiere::set_filieres(list <Filiere*> f)
{
	filieres = f;
}

void Matiere::set_cours(list <Cours*> c)
{
	cours = c;
}

void Matiere::set_salles(list<Salle*> s)
{
	salles = s;
}

void Matiere::set_enseignants(list <Enseignant*> e)
{
	enseignants = e;
}

void Matiere::set_nom(string n)
{
	nom = n;
}

void Matiere::set_volume(int v)
{
	volume = v;
}
