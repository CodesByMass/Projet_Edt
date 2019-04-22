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
		Filiere* filiere;
		int dureeCreneau;
		int nbJours;
		int nbCreneau;	
		
	public:
		EDT();
		
		EDT(list <Cours*>**, Filiere*, int, int, int);
		
		EDT(EDT const&);
		
		EDT(string);
		
		~EDT();
		
		list <Cours*>** get_cours();
		
		Filiere* get_filiere();
		
		int get_dureeCreneau();
		
		int get_nbJours();
		
		int get_nbCreneau();
		
		string to_string();
		
		void set_cours(list <Cours*>, int x, int y);
		
		void set_filiere(Filiere* );
		
		void set_dureeCreneau(int);
		
		void set_nbJours(int);
		
		void set_nbCreneau(int);
};

#endif
