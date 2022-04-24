/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 08/05/2019*/


#ifndef __VILLE__
#define __VILLE__

	typedef struct ville{
		int x;
		int y;
		char libelle[30];
	}Ville; /* ce type gère une ville (ses coordonnées et son nom) */

	
	/* fonction : recupereVille
	* parametres : un fichier , un tableau de ville , un pointeur sur un entier
	* retour :rien
	* description : fonction qui lit les éléments du fichier fic
	* le place dans le tableau ville et un incremente le compteur 
	* qui compte le nombre des éléments lus dans le fichier */
	void recupererVille(FILE* fic, Ville tab[], int *i);
	
	/* fonction : recupere_coordonnees
	* parametres : un tableau de ville et  un pointeur sur un entier
	* retour :rien
	* description : cette fonction récupère les données que l'utilisateur
	* entre (le nom et les coordonnées de ville) remplie le tableau de ville
	* et incremente la taille . */
	
	void recupere_coordonnees(Ville villes[] , int *taille);
	
	/* fonction   : afficherVille
	 * parametre  : tableau de ville
	 * retour     : void
	 * description : cette fonction affiche les villes */
	
	void afficherVille(Ville const city);

#endif
