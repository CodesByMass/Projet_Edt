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
using namespace std;

struct Batiment;
class Matiere;
class Cours;
class Salle : public Ressource
{
	public:
		Batiment* batiment;
		list <Matiere*> materiels;
		int effectif;
		Type type;
		
	private:
		Salle();

		Salle(Universite*, string, int, int, int, list <Cours*>, Batiment*, list <Matiere*>, int, Type);
		
		Salle(Salle const&);
		
		Salle(string);
		
		~Salle();
		
		Batiment* get_batiment();
		
		list <Matiere*> get_materiels();
		
		int get_effectif();
		
		Type get_type();	
		
		string to_string();
		
		void set_batiment(Batiment* );
		
		void set_materiels(list <Matiere*> );
		
		void set_effectif(int );
		
		void set_type(Type );
};

struct Batiment
{
	list<Salle*> salles;
};

#endif
