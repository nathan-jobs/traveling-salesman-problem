
/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 09/05/2019*/


#ifndef __affichage__
#define __affichage__
	
	#include <MLV/MLV_all.h>
	#include "Population.h"
	#define TAILLE_X 1014
	#define TAILLE_Y 690

	/*
	*fonction : dessine_carte
	*parametre : rien
	*retour :rien
	*description : dessine un repere orthonormé. */
	void dessine_carte(void);

	/*fonction : dessine_ville
	*parametre : un pointeur sur un tableau de ville et une taille
	*retour :rien
	*description : place le nom de ville sur la carte . */
	void dessine_ville(Ville* const tab[], int const taille);
	
	/*fonction : trace_chemin
	*parametre : une population et une taille
	*retour :rien
	*description : cette fonction trace les lignes qui relient
	* les deux ville . */
	void trace_chemin(Population const pop , int const taille);
	
	/* 
	* fonction : afficher_menu
	* parametre : rien
	* retour : un entier
	* description : cette fonction affiche un menu en utilisant
	* la bibliothèque MLV */
	int afficher_menu(void);
	
	/* 
	* fonction : fabriqueCouleur
	* parametre : rien
	* retour : une couleur
	* description : cette fonction crée une couleur avec
	* un constraste très faible pour éviter de cacher l'image sur l'arrière plan*/
	
	MLV_Color fabriqueCouleur(void);

#endif
