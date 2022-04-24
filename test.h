/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 25/03/2019*/


#ifndef __test__
#define __test__
	
	#include "Visite.h"
	
	/* fonction : test_generateur
	* parametre : rien
	* retour :un entier
	* description :cette fonction test si la fonction generateur arrive à
	* generer le bon nombre. Elle renvoie 1 si tout c'est bien passé 0 sinon */
	int test_generateur(void);
	
	/* fonction : test_compare
	* parametre : rien
	* retour :un entier
	* description :cette fonction test si la fonction compare arrive à
	* comparer deux entiers. Elle renvoie 1 si tout c'est bien passé 0 sinon */
	int test_compare(void);
	
	/* fonction : mutation_int
	* parametre : un pointeur d'entier et une mutation
	* retour :rien 
	* description :cette fonction réalise une mutation 
	* avec des valeurs du tableau*/
	void mutation_int(int *tab, Mutation gen);

	/* fonction : test_mutation
	* parametre : rien
	* retour :un entier 
	* description :cette fonction test si les mutations 
	* sont réalisées avec succès. Elle renvoie 1 si tout c'est bien 
	* passé 0 sinon */
	int test_mutation(void);
	
	/* fonction : test
	* parametre : rien
	* retour :un entier 
	* description :cette fonction test si toutes les fonctions
	* du projet fonctionne correctement . Elle renvoie 1 si tout c'est bien 
	* passé 0 sinon */
	int test(void);
	
#endif
