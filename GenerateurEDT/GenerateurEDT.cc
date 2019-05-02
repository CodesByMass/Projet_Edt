#include "GenerateurEDT.h"
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

EDT* GenereEDT(Universite* univ, Filiere* fil, EDT* edt, int debug)
{
	//Find a random initial solution
	edt = InitialiseEDT(fil, edt, debug--);
	//Initialise le pointeur vers le voisin
	EDT* edtVoisin = NULL;
	//Select an initial temperature
	int temp = 100;
	//Select a temperature reduction variable
	int reduc = 1;
	//Tant que la temperature n'a pas atteint la valeur seuil faire
	while(temp >= 0)
	{
		//Evaluer l'EDT actuelle
		int Eactuelle = EvalueEDT(univ, edt, debug--);
		//Tant qu'il n'y a pas de changement accepté jusqu'a un certain seuil
		int i = 0;
		while(i < 100)
		{
			//Créer l'EDT voisin
			edtVoisin = GenereVoisin(fil, edt, debug--);
			//Evaluer l'EDT voisin
			int Evoisin = EvalueEDT(univ, edt, debug--);
			//Si on accepte le changement
			if(Accepte(Eactuelle, Evoisin, temp, debug--)){
				//Supprimer l'EDT actuelle
				delete edt;
				//Remplacer l'EDT actuelle par le voisin
				edt = edtVoisin;
				//on sort
				break;
			}
			//Sinon 
			else{
				//Supprimer l'EDT voisin
				delete edtVoisin;
				i++;
			}
		}	
		//Si on a pas eu dechangement i fois d'affilé on quitte
		break;
		//Diminuer la temperature
		temp = DiminueTemperature(temp, reduc, debug--);
	}
	//Retourner EDT
	return edt;
}

bool VerifieEDT(Universite* univ, EDT* edt, int debug)
{
	//Verifie si aucune contrainte forte n'est enfreinte
	return EvalueHard(univ, edt, debug--) == 0;
}

//Verifié
EDT* InitialiseEDT(Filiere* fil, EDT* edt, int debug)
{
	list<Matiere*>::iterator matieres;
	list<Cours*>::iterator cours;
	
	//Pour chaque matiere de la filiere
	for(matieres = fil->get_matieres()->begin(); matieres != fil->get_matieres()->end(); ++matieres){
		
		if(Affiche_debug(debug))	cout << "Initialisation de la matiere " << (*matieres)->get_nom() << endl;

		//Pour chaque Cours de Matiere
		for(cours = (*matieres)->get_cours()->begin(); cours != (*matieres)->get_cours()->end(); ++cours){
			if(Affiche_debug(debug))	cout << "Initialisation du cours du groupe" << endl;
			
			//Lui affecter des ressources si necessaire
			if(Affiche_debug(debug))	cout << "Affectation des ressources" << endl;
			AffecteCours(fil, *cours, debug--);

			//Si emplacement est vide (= -1)
			if((*cours)->get_emplacement()[0] == -1 || (*cours)->get_emplacement()[1] == -1){
				//Placer le cours dans l'EDT
				if(Affiche_debug(debug))	cout << "Affectation des ressources" << endl;
				PlaceCours(edt, *cours, debug--);
			}

		}
	}

	//Retourner l'EDT
	return edt;
}

// verifié
EDT* GenereVoisin(Filiere* fil, EDT* edt, int debug)
{
	//Appeller le constructeur de recopie de l'EDT
	if(Affiche_debug(debug))	cout << "Constructeur de recopie" << endl;
	EDT* edtVoisin = new EDT(*edt);
	
	//Tirer au sort si on déplace ou change affectation
		//Si deplacer
		if(Random_a_b(0, 100, debug--) > 50){ 
			//Deplacer
			if(Affiche_debug(debug))	cout << "On deplace un cours" << endl;
			DeplaceCours(edtVoisin, debug--);
		}
		//Si changer affectaion
		else{
			//Changer affectation
			if(Affiche_debug(debug))cout << "On change une affectation" << endl;
			ChangeAffectation(edtVoisin, fil, debug--);
		}

	//Retourner l'edt copié
	return edtVoisin;
}

//verifié
int EvalueEDT(Universite* univ, EDT* edt, int debug)
{
	//Stocker l'evaluation des contraintes hards
	if(Affiche_debug(debug))cout << "Evaluation des contraintes hard" << endl;
	int Ehard = EvalueHard(univ, edt, debug--);
	
	//Si levaluation des contraintes hard est egal a 0
	if(Ehard == 0){
		//Retourner l'evaluation des contraintes soft
		if(Affiche_debug(debug))cout << "Evaluation des contraintes hard" << endl;
		return EvalueSoft(univ, edt, debug--);
	}
	//Sinon retourner 0 - l'evaluation des contraintes (en negatif pour qu'on sache si que c les contraintes hard)
	return 0-Ehard;
}

//verifié
int DiminueTemperature(int temp, int reduc, int debug)
{
	//Diminuer la temp en fonction de la variable de reduction
	return temp-reduc;
}

