#include "../les_h/Universite.h"
#include "../les_h/Groupe.h"
#include "../les_h/Salle.h"
#include "../les_h/Enseignant.h"
#include "../les_h/Filiere.h"


Universite::Universite()
{	
	//cout << "Construction Universite" << endl;
	fermeture = -1;
	ouverture = -1;
	interclasse = -1;
	pauseDejeuner = -1;
	nom = "";
	filieres = {};
	groupes = {};
	salles = {};
	enseignants = {};
}
		
Universite::Universite(list <Filiere*> f, list <Groupe*> g, list <Salle*> s, list <Enseignant*> e, string new_nom)
{
	//cout << "Construction Universite" << endl;
	filieres = f;
	groupes = g;
	salles = s;
	enseignants = e;		
	fermeture = -1;
	ouverture = -1;
	interclasse = -1;
	pauseDejeuner = -1;
	nom = new_nom;
}

Universite::Universite(int new_ouverture, int new_fermeture, int new_interclasse, int new_pauseDejeuner, string new_nom)
{
	//cout << "Construction Universite" << endl;
	fermeture = new_fermeture;
	ouverture = new_ouverture;
	interclasse = new_interclasse;
	pauseDejeuner = new_pauseDejeuner;
	nom = new_nom;
	filieres = {};
	groupes = {};
	salles = {};
	enseignants = {};
}
		
Universite::Universite(Universite const& autre)
{
	//cout << "Construction Universite" << endl;
	filieres = autre.filieres;
	groupes = autre.groupes;
	salles = autre.salles;
	enseignants = autre.enseignants;		
	fermeture = autre.fermeture;
	ouverture = autre.ouverture;
	interclasse = autre.interclasse;
	pauseDejeuner = autre.pauseDejeuner;
	nom = autre.nom;
}
		
Universite::Universite(string)
{
	//cout << "Construction Universite" << endl;
	//pour abdou & ali
}
		
Universite::~Universite()
{
	//cout << "Destruction Universite" << endl;
	// On supprime les ressources contenu dans l'université 
	for(list<Groupe*>::iterator it = groupes.begin(); it!=groupes.end(); ++it){
		if((*it)!=NULL) delete (*it);}
	for(list<Salle*>::iterator it = salles.begin(); it!=salles.end(); ++it){
		if((*it)!=NULL) delete (*it);}
	for(list<Enseignant*>::iterator it = enseignants.begin(); it!=enseignants.end(); ++it){
		if((*it)!=NULL) delete (*it);}
	// On supprime les filieres qui lui sont associées
	for(list<Filiere*>::iterator it = filieres.begin(); it!=filieres.end(); ++it){
		if((*it)!=NULL) delete (*it);}
}

list <Filiere*>* Universite::get_filieres()
{
	return &filieres;
}
		
list <Groupe*>* Universite::get_groupes()
{
	return &groupes;
}
		
list <Salle*>* Universite::get_salles()
{
	return &salles;
}
		
list <Enseignant*>* Universite::get_enseignants()
{
	return &enseignants;
}

Filiere* Universite::get_filieres(string s)
{
	for(list<Filiere*>::iterator it = filieres.begin(); it!= filieres.end(); ++it)
		if((*it)->get_nom() == s) return (*it);
	return NULL;
}
		
Groupe* Universite::get_groupes(string s)
{
	for(list<Groupe*>::iterator it = groupes.begin(); it!= groupes.end(); ++it)
		if((*it)->get_identifiant() == s) return (*it);
	return NULL;
}
		
Salle* Universite::get_salles(string s)
{
	for(list<Salle*>::iterator it = salles.begin(); it!= salles.end(); ++it)
		if((*it)->get_identifiant() == s) return (*it);
	return NULL;
}
		
Enseignant* Universite::get_enseignants(string s)
{
	for(list<Enseignant*>::iterator it = enseignants.begin(); it!= enseignants.end(); ++it)
		if((*it)->get_identifiant() == s) return (*it);
	return NULL;
}
		
string Universite::get_nom()
{
	return nom;
}

