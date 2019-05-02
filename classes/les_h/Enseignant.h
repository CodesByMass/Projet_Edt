#ifndef Enseignant_h
#define Enseignant_h

#include "Cours.h"
#include "Matiere.h"
#include "Ressource.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
using namespace std;

class Matiere;
class Cours;
class Enseignant: public Ressource
{
	private:
		list<Matiere*> specialites;
		
	public:
		Enseignant();
		
		Enseignant(Universite*, string, int, int[6][2], list<Cours*>, list<Matiere*>);
		
		Enseignant(Universite*, string, int, int[6][2]);
		
		Enseignant(Enseignant const&);
		
		Enseignant(string);
		
		~Enseignant();
		
		list <Matiere*>* get_specialites();
		
		Matiere* get_specialites(string);
		
		string to_string();
		
		void add_specialite(Matiere*);
		
		void del_specialite(Matiere*);	
};

#endif
