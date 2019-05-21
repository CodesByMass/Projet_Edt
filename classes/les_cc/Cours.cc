#include "../les_h/Cours.h"
#include "../les_h/Groupe.h"
#include "../les_h/Enseignant.h"
#include "../les_h/Salle.h"
#include "../les_h/Ressource.h"
#include "../les_h/EDT.h"
#include "../les_h/Matiere.h"

Cours::Cours()
{
	//cout << "Construction Cours" << endl;
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
	//cout << "Construction Cours" << endl;
	salle = s;
	groupes = g;
	enseignant = e;
	type = t;
	matiere = m;
	edt = new_edt;
	duree = duree;
	emplacement[0] = emplacementJour;
	emplacement[1] = emplacementHeure;
	for(list<Groupe*>::iterator groupe = g.begin(); groupe != g.end(); ++groupe)
		(*groupe)->add_cours(this);
}

Cours::Cours(int d, Matiere* m, list <Groupe*> g, Type t)
{
	//cout << "Construction Cours" << endl;
	salle = NULL;
	enseignant = NULL;
	groupes = g;
	matiere = m;
	duree = d;
	emplacement[0] = -1;
	emplacement[1] = -1;
	enseignant = {};
	type = t;
	for(list<Groupe*>::iterator groupe = g.begin(); groupe != g.end(); ++groupe)
		(*groupe)->add_cours(this);
}

Cours::Cours(Cours const& autre)
{
	//cout << "Construction Cours" << endl;
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

Cours::Cours(Universite* u, const string &chaine)
{
	stringstream ss(chaine);
	string sousChaine;
	
	getline(ss, sousChaine, '_');
	type = (Type)stoi(sousChaine);
	
	getline(ss, sousChaine, '_');
	if(u->get_matiere(sousChaine) != NULL){
		matiere = u->get_matiere(sousChaine);
		matiere->add_cours(this);}
	
	getline(ss, sousChaine, '_');
	if(u->get_salles(sousChaine) != NULL){
		salle = u->get_salles(sousChaine);
		salle->add_cours(this);}
	else{
		salle = NULL;}
		
	getline(ss, sousChaine, '_');
	if(u->get_enseignants(sousChaine) != NULL){
		enseignant = u->get_enseignants(sousChaine);
		enseignant->add_cours(this);}
	else{
		enseignant = NULL;}
	
	getline(ss, sousChaine, '_');
	duree = stoi(sousChaine);
	
	getline(ss, sousChaine, '_');
	emplacement[0] = stoi(sousChaine);
	
	getline(ss, sousChaine, '_');
	emplacement[1] = stoi(sousChaine);
	
	if(emplacement[0] != -1 && emplacement[1] != -1){
		for(list<Filiere*>::iterator f = matiere->get_filieres()->begin(); f != matiere->get_filieres()->end(); ++f){
			edt.push_front((*f)->get_edt());
			(*f)->get_edt()->add_cours(this,emplacement[0], emplacement[1]);}}
		
	
	while (getline(ss, sousChaine, '_'))
	{
		if(u->get_groupes(sousChaine) != NULL){
			groupes.push_back(u->get_groupes(sousChaine));
			u->get_groupes(sousChaine)->add_cours(this);}
	}
	
}
Cours::~Cours()
{
	//cout << "Destruction Cours" << endl;
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

string Cours::get_type_string()
{
	switch(type)
	{
		case CM:
			return "CM";
		case TD:
			return "TD";
		case TP:
			return "TP";
		default:
			return "~";
	}
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

char Cours::get_emplacementJour()
{
	switch(emplacement[0])
	{
		case 0:
			return 'M';
		case 1:
			return 'T';
		case 2:
			return 'W';
		case 3:
			return 'H';
		case 4:
			return 'F';
		case 5:
			return 'S';
		case 6:
			return 'U';
		default:
			return '~';
	}
}

string Cours::get_heure_debut()
{
	switch (emplacement[1])
	{
	  case 0:
	  	return "8:00";
	  case 1:
	  	return "9:40";
	  case 2:
	  	return "11:20";
	  case 3:
	  	return "13:00"; 
	  case 4:
	  	return "13:40";
	  case 5:
	  	return "15:20";
	  case 6:
	  	return "17:00";
	  case 7:
	  	return "18:40";
	  default:
	  	return "~";
	}
}

string Cours::get_heure_fin()
{
	switch (emplacement[1]) 
	{
	  case 0:
	  	if(duree==1)
	    	return "9:30";
	  	return "11:10";
	  case 1:
		if(duree==1)
			return "11:10";
		return "12:50";
	  case 2:
	  	return "12:50";
	  case 3:
	  	return "13:30";
	  case 4:
		if(duree==1)
			return "15:10";
		return "16:50";
	  case 5:
		if(duree==1)
			return "16:50";
		return "18:30";
	  case 6:
		if(duree==1)
			return "18:30";
		return "20:10";
	  case 7:
			return "20:10";
	  default:
	  	return "~";
	}
}

string Cours::to_string()
{
	string s = "Cours_" + std::to_string(type) + "_" + matiere->get_nom() + "_";
	
	if(salle != NULL)
		s = s + salle->get_identifiant();
	s = s + "_";
	if(enseignant != NULL)
		s = s + enseignant->get_identifiant();
	s = s + "_";
	
	s = s + std::to_string(duree) + "_" + std::to_string(emplacement[0]) + "_" + std::to_string(emplacement[1]) + "_";
	
	for(list<Groupe*>::iterator it = groupes.begin(); it!= groupes.end(); ++it)
		s = s + (*it)->get_identifiant() + "_";
	
	 s = s + "\n";
	
	return s;
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
	edt.push_back(e);
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

bool Cours::operator ==(Cours const& autre)
{
	
	if(groupes.size() != autre.groupes.size())
		return false;
	
	for(list<Groupe*>::const_iterator g1 = autre.groupes.begin(); g1 != autre.groupes.end(); ++g1){
		for(list<Groupe*>::iterator g2 = groupes.begin(); g2 != groupes.end(); ++g2){
			if((*g1)->get_identifiant() != (*g2)->get_identifiant())
				return false;}}
	
	
	return (matiere == autre.matiere && type == autre.type);
}

