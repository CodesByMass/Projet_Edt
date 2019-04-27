#include "../les_h/Cours.h"
#include "../les_h/Groupe.h"
#include "../les_h/Enseignant.h"
#include "../les_h/Salle.h"
#include "../les_h/Ressource.h"
#include "../les_h/EDT.h"
#include "../les_h/Matiere.h"

Cours::Cours()
{
	cout << "Construction Cours" << endl;
	salle = NULL;
	enseignant = NULL;
	matiere = NULL;
	duree = -1;
	emplacement[0] = -1;
	emplacement[1] = -1;
	groupes = {};
	enseignant = {};
}

Cours::Cours(Salle* s, list <Groupe*> g, Enseignant* e, Type t, Matiere* m, list <EDT*> new_edt, int du, int emplacementJour, int emplacementHeure)
{
	cout << "Construction Cours" << endl;
	salle = s;
	groupes = g;
	enseignant = e;
	type = t;
	matiere = m;
	edt = new_edt;
	duree = duree;
	emplacement[0] = emplacementJour;
	emplacement[1] = emplacementHeure;
}

Cours::Cours(int d, Matiere* m, list <Groupe*> g, Type t)
{
	cout << "Construction Cours" << endl;
	salle = NULL;
	enseignant = NULL;
	groupes = g;
	matiere = m;
	duree = d;
	emplacement[0] = -1;
	emplacement[1] = -1;
	enseignant = {};
	type = t;
}

Cours::Cours(Cours const& autre)
{
	cout << "Construction Cours" << endl;
	salle = autre.salle;
	groupes = autre.groupes;
	enseignant = autre.enseignant;
	type = autre.type;
	matiere = autre.matiere;
	edt = autre.edt;
	duree = autre.duree;
	emplacement[0] = autre.emplacement[0];
	emplacement[1] = autre.emplacement[1];
}

Cours::Cours(string)
{
	//Pour abdou et ali
}

Cours::~Cours()
{
	cout << "Destruction Cours" << endl;
}

Salle* Cours::get_salle()
{
	return salle;
}

list <Groupe*>* Cours::get_groupes()
{
	return &groupes;
}

Groupe* Cours::get_groupes(string s)
{
	for(list<Groupe*>::iterator it = groupes.begin(); it!= groupes.end(); ++it)
		if((*it)->get_identifiant() == s) return (*it); 
	return NULL;
}

Enseignant* Cours::get_enseignant()
{
	return enseignant;
}

Type Cours::get_type()
{
	return type;
}

Matiere* Cours::get_matiere()
{
	return matiere;
}

list <EDT*>* Cours::get_edt()
{
	return &edt;
}

EDT* Cours::get_edt(string s)
{
	for(list<EDT*>::iterator it = edt.begin(); it!= edt.end(); ++it){
		if((*it)->get_filiere() != NULL && (*it)->get_filiere()->get_nom() == s)	return (*it);}
	return NULL;
}

int Cours::get_duree()
{
	return duree;
}

int* Cours::get_emplacement()
{
	return emplacement;
}

string Cours::to_string()
{
	// Pour abdou et ali
	return "rien";
}

void Cours::set_salle(Salle* s)
{
	salle = s;
}

void Cours::add_groupe(Groupe* g)
{
	groupes.push_front(g);
}
		
void Cours::del_groupe(Groupe* g)
{
	groupes.remove(g);
}

void Cours::set_enseignant(Enseignant* e)
{
	enseignant = e;
}

void Cours::set_type(Type t)
{
	type = t;
}

void Cours::set_matiere(Matiere* m)
{
	matiere = m;
}

void Cours::del_edt(EDT* e)
{
	edt.remove(e);
}
		
void Cours::add_edt(EDT* e)
{
	edt.push_front(e);
}

void Cours::set_duree(int d)
{
	duree = d;
}

void Cours::set_emplacement(int J,int H)
{
	emplacement[0] = J;
	emplacement[1] = H;
}
