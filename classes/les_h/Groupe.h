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
		int effectif;
		
	public:
		Groupe();
		
		Groupe(Universite*, string, int, int[6][2], list <Cours*>, list <Filiere*>, int effectif);
		
		Groupe(Universite*, string, int, int[6][2], int effectif);
		
		Groupe(Groupe const&);
		
		Groupe(string);
		
		~Groupe();

		list <Filiere*>* get_filieres();
		
		int get_effectif();
		
		Filiere* get_filieres(string);
		
		string to_string();
		
		void set_effectif(int);
		
		void add_filiere(Filiere*);
		
		void del_filiere(Filiere* f);
};

#endif
