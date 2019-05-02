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
		int semestre;
	
	public:
		Filiere();
		
		Filiere(list <Matiere*>, list<Groupe*>, Universite*, string, EDT*, int);
		
		Filiere(string new_nom, Universite*, EDT*, int);
		
		Filiere(Filiere const&);
		
		Filiere(string to_construct);
		
		~Filiere();
		
		list <Matiere*>* get_matieres();
		
		Matiere* get_matieres(string);
		
		string get_nom();
		
		Universite* get_universite();
		
		int get_semestre();
		
		EDT* get_edt();
		
		list<Groupe*>* get_groupes();
		
		Groupe* get_groupes(string);
		
		string to_string();
		
		void add_matiere(Matiere*);
		
		void del_matiere(Matiere*);
		
		void set_semestre(int);
		
		void set_nom(string );
		
		void add_groupe(Groupe*);

		void del_groupe(Groupe*);
		
		void set_universite(Universite*);
		
		void set_edt(EDT* );
};

#endif
