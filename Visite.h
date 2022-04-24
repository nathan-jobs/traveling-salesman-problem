/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 25/03/2019*/

#ifndef __Visite__
#define __Visite__

	#include "Ville.h"

	typedef struct visite{
		Ville **tab;
		int longueur;
	}Visite;
	/* une visite est un pointeur sur un tableau de ville
	 * et la longueur de la visite */

	typedef struct mut{
		int j, i, l;
	}Mutation;
	/* une mutation gère trois entiers i ,j, l qui sont
	 * indispensable pour realiser une mutation */
	
	
	/* fonction : afficherVisite
	* parametres : une visite et une taille
	* retour : rien
	* description : Affiche une visite sur la sortie standard */ 
	void afficherVisite(Visite visit, const int taille);
	
	/* fonction : generer_visite
	* parametres : un tableau de ville et une taille
	* retour : une visite
	* description :renvoie une visite aléatoire générée 
	* en fonction du tableau de ville tab */
	Visite generer_visite(Ville tab[],const  int taille);
	
	/* fonction : compare
	* parametres : deux pointeurs d'entier
	* retour : un entier
	* description :une fonction génèrique de comparaison 
	* de deux entiers */
	int compare (void const *a, void const *b);
	
	/* fonction : calculDistance
	* parametres : un pointeur sur une visite et une taille
	* retour : rien
	* description :Fonction qui calcule le longueur totale de parcours
	* pour la visite visit. */
	void calculeDistance(Visite* visit, const int taille);
	
	/* fonction : generateur
	* parametres : une taille
	* retour : une mutation
	* description :génère trois entiers nécessaires pour 
	* la mutation et réalise les tests nécessaires pour eviter une collision. */
	Mutation generateur(const int taille);
	
	/* fonction : mutation
	* parametres : une visite et une taille
	* retour : rien
	* description : réalise la mutation sur la 
	* permutation de villes visit. */
	void mutation(Visite visit, const int taille);

#endif
