#ifndef Cours_h
#define Cours_h

#include "EDT.h"
#include "Type.h"
#include "Matiere.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
using namespace std;

class Enseignant;
class Groupe;
class Salle;
class EDT;
class Matiere;
class Cours
{
	private:
		Salle* salle;
		list <Groupe*> groupes;
		Enseignant* enseignant;
		Type type;
		Matiere* matiere;
		EDT* edt;
		int duree;
		int emplacement[2];
		
	public:
		Cours();
		
		Cours(Salle*, list <Groupe*>, Enseignant*, Type, Matiere*, EDT*, int, int emplacementJour, int emplacementHeure);
		
		Cours(int);
		
		Cours(Cours const& );
		
		Cours(string);
		
		~Cours();
		
		Salle* get_salle();
		
		list <Groupe*> get_groupes();
		
		Enseignant* get_enseignant();
		
		Type get_type();
		
		Matiere* get_matiere();
		
		EDT* get_edt();
		
		int get_duree();
		
		int* get_emplacement();
		
		string to_string();
		
		void set_salle(Salle*);
		
		void set_groupes(list <Groupe*>);
		
		void set_enseignant(Enseignant*);
		
		void set_type(Type);
		
		void set_matiere(Matiere*);
		
		void set_edt(EDT*);
		
		void set_duree(int);
		
		void set_emplacement(int,int);
};

#endif
