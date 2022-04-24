/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 8/05/2019*/

#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Ville.h"



void recupererVille(FILE* fic, Ville  villes[], int *i){
	char str[20];
	int nbr;
	int c;
	assert(NULL != fic);

	c = fscanf(fic, "%s", str);
	if(c != EOF){
		strcpy(villes[0].libelle, str);
		fscanf(fic, "%d", &nbr);
		villes[0].x = nbr;
		fscanf(fic, "%d", &nbr);
		villes[0].y = nbr;
		*i += 1;
		recupererVille(fic, villes+1, i);
	}
}

void recupere_coordonnees(Ville villes[] , int *taille){

	MLV_Font* font;
	char *texte;
	char mot[] = "stop";
	int i,x,y;
	i = 0;
	font = MLV_load_font( "src/Garuda-Oblique.ttf" , 25 );
	

	do{
			
		MLV_wait_input_box_with_font(
					350,500,
					400,50,
					MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
					"le nom de la ville : ",
					&texte,font); 
		
		
		
		
		if(strcmp(mot ,texte) == 0)
			break;
		MLV_wait_mouse(
			&x
			,&y);
		MLV_draw_filled_circle(x,y,2,MLV_COLOR_GREEN);
		MLV_actualise_window();
		
		villes[i].x = (x /46 ) -2 ;
		villes[i].y = 12  - (y /46 );
		
		strcpy(villes[i].libelle, texte);
		
	
		i++;
		*taille += 1;
			
		}while(strcmp(mot , texte) != 0);
	

}



void afficherVille(Ville const city){
	printf("%s %d %d\n", city.libelle, city.x, city.y);
}
