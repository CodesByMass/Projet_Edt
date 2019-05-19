#include "SGF.h"


void ecriture_universite(Universite *u)
{
	string const myFile ="universite.txt";
	ofstream fichier(myFile.c_str(),ios::out);  
		 
	if(fichier)
	{
		fichier << u->to_string();
		
		//salles
		for(list<Salle*>::iterator it = u->get_salles()->begin(); it!= u->get_salles()->end(); ++it)
		{	
			fichier << (*it)->to_string();
		}
		
		//Enseignant
		for(list<Enseignant*>::iterator it = u->get_enseignants()->begin(); it != u->get_enseignants()->end(); ++it)
		{
			fichier << (*it)->to_string();
		}
		
		//Groupes
		for(list<Groupe*>::iterator it = u->get_groupes()->begin(); it != u->get_groupes()->end(); ++it)
		{
			fichier << (*it)->to_string();
		}
		
		//Filières
		for(list<Filiere*>::iterator it = u->get_filieres()->begin(); it != u->get_filieres()->end(); ++it)
		{	
			fichier << (*it)->to_string();
		}
	
		//EDT
		for(list<Filiere*>::iterator it = u->get_filieres()->begin(); it != u->get_filieres()->end(); ++it)
		{	
			fichier << (*it)->get_edt()->to_string();
		}
	
		//Matieres
		for(list<Filiere*>::iterator it = u->get_filieres()->begin(); it != u->get_filieres()->end(); ++it){	
			for(list<Matiere*>::iterator m = (*it)->get_matieres()->begin(); m != (*it)->get_matieres()->end(); ++m){
				fichier << (*m)->to_string();}
		}
		
		//Cours
		for(list<Filiere*>::iterator it = u->get_filieres()->begin(); it != u->get_filieres()->end(); ++it){	
			for(list<Matiere*>::iterator m = (*it)->get_matieres()->begin(); m != (*it)->get_matieres()->end(); ++m){
				for(list<Cours*>::iterator c = (*m)->get_cours()->begin(); c != (*m)->get_cours()->end(); ++c){
					fichier << (*c)->to_string();}}}
	
		fichier.close();
	}
	else
	{
		cerr<< "Erreur à l'ouverture !"<<endl;
	}

	 
}

Universite* lecture_universite()
{
	return NULL;
}
