#include "classes/les_h/Data.h"
#include "GenerateurEDT/GenerateurEDT.h"
#include "SGF/SGF.h"
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
	Buffon.nom = "Buffon";
	Batiment Descartes;
	Descartes.nom = "Descartes";
	Batiment Fermat;
	Fermat.nom = "Fermat";
	
	Universite *u = new Universite(480,1100,10,4,"UFR des sciences de Versailles");
	
	/* ---------------- Creation des filieres ---------------- */
	
	u->add_filiere(new Filiere("S6INFO",u,NULL,6));
	u->add_filiere(new Filiere("S6BIO",u,NULL,6));
	u->add_filiere(new Filiere("S6MATH",u,NULL,6));
	u->add_filiere(new Filiere("S6SVT",u,NULL,6));
	u->add_filiere(new Filiere("S5INFO",u,NULL,5));
	u->add_filiere(new Filiere("S5BIO",u,NULL,5));
	u->add_filiere(new Filiere("S5MATH",u,NULL,5));
	u->add_filiere(new Filiere("S5SVT",u,NULL,5));
	u->add_filiere(new Filiere("S4INFO",u,NULL,4));
	u->add_filiere(new Filiere("S4BIO",u,NULL,4));
	u->add_filiere(new Filiere("S4MATH",u,NULL,4));
	u->add_filiere(new Filiere("S4SVT",u,NULL,4));
	u->add_filiere(new Filiere("S3INFO",u,NULL,3));
	u->add_filiere(new Filiere("S3BIO",u,NULL,3));
	u->add_filiere(new Filiere("S3MATH",u,NULL,3));
	u->add_filiere(new Filiere("S3SVT",u,NULL,3));
	u->add_filiere(new Filiere("S2INFO",u,NULL,2));
	u->add_filiere(new Filiere("S2BIO",u,NULL,2));
	u->add_filiere(new Filiere("S2MATH",u,NULL,2));
	u->add_filiere(new Filiere("S2SVT",u,NULL,2));
	u->add_filiere(new Filiere("S1INFO",u,NULL,1));
	u->add_filiere(new Filiere("S1BIO",u,NULL,1));
	u->add_filiere(new Filiere("S1MATH",u,NULL,1));
	u->add_filiere(new Filiere("S1SVT",u,NULL,1));

	/* ---------------- Creation de l'edt de la filiere ---------------- */
	u->get_filieres("S6INFO")->set_edt(new EDT(u->get_filieres("S6INFO"),90,6,8));
	u->get_filieres("S6BIO")->set_edt(new EDT(u->get_filieres("S6BIO"),90,6,8));
	u->get_filieres("S6MATH")->set_edt(new EDT(u->get_filieres("S6MATH"),90,6,8));
	u->get_filieres("S6SVT")->set_edt(new EDT(u->get_filieres("S6SVT"),90,6,8));
	u->get_filieres("S5INFO")->set_edt(new EDT(u->get_filieres("S5INFO"),90,6,8));
	u->get_filieres("S5BIO")->set_edt(new EDT(u->get_filieres("S5BIO"),90,6,8));
	u->get_filieres("S5MATH")->set_edt(new EDT(u->get_filieres("S5MATH"),90,6,8));
	u->get_filieres("S5SVT")->set_edt(new EDT(u->get_filieres("S5SVT"),90,6,8));
	u->get_filieres("S4INFO")->set_edt(new EDT(u->get_filieres("S4INFO"),90,6,8));
	u->get_filieres("S4BIO")->set_edt(new EDT(u->get_filieres("S4BIO"),90,6,8));
	u->get_filieres("S4MATH")->set_edt(new EDT(u->get_filieres("S4MATH"),90,6,8));
	u->get_filieres("S4SVT")->set_edt(new EDT(u->get_filieres("S4SVT"),90,6,8));
	u->get_filieres("S3INFO")->set_edt(new EDT(u->get_filieres("S3INFO"),90,6,8));
	u->get_filieres("S3BIO")->set_edt(new EDT(u->get_filieres("S3BIO"),90,6,8));
	u->get_filieres("S3MATH")->set_edt(new EDT(u->get_filieres("S3MATH"),90,6,8));
	u->get_filieres("S3SVT")->set_edt(new EDT(u->get_filieres("S3SVT"),90,6,8));
	u->get_filieres("S2INFO")->set_edt(new EDT(u->get_filieres("S2INFO"),90,6,8));
	u->get_filieres("S2BIO")->set_edt(new EDT(u->get_filieres("S2BIO"),90,6,8));
	u->get_filieres("S2MATH")->set_edt(new EDT(u->get_filieres("S2MATH"),90,6,8));
	u->get_filieres("S2SVT")->set_edt(new EDT(u->get_filieres("S2SVT"),90,6,8));
	u->get_filieres("S1INFO")->set_edt(new EDT(u->get_filieres("S1INFO"),90,6,8));
	u->get_filieres("S1BIO")->set_edt(new EDT(u->get_filieres("S1BIO"),90,6,8));
	u->get_filieres("S1MATH")->set_edt(new EDT(u->get_filieres("S1MATH"),90,6,8));
	u->get_filieres("S1SVT")->set_edt(new EDT(u->get_filieres("S1SVT"),90,6,8));

	/* ---------------- Creation des matieres de la filiere ---------------- */
	u->get_filieres("S6INFO")->add_matiere(new Matiere({},{u->get_filieres("S6INFO")},{},20,{},"Anglais3"));
	u->get_filieres("S6INFO")->add_matiere(new Matiere({},{u->get_filieres("S6INFO")},{},20,{},"Cryptographie"));
	u->get_filieres("S6INFO")->add_matiere(new Matiere({},{u->get_filieres("S6INFO")},{},20,{},"CHP"));
	u->get_filieres("S6INFO")->add_matiere(new Matiere({},{u->get_filieres("S6INFO")},{},20,{},"Reseau"));
	u->get_filieres("S6INFO")->add_matiere(new Matiere({},{u->get_filieres("S6INFO")},{},20,{},"Projet INFO"));
	u->get_filieres("S5INFO")->add_matiere(new Matiere({},{u->get_filieres("S5INFO")},{},20,{},"Base Donnees"));
	u->get_filieres("S5INFO")->add_matiere(new Matiere({},{u->get_filieres("S5INFO")},{},20,{},"C++"));
	u->get_filieres("S5INFO")->add_matiere(new Matiere({},{u->get_filieres("S5INFO")},{},20,{},"Compilation"));
	u->get_filieres("S5INFO")->add_matiere(new Matiere({},{u->get_filieres("S5INFO")},{},20,{},"Algorithmique2"));
	u->get_filieres("S5INFO")->add_matiere(new Matiere({},{u->get_filieres("S5INFO")},{},20,{},"TOD"));
	u->get_filieres("S4INFO")->add_matiere(new Matiere({},{u->get_filieres("S4INFO")},{},20,{},"Anglais2"));
	u->get_filieres("S4INFO")->add_matiere(new Matiere({},{u->get_filieres("S4INFO")},{},20,{},"Algorithmique1"));
	u->get_filieres("S4INFO")->add_matiere(new Matiere({},{u->get_filieres("S4INFO")},{},20,{},"Langage Objet"));
	u->get_filieres("S4INFO")->add_matiere(new Matiere({},{u->get_filieres("S4INFO")},{},20,{},"Systeme Exploitation"));
	u->get_filieres("S4INFO")->add_matiere(new Matiere({},{u->get_filieres("S4INFO")},{},20,{},"Theorie Langages"));
	u->get_filieres("S4INFO")->add_matiere(new Matiere({},{u->get_filieres("S4INFO")},{},20,{},"Analyse Genome"));
	u->get_filieres("S3INFO")->add_matiere(new Matiere({},{u->get_filieres("S3INFO")},{},20,{},"Langage C"));
	u->get_filieres("S3INFO")->add_matiere(new Matiere({},{u->get_filieres("S3INFO")},{},20,{},"Archi des Ordi"));
	u->get_filieres("S3INFO")->add_matiere(new Matiere({},{u->get_filieres("S3INFO")},{},20,{},"Structure donnees"));
	u->get_filieres("S3INFO")->add_matiere(new Matiere({},{u->get_filieres("S3INFO")},{},20,{},"Mathematique3"));
	u->get_filieres("S3INFO")->add_matiere(new Matiere({},{u->get_filieres("S3INFO")},{},20,{},"Anglais1"));
	u->get_filieres("S2INFO")->add_matiere(new Matiere({},{u->get_filieres("S2INFO")},{},20,{},"Intro Info"));
	u->get_filieres("S2INFO")->add_matiere(new Matiere({},{u->get_filieres("S2INFO")},{},20,{},"Intro Bio"));
	u->get_filieres("S2INFO")->add_matiere(new Matiere({},{u->get_filieres("S2INFO")},{},20,{},"Mathematique2"));
	u->get_filieres("S2INFO")->add_matiere(new Matiere({},{u->get_filieres("S2INFO")},{},20,{},"Application Info"));
	u->get_filieres("S2INFO")->add_matiere(new Matiere({},{u->get_filieres("S2INFO")},{},20,{},"Geologie"));
	u->get_filieres("S1INFO")->add_matiere(new Matiere({},{u->get_filieres("S1INFO")},{},20,{},"Bio"));
	u->get_filieres("S1INFO")->add_matiere(new Matiere({},{u->get_filieres("S1INFO")},{},20,{},"Chimie"));
	u->get_filieres("S1INFO")->add_matiere(new Matiere({},{u->get_filieres("S1INFO")},{},20,{},"Mathematique1"));
	u->get_filieres("S1INFO")->add_matiere(new Matiere({},{u->get_filieres("S1INFO")},{},20,{},"Info"));

	u->get_filieres("S6BIO")->add_matiere(new Matiere({},{u->get_filieres("S6BIO")},{},20,{},"Virus et parasites"));
	u->get_filieres("S6BIO")->add_matiere(new Matiere({},{u->get_filieres("S6BIO")},{},20,{},"Mutation à l'espece"));
	u->get_filieres("S6BIO")->add_matiere(new Matiere({},{u->get_filieres("S6BIO")},{},20,{},"Genomique"));
	u->get_filieres("S6BIO")->add_matiere(new Matiere({},{u->get_filieres("S6BIO")},{},20,{},"Projet BIO"));
	u->get_filieres("S5BIO")->add_matiere(new Matiere({},{u->get_filieres("S5BIO")},{},20,{},"Phylogenie"));
	u->get_filieres("S5BIO")->add_matiere(new Matiere({},{u->get_filieres("S5BIO")},{},20,{},"Analyse Experimentale"));
	u->get_filieres("S5BIO")->add_matiere(new Matiere({},{u->get_filieres("S5BIO")},{},20,{},"Genomes aux protéome"));
	u->get_filieres("S5BIO")->add_matiere(new Matiere({},{u->get_filieres("S5BIO")},{},20,{},"Genetique2"));
	u->get_filieres("S5BIO")->add_matiere(new Matiere({},{u->get_filieres("S5BIO")},{},20,{},"Dynamique Cellulaire"));
	u->get_filieres("S5BIO")->add_matiere(new Matiere({},{u->get_filieres("S5BIO")},{},20,{},"Anglais3"));
	u->get_filieres("S4BIO")->add_matiere(new Matiere({},{u->get_filieres("S4BIO")},{},20,{},"Outils Biologie"));
	u->get_filieres("S4BIO")->add_matiere(new Matiere({},{u->get_filieres("S4BIO")},{},20,{},"Physiologie"));
	u->get_filieres("S4BIO")->add_matiere(new Matiere({},{u->get_filieres("S4BIO")},{},20,{},"Chimie Orga"));
	u->get_filieres("S4BIO")->add_matiere(new Matiere({},{u->get_filieres("S4BIO")},{},20,{},"Analyse Genome"));
	u->get_filieres("S4BIO")->add_matiere(new Matiere({},{u->get_filieres("S4BIO")},{},20,{},"Genetique"));
	u->get_filieres("S3BIO")->add_matiere(new Matiere({},{u->get_filieres("S3BIO")},{},20,{},"Chimie"));
	u->get_filieres("S3BIO")->add_matiere(new Matiere({},{u->get_filieres("S3BIO")},{},20,{},"Bio Physique"));
	u->get_filieres("S3BIO")->add_matiere(new Matiere({},{u->get_filieres("S3BIO")},{},20,{},"Bio du developpement"));
	u->get_filieres("S3BIO")->add_matiere(new Matiere({},{u->get_filieres("S3BIO")},{},20,{},"Communication cellulaire"));
	u->get_filieres("S3BIO")->add_matiere(new Matiere({},{u->get_filieres("S3BIO")},{},20,{},"Biochimie"));
	u->get_filieres("S3BIO")->add_matiere(new Matiere({},{u->get_filieres("S3BIO")},{},20,{},"Anglais2"));
	u->get_filieres("S2BIO")->add_matiere(new Matiere({},{u->get_filieres("S2BIO")},{},20,{},"Biodiversite"));
	u->get_filieres("S2BIO")->add_matiere(new Matiere({},{u->get_filieres("S2BIO")},{},20,{},"Geologie"));
	u->get_filieres("S2BIO")->add_matiere(new Matiere({},{u->get_filieres("S2BIO")},{},20,{},"Intro Chimie"));
	u->get_filieres("S2BIO")->add_matiere(new Matiere({},{u->get_filieres("S2BIO")},{},20,{},"Intro Bio"));
	u->get_filieres("S1BIO")->add_matiere(new Matiere({},{u->get_filieres("S1BIO")},{},20,{},"Anglais1"));
	u->get_filieres("S1BIO")->add_matiere(new Matiere({},{u->get_filieres("S1BIO")},{},20,{},"Methodo Bio"));
	u->get_filieres("S1BIO")->add_matiere(new Matiere({},{u->get_filieres("S1BIO")},{},20,{},"Mathematique1"));
	u->get_filieres("S1BIO")->add_matiere(new Matiere({},{u->get_filieres("S1BIO")},{},20,{},"Intro Info"));
	u->get_filieres("S1BIO")->add_matiere(new Matiere({},{u->get_filieres("S1BIO")},{},20,{},"Du gène à la protéine"));
	u->get_filieres("S1BIO")->add_matiere(new Matiere({},{u->get_filieres("S1BIO")},{},20,{},"Atomes et molecules"));

	u->get_filieres("S6MATH")->add_matiere(new Matiere({},{u->get_filieres("S6MATH")},{},20,{},"Projet Maths"));	
	u->get_filieres("S6MATH")->add_matiere(new Matiere({},{u->get_filieres("S6MATH")},{},20,{},"Probabilités avancées"));
	u->get_filieres("S6MATH")->add_matiere(new Matiere({},{u->get_filieres("S6MATH")},{},20,{},"Optimisation et applications"));
	u->get_filieres("S6MATH")->add_matiere(new Matiere({},{u->get_filieres("S6MATH")},{},20,{},"Analyse numérique"));
	u->get_filieres("S6MATH")->add_matiere(new Matiere({},{u->get_filieres("S6MATH")},{},20,{},"Groupes et Géométries"));
	u->get_filieres("S5MATH")->add_matiere(new Matiere({},{u->get_filieres("S5MATH")},{},20,{},"Anglais3"));
	u->get_filieres("S5MATH")->add_matiere(new Matiere({},{u->get_filieres("S5MATH")},{},20,{},"Phylogenie"));
	u->get_filieres("S5MATH")->add_matiere(new Matiere({},{u->get_filieres("S5MATH")},{},20,{},"Calcul intégrale"));
	u->get_filieres("S5MATH")->add_matiere(new Matiere({},{u->get_filieres("S5MATH")},{},20,{},"Topologie, calculs differentiels"));
	u->get_filieres("S5MATH")->add_matiere(new Matiere({},{u->get_filieres("S5MATH")},{},20,{},"Genetique2"));
	u->get_filieres("S5MATH")->add_matiere(new Matiere({},{u->get_filieres("S5MATH")},{},20,{},"Algèbre2"));
	u->get_filieres("S4MATH")->add_matiere(new Matiere({},{u->get_filieres("S4MATH")},{},20,{},"Proba statistiques"));
	u->get_filieres("S4MATH")->add_matiere(new Matiere({},{u->get_filieres("S4MATH")},{},20,{},"Analyse Complexe"));
	u->get_filieres("S4MATH")->add_matiere(new Matiere({},{u->get_filieres("S4MATH")},{},20,{},"Algèbre1"));
	u->get_filieres("S4MATH")->add_matiere(new Matiere({},{u->get_filieres("S4MATH")},{},20,{},"Suites et fonctions"));
	u->get_filieres("S4MATH")->add_matiere(new Matiere({},{u->get_filieres("S4MATH")},{},20,{},"Anglais2"));
	u->get_filieres("S3MATH")->add_matiere(new Matiere({},{u->get_filieres("S3MATH")},{},20,{},"Electro Magnetisme"));
	u->get_filieres("S3MATH")->add_matiere(new Matiere({},{u->get_filieres("S3MATH")},{},20,{},"Base de donnees"));
	u->get_filieres("S3MATH")->add_matiere(new Matiere({},{u->get_filieres("S3MATH")},{},20,{},"Mathematiques par ordi"));
	u->get_filieres("S3MATH")->add_matiere(new Matiere({},{u->get_filieres("S3MATH")},{},20,{},"Mathematiques3"));
	u->get_filieres("S2MATH")->add_matiere(new Matiere({},{u->get_filieres("S2MATH")},{},20,{},"Transformation Chimique"));
	u->get_filieres("S2MATH")->add_matiere(new Matiere({},{u->get_filieres("S2MATH")},{},20,{},"Thermodynamique"));
	u->get_filieres("S2MATH")->add_matiere(new Matiere({},{u->get_filieres("S2MATH")},{},20,{},"Mecanique"));
	u->get_filieres("S2MATH")->add_matiere(new Matiere({},{u->get_filieres("S2MATH")},{},20,{},"Mathematique2"));
	u->get_filieres("S2MATH")->add_matiere(new Matiere({},{u->get_filieres("S2MATH")},{},20,{},"Anglais1"));
	u->get_filieres("S1MATH")->add_matiere(new Matiere({},{u->get_filieres("S1MATH")},{},20,{},"Atomes et molecules"));
	u->get_filieres("S1MATH")->add_matiere(new Matiere({},{u->get_filieres("S1MATH")},{},20,{},"Methodo Maths"));
	u->get_filieres("S1MATH")->add_matiere(new Matiere({},{u->get_filieres("S1MATH")},{},20,{},"Intro Info"));
	u->get_filieres("S1MATH")->add_matiere(new Matiere({},{u->get_filieres("S1MATH")},{},20,{},"Physique"));
	u->get_filieres("S1MATH")->add_matiere(new Matiere({},{u->get_filieres("S1MATH")},{},20,{},"Mathematiques1"));

	u->get_filieres("S6SVT")->add_matiere(new Matiere({},{u->get_filieres("S6SVT")},{},20,{},"Géologie en France"));		
	u->get_filieres("S6SVT")->add_matiere(new Matiere({},{u->get_filieres("S6SVT")},{},20,{},"Biotechnologies Vegetales"));
	u->get_filieres("S6SVT")->add_matiere(new Matiere({},{u->get_filieres("S6SVT")},{},20,{},"Virus et parasites"));
	u->get_filieres("S6SVT")->add_matiere(new Matiere({},{u->get_filieres("S6SVT")},{},20,{},"Genetique des populations"));
	u->get_filieres("S6SVT")->add_matiere(new Matiere({},{u->get_filieres("S6SVT")},{},20,{},"Ecologie"));
	u->get_filieres("S5SVT")->add_matiere(new Matiere({},{u->get_filieres("S5SVT")},{},20,{},"Projet Maths"));	
	u->get_filieres("S5SVT")->add_matiere(new Matiere({},{u->get_filieres("S5SVT")},{},20,{},"Anglais3"));
	u->get_filieres("S5SVT")->add_matiere(new Matiere({},{u->get_filieres("S5SVT")},{},20,{},"Dynamiques enveloppes terrestres"));
	u->get_filieres("S5SVT")->add_matiere(new Matiere({},{u->get_filieres("S5SVT")},{},20,{},"Immunologie"));
	u->get_filieres("S5SVT")->add_matiere(new Matiere({},{u->get_filieres("S5SVT")},{},20,{},"Dynamique cellulaire"));
	u->get_filieres("S5SVT")->add_matiere(new Matiere({},{u->get_filieres("S5SVT")},{},20,{},"Diversite Micro-organismes"));
	u->get_filieres("S5SVT")->add_matiere(new Matiere({},{u->get_filieres("S5SVT")},{},20,{},"Analyses Experimentales"));
	u->get_filieres("S4SVT")->add_matiere(new Matiere({},{u->get_filieres("S4SVT")},{},20,{},"Physiologie"));
	u->get_filieres("S4SVT")->add_matiere(new Matiere({},{u->get_filieres("S4SVT")},{},20,{},"Introduction a l'environnement terrestre"));
	u->get_filieres("S4SVT")->add_matiere(new Matiere({},{u->get_filieres("S4SVT")},{},20,{},"Analyse des Genomes"));
	u->get_filieres("S4SVT")->add_matiere(new Matiere({},{u->get_filieres("S4SVT")},{},20,{},"Physiologie vegetale"));
	u->get_filieres("S4SVT")->add_matiere(new Matiere({},{u->get_filieres("S4SVT")},{},20,{},"Genetique1"));
	u->get_filieres("S3SVT")->add_matiere(new Matiere({},{u->get_filieres("S3SVT")},{},20,{},"Anglais2"));
	u->get_filieres("S3SVT")->add_matiere(new Matiere({},{u->get_filieres("S3SVT")},{},20,{},"Biologie du developpement"));
	u->get_filieres("S3SVT")->add_matiere(new Matiere({},{u->get_filieres("S3SVT")},{},20,{},"Biodiversite Animale"));
	u->get_filieres("S3SVT")->add_matiere(new Matiere({},{u->get_filieres("S3SVT")},{},20,{},"Communication cellulaire"));
	u->get_filieres("S3SVT")->add_matiere(new Matiere({},{u->get_filieres("S3SVT")},{},20,{},"Biochimie"));
	u->get_filieres("S2SVT")->add_matiere(new Matiere({},{u->get_filieres("S2SVT")},{},20,{},"Intro Geologie"));
	u->get_filieres("S2SVT")->add_matiere(new Matiere({},{u->get_filieres("S2SVT")},{},20,{},"Biodiversite"));
	u->get_filieres("S2SVT")->add_matiere(new Matiere({},{u->get_filieres("S2SVT")},{},20,{},"Intro Chimie"));
	u->get_filieres("S2SVT")->add_matiere(new Matiere({},{u->get_filieres("S2SVT")},{},20,{},"Intro Info2"));
	u->get_filieres("S2SVT")->add_matiere(new Matiere({},{u->get_filieres("S2SVT")},{},20,{},"Intro Bio"));
	u->get_filieres("S2SVT")->add_matiere(new Matiere({},{u->get_filieres("S2SVT")},{},20,{},"Anglais1"));
	u->get_filieres("S1SVT")->add_matiere(new Matiere({},{u->get_filieres("S1SVT")},{},20,{},"Atomes et molecules"));
	u->get_filieres("S1SVT")->add_matiere(new Matiere({},{u->get_filieres("S1SVT")},{},20,{},"Genes à la proteine"));
	u->get_filieres("S1SVT")->add_matiere(new Matiere({},{u->get_filieres("S1SVT")},{},20,{},"Intro Info"));
	u->get_filieres("S1SVT")->add_matiere(new Matiere({},{u->get_filieres("S1SVT")},{},20,{},"Methodo Bio"));
	u->get_filieres("S1SVT")->add_matiere(new Matiere({},{u->get_filieres("S1SVT")},{},20,{},"Mathematiques1"));


	/* ---------------- Creation des ressources ---------------- */

	int horaires[6][2] = {{1,7}, {1,7}, {1,7}, {1,7}, {1,7}, {1,7}};

	u->add_enseignant(new Enseignant(u,"Prof Anglais 1",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Anglais3"),u->get_filieres("S4INFO")->get_matieres("Anglais2")}));
	u->add_enseignant(new Enseignant(u,"Prof Anglais 2",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Anglais3"),u->get_filieres("S4INFO")->get_matieres("Anglais2")}));
	u->add_enseignant(new Enseignant(u,"Prof Anglais 3",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Anglais3"),u->get_filieres("S4INFO")->get_matieres("Anglais2")}));
	u->add_enseignant(new Enseignant(u,"Prof Crypto 1",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Cryptographie")}));
	u->add_enseignant(new Enseignant(u,"Prof Crypto 2",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Cryptographie")}));
	u->add_enseignant(new Enseignant(u,"Prof Crypto 3",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Cryptographie")}));
	u->add_enseignant(new Enseignant(u,"Prof Crypto 4",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Cryptographie")}));
	u->add_enseignant(new Enseignant(u,"Prof CHPS 1",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("CHP"),u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation")}));
	u->add_enseignant(new Enseignant(u,"Prof CHPS 2",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("CHP")}));
	u->add_enseignant(new Enseignant(u,"Prof Reseau 1",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Reseau")}));
	u->add_enseignant(new Enseignant(u,"Prof Reseau 2",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Reseau")}));
	u->add_enseignant(new Enseignant(u,"Prof Reseau 3",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Reseau")}));
	u->add_enseignant(new Enseignant(u,"Prof Projet 1",35, horaires,{},{u->get_filieres("S6INFO")->get_matieres("Projet INFO")}));
	u->add_enseignant(new Enseignant(u,"Prof Algo 1",35, horaires,{},{u->get_filieres("S4INFO")->get_matieres("Algorithmique1")}));
	u->add_enseignant(new Enseignant(u,"Prof Theorie Langages 1",35, horaires,{},{u->get_filieres("S4INFO")->get_matieres("Theorie Langages")}));
	u->add_enseignant(new Enseignant(u,"Prof Analyse Genome 1",35, horaires,{},{u->get_filieres("S4INFO")->get_matieres("Analyse Genome")}));
	u->add_enseignant(new Enseignant(u,"Prof Analyse Genome 2",35, horaires,{},{u->get_filieres("S4INFO")->get_matieres("Analyse Genome")}));
	u->add_enseignant(new Enseignant(u,"Prof OS 1",35, horaires,{},{u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation")}));
	u->add_enseignant(new Enseignant(u,"Prof Langage Objet 1",35, horaires,{},{u->get_filieres("S4INFO")->get_matieres("Langage Objet")}));
	u->add_enseignant(new Enseignant(u,"Prof Langage Objet 2",35, horaires,{},{u->get_filieres("S4INFO")->get_matieres("Langage Objet")}));
	u->add_enseignant(new Enseignant(u,"Prof Langage Objet 3",35, horaires,{},{u->get_filieres("S4INFO")->get_matieres("Langage Objet")}));
	

	
	u->add_salle(new Salle(u,"AMPHI D",40,horaires,{},&Descartes,{u->get_filieres("S6INFO")->get_matieres("Anglais3"), u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 150, CM));
	u->add_salle(new Salle(u,"AMPHI H",40,horaires,{},&Fermat,{u->get_filieres("S6INFO")->get_matieres("Anglais3"), u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 150, CM));
	u->add_salle(new Salle(u,"Aquitaine",40,horaires,{},&Descartes,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 40, TD));	
	u->add_salle(new Salle(u,"Alsace",40,horaires,{},&Descartes,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 40, TD));	
	u->add_salle(new Salle(u,"Jungle",40,horaires,{},&Descartes,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 40, TD));	
	u->add_salle(new Salle(u,"G201",40,horaires,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 40, TD));	
	u->add_salle(new Salle(u,"G202",40,horaires,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 48, TD));	
	u->add_salle(new Salle(u,"G203",40,horaires,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 42, TD));	
	u->add_salle(new Salle(u,"G204",40,horaires,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 40, TD));	
	u->add_salle(new Salle(u,"G205",40,horaires,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 44, TD));	
	u->add_salle(new Salle(u,"G206",40,horaires,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 40, TD));	
	u->add_salle(new Salle(u,"G207",40,horaires,{},&Germain,{u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"), u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 43, TD));	
	u->add_salle(new Salle(u,"1001",40,horaires,{},&Fermat,{u->get_filieres("S6INFO")->get_matieres("Anglais3"), u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"),u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 50, TD));
	u->add_salle(new Salle(u,"1002",40,horaires,{},&Fermat,{u->get_filieres("S6INFO")->get_matieres("Anglais3"), u->get_filieres("S6INFO")->get_matieres("Cryptographie"), u->get_filieres("S6INFO")->get_matieres("CHP"), u->get_filieres("S6INFO")->get_matieres("Reseau"), u->get_filieres("S6INFO")->get_matieres("Projet INFO"),u->get_filieres("S4INFO")->get_matieres("Algorithmique1"), u->get_filieres("S4INFO")->get_matieres("Theorie Langages"), u->get_filieres("S4INFO")->get_matieres("Analyse Genome"), u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"), u->get_filieres("S4INFO")->get_matieres("Langage Objet"), u->get_filieres("S4INFO")->get_matieres("Anglais2")}, 50, TD));



	u->add_groupe(new Groupe(u,"TD1",35,horaires,{},{u->get_filieres("S6INFO")},37));
	u->add_groupe(new Groupe(u,"TD2",35,horaires,{},{u->get_filieres("S6INFO")},35));
	u->add_groupe(new Groupe(u,"TD3",35,horaires,{},{u->get_filieres("S6INFO")},33));
	u->add_groupe(new Groupe(u,"TD4",35,horaires,{},{u->get_filieres("S6INFO")},32));
	u->add_groupe(new Groupe(u,"Anglais TD1",35,horaires,{},{u->get_filieres("S6INFO")},40));
	u->add_groupe(new Groupe(u,"Anglais TD2",35,horaires,{},{u->get_filieres("S6INFO")},41));
	u->add_groupe(new Groupe(u,"Anglais TD3",35,horaires,{},{u->get_filieres("S6INFO")},38));



	u->add_groupe(new Groupe(u,"TD1",35,horaires,{},{u->get_filieres("S4INFO")},37));
	u->add_groupe(new Groupe(u,"TD2",35,horaires,{},{u->get_filieres("S4INFO")},35));
	u->add_groupe(new Groupe(u,"TD3",35,horaires,{},{u->get_filieres("S4INFO")},33));
	u->add_groupe(new Groupe(u,"TD4",35,horaires,{},{u->get_filieres("S4INFO")},32));
	u->add_groupe(new Groupe(u,"Anglais TD1",35,horaires,{},{u->get_filieres("S4INFO")},40));
	u->add_groupe(new Groupe(u,"Anglais TD2",35,horaires,{},{u->get_filieres("S4INFO")},41));
	u->add_groupe(new Groupe(u,"Anglais TD3",35,horaires,{},{u->get_filieres("S4INFO")},38));



	/* ---------------- Creation des cours ---------------- */
	u->get_filieres("S6INFO")->get_matieres("Anglais3")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Anglais3"),{u->get_groupes("Anglais TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("Anglais3")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Anglais3"),{u->get_groupes("Anglais TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("Anglais3")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Anglais3"),{u->get_groupes("Anglais TD3")},TD));	
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD4")},TD));
	u->get_filieres("S6INFO")->get_matieres("Cryptographie")->add_cours(new Cours(1,u->get_filieres("S6INFO")->get_matieres("Cryptographie"),{u->get_groupes("TD4"),u->get_groupes("TD3"),u->get_groupes("TD2"),u->get_groupes("TD1")},CM));	
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD4")},TD));
	u->get_filieres("S6INFO")->get_matieres("Reseau")->add_cours(new Cours(1,u->get_filieres("S6INFO")->get_matieres("Reseau"),{u->get_groupes("TD4"), u->get_groupes("TD3"), u->get_groupes("TD2"), u->get_groupes("TD1")},CM));
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD4")},TD));	
	u->get_filieres("S6INFO")->get_matieres("CHP")->add_cours(new Cours(1,u->get_filieres("S6INFO")->get_matieres("CHP"),{u->get_groupes("TD4"), u->get_groupes("TD3"), u->get_groupes("TD2"), u->get_groupes("TD1")},CM));	
	u->get_filieres("S6INFO")->get_matieres("Projet INFO")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Projet INFO"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S6INFO")->get_matieres("Projet INFO")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Projet INFO"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S6INFO")->get_matieres("Projet INFO")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Projet INFO"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S6INFO")->get_matieres("Projet INFO")->add_cours(new Cours(2,u->get_filieres("S6INFO")->get_matieres("Projet INFO"),{u->get_groupes("TD4")},TD));	



	u->get_filieres("S4INFO")->get_matieres("Anglais2")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Anglais2"),{u->get_groupes("Anglais TD1")},TD));
	u->get_filieres("S4INFO")->get_matieres("Anglais2")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Anglais2"),{u->get_groupes("Anglais TD2")},TD));
	u->get_filieres("S4INFO")->get_matieres("Anglais2")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Anglais2"),{u->get_groupes("Anglais TD3")},TD));	
	u->get_filieres("S4INFO")->get_matieres("Algorithmique1")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Algorithmique1"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S4INFO")->get_matieres("Algorithmique1")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Algorithmique1"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S4INFO")->get_matieres("Algorithmique1")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Algorithmique1"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S4INFO")->get_matieres("Algorithmique1")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Algorithmique1"),{u->get_groupes("TD4")},TD));
	u->get_filieres("S4INFO")->get_matieres("Algorithmique1")->add_cours(new Cours(1,u->get_filieres("S4INFO")->get_matieres("Algorithmique1"),{u->get_groupes("TD4"),u->get_groupes("TD3"),u->get_groupes("TD2"),u->get_groupes("TD1")},CM));	
	u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"),{u->get_groupes("TD4")},TD));
	u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation")->add_cours(new Cours(1,u->get_filieres("S4INFO")->get_matieres("Systeme Exploitation"),{u->get_groupes("TD4"), u->get_groupes("TD3"), u->get_groupes("TD2"), u->get_groupes("TD1")},CM));
	u->get_filieres("S4INFO")->get_matieres("Theorie Langages")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Theorie Langages"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S4INFO")->get_matieres("Theorie Langages")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Theorie Langages"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S4INFO")->get_matieres("Theorie Langages")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Theorie Langages"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S4INFO")->get_matieres("Theorie Langages")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Theorie Langages"),{u->get_groupes("TD4")},TD));	
	u->get_filieres("S4INFO")->get_matieres("Theorie Langages")->add_cours(new Cours(1,u->get_filieres("S4INFO")->get_matieres("Theorie Langages"),{u->get_groupes("TD4"), u->get_groupes("TD3"), u->get_groupes("TD2"), u->get_groupes("TD1")},CM));
	u->get_filieres("S4INFO")->get_matieres("Langage Objet")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Langage Objet"),{u->get_groupes("TD1")},TD));
	u->get_filieres("S4INFO")->get_matieres("Langage Objet")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Langage Objet"),{u->get_groupes("TD2")},TD));
	u->get_filieres("S4INFO")->get_matieres("Langage Objet")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Langage Objet"),{u->get_groupes("TD3")},TD));		
	u->get_filieres("S4INFO")->get_matieres("Langage Objet")->add_cours(new Cours(2,u->get_filieres("S4INFO")->get_matieres("Langage Objet"),{u->get_groupes("TD4")},TD));	
	u->get_filieres("S4INFO")->get_matieres("Langage Objet")->add_cours(new Cours(1,u->get_filieres("S4INFO")->get_matieres("Langage Objet"),{u->get_groupes("TD4"), u->get_groupes("TD3"), u->get_groupes("TD2"), u->get_groupes("TD1")},CM));

	// Ici VOus pouvez vous amusez avec la filiere

	u = lecture_universite();

	u->get_filieres("S6INFO")->set_edt(GenereEDT(u,u->get_filieres("S6INFO"), u->get_filieres("S6INFO")->get_edt(), 0));
	
	AfficheEDT(u->get_filieres("S4INFO")->get_edt());
	
	AfficheEDT(u->get_filieres("S6INFO")->get_edt());
	
	ecriture_universite(u);
	delete u;
}