string Universite::to_string()
{
	// pour abdou & ali
	return "rien";
}

int Universite::get_fermeture()
{
	return fermeture;
}
		
int Universite::get_ouverture()
{
	return ouverture;
}
		
int Universite::get_interclasse()
{
	return interclasse;
}
		
int Universite::get_pauseDejeuner()
{
	return pauseDejeuner;
}

void Universite::add_filiere(Filiere* f)
{
	filieres.push_front(f);
}	

void Universite::del_filiere(Filiere* f)
{
	filieres.remove(f);
}

void Universite::add_groupe(Groupe* g)
{
	groupes.push_front(g);
}

void Universite::del_groupe(Groupe* g)
{
	groupes.remove(g);
}

void Universite::add_salle(Salle* s)
{
	salles.push_front(s);
}

void Universite::del_salle(Salle* s)
{
	salles.remove(s);
}

void Universite::add_enseignant(Enseignant* e)
{
	enseignants.push_front(e);
}

void Universite::del_enseignant(Enseignant* e)
{
	enseignants.remove(e);
}

void Universite::set_fermeture(int new_fermeture)
{
	fermeture = new_fermeture;
}
		
void Universite::set_ouverture(int new_ouverture)
{
	ouverture = new_ouverture;
}
		
void Universite::set_interclasse(int new_interclasse)
{
	interclasse = new_interclasse;
}
		
void Universite::set_pauseDejeuner(int new_pauseDejeuner)
{
	pauseDejeuner = new_pauseDejeuner;
}
		
void Universite::set_nom(string new_nom)
{
	nom = new_nom;
}


