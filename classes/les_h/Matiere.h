#ifndef Matiere_h
#define Matiere_h

#include "Filiere.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
using namespace std;

class Salle;
class Enseignant;
class Filiere;
class Cours;
class Matiere
{
	private:
		list <Filiere*> filieres;
		list <Cours*> cours;
		string nom;
		int volume;
		list <Salle*> salles;
		list <Enseignant*> enseignants;
	
	public:
		Matiere();
		
		Matiere(list <Cours*>, list <Filiere*>, list <Salle*>,int, list <Enseignant*>, string);
		
		Matiere(int, string);
		
		Matiere(Matiere const&);
				
		Matiere(string);
		
		~Matiere();
		
		list <Filiere*> get_filieres();
		
		list <Cours*> get_cours();
		
		list <Enseignant*> get_enseignants();
		
		list <Salle*> get_salles();
		
		string get_nom();
		
		int get_volume();
		
		string to_string();
		
		void add_filiere(Filiere*);
		
		void del_filiere(Filiere*);
		
		void add_cours(Cours*);
		
		void del_cours(Cours*);
		
		void add_salle(Salle*);
		
		void del_salle(Salle*);
		
		void add_enseignant(Enseignant*);
		
		void del_enseignant(Enseignant*);
		
		void set_nom(string );
		
		void set_volume(int);
};

#endif
