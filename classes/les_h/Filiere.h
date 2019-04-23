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
		
		Filiere(string new_nom, Universite*, EDT*);
		
		Filiere(Filiere const&);
		
		Filiere(string to_construct);
		
		~Filiere();
		
		list <Matiere*> get_matieres();
		
		string get_nom();
		
		Universite* get_universite();
		
		EDT* get_edt();
		
		list<Groupe*> get_groupes();
		
		string to_string();
		
		void add_matiere(Matiere*);
		
		void del_matiere(Matiere*);
		
		void set_nom(string );
		
		void add_groupe(Groupe*);

		void del_groupe(Groupe*);
		
		void set_universite(Universite*);
		
		void set_edt(EDT* );
};

#endif
