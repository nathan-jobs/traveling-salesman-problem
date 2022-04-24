/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 09/05/2019*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "affichage.h"
#include "Ville.h"

MLV_Color fabriqueCouleur(void) {
	return MLV_rgba(255, 255, 255, 60);
}

int afficher_menu(void){
	MLV_Event event;
	int i = 1;
	int x, y ;
	MLV_Image *image;
	MLV_Font* font = MLV_load_font( "src/Garuda-Oblique.ttf" , 28 );
	image = MLV_load_image("src/voyage.jpg");
	
	MLV_resize_image_with_proportions(image, TAILLE_X, TAILLE_Y);

	MLV_draw_image(image, 0, 0);
	MLV_actualise_window();
	
	MLV_draw_filled_rectangle(350, 200, 450, 50,fabriqueCouleur() );
	MLV_draw_text_with_font(400, 198,"CHARGER UN FICHIER", font, MLV_COLOR_BLUE);
	MLV_draw_filled_rectangle(350,260, 450, 50,  fabriqueCouleur() );
	MLV_draw_text_with_font(400, 258,"SAISIR VOS VILLES", font, MLV_COLOR_BLUE);
	MLV_draw_filled_rectangle(360, 320, 450, 50, fabriqueCouleur());
	MLV_draw_text_with_font(450, 318,"QUITTER", font, MLV_COLOR_BLUE);
	
	
	MLV_actualise_window();
	do{
		event = MLV_get_event(
			NULL,NULL,NULL,
			NULL, NULL,
			&x,&y,NULL,
			NULL
		);
		if(event == MLV_MOUSE_BUTTON ){
			if((x>350 && y> 200) && (x<800 && y> 200) &&  (x> 350 && y< 250) && (x<800 && y< 250))
				return 1;
			else if((x>350 && y> 260) && (x<800 && y>260) &&  (x> 350 && y< 320) && (x<800 && y< 320))
				return 2;
			else if((x>350 && x < 800) && (y < 380 &&  y> 320))
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_filled_rectangle(1014/2-100, 680/2-50, 250, 50, MLV_COLOR_WHITE);
				MLV_draw_text_with_font(1014/2-85 , 680/2-50 ,"Au revoir  !!!", font, MLV_COLOR_BLUE);
				MLV_actualise_window();
				MLV_wait_seconds(5);
				MLV_free_window();
				exit(EXIT_FAILURE);
			}
		}
	}while(i);
	MLV_free_font( font );
	return 0;
}

void dessine_carte(void){
	int i ,j, a = 0, b=0;
	int n = -2;
	
	for(i = 0 ; i< 15 ;i++){
		a = 0;
		for(j = 0 ; j<22 ; j++){
			MLV_draw_filled_rectangle(1 + a, b, 45, 45, MLV_COLOR_WHITE);
			a = a + 46;
			
			}
		b = b + 46;
	}
	a = 643;
	for ( i = 0 ; i<14 ; i++){
		/*  y */
		if(i == 2){
			n = n + 1;
			a = a - 47;
			continue;
		
		}
		MLV_draw_text(81, a, "%d", MLV_COLOR_BLACK,n);
		
		n = n + 1;
		a = a - 47;
	}
	a = 39;
	n = -1;
	for ( i = 0 ; i<20 ; i++){
		/*x*/
		
		MLV_draw_text(a, 550, "%d ", MLV_COLOR_BLACK,n);
		n = n + 1;
		a = a + 47;
	}
	
	MLV_draw_line(93, 0 ,93 , 690 ,  MLV_COLOR_GREEN);
	MLV_draw_line(0, 552 ,1014 , 552, MLV_COLOR_GREEN);
}



void dessine_ville(Ville* const tab[], int const taille){
	MLV_Image *image;
    int i;
     
    image = MLV_load_image("src/1048.png");
    MLV_resize_image_with_proportions(image, 38, 38);
   
	for(i = 0 ; i < taille ; i++){
		
		
		if(i == 0){
			
           
			
			MLV_draw_filled_circle(tab[i]->x * 46 + 93,552 - (tab[i]->y *46),4,MLV_COLOR_BLACK);
			MLV_draw_text(tab[i]->x * 46 + 80,565 - (tab[i]->y *46) , "%s ", MLV_COLOR_BLACK,tab[i]->libelle);
			continue;
		}
		if(i == taille-1){
            MLV_draw_image(image, tab[i]->x * 46 + 85,552 - (tab[i]->y *46));
			MLV_draw_filled_circle(tab[i]->x * 46 + 93, 552 - (tab[i]->y *46),3, MLV_COLOR_RED);
			MLV_draw_text(tab[i]->x * 46 + 80,565 - (tab[i]->y *46) , "%s ", MLV_COLOR_BLACK,tab[i]->libelle);
			continue;
		}
		MLV_draw_filled_circle(tab[i]->x * 46 + 93, 552 - (tab[i]->y *46),3, MLV_COLOR_GREEN);
		MLV_draw_text(tab[i]->x * 46 + 80,565 - (tab[i]->y *46) , "%s ", MLV_COLOR_BLACK,tab[i]->libelle);
	
	}
}


void trace_chemin(Population const pop , int const taille){
	int i,x1,y1,x2,y2;
	for( i = 0 ; i < taille-1 ; i++){
		x1 = pop.tab[0].tab[i]->x * 46 + 93;
		x2 = pop.tab[0].tab[i+1]->x * 46 + 93;
		y1 = 552 - (pop.tab[0].tab[i]->y * 46);
		y2 = 552 - (pop.tab[0].tab[i+1]->y * 46);
		MLV_draw_line(x1, y1, x2, y2, MLV_COLOR_RED);
	}
	MLV_draw_adapted_text_box(905, 650, "%.6f km", 9, MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK, MLV_TEXT_CENTER, sqrt(pop.tab[0].longueur));
}