//Verifié
Cours* AffecteCours(Filiere* fil, Cours* cours, int debug)
{
	//Si le cours n'a pas d'enseignant
	if(cours->get_enseignant() == NULL){
		if(Affiche_debug(debug))	cout << "Le cours n'a pas d'enseignant" << endl;
		
		//choisir aleatoirement l'un des enseignants specialiste de la matiere du cours
		if(Affiche_debug(debug))	cout << "Choix parmi les " << cours->get_matiere()->get_enseignants()->size() << " enseignants qualifiés" << endl;
		list<Enseignant*>::iterator e = cours->get_matiere()->get_enseignants()->begin();
		advance(e, Random_a_b(0,cours->get_matiere()->get_enseignants()->size(), debug--));
		
		//lui affecter l'enseignant
		if(Affiche_debug(debug))	cout << "Affectation de l'enseignant" << endl;
		cours->set_enseignant(*e);
		
		//affecter le cours a l'enseignant
		if(Affiche_debug(debug))	cout << "Affectation du cours à l'enseignant" << endl;
		(*e)->add_cours(cours);
	}
	/* le cours devra imperativement avoir un groupe de prévu */
	
	//Si le cours n'a pas de salle 
	if(cours->get_salle() == NULL){
		if(Affiche_debug(debug))	cout << "Le cours n'a pas de salle" << endl;
		
		//choisir une salle aléatoirement parmi celle compatible avec la matiere et le type
		if(Affiche_debug(debug))	cout << "Choix parmi les " << cours->get_matiere()->get_salles()->size() << " salles disponibles" << endl;
		list<Salle*>::iterator s = cours->get_matiere()->get_salles()->begin();
		advance(s, Random_a_b(0, cours->get_matiere()->get_salles()->size(), debug--));
		
		//lui affecter la salle
		if(Affiche_debug(debug))	cout << "Affectation de la salle" << endl;
		cours->set_salle(*s);
		
		//affecter le cours a la salle
		if(Affiche_debug(debug))	cout << "Affectation du cours à la salle" << endl;
		(*s)->add_cours(cours);
	}
	//Retourner le cours
	return cours;
}

//Verifié
EDT* PlaceCours(EDT* edt, Cours* cours, int debug)
{
	//Selectionne aleatoirement un jours
	if(Affiche_debug(debug))	cout << "Choix du jours parmi les " << edt->get_nbJours() << " jours disponibles" << endl;	
	int jour = Random_a_b(0, edt->get_nbJours(), debug--);
	
	//Selectionne aleatoirement une heure
	if(Affiche_debug(debug))	cout << "Choix du creneau parmi les " << edt->get_nbCreneau() << " creneaux disponibles" << endl;	
	int heure = Random_a_b(0, edt->get_nbCreneau() - cours->get_duree()+1, debug--);
	
	//Voir si le cours peut etre placer a ce créneau en fonction de la duree de celui la et de la pause
	cours->set_emplacement(jour, heure);
	cours->add_edt(edt);
	//Placer le cours a cette heure dans tout les edt
	for(list<EDT*>::iterator it = cours->get_edt()->begin(); it!=cours->get_edt()->end(); ++it){
		(*it)->add_cours(cours,jour,heure);}
	
	return edt;
}

//Verifié
EDT* DeplaceCours(EDT* edt, int debug)
{
	if(Affiche_debug(debug)) cout << "Selection aléatoire du cours de "; 
	//Selectionner un cours aleatoirement dans EDT
	Cours* cours = SelectionneAleatoirement(edt, debug--);
	if(Affiche_debug(debug)) cout << cours->get_matiere()->get_nom() << " du " << (*cours->get_groupes()->begin())->get_identifiant() << "du " << cours->get_emplacement()[0]+1 << "eme jour et " << cours->get_emplacement()[1]+1 << "eme creneau" << endl;
	//Le supprimer de l'emploi du temps
	edt->get_cours()[cours->get_emplacement()[0]][cours->get_emplacement()[1]].remove(cours);
	cours->get_enseignant()->get_cours()->remove(cours);
	cours->get_salle()->get_cours()->remove(cours);
	for(list<Groupe*>::iterator g = cours->get_groupes()->begin(); g != cours->get_groupes()->begin(); ++g)
		(*g)->get_cours()->remove(cours);
	//Le copier
	cours = new Cours(*cours);
	//Le remplacer par la copie
	edt->get_cours()[cours->get_emplacement()[0]][cours->get_emplacement()[1]].push_front(cours);
	cours->get_enseignant()->get_cours()->push_front(cours);
	cours->get_salle()->get_cours()->push_front(cours);
	for(list<Groupe*>::iterator g = cours->get_groupes()->begin(); g != cours->get_groupes()->begin(); ++g)
		(*g)->get_cours()->push_front(cours);


	//emplacemnt actuel du cours
	int jour = cours->get_emplacement()[0];
	int heure = cours->get_emplacement()[1];
	if(Affiche_debug(debug)) cout << "Deplacement du " << jour+1 << "eme jour " << heure+1 << "eme creneau vers le ";
	

	//Supprimer le cours de tout les edt qui lui sont associés
	edt->del_cours(cours,jour,heure);
	//Selectionne aleatoirement un jours
	jour = Random_a_b(0, edt->get_nbJours(), debug--);
	//Selectionne aleatoirement une heure
	heure = Random_a_b(0, edt->get_nbCreneau() - cours->get_duree()+1, debug--);
	
	if(Affiche_debug(debug)) cout<< jour+1 << "eme jour " << heure+1 << "eme creneau" << endl;
	//Voir si le cours peut etre placer a ce créneau en fonction de la duree de celui la et de la pause
	cours->set_emplacement(jour, heure);
	//Placer le cours a cette heure dans l'edt à mofifier et pas dans tous les edt a voir si acceptation
	edt->add_cours(cours,jour,heure);
	
	return edt;
}

