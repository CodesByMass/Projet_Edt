Test: GenerateurEDT/GenerateurEDT.o Test.o classes/les_cc/EDT.o classes/les_cc/Universite.o classes/les_cc/Salle.o classes/les_cc/Ressource.o classes/les_cc/Enseignant.o classes/les_cc/Groupe.o classes/les_cc/Matiere.o classes/les_cc/Filiere.o classes/les_cc/Cours.o
	g++ -o Test Test.o GenerateurEDT/GenerateurEDT.o classes/les_cc/EDT.o classes/les_cc/Universite.o classes/les_cc/Salle.o classes/les_cc/Ressource.o classes/les_cc/Enseignant.o classes/les_cc/Groupe.o classes/les_cc/Matiere.o classes/les_cc/Filiere.o classes/les_cc/Cours.o -lm -lpthread -Wall
	
Test.o: Test.cc 
	g++ -o Test.o -c Test.cc -Wall
