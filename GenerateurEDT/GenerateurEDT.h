#ifndef GenerateurEDT_h
#define GenerateurEDT_h

#include "../classes/les_h/Data.h"
#include <pthread.h>
#include <algorithm>
#include <list> 
#include <iterator> 
#include <cmath> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

EDT* GenereEDT(Universite* univ, Filiere* fil, EDT* edt, int debug = 0);

bool VerifieEDT(Universite* univ, EDT* edt, int debug = 0);

EDT* InitialiseEDT(Filiere* fil, EDT* edt, int debug = 0);

EDT* GenereVoisin(Filiere* fil, EDT* edt, int debug = 0);

int EvalueEDT(Universite* univ, EDT* edt, int debug = 0);

float DiminueTemperature(float temp, float reduc, int debug = 0);

Cours* AffecteCours(Filiere* fil, Cours* cours, int debug = 0);

EDT* PlaceCours(EDT* edt, Cours* cours, int debug = 0);

EDT* DeplaceCours(EDT* edt, int debug = 0);

EDT* ChangeAffectation(EDT* edt, Filiere* fil, int debug = 0);

int EvalueSoft(Universite* univ, EDT* edt, int debug = 0);

int EvalueHard(Universite*, EDT*, int debug = 0);

Cours* SelectionneAleatoirement(EDT* edt, int debug = 0);

float Random_a_b(int a, int b, int debug = 0);

bool Accepte(int Eactuelle, int Evoisin, int temp, int debug = 0);

bool Affiche_debug(int debug = 0);

/*------------- struct contraintes ------------------*/

struct contrainte_arg{
	Universite* univ;
	EDT* edt;
	int debug = 0;
};

/*------------- Contraintes Hard ------------------*/

void* ressource_par_creneau(void *void_arg);

void* volume_horaire_ressources(void *void_arg);

void* respect_horaire_ressources(void *void_arg);

void* effectif_salles(void *void_arg);

void* equipement_salles(void *void_arg);

void* respect_pause_dejeuner(void *void_arg);

void* respect_enseignant_qualifie(void *void_arg);

void* respect_type_salle(void *void_arg);

void* cours_plusieurs_jours(void *void_arg);

/*------------- Contraintes Soft ------------------*/

void* CM_avant_TD(void *void_arg);

void* nb_trous(void *void_arg);

void* repartition_horaire(void *void_arg);

void* CM_TD_journee(void *void_arg);

void* nb_deplacement(void *void_arg);

#endif
