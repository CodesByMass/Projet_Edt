#ifndef Filiere_h
#define Filiere_h

#include "Universite.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
using namespace std;

class Groupe;
class Matiere;
class Universite;
class EDT;
class Filiere
{
	private:
		list <Matiere*> matieres;
		list <Groupe*> groupes;
		string nom;
		Universite* universite;
		EDT* edt;
	
	public:
		Filiere();
		
		Filiere(list <Matiere*>, list<Groupe*>, Universite*, string, EDT*);
		
		Filiere(Filiere const&);
		
		Filiere(string);
		
		~Filiere();
		
		list <Matiere*> get_matieres();
		
		string get_nom();
		
		Universite* get_universite();
		
		EDT* get_edt();
		
		list<Groupe*> get_groupes();
		
		string to_string();
		
		void set_matieres(list <Matiere*>);
		
		void set_nom(string );
		
		void set_groupes(list<Groupe*>);
		
		void set_universite(Universite*);
		
		void set_edt(EDT* );
};

#endif
