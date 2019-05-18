#ifndef Salle_h
#define Salle_h

#include "Ressource.h"
#include "Matiere.h"
#include "Cours.h"
#include "Type.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Batiment;
class Matiere;
class Cours;
class Salle : public Ressource
{
	private:
		Batiment* batiment;
		list <Matiere*> materiels;
		int effectif;
		Type type;
		
	public:
		Salle();

		Salle(Universite*, string, int, int[6][2], list <Cours*>, Batiment*, list <Matiere*>, int, Type);
		
		Salle(Universite* u, string id, int vh, int h[6][2], Batiment*, int, Type);
		
		Salle(Salle const&);
		
		Salle(string);
		
		~Salle();
		
		Batiment* get_batiment();
		
		list <Matiere*>* get_materiels();
		
		Matiere* get_materiels(string);
		
		int get_effectif();
		
		Type get_type();	
		
		string to_string();
		
		void set_batiment(Batiment* );
		
		void add_materiel(Matiere*);

		void del_materiel(Matiere*);
		
		void set_effectif(int );
		
		void set_type(Type );
};

struct Batiment
{
	string nom;
	list<Salle*> salles;
};

#endif