bool Universite::write_university(Universite *u)
{
	string const myFile ="universite.txt";
	ofstream fichier(myFile.c_str(),ios::out);  
		 
	if(fichier)
	{
		fichier<< u->get_nom() << "\n"<< u->get_ouverture()<< " "<< u->get_fermeture() << " "<< u->get_pauseDejeuner() << " " << u->get_interclasse() <<endl;
		
		//salles
		fichier<<"SALLES:"<<endl;
		
		for(list<Salle*>::iterator it = u->get_salles()->begin(); it!= u->get_salles()->end(); ++it)
		{	
			//info de base des ressources
			fichier<<(*it)->get_identifiant()<<" "<<(*it)->get_Vhoraire()<<" "<<(*it)->get_type()<<" "<<(*it)->get_effectif()<<" "<<(*it)->get_batiment()->nom<<endl;
			
			//les matières données dans les salles
			for(list<Matiere*>::iterator iit = (*it)->get_materiels()->begin(); iit !=(*it)->get_materiels()->end(); ++iit)
				fichier<<(*iit)->get_nom()<<" "<<(*iit)->get_volume()<<endl;
				
			//La disponibilité	des salles
			for(int i=0; i<6;i++)
				for(int j=0;j<2;j++)
					fichier<<(*it)->get_horaires(i,j)<<" ";
			fichier<<endl<<endl;
		}
		
		//Enseignant
		fichier<<"ENSEIGNANT:"<<endl;
		for(list<Enseignant*>::iterator it = u->get_enseignants()->begin(); it != u->get_enseignants()->end(); ++it)
		{
			fichier<<(*it)->get_identifiant()<<" "<<(*it)->get_Vhoraire()<<endl;
			
			for(list<Matiere*>::iterator iit = (*it)->get_specialites()->begin(); iit != (*it)->get_specialites()->end(); ++iit)
				fichier<<(*iit)->get_nom()<<" "<<(*iit)->get_volume()<<endl;
				
			for(int i=0; i<6;i++)
				for(int j=0;j<2;j++)
					fichier<<(*it)->get_horaires(i,j)<<" ";
			fichier<<endl<<endl;
		}
		
		//Groupes
		fichier<<"GROUPES:"<<endl;
		for(list<Groupe*>::iterator it = u->get_groupes()->begin(); it != u->get_groupes()->end(); ++it)
		{
			fichier<<(*it)->get_identifiant()<<" "<<(*it)->get_Vhoraire()<<endl;
			
			for(list<Filiere*>::iterator iit = (*it)->get_filieres()->begin(); iit != (*it)->get_filieres()->end(); ++iit)
				fichier<<(*iit)->get_nom()<<" "<<(*iit)->get_semestre()<<endl;
				
			for(int i=0; i<6;i++)
				for(int j=0;j<2;j++)
					fichier<<(*it)->get_horaires(i,j)<<" ";
			fichier<<endl;
		}
		
		//Filières
		fichier<<"\nFILIERES:"<<endl;
		
		for(list<Filiere*>::iterator it = u->get_filieres()->begin(); it != u->get_filieres()->end(); ++it)
		{	
			//info de base d'une filière
			fichier<<(*it)->get_nom()<<" "<<(*it)->get_semestre()<<" "<<(*it)->get_edt()->get_dureeCreneau()<<" "<<(*it)->get_edt()->get_nbJours()<<" "<<(*it)->get_edt()->get_nbCreneau()<<endl;
			
			//les matière de la filière
			for(list<Matiere*>::iterator iit = (*it)->get_matieres()->begin(); iit != (*it)->get_matieres()->end(); ++iit)
				fichier<<(*iit)->get_nom()<<" "<<(*iit)->get_volume()<<endl;
			fichier<<endl;
			
			//les groupes de la filière
			for(list<Groupe*>::iterator iit = (*it)->get_groupes()->begin(); iit != (*it)->get_groupes()->end(); ++iit)
			{
				//info de base d'un groupe 
				fichier<<(*iit)->get_identifiant()<<" "<<(*iit)->get_Vhoraire()<<" "<<(*iit)->get_effectif()<<endl;
					for(int i=0; i<6;i++)
						for(int j=0;j<2;j++)
							fichier<<(*iit)->get_horaires(i,j)<<" ";
				fichier<<endl<<endl;
			}

			//edt de la filière
			fichier<<"EDT de la filière: \n"<<endl;
			for(int i = 0; i < (*it)->get_edt()->get_nbJours(); i++)
			{
				for(int j = 0; j < (*it)->get_edt()->get_nbCreneau(); j++)
				{
				
					for(list<Cours*>::iterator iit =(*it)->get_edt()->get_cours()[i][j].begin(); iit!= (*it)->get_edt()->get_cours()[i][j].end(); ++iit)
					{
						//jours et creneau de la matière
						fichier <<(*iit)->get_emplacement()[0]<<" "<<(*iit)->get_emplacement()[1]<<" ";

						//nom du cours et type de la matière(td,tp ou cm)
						fichier <<(*iit)->get_matiere()->get_nom()<<" "<<(*iit)->get_type()<<" ";
						//groupe d'appartenance de la matière
						/*for(list<Groupe*>::iterator iiit = (*iit)->get_groupes()->begin(); iiit!=(*iit)->get_groupes()->end(); ++iit)
						{
							fichier <<(*iiit)->get_identifiant() <<" ";
						}*/

						//enseignant du cours et la salle dans laquelle va se tenir le cours
						fichier << (*iit)->get_enseignant()->get_identifiant()<< " ";
						fichier << (*iit)->get_salle()->get_identifiant()<<" "<<endl;
					}
				}
			}
		
		}
		
		fichier.close();
		
		return true;
	}
	else
	{
		cerr<< "Erreur à l'ouverture !"<<endl;
		
		return false;
	}

	 
}

Ressource* Universite::get_ressource(string str)
{
	for(list<Salle*>::iterator s = salles.begin(); s != salles.end(); ++s){
		if((*s)->get_identifiant() == str)
			return *s;}

	for(list<Enseignant*>::iterator e = enseignants.begin(); e != enseignants.end(); ++e){
		if((*e)->get_identifiant() == str)
			return *e;}
		
	for(list<Groupe*>::iterator g = groupes.begin(); g != groupes.end(); ++g){
		if((*g)->get_identifiant() == str)
			return *g;}
	
	return NULL;
}
