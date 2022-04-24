/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 25/03/2019*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Population.h"
#include "Ville.h"



void Nouvelle_population(Population* pop, Ville tab[], const int alpha, const int beta, const int gamma, const int taille){
	int i;
	Visite *intermediaire;
	assert(taille > 0);
	assert(NULL != tab);
	
	intermediaire = (Visite*)malloc(beta * sizeof(Visite));
	if(NULL == intermediaire)
		exit(EXIT_FAILURE);
	assert(alpha + beta + gamma == K);
	for(i = 0 ; i < beta; i++)
		intermediaire[i] = pop->tab[i];
	for(i = 0 ; i < beta; i++)
		pop->tab[alpha+i] = intermediaire[i];
	for(i = 0 ; i < gamma ; i++){
		pop->tab[alpha+beta+i] = generer_visite(tab, taille);
		calculeDistance(&(pop->tab[alpha+beta+i]), taille);
	}
}



void Nouvelle_populationM(Population pop, const int alpha, const int taille){
	int i;
	assert(taille > 0);
	for(i = 0 ; i < alpha ; i++)
		mutation(pop.tab[i], taille);
}
