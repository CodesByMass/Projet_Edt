#ifndef EDT_h
#define EDT_h

#include "Filiere.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
using namespace std;

class Cours;
class Filiere;
class EDT
{
	private:	
		list <Cours*>** cours;
		Universite* universite;
		int dureeCreneau;
		int nbJours;
		int nbCreneau;	
		
	public:
		EDT();
		
		EDT(list <Cours*>**, Universite*, int, int, int*);
		
		EDT(EDT const&);
		
		EDT(string);
		
		~EDT();
		
		list <Cours*>** get_cours();
		
		Universite* get_universite();
		
		int get_dureeCreneau();
		
		int get_nbJours();
		
		int get_nbCreneau();
		
		string to_string();
		
		void set_cours(list <Cours*>**);
		
		void set_universite(Universite* );
		
		void set_dureeCreneau(int);
		
		void set_nbJours(int);
		
		void set_nbCreneau(int);
};

#endif
