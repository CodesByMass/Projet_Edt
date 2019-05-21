#include "../les_h/Salle.h"

Salle::Salle()
{
	//cout << "Construction Salle" << endl;
	batiment = NULL;
	effectif = -1;
}

Salle::Salle(Universite* u, string id, int vh, int h[6][2], list <Cours*> c, Batiment* b, list <Matiere*> l, int eff, Type t)
{
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	cours = c;
	batiment = b;
	materiels = l;
	
	for(list<Matiere*>::iterator it = materiels.begin(); it!=materiels.end(); ++it){
		(*it)->add_salle(this);
		(*it)->get_salles()->unique();}	
		
	effectif = eff;
	type = t;
}

Salle::Salle(Universite* u, string id, int vh, int h[6][2], Batiment* b, int eff, Type t){
	universite = u;
	identifiant = id;
	Vhoraire = vh;
	if(h!= NULL)
		copy(&h[0][0],&h[0][0]+6*2,&horaires[0][0]);
	batiment = b;
	effectif = eff;
	type = t;
	cours = {};
}

Salle::Salle(Salle const& autre)
{
	universite = autre.universite;
	identifiant = autre.identifiant;
	Vhoraire = autre.Vhoraire;
	copy(&autre.horaires[0][0],&autre.horaires[0][0]+6*2,&horaires[0][0]);
	cours = autre.cours;
	batiment = autre.batiment;
	materiels = autre.materiels;
	effectif = autre.effectif;
	type = autre.type;
}

Salle::Salle(Universite* u, const string &chaine)
{
	
	stringstream ss(chaine);
	string sousChaine;

	universite = u;
	u->add_salle(this);
	
	getline(ss, sousChaine, '_');
	identifiant = sousChaine;
	getline(ss, sousChaine, '_');
	Vhoraire = stoi(sousChaine);
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 2; j++){
			getline(ss, sousChaine, '_');
			horaires[i][j] = stoi(sousChaine);}}
	
	getline(ss, sousChaine, '_');
	type = (Type)stoi(sousChaine);
	getline(ss, sousChaine, '_');
	effectif = stoi(sousChaine);

	getline(ss, sousChaine, '_');
	batiment = new Batiment;
	batiment->nom = sousChaine;
	batiment->salles.push_front(this);

	while (getline(ss, sousChaine, '_'))
	{
		if(universite->get_matiere(sousChaine) != NULL){
			materiels.push_back(universite->get_matiere(sousChaine));
			universite->get_matiere(sousChaine)->add_salle(this);}
	}
}

Salle::~Salle()
{
	//cout << "Destruction Salle" << endl;
}

Batiment* Salle::get_batiment()
{
	return batiment;
}

list <Matiere*>* Salle::get_materiels()
{
	return &materiels;
}

Matiere* Salle::get_materiels(string s)
{
	for(list<Matiere*>::iterator it = materiels.begin(); it!=materiels.end(); ++it)
		if((*it)->get_nom() == s) return *it;
	return NULL;
}

int Salle::get_effectif()
{
	return effectif;
}

Type Salle::get_type()
{
	return type;
}	

string Salle::to_string()
{
	
	string s = "Salle_" + Ressource::to_string();
	
	s = s + std::to_string(type);
	
	 s = s + "_" + std::to_string(effectif) + "_" + batiment->nom + "_";
	
	for(list<Matiere*>::iterator it = materiels.begin(); it!=materiels.end(); ++it)
		s = s + (*it)->get_nom() + "_";
	
	s = s + "\n";
	
	return s;
}

void Salle::set_batiment(Batiment* b)
{
	batiment = b;
}

void Salle::add_materiel(Matiere* m)
{
	materiels.push_front(m);
}

void Salle::del_materiel(Matiere* m)
{
	materiels.remove(m);
}

void Salle::set_effectif(int eff)
{
	effectif = eff;
}

void Salle::set_type(Type t)
{
	type = t;
}