//Verifié
EDT* ChangeAffectation(EDT* edt, Filiere* fil, int debug)
{
	if(Affiche_debug(debug)) cout << "Selection aléatoire du cours de "; 
	//Selectionner un cours aleatoirement dans EDT
	Cours* cours = SelectionneAleatoirement(edt, debug--);
	if(Affiche_debug(debug)) cout << cours->get_matiere()->get_nom() << " du " << (*cours->get_groupes()->begin())->get_identifiant() << "du " << cours->get_emplacement()[0]+1 << "eme jour et " << cours->get_emplacement()[1]+1 << "eme creneau" << endl;
	//Le supprimer de l'emploi du temps
	edt->get_cours()[cours->get_emplacement()[0]][cours->get_emplacement()[1]].remove(cours);
	cours->get_enseignant()->get_cours()->remove(cours);
	cours->get_salle()->get_cours()->remove(cours);
	for(list<Groupe*>::iterator g = cours->get_groupes()->begin(); g != cours->get_groupes()->begin(); ++g)
		(*g)->get_cours()->remove(cours);
	//Le copier
	cours = new Cours(*cours);
	//Le remplacer par la copie
	edt->get_cours()[cours->get_emplacement()[0]][cours->get_emplacement()[1]].push_front(cours);
	cours->get_enseignant()->get_cours()->push_front(cours);
	cours->get_salle()->get_cours()->push_front(cours);
	for(list<Groupe*>::iterator g = cours->get_groupes()->begin(); g != cours->get_groupes()->begin(); ++g)
		(*g)->get_cours()->push_front(cours);
		
	int i = Random_a_b(0,2);

	if(i){
		if(Affiche_debug(debug)) cout << "changement d'enseignant" << endl;
		//Supprimer le cours en question des cours de l'enseignant
		cours->get_enseignant()->del_cours(cours);
		//Supprimer l'enseignant du cours
		cours->set_enseignant(NULL);
		//choisir aleatoirement l'un des enseignants specialiste de la matiere du cours
		list<Enseignant*>::iterator e = cours->get_matiere()->get_enseignants()->begin();
		advance(e, Random_a_b(0,cours->get_matiere()->get_enseignants()->size(), debug--));
		//lui affecter l'enseignant
		cours->set_enseignant(*e);
		//ajouter le cours a la liste de cours de l'enseignant
		(*e)->add_cours(cours);
	}
	else{
		if(Affiche_debug(debug)) cout << "changement de salle" << endl;
		//Supprimer le cours en question des cours de la salle
		cours->get_salle()->del_cours(cours);
		//Supprimer la salle du cours
		cours->set_salle(NULL);
		//choisir une salle aléatoirement parmi celle compatible avec la matiere et le type
		list<Salle*>::iterator s = cours->get_matiere()->get_salles()->begin();
		advance(s, Random_a_b(0, cours->get_matiere()->get_salles()->size(), debug--));
		//lui affecter la salle
		cours->set_salle(*s);
		//ajouter le cours a la liste de cours de la salle
		(*s)->add_cours(cours);
	}

	//Retourner l'edt
	return edt;
}

