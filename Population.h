/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 25/03/2019*/


#ifndef __Population__
#define __Population__

	#include "Visite.h"
	#define K 128


	typedef struct population{
		Visite tab[K];
	}Population;
	/* une Population est un tableau de visite  en gros c'est
	 * une historique de visite */
	 
	/* fonction : Nouvelle_population
	* parametres : un pointeur sur une population ,un tableau de ville
	* quatre entiers 
	* retour :rien
	* description :crée notre nouvelle population en 
	* réalisant un ensemble de copies et un ensemble 
	* de génération aléatoire par rapport aux entiers 
	* alpha, béta et gamma. */

	void Nouvelle_population(Population* pop, Ville tab[], const int alpha, const int beta, const int gamma, const int taille);
	
	
	/* fonction : Nouvelle_populationM
	* parametres :  une population et deux entiers
	* retour :rien
	* description :Elle poursuit la création de notre nouvelle population en 
	* réalisant un ensemble de mutation par rapport à l'entier alpha.. */
	void Nouvelle_populationM(Population pop, const int alpha, const int taille);
	
#endif
