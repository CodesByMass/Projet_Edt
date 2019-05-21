#ifndef Cours_h
#define Cours_h

#include "EDT.h"
#include "Type.h"
#include "Matiere.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
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
		list<EDT*> edt;
		int duree;
		int emplacement[2];
		
	public:
		Cours();
		
		Cours(Salle*, list <Groupe*>, Enseignant*, Type, Matiere*, list <EDT*>, int, int emplacementJour, int emplacementHeure);
		
		Cours(int, Matiere*, list <Groupe*>, Type t);
		
		Cours(Cours const& );
		
		Cours(Universite* u, const string &chaine);
		
		~Cours();
		
		Salle* get_salle();
		
		list <Groupe*>* get_groupes();
		
		Groupe* get_groupes(string);
		
		Enseignant* get_enseignant();
		
		Type get_type();

		string get_type_string();
		
		Matiere* get_matiere();
		
		list <EDT*>* get_edt();
		
		EDT* get_edt(string);
		
		int get_duree();
		
		char get_jour();

		string get_heure_debut();

		string get_heure_fin();

		int* get_emplacement();

		char get_emplacementJour();

		string get_emplacementCreneau();
		
		string to_string();
		
		void set_salle(Salle*);
		
		void add_groupe(Groupe*);
		
		void del_groupe(Groupe*);
		
		void set_enseignant(Enseignant*);
		
		void set_type(Type);
		
		void set_matiere(Matiere*);
		
		void del_edt(EDT*);
		
		void add_edt(EDT*);
		
		void set_duree(int);
		
		void set_emplacement(int,int);
		
		bool operator ==(Cours const& autre);
};

#endif