//verifé
int EvalueSoft(Universite* univ, EDT* edt, int debug)
{
	//creer une variable ou stocker les energies retournées & les pthreads
	int* Esoft[5] = {0,0,0,0,0};
	pthread_t contrainte1, contrainte2, contrainte3, contrainte4, contrainte5;
	
	//creation de la strucure de donnée a donner en argument aux threads
	contrainte_arg arg = {univ, edt, debug--};
	
	//lancer les threads 
	if(Affiche_debug(debug))	cout << "debut lancement des contraintes soft" << endl;
	   
	if(pthread_create(&contrainte1, NULL, CM_avant_TD, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 1" << endl;
	if(pthread_create(&contrainte2, NULL, nb_trous, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 2" << endl;
	if(pthread_create(&contrainte3, NULL, repartition_horaire, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 3" << endl;
	if(pthread_create(&contrainte4, NULL, CM_TD_journee, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 4" << endl;
	if(pthread_create(&contrainte5, NULL, nb_deplacement, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 5" << endl;
		
	if(Affiche_debug(debug))	cout << "fin lancement des contraintes soft" << endl;
	
	//recuperer les threads
	if(Affiche_debug(debug))	cout << "debut recuperation des contraintes soft" << endl;
	
	if (pthread_join(contrainte1, (void**)&Esoft[0]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 1" << endl;	
	if (pthread_join(contrainte2, (void**)&Esoft[1]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 2" << endl;	
	if (pthread_join(contrainte3, (void**)&Esoft[2]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 3" << endl;	
	if (pthread_join(contrainte4, (void**)&Esoft[3]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 4" << endl;	
	if (pthread_join(contrainte5, (void**)&Esoft[4]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 5" << endl;	
	
	if(Affiche_debug(debug))	cout << "fin recuperation des contraintes soft" << endl;
	
	//faire la somme des energies
	if(Affiche_debug(debug))	cout << "somme des contraintes" << endl;
	int res = 0;
	for(int i=0; i<5; i++){
		res = res + *Esoft[i];
		delete Esoft[i];}
	if(Affiche_debug(debug))	cout << "Esoft = " << res << endl;

	//retourner l'energie
	return res;
}

//verifié
int EvalueHard(Universite* univ, EDT* edt, int debug)
{
	//creer une variable ou stocker les energies retournées & les pthreads
	int* Ehard[9] = {0,0,0,0,0,0,0,0,0};
	pthread_t contrainte1, contrainte2, contrainte3, contrainte4, contrainte5, contrainte6, contrainte7, contrainte8, contrainte9;
	
	//creation de la strucure de donnée a donner en argument aux threads
	contrainte_arg arg = {univ, edt, debug--};
	
	//lancer les threads 
	if(Affiche_debug(debug))	cout << "debut lancement des contraintes hard" << endl;
	   
	if(pthread_create(&contrainte1, NULL, ressource_par_creneau, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 1" << endl;
	if(pthread_create(&contrainte2, NULL, volume_horaire_ressources, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 2" << endl;
	if(pthread_create(&contrainte3, NULL, respect_horaire_ressources, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 3" << endl;
	if(pthread_create(&contrainte4, NULL, effectif_salles, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 4" << endl;
	if(pthread_create(&contrainte5, NULL, equipement_salles, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 5" << endl;
	if(pthread_create(&contrainte6, NULL, respect_pause_dejeuner, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 6" << endl;
	if(pthread_create(&contrainte7, NULL, respect_enseignant_qualifie, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 7" << endl;
	if(pthread_create(&contrainte8, NULL, respect_type_salle, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 8" << endl;
	if(pthread_create(&contrainte9, NULL, cours_plusieurs_jours, &arg) == -1 && Affiche_debug(debug))
		cout << "erreur lancement contrainte 9" << endl;
		
	if(Affiche_debug(debug))	cout << "fin lancement des contraintes hard" << endl;
	
	//recuperer les threads
	if(Affiche_debug(debug))	cout << "debut recuperation des contraintes hard" << endl;
	
	if (pthread_join(contrainte1, (void**)&Ehard[0]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 1" << endl;	
	if (pthread_join(contrainte2, (void**)&Ehard[1]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 2" << endl;	
	if (pthread_join(contrainte3, (void**)&Ehard[2]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 3" << endl;	
	if (pthread_join(contrainte4, (void**)&Ehard[3]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 4" << endl;	
	if (pthread_join(contrainte5, (void**)&Ehard[4]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 5" << endl;	
	if (pthread_join(contrainte6, (void**)&Ehard[5]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 6" << endl;	
	if (pthread_join(contrainte7, (void**)&Ehard[6]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 7" << endl;	
	if (pthread_join(contrainte8, (void**)&Ehard[7]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 8" << endl;	
	if (pthread_join(contrainte9, (void**)&Ehard[8]) && Affiche_debug(debug))
		cout << "erreur recuperation contrainte 9" << endl;	
	
	if(Affiche_debug(debug))	cout << "fin recuperation des contraintes hard" << endl;
	
	//faire la somme des energies
	if(Affiche_debug(debug))	cout << "somme des contraintes" << endl;
	int res = 0;
	for(int i=0; i<9; i++){
		res = res + *Ehard[i];
		delete Ehard[i];}
	if(Affiche_debug(debug))	cout << "Ehard = " << res << endl;

	//retourner l'energie
	return res;
}

//Verifié
Cours* SelectionneAleatoirement(EDT* edt, int debug)
{
	list<Cours*>::iterator c;
	//Tant qu'il n'y a pas de cours dans le creneau choisi
	while(1){
		//Selectionne aleatoirement un jours
		int jour = Random_a_b(0, edt->get_nbJours(), debug--);
		//Selectionne aleatoirement une heure
		int heure = Random_a_b(0, edt->get_nbCreneau(), debug--);
		//Voir si il y a des cours dans le creneau en question
		if(edt->get_cours()[jour][heure].size()!=0){
			//Selection aleatoirement un cours dans la liste de creneau
			 c = edt->get_cours()[jour][heure].begin();
			advance(c, Random_a_b(0,edt->get_cours()[jour][heure].size(), debug--));
			break;}
	}
	
	//Retourner le cours
	return *c;
}

//Verifié juste pour les entiers
float Random_a_b(int a, int b, int debug)
{
	if(a==0 && b==1){
		return (rand()/(double)RAND_MAX)*(b-a)+a;}
	
	// retourne un entier entre 
	return rand()%(b-a)+a;
}

bool Affiche_debug(int debug)
{
	return debug >= 1;
}

bool Accepte(int Eactuelle, int Evoisin, int temp, int debug)
{
	//initialiser delta
	int delta = 0;
	
	//Si les deux energies sont négatives
	if(Eactuelle<0 && Evoisin<0){
		//delta = Eactuelle - Evoisin
		delta = Eactuelle - Evoisin;
		// retourner delta < 0
		return delta<0;
	}

	//Sinon si les deux energies sont positives
	else if(Eactuelle > 0 && Evoisin > 0){
		//delta = Evoisin - Eactuelle
		delta = Evoisin - Eactuelle;
		//retourner delta < 0 ou (exp(-delta/temp) < rand[0,1])
		return delta < 0 || (exp(-delta/temp) < Random_a_b(0,1,debug--));
	}
	//Sinon 
	else{
		//retourner Evoisin > Eactuelle
		return Evoisin > Eactuelle;
	}
	
	//Dans le doute on retourne faux
	return false;
}

/*------------- Contraintes Hard ------------------*/
/* Attention au moment ou on evalue l'edt n'est pas encore accepté c a dire que les informations sont pas les meme entre celle de l'edt de l'argument et celles de l'universié */
//Verifié
void* ressource_par_creneau(void* void_arg)
{	
	//recuperation des arguments et initialisation du resultat
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte ressource_par_creneau \n---------------------\n"  << endl;
	int* cpt = new int(0);
	
	//pour chaque groupe concerné
	for(list<Groupe*>::iterator g = (*arg).edt->get_filiere()->get_groupes()->begin(); g != (*arg).edt->get_filiere()->get_groupes()->end(); ++g){
		if(Affiche_debug((*arg).debug)) cout << "\nVerification ressource_par_creneau groupe " << (*arg).edt->get_filiere()->get_nom() << " " << (*g)->get_identifiant() << "\n" << endl;
		for(list<Cours*>::iterator c = (*g)->get_cours()->begin(); c != (*g)->get_cours()->end(); ++c){
			if(Affiche_debug((*arg).debug)) cout << "Verification cours " <<  (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<endl;
			for(list<Cours*>::iterator autre = next(c,1); autre != (*g)->get_cours()->end(); ++autre){
				if((*c)->get_emplacement()[0] == (*autre)->get_emplacement()[0] && (*c)->get_emplacement()[1] == (*autre)->get_emplacement()[1]){
					if(Affiche_debug((*arg).debug)) cout << "\t" << (*c)->get_matiere()->get_nom() << " utilise le meme groupe que " << (*autre)->get_matiere()->get_nom() << "!!!" << endl;
					*cpt = *cpt + 1;}}}}
					
	//Pour chaque enseignant concerné
	for(list<Matiere*>::iterator m = (*arg).edt->get_filiere()->get_matieres()->begin(); m != (*arg).edt->get_filiere()->get_matieres()->end(); ++m){
		for(list<Enseignant*>::iterator e = (*m)->get_enseignants()->begin(); e != (*m)->get_enseignants()->end(); ++e){
			if(Affiche_debug((*arg).debug)) cout << " \nVerification ressource_par_creneau de l'enseignant de " << (*m)->get_nom() << " " << (*e)->get_identifiant() << "\n" << endl;
			for(list<Cours*>::iterator c = (*e)->get_cours()->begin(); c != (*e)->get_cours()->end(); ++c){
			if(Affiche_debug((*arg).debug)) cout << "Verification cours " <<  (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<endl;
			for(list<Cours*>::iterator autre = next(c,1); autre != (*e)->get_cours()->end(); ++autre){
				if((*c)->get_emplacement()[0] == (*autre)->get_emplacement()[0] && (*c)->get_emplacement()[1] == (*autre)->get_emplacement()[1]){
					if(Affiche_debug((*arg).debug)) cout << "\t" << (*c)->get_matiere()->get_nom() << " utilise le meme enseignant que " << (*autre)->get_matiere()->get_nom() << "!!!" << endl;
					*cpt = *cpt + 1;}}}}}
	
	//Pour chaque salle concernés
	for(list<Salle*>::iterator s = (*arg).univ->get_salles()->begin(); s != (*arg).univ->get_salles()->end(); ++s){
			if(Affiche_debug((*arg).debug)) cout << " \nVerification ressource_par_creneau de la salle " << (*s)->get_identifiant() << "\n" << endl;	
			for(list<Cours*>::iterator c = (*s)->get_cours()->begin(); c != (*s)->get_cours()->end(); ++c){
					if(Affiche_debug((*arg).debug)) cout << "Verification cours " <<  (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<endl;
					for(list<Cours*>::iterator autre = next(c,1); autre != (*s)->get_cours()->end(); ++autre){
						if((*c)->get_emplacement()[0] == (*autre)->get_emplacement()[0] && (*c)->get_emplacement()[1] == (*autre)->get_emplacement()[1]){
							if(Affiche_debug((*arg).debug)) cout << "\t" << (*c)->get_matiere()->get_nom() << " utilise la meme salle que " << (*autre)->get_matiere()->get_nom() << "!!!" << endl;
							*cpt = *cpt + 1;}}}}

	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte ressource_par_creneau \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

//Verifié
void* volume_horaire_ressources(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte volume_horaire_ressources \n---------------------\n"  << endl;
	int* cpt = new int(0);
	int vh;
	
	//Pour chaque groupe concerné
	for(list<Groupe*>::iterator g = (*arg).edt->get_filiere()->get_groupes()->begin(); g != (*arg).edt->get_filiere()->get_groupes()->end(); ++g){
		if(Affiche_debug((*arg).debug)) cout << "\nVerification volume_horaire groupe " << (*arg).edt->get_filiere()->get_nom() << " " << (*g)->get_identifiant() << "\n" << endl;
		vh = 0;
		for(list<Cours*>::iterator c = (*g)->get_cours()->begin(); c != (*g)->get_cours()->end(); ++c){
			if(Affiche_debug((*arg).debug)) cout << "\tCours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau dure " << (*c)->get_duree() * (*arg).edt->get_dureeCreneau() << "min" <<  endl;;
			vh = vh + ((*c)->get_duree() * (*arg).edt->get_dureeCreneau());}
			if(Affiche_debug((*arg).debug)) cout << "Total de " << vh/60 << "heures pour une limite de " << (*g)->get_Vhoraire() << "heures" << endl;
			if(vh/60 > (*g)->get_Vhoraire()) *cpt = *cpt + 1;}
	
	//Pour chaque enseignant concerné
	for(list<Matiere*>::iterator m = (*arg).edt->get_filiere()->get_matieres()->begin(); m != (*arg).edt->get_filiere()->get_matieres()->end(); ++m){
		for(list<Enseignant*>::iterator e = (*m)->get_enseignants()->begin(); e != (*m)->get_enseignants()->end(); ++e){
			if(Affiche_debug((*arg).debug)) cout << " \nVerification volume_horaire de l'enseignant de " << (*m)->get_nom() << " " << (*e)->get_identifiant() << "\n" << endl;
			vh = 0;
			for(list<Cours*>::iterator c = (*e)->get_cours()->begin(); c != (*e)->get_cours()->end(); ++c){
				if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau dure " << (*c)->get_duree() * (*arg).edt->get_dureeCreneau() << "min" <<  endl;;
				vh = vh + ((*c)->get_duree() * (*arg).edt->get_dureeCreneau());}
				if(Affiche_debug((*arg).debug)) cout << "Total de " << vh/60 << "heures pour une limite de " << (*e)->get_Vhoraire() << "heures" << endl;
				if(vh/60 > (*e)->get_Vhoraire()) *cpt = *cpt + 1;}}
	
	//Pour chaque salle concernés
	for(list<Salle*>::iterator s = (*arg).univ->get_salles()->begin(); s != (*arg).univ->get_salles()->end(); ++s){
		if(Affiche_debug((*arg).debug)) cout << " \nVerification volume_horaire de la salle " << (*s)->get_identifiant() << "\n" << endl;	
		vh = 0;
			for(list<Cours*>::iterator c = (*s)->get_cours()->begin(); c != (*s)->get_cours()->end(); ++c){
				if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau dure " << (*c)->get_duree() * (*arg).edt->get_dureeCreneau() << "min" <<  endl;;
				vh = vh + ((*c)->get_duree() * (*arg).edt->get_dureeCreneau());}
				if(Affiche_debug((*arg).debug)) cout << "Total de " << vh/60 << "heures pour une limite de " << (*s)->get_Vhoraire() << "heures" << endl;
				if(vh/60 > (*s)->get_Vhoraire()) *cpt = *cpt + 1;}
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte volume_horaire_ressources \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

//Verifié
void* respect_horaire_ressources(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte respect_horaire_ressources \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	//Pour chaque groupe concerné
	for(list<Groupe*>::iterator g = (*arg).edt->get_filiere()->get_groupes()->begin(); g != (*arg).edt->get_filiere()->get_groupes()->end(); ++g){
		if(Affiche_debug((*arg).debug)) cout << "\nVerification respect_horaire groupe " << (*arg).edt->get_filiere()->get_nom() << " " << (*g)->get_identifiant() << "\n" << endl;
		for(list<Cours*>::iterator c = (*g)->get_cours()->begin(); c != (*g)->get_cours()->end(); ++c){
			if(Affiche_debug((*arg).debug)) cout << "\tCours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<  endl;
			if((*c)->get_emplacement()[1] < (*g)->get_horaires((*c)->get_emplacement()[0],0) || (*c)->get_emplacement()[1] > ((*g)->get_horaires((*c)->get_emplacement()[0],1))){
				if(Affiche_debug((*arg).debug)) cout << "\t\t" << (*g)->get_identifiant() << " n'est pas disponible a cette heure la !!!" << endl;
				*cpt = *cpt + 1;}}}
	
	//Pour chaque enseignant concerné
	for(list<Matiere*>::iterator m = (*arg).edt->get_filiere()->get_matieres()->begin(); m != (*arg).edt->get_filiere()->get_matieres()->end(); ++m){
		for(list<Enseignant*>::iterator e = (*m)->get_enseignants()->begin(); e != (*m)->get_enseignants()->end(); ++e){
			if(Affiche_debug((*arg).debug)) cout << " \nVerification respect_horaire de l'enseignant de " << (*m)->get_nom() << " " << (*e)->get_identifiant() << "\n" << endl;
			for(list<Cours*>::iterator c = (*e)->get_cours()->begin(); c != (*e)->get_cours()->end(); ++c){
				if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<  endl;
			if((*c)->get_emplacement()[1] < (*e)->get_horaires((*c)->get_emplacement()[0],0) || (*c)->get_emplacement()[1] > ((*e)->get_horaires((*c)->get_emplacement()[0],1))){
					if(Affiche_debug((*arg).debug)) cout << "\t\t" << (*e)->get_identifiant() << " n'est pas disponible a cette heure la !!!" << endl;
					*cpt = *cpt + 1;}}}}
	
	//Pour chaque salle concernés
	for(list<Salle*>::iterator s = (*arg).univ->get_salles()->begin(); s != (*arg).univ->get_salles()->end(); ++s){
		if(Affiche_debug((*arg).debug)) cout << " \nVerification respect_horaire de la salle " << (*s)->get_identifiant() << "\n" << endl;	
			for(list<Cours*>::iterator c = (*s)->get_cours()->begin(); c != (*s)->get_cours()->end(); ++c){
				if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<  endl;
							if((*c)->get_emplacement()[1] < (*s)->get_horaires((*c)->get_emplacement()[0],0) || (*c)->get_emplacement()[1] > ((*s)->get_horaires((*c)->get_emplacement()[0],1))){
					if(Affiche_debug((*arg).debug)) cout << "\t\t" << (*s)->get_identifiant() << " n'est pas disponible a cette heure la !!!" << endl;
					*cpt = *cpt + 1;}}}
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte respect_horaire_ressources \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

//Verifié
void* effectif_salles(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte effectif_salles \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	int effectif;
	
	//Pour chaque salle concernés
		for(list<Salle*>::iterator s = (*arg).univ->get_salles()->begin(); s != (*arg).univ->get_salles()->end(); ++s){
			if(Affiche_debug((*arg).debug)) cout << " \nVerification effectif_salles de la salle " << (*s)->get_identifiant() << "\n" << endl;	
			for(list<Cours*>::iterator c = (*s)->get_cours()->begin(); c != (*s)->get_cours()->end(); ++c){
				if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<  endl;
				effectif = 0;
				for(list<Groupe*>::iterator g = (*c)->get_groupes()->begin(); g != (*c)->get_groupes()->end(); ++g){
					effectif+= (*g)->get_effectif();}
				if(Affiche_debug((*arg).debug)) cout << "Le total est de " << effectif << " élèves pour une salle de " << (*s)->get_effectif() <<  endl;
				if(effectif > (*s)->get_effectif()){
					if(Affiche_debug((*arg).debug)) cout << "\t\tConflit effectif de salle !!!" <<  endl;
					*cpt = *cpt + 1;}}}
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie de la contrainte effectif_salles \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

//Verifié
void* equipement_salles(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte equipement_salles \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	int flag;
	
	//Pour chaque salle concernés
		for(list<Salle*>::iterator s = (*arg).univ->get_salles()->begin(); s != (*arg).univ->get_salles()->end(); ++s){
			if(Affiche_debug((*arg).debug)) cout << " \nVerification equipement_salles de la salle " << (*s)->get_identifiant() << "\n" << endl;	
			for(list<Cours*>::iterator c = (*s)->get_cours()->begin(); c != (*s)->get_cours()->end(); ++c){
				if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<  endl;
				flag = 1;
				for(list<Matiere*>::iterator m = (*s)->get_materiels()->begin(); m != (*s)->get_materiels()->end(); ++m){
					if((*c)->get_matiere() == (*m))	flag = 0;}
				if(flag){
					if(Affiche_debug((*arg).debug)) cout << "\t\tConflit equipement de salle !!!" <<  endl;
					*cpt = *cpt + 1;}}}
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte equipement_salles \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

//Verifié
void* respect_pause_dejeuner(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte respect_pause_dejeuner \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	//Pour chaque pause dejeuner de chaque jours
	for(int i = 0; i < (*arg).edt->get_nbJours(); i++){
		if(Affiche_debug((*arg).debug)) cout << "Verificaiton de la pause déjeuner du " << i+1 << "eme jour" << endl;
		if((*arg).edt->get_cours()[i][(*arg).univ->get_pauseDejeuner()].size() != 0){
			if(Affiche_debug((*arg).debug)) cout << "\t\tIl y a " << (*arg).edt->get_cours()[i][(*arg).univ->get_pauseDejeuner()].size() << " cours !!!" << endl;
			*cpt = *cpt + (*arg).edt->get_cours()[i][(*arg).univ->get_pauseDejeuner()].size();}}
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte respect_pause_dejeuner \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

//Verifié
void* respect_enseignant_qualifie(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte respect_enseignant_qualifie \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	int flag = 1;
	
	//Pour chaque enseignant concerné
	for(list<Matiere*>::iterator m = (*arg).edt->get_filiere()->get_matieres()->begin(); m != (*arg).edt->get_filiere()->get_matieres()->end(); ++m){
		for(list<Enseignant*>::iterator e = (*m)->get_enseignants()->begin(); e != (*m)->get_enseignants()->end(); ++e){
			if(Affiche_debug((*arg).debug)) cout << " \nVerification respect_enseignant_qualifie de l'enseignant de " << (*m)->get_nom() << " " << (*e)->get_identifiant() << "\n" << endl;
			for(list<Cours*>::iterator c = (*e)->get_cours()->begin(); c != (*e)->get_cours()->end(); ++c){
				if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<  endl;
				flag = 1;
				for(list<Matiere*>::iterator m = (*e)->get_specialites()->begin(); m != (*e)->get_specialites()->end(); ++m){
					if((*c)->get_matiere() == (*m))	flag = 0;}
				if(flag){
					if(Affiche_debug((*arg).debug)) cout << "\t\tL'enseignant n'est pas qualifié!!!" <<  endl;
					*cpt = *cpt + 1;}}}}
	
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte respect_enseignant_qualifie \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

//Verifié
void* respect_type_salle(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte respect_type_salle \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	//Pour chaque salle concernés
		for(list<Salle*>::iterator s = (*arg).univ->get_salles()->begin(); s != (*arg).univ->get_salles()->end(); ++s){
			if(Affiche_debug((*arg).debug)) cout << " \nVerification respect_type_salle de la salle " << (*s)->get_identifiant() << "\n" << endl;	
			for(list<Cours*>::iterator c = (*s)->get_cours()->begin(); c != (*s)->get_cours()->end(); ++c){
				if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<  endl;
				if((*c)->get_type() != (*s)->get_type()){
					if(Affiche_debug((*arg).debug)) cout << "\t\tConflit type de salle !!!" <<  endl;
					*cpt = *cpt + 1;}}}
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte respect_type_salle \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

//Verifié
void* cours_plusieurs_jours(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte cours_plusieurs_jours \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	//Pour chaque cours concerné
	for(list<Matiere*>::iterator m = (*arg).edt->get_filiere()->get_matieres()->begin(); m != (*arg).edt->get_filiere()->get_matieres()->end(); ++m){
		for(list<Cours*>::iterator c = (*m)->get_cours()->begin(); c != (*m)->get_cours()->end(); ++c){
			if(Affiche_debug((*arg).debug)) cout << "Cours de " << (*c)->get_matiere()->get_nom() << " du " << (*c)->get_emplacement()[0]+1 << "eme Jour " <<  (*c)->get_emplacement()[1]+1 << "eme Creneau" <<  endl;
			if(((*c)->get_emplacement()[1] + (*c)->get_duree() - 1) >= (*arg).edt->get_nbCreneau()){
				if(Affiche_debug((*arg).debug)) cout << "\t\t Ne se termine pas avant la fin des cours !!!" << endl;
				*cpt = *cpt + 1;}}}
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte cours_plusieurs_jourss \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

/*------------- Contraintes Soft ------------------*/

void* CM_avant_TD(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte CM_avant_TD \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte CM_avant_TD \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

void* nb_trous(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte nb_trous \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte nb_trous \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

void* repartition_horaire(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte repartition_horaire \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte repartition_horaire \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

void* CM_TD_journee(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte CM_TD_journee \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte CM_TD_journee \n---------------------\n"  << endl;
	pthread_exit(cpt);
}

void* nb_deplacement(void* void_arg)
{
	contrainte_arg* arg = (contrainte_arg*)void_arg;
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n entrer dans la contrainte nb_deplacement \n---------------------\n"  << endl;
	
	int* cpt = new int(0);
	
	if(Affiche_debug((*arg).debug)) cout << "\n---------------------\n sortie la contrainte nb_deplacement \n---------------------\n"  << endl;
	pthread_exit(cpt);
}
