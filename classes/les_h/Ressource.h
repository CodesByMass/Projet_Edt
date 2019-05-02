#ifndef Ressource_h
#define Ressource_h

#include "Universite.h"
#include "Cours.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
using namespace std;

class Ressource
{
	protected:
		Universite* universite;
		string identifiant;
		int Vhoraire;
		int horaires[6][2];
		list <Cours*> cours;
		
	public:
		Ressource();
		
		Ressource(Universite*, string, int, int[6][2], list <Cours*>);
		
		Ressource(Universite*, string, int, int[6][2]);
		
		Ressource(Ressource const&);
		
		virtual ~Ressource();
		
		Universite* get_universite();
		
		string get_identifiant();
		
		int get_Vhoraire();
		
		int get_horaires(int, int);
		
		list <Cours*>* get_cours();
		
		Cours* get_cours(string);
		
		string to_string();
		
		void set_universite(Universite*);
		
		void set_identifiant(string );
		
		void set_Vhoraire(int );
		
		void add_cours(Cours* );
		
		void del_cours(Cours* );
		
		void set_horaires(int**);
		
		void from_string(string);
};

#endif
