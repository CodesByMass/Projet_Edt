#ifndef Universite_h
#define Universite_h

#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
using namespace std;

class Filiere;
class Groupe;
class Salle;
class Enseignant;
class Universite
{
	private:
		list <Filiere*> filieres;
		list <Groupe*> groupes;
		list <Salle*> salles;
		list <Enseignant*> enseignants;		
		int fermeture;
		int ouverture;
		int interclasse;
		int pauseDejeuner;
		string nom;
		
	public:
		Universite();
		
		Universite(list <Filiere*>, list <Groupe*>, list <Salle*>, list <Enseignant*> , string);
		
		Universite(Universite const&);
		
		Universite(string);
		
		~Universite();
		
		list <Filiere*> get_filieres();
		
		list <Groupe*> get_groupes();
		
		list <Salle*> get_salles();
		
		list <Enseignant*> get_enseignants();
		
		string get_nom();

		string to_string();

		int get_fermeture();
		
		int get_ouverture();
		
		int get_interclasse();
		
		int get_pauseDejeuner();
		
		void set_filieres(list <Filiere*> );
		
		void set_groupes(list <Groupe*>);
		
		void set_salles(list <Salle*> );
		
		void set_enseignants(list <Enseignant*> );

		void set_fermeture(int);
		
		void set_ouverture(int);
		
		void set_interclasse(int);
		
		void set_pauseDejeuner(int);
		
		void set_nom(string);
};

#endif

