#include "SGF.h"


void ecriture_universite(Universite *u)
{
	string const myFile ="universite.txt";
	ofstream fichier(myFile.c_str(),ios::out);  
		 
	if(fichier)
	{
		fichier << u->to_string();

		//Filières
		for(list<Filiere*>::iterator it = u->get_filieres()->begin(); it != u->get_filieres()->end(); ++it)
		{	
			fichier << (*it)->to_string();
		}
	
		//Matieres
		for(list<Filiere*>::iterator it = u->get_filieres()->begin(); it != u->get_filieres()->end(); ++it){	
			for(list<Matiere*>::iterator m = (*it)->get_matieres()->begin(); m != (*it)->get_matieres()->end(); ++m){
				fichier << (*m)->to_string();}
		}

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
	ifstream fichier("universite.txt", ios::in);  

	Universite* u = NULL;

	if(fichier)
	{
		string ligne;
        while(getline(fichier, ligne)){
			stringstream ss(ligne);
			string sousChaine;

			getline(ss, sousChaine, '_');
			if(sousChaine == "Universite"){
				getline(ss, sousChaine, '\n');
				u = new Universite(sousChaine);}
			else if(sousChaine == "Enseignant"){
				getline(ss, sousChaine, '\n');		
				new Enseignant(u,sousChaine);}
			else if(sousChaine == "Groupe"){
				getline(ss, sousChaine, '\n');	
				new Groupe(u,sousChaine);}
			else if(sousChaine == "Salle"){
				getline(ss, sousChaine, '\n');
				new Salle(u,sousChaine);}
			else if(sousChaine == "Filiere"){
				getline(ss, sousChaine, '\n');
				new Filiere(u,sousChaine);}
			else if(sousChaine == "Matiere"){
				getline(ss, sousChaine, '\n');
				new Matiere(u,sousChaine);}
			else if(sousChaine == "Cours"){
				getline(ss, sousChaine, '\n');
				new Cours(u,sousChaine);}
        }
		fichier.close();
	}
	else
	{
		cerr<< "Erreur à l'ouverture !"<<endl;
	}
	
	return u;
}


void conv_latex(EDT* edt)
{
	list<Groupe*> groupes = *(edt->get_filiere()->get_groupes());
	for(list<Groupe*>::iterator it1 = groupes.begin(); it1 != groupes.end(); ++it1)
	{
		string const path = "EDT/" + edt->get_filiere()->get_nom() + " - " + (*it1)->get_identifiant();
		ofstream fichier(path.c_str(),ios::out);
		if(fichier)
		{
			fichier<<"\\documentclass[12pt]{article}"<<endl;
			fichier<<"\\usepackage{edt}"<<endl;
			fichier<<"\\usepackage{geometry}"<<endl;
			fichier<<"\\geometry{hmargin=2.2cm,vmargin=1.6cm}"<<endl;
			fichier<<"\\schedtopsep 25"<<endl;
			fichier<<"\\thicklines"<<endl;
			fichier<<"\\schedunitlength=0.9pt"<<endl;
			fichier<<"\\firstday 0"<<endl;
			fichier<<"\\lastday 5"<<endl;
			fichier<<"\\startday 8"<<endl;
			fichier<<"\\endday 21"<<endl;
			fichier<<"\\markhours"<<endl;
			fichier<<"\\begin{document}"<<endl;
			fichier<<"\\preamble{\\Large "<<edt->get_filiere()->get_nom()<<" "<<(*it1)->get_identifiant()<<"}"<<endl;
			fichier<<"\\begin{schedule}"<<endl;
			for(int i = 0; i < edt->get_nbJours(); i++)
				for(int j = 0; j < edt->get_nbCreneau(); j++)
					for(list<Cours*>::iterator it2 = edt->get_cours()[i][j].begin(); it2 != edt->get_cours()[i][j].end(); ++it2)
					{
						int verif = 0;
						for(list<Groupe*>::iterator it3 = (*it2)->get_groupes()->begin(); it3 != (*it2)->get_groupes()->end() && verif == 0; ++it3)
							if((*it1)->get_identifiant() == (*it3)->get_identifiant())
								verif = 1;
						if(verif == 1)
							fichier<<"\\c "<<(*it2)->get_emplacementJour()<<" "<<(*it2)->get_heure_debut()<<"-"<<(*it2)->get_heure_fin()<<" "<<(*it2)->get_matiere()->get_nom()<<" "<<(*it2)->get_type_string()<<"\\\\"<<(*it2)->get_salle()->get_identifiant()<<"\\\\"<<(*it2)->get_enseignant()->get_identifiant()<<";"<<endl;
					}
			fichier<<"\\end{schedule}"<<endl;
			fichier<<"\\end{document}"<<endl;
			fichier.close();
		}
		else
			cerr<< "Erreur à l'ouverture !"<<endl;
	}
}
