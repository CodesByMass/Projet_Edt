#include "classes/les_h/Data.h"
#include "GenerateurEDT/GenerateurEDT.h"
#include <list> 
#include <iterator> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{	
	/* ---------------- Creation de l'universite de versailles ---------------- */
	Batiment Germain;
	Germain.nom = "Germain";
	Batiment Buffon;
	Germain.nom = "Buffon";
	Batiment Descartes;
	Germain.nom = "Descartes";
	Batiment Fermat;
	Germain.nom = "Fermat";
	
	Universite *u = new Universite(480,1100,10,4,"UFR des sciences de Versailles");
	
	/* ---------------- Creation de la filiere L3 INFO ---------------- */
	
	u->add_filiere(new Filiere("S6INFO",u,NULL,6));
	
	/* ---------------- Creation de l'edt de la filiere ---------------- */
	u->get_filieres("S6INFO")->set_edt(new EDT(u->get_filieres("L3INFO"),90,6,10));
	
	/* ---------------- Creation des matieres de la filiere ---------------- */
	u->get_filieres("S6INFO")->add_matiere(new Matiere(20,"Anglais"));
	u->get_filieres("S6INFO")->add_matiere(new Matiere(20,"Cryptographie"));
	u->get_filieres("S6INFO")->add_matiere(new Matiere(20,"CHP"));
	u->get_filieres("S6INFO")->add_matiere(new Matiere(20,"Reseau"));
	u->get_filieres("S6INFO")->add_matiere(new Matiere(20,"Projet"));
	
	/* ---------------- Creation des ressources ---------------- */
	u->add_enseignant(new Enseignant(u,"Prof Anglais 1",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Anglais")}));
	u->add_enseignant(new Enseignant(u,"Prof Anglais 2",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Anglais")}));
	u->add_enseignant(new Enseignant(u,"Prof Anglais 3",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Anglais")}));
	u->add_enseignant(new Enseignant(u,"Prof Crypto 1",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Cryptographie")}));
	u->add_enseignant(new Enseignant(u,"Prof Crypto 2",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Cryptographie")}));
	u->add_enseignant(new Enseignant(u,"Prof Crypto 3",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Cryptographie")}));
	u->add_enseignant(new Enseignant(u,"Prof Crypto 4",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Cryptographie")}));
	u->add_enseignant(new Enseignant(u,"Prof CHPS 1",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("CHP")}));
	u->add_enseignant(new Enseignant(u,"Prof CHPS 2",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("CHP")}));
	u->add_enseignant(new Enseignant(u,"Prof Reseau 1",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Reseau")}));
	u->add_enseignant(new Enseignant(u,"Prof Reseau 2",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Reseau")}));
	u->add_enseignant(new Enseignant(u,"Prof Reseau 3",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Reseau")}));
	u->add_enseignant(new Enseignant(u,"Prof Projet 1",35, NULL,{},{u->get_filieres("S6INFO")->get_matieres("Projet")}));
	u->add_salle(new Salle(u,"AMPHI D",40,NULL,{},&Descartes,{u->get_filieres("S6INFO")->get_matieres("Anglais"), u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 150, CM));
	u->add_salle(new Salle(u,"AMPHI H",40,NULL,{},&Fermat,{u->get_filieres("S6INFO")->get_matieres("Anglais"), u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 150, CM));
	u->add_salle(new Salle(u,"Aquitaine",40,NULL,{},&Descartes,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 40, TD));	
	u->add_salle(new Salle(u,"Alsace",40,NULL,{},&Descartes,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 40, TD));	
	u->add_salle(new Salle(u,"Jungle",40,NULL,{},&Descartes,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 40, TD));	
	u->add_salle(new Salle(u,"G201",40,NULL,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 40, TD));	
	u->add_salle(new Salle(u,"G202",40,NULL,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 48, TD));	
	u->add_salle(new Salle(u,"G203",40,NULL,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 42, TD));	
	u->add_salle(new Salle(u,"G204",40,NULL,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 40, TD));	
	u->add_salle(new Salle(u,"G205",40,NULL,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 44, TD));	
	u->add_salle(new Salle(u,"G206",40,NULL,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 40, TD));	
	u->add_salle(new Salle(u,"G207",40,NULL,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 43, TD));	
	u->add_salle(new Salle(u,"1001",40,NULL,{},&Fermat,{u->get_filieres("S6INFO")->get_matieres("Anglais"), u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 50, TD));
	u->add_salle(new Salle(u,"1002",40,NULL,{},&Fermat,{u->get_filieres("S6INFO")->get_matieres("Anglais"), u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet")}, 50, TD));
	u->add_groupe(new Groupe(u,"TD1",35,NULL,{},{u->get_filieres("S6INFO")},37));
	u->add_groupe(new Groupe(u,"TD2",35,NULL,{},{u->get_filieres("S6INFO")},35));
	u->add_groupe(new Groupe(u,"TD3",35,NULL,{},{u->get_filieres("S6INFO")},33));
	u->add_groupe(new Groupe(u,"TD4",35,NULL,{},{u->get_filieres("S6INFO")},32));
	u->add_groupe(new Groupe(u,"Anglais TD1",35,NULL,{},{u->get_filieres("S6INFO")},40));
	u->add_groupe(new Groupe(u,"Anglais TD2",35,NULL,{},{u->get_filieres("S6INFO")},41));
	u->add_groupe(new Groupe(u,"Anglais TD3",35,NULL,{},{u->get_filieres("S6INFO")},38));
	
	/* ---------------- Creation des cours ---------------- */
	u->get_filieres("S6INFO")->get_matieres("Anglais")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Anglais"),{u->get_groupes("Anglais TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("Anglais")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Anglais"),{u->get_groupes("Anglais TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("Anglais")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Anglais"),{u->get_groupes("Anglais TD3")},TD));	
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD4")},TD));	
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD4")},TD));
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD4")},TD));	
	u->get_filieres("S6INFO")->get_matieres("Projet")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Projet"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("Projet")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Projet"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("Projet")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Projet"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S6INFO")->get_matieres("Projet")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Projet"),{u->get_groupes("TD4")},TD));	

	InitialiseEDT(u->get_filieres("S6INFO"), u->get_filieres("S6INFO")->get_edt(), 0);
	
	// Ici VOus pouvez vous amusez avec la filiere
	
	
	
	
	
	
	
	
	
	
	
	
	
	// Affichage de l'edt attention ce n'est valable que pour l'edt de S6INFO
	
	int max = 0;
	
	for(int i = 0; i < u->get_filieres("S6INFO")->get_edt()->get_nbJours(); i++){
		for(int j = 0; j < u->get_filieres("S6INFO")->get_edt()->get_nbCreneau(); j++){
			for(list<Cours*>::iterator it = u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].begin(); it!=u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].end(); ++it){
				string s;
				if((*it)->get_type() == CM){
					s = s + "CM " + (*it)->get_matiere()->get_nom();}
				if((*it)->get_type() == TD){
					s = s + "TD " + (*it)->get_matiere()->get_nom();}
				if((*it)->get_type() == TP){
					s = s + "TD " + (*it)->get_matiere()->get_nom();}
				if(s.length() > max)
					max = s.length();
				
				string s1;
				
				if((*it)->get_type() == CM)
					s1 = s1 + u->get_filieres("S6INFO")->get_nom();
				if((*it)->get_type() == TD)
					s1 = s1 + "Groupe " + (*(*it)->get_groupes()->begin())->get_identifiant();
				if((*it)->get_type() == TP)
					s1 = s1 + "Groupe " + (*(*it)->get_groupes()->begin())->get_identifiant();
				if(s1.length() > max)
					max = s1.length();}}}
	
	
	for(int j = 0; j < u->get_filieres("S6INFO")->get_edt()->get_nbCreneau(); j++){
		for(int y = 0; y < u->get_filieres("S6INFO")->get_edt()->get_nbJours() * max + u->get_filieres("S6INFO")->get_edt()->get_nbJours() * 2; y++)
			cout << "-";
		cout << endl;
		int size = 1;
		for(int x = 0; x<size ; x++){
			for(int i = 0; i < u->get_filieres("S6INFO")->get_edt()->get_nbJours(); i++){
			string s;
				if(x < u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].size()){
					size = (u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].size() > size) ? u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].size() : size;
					list<Cours*>::iterator c = next(u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].begin(),x);
					if((*c)->get_type() == CM)
						s = s + "CM " + (*c)->get_matiere()->get_nom();
					if((*c)->get_type() == TD)
						s = s + "TD " + (*c)->get_matiere()->get_nom();
					if((*c)->get_type() == TP)
						s = s + "TD " + (*c)->get_matiere()->get_nom();
					cout << s;}
				
			for(int z = s.length(); z<=max; z++)
				cout << " ";
			cout << "|";}
			cout << endl;
				
			for(int i = 0; i < u->get_filieres("S6INFO")->get_edt()->get_nbJours(); i++){
			string s;
				if(x < u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].size()){
					size = (u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].size() > size) ? u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].size() : size;
					list<Cours*>::iterator c = next(u->get_filieres("S6INFO")->get_edt()->get_cours()[i][j].begin(),x);
					if((*c)->get_type() == CM)
						s = s + u->get_filieres("S6INFO")->get_nom();
					if((*c)->get_type() == TD)
						s = s + "Groupe " + (*(*c)->get_groupes()->begin())->get_identifiant();
					if((*c)->get_type() == TP)
						s = s + "Groupe " + (*(*c)->get_groupes()->begin())->get_identifiant();
					cout << s;}
				
			for(int z = s.length(); z<=max; z++)
				cout << " ";
			cout << "|";}
			cout << endl;}}

	delete u;
}
