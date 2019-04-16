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
		
		Ressource(Universite*, string, int, int, int, list <Cours*>);
		
		Ressource(Ressource const&);
		
		virtual ~Ressource();
		
		Universite* get_universite();
		
		string get_identifiant();
		
		int get_Vhoraire();
		
		int** get_horaires();
		
		list <Cours*> get_cours();
		
		string to_string();
		
		void set_universite(Universite*);
		
		void set_identifiant(string );
		
		void set_Vhoraire(int );
		
		void set_Hmin(int );
		
		void set_Hmax(int );
		
		void set_cours(list <Cours*> );
		
		void set_horaires(int**);
		
		void from_string(string);
};

#endif
