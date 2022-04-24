/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 25/03/2019*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "Population.h"
#include "Ville.h"

void mutation_int(int *tab, Mutation gen){
	int tmp;
	int cmp;
	for(cmp = 0 ; cmp < gen.l ; cmp++){
		tmp = tab[gen.i+cmp-1];
		tab[gen.i+cmp-1] = tab[gen.j+cmp-1];
		tab[gen.j+cmp-1] = tmp;
	}
}


int test_generateur(void){
	Mutation test;
	test = generateur(5);
	if((test.i + test.l < test.j) && (test.l + test.j <= 6))
		return 1;
	printf("ERREUR DANS LA FONCTION GENERATEUR !\n");
	return 0;
}


int test_mutation(void){
	Mutation test;
	int i;
	int tab[5] = {1, 2, 3, 4, 5};
	int tab2[5] = {4, 5, 3, 1, 2};
	test.l = 2;
	test.i = 1;
	test.j = 4;
	mutation_int(tab2, test);
	for(i = 0 ; i < 5 ; i++){
		if (tab[i] != tab2[i]){
			printf("ERREUR DANS LA FONCTION MUTATION !\n");
			return 0;
		}
	}
	return 1;
}


int test_compare(void){
	Visite a;
	Visite b;
	a.longueur = 25;
	b.longueur = 20;
	if (compare( &a, &b ) == 5)
		return 1;
	printf("ERREUR DANS LA FONCTION COMPARE !\n");
	return 0;
}


int test(void){
	int testGEN;
	int testMUT;
	int testCOMP;
	srand(time(NULL));
	testGEN = test_generateur();
	testMUT = test_mutation();
	testCOMP = test_compare();
	if (testGEN == 1 && testMUT == 1 && testCOMP == 1){
		
		return 1;
	}
	return 0;
}
