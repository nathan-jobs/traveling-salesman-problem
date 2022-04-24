/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 25/03/2019*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Visite.h"

Visite generer_visite(Ville tab[], const int taille){
	int i, j, n,k,tmp;
	
	Visite visite_alea;
	Ville *copie;
	k = 0;
	tmp =taille;
	assert(NULL != tab);
	assert(taille > 0);
	
	
	visite_alea.tab = (Ville**)malloc(taille * sizeof(Ville*));
	copie = (Ville*)malloc(taille *sizeof(Ville));
	if (NULL == visite_alea.tab || NULL == copie)
		exit(EXIT_FAILURE);
	
	for(i = 0 ; i < taille ; i++)
		copie[i] = tab[i];
	
	while(tmp > 0){
		n = rand() % tmp +1;
		j = 0;
		i = 0;
		while(i < n){
			if(copie[j].x == -10)
				j++;
			else{
				i++;
				j++;
			}
		} 
		visite_alea.tab[k]= &(tab[j-1]); 
		copie[j-1].x = -10;
		tmp -= 1;
		k++;
	}
	return visite_alea;
}



int compare (void const *a, void const *b){
  
	Visite const *pa = a;
	Visite const *pb = b;
	
	return pa->longueur - pb->longueur;
}



void afficherVisite(Visite visit, const int taille){
	int i;
	for(i = 0 ; i < taille ; i++)
		afficherVille(*(visit.tab[i]));
}



void calculeDistance(Visite* visit, const int taille){
	int i;
	assert(taille > 0);
	assert(NULL != visit);
	visit->longueur = 0;
	for(i = 1 ; i < taille ; i++){
		visit->longueur += ((visit->tab[i]->x - visit->tab[i-1]->x) * (visit->tab[i]->x - visit->tab[i-1]->x)) + ((visit->tab[i]->y - visit->tab[i-1]->y) * (visit->tab[i]->y - visit->tab[i-1]->y));
	}
}



Mutation generateur(const int taille){
	Mutation gen;
	assert(taille > 0);
	do{
		
		gen.l = rand() % (taille/2)+1;
		gen.i = rand() % (taille/2)+1;
		gen.j = rand() % (taille)+taille/2;
		
	}while((gen.i + gen.l >= gen.j) || (gen.l + gen.j > taille + 1));
	return gen;
}



void mutation(Visite visit, const int taille){
	Mutation gen;
	Ville* tmp;
	int cmp = 0;
	assert(taille > 0);
	gen = generateur(taille);
	while(cmp < gen.l){
		tmp = visit.tab[gen.i+cmp-1];
		visit.tab[gen.i+cmp-1] = visit.tab[gen.j+cmp-1];
		visit.tab[gen.j+cmp-1] = tmp;
		cmp++;
	}
}
