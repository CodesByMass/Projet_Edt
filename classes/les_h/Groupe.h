#ifndef Groupe_h
#define Groupe_h

#include "Ressource.h"
#include "Filiere.h"
#include "Cours.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
using namespace std;

class Filiere;
class Cours;
class Groupe : public Ressource
{
	private:
		list <Filiere*> filieres;
		
	public:
		Groupe();
		
		Groupe(Universite*, string, int, int**, list <Cours*>, list <Filiere*>);
		
		Groupe(Universite*, string, int, int**);
		
		Groupe(Groupe const&);
		
		Groupe(string);
		
		~Groupe();

		list <Filiere*>* get_filieres();
		
		Filiere* get_filieres(string);
		
		string to_string();
		
		void add_filiere(Filiere*);
		
		void del_filiere(Filiere* f);
};

#endif
