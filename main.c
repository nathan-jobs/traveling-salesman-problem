/* Auteur : MBUMA MONA Nathan
 * création : 01/04/2019
 * modification : 25/03/2019*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <MLV/MLV_all.h>
#include "affichage.h"
#include "test.h"
#define TAILLE 30
#define K 128


void dimension(int *alpha , int *beta , int *gamma){
    MLV_Font* font;
    char *gam;
    font = MLV_load_font( "src/Garuda-Oblique.ttf" , 25 );
    MLV_draw_text_with_font(
		10, 10,
		"\nDonner un alpha, un bêta et un gamma (le tout doit faire 128):\n",font,
		MLV_COLOR_GREEN
	);
    
    do{
        
        MLV_wait_input_box_with_font(
			10,70,
			200,90,
			MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			"alpha : ",
			&gam,font
		);
		*alpha = atoi(gam);
        	
           MLV_wait_input_box_with_font(
			10,70,
			200,90,
			MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			"béta : ",
			&gam,font
		);  
        *beta = atoi(gam); 
         
        MLV_wait_input_box_with_font(
			10,70,
			200,90,
			MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			"gamma : ",
			&gam,font
		); 
         *gamma = atoi(gam); 
       
		}while(*alpha + *beta + *gamma != K);
    
  
    
    
}

int main(int argc, char* argv[]){
	MLV_Font* font;
	FILE* fichier;
	char *texte;
	int alpha, beta, gamma;
	int i, j,svg,retour;
	MLV_Keyboard_button sym;
	MLV_Event event;
	Ville tab[TAILLE];
	Population pop;
	MLV_create_window("PVC", "PVC", TAILLE_X, TAILLE_Y);
	font = MLV_load_font( "src/Garuda-Oblique.ttf" , 25 );
	if(test()){
		
		MLV_draw_filled_rectangle(520/2-100, 700/2-50, 800, 50, MLV_COLOR_WHITE);
		MLV_draw_text_with_font(522/2-85 , 700/2-50 ,"AUCUNE ERREUR DETECTEE VOS FONCTIONS SONT PRETES !", font, MLV_COLOR_BLUE);
		MLV_actualise_window();
		MLV_wait_seconds( 2 );
		svg = 0;
		
		MLV_clear_window(MLV_COLOR_BLACK);
		srand(time(NULL));
		retour = afficher_menu();
		MLV_actualise_window();
		if(retour == 1){
		
			do{
				MLV_wait_input_box_with_font(
					10,70,
					300,50,
					MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
					"nom du fichier : ",
					&texte,font); 
				fichier = fopen(texte,"r"); 
			
			}while(fichier == NULL);	
		
			recupererVille(fichier, tab, &svg);
		
			if(svg < 3){  
				MLV_draw_filled_rectangle(520/2-100, 700/2-50, 800, 50, MLV_COLOR_WHITE);
				MLV_draw_text_with_font(522/2-85 , 700/2-50 ,"Mettez au moins 3 villes dans votre fichier c'est mieux nan", font, MLV_COLOR_BLUE);
				return 0;
			}
		}
		if(retour == 2){
			
			MLV_clear_window(MLV_COLOR_BLACK);
			MLV_draw_filled_rectangle(522/2-100, 700/2-50, 800, 50, MLV_COLOR_WHITE);
			MLV_draw_text_with_font(
			521/2-100 , 700/2-50,
				"Après avoir entré vos villes ecrivez 'stop' pour lancer le programme",font,
				MLV_COLOR_BLUE
				);
			MLV_actualise_window();
			MLV_wait_keyboard_or_mouse(NULL, NULL, NULL, NULL, NULL);
			MLV_clear_window(MLV_COLOR_BLACK);
			recupere_coordonnees(tab , &svg);
			do{
				
				if(svg < 3){  
					MLV_draw_filled_rectangle(520/2-100, 700/2-50, 800, 50, MLV_COLOR_WHITE);
					MLV_draw_text_with_font(522/2-85 , 700/2-50 ,"Mettez au moins 3 villes dans votre fichier c'est mieux !!", font, MLV_COLOR_BLUE);
					MLV_actualise_window();
					MLV_wait_seconds( 3 );
					MLV_clear_window(MLV_COLOR_BLACK);
					recupere_coordonnees(tab , &svg);
				
				}
			}while(svg < 3);
		
		}
		
		
			
	
		for(i = 0 ; i < K ; i++){
			pop.tab[i] = generer_visite(tab, svg);
			calculeDistance(&(pop.tab[i]), svg);
		}	
		qsort(pop.tab, K, sizeof(Visite), compare);	
		
		MLV_clear_window(MLV_COLOR_BLACK);
	
		dimension(&alpha , &beta , &gamma);
        MLV_actualise_window();
        MLV_clear_window(MLV_COLOR_BLACK);
         
        MLV_draw_filled_rectangle(520/2-100, 700/2-50, 700, 50, MLV_COLOR_WHITE);
        MLV_draw_text_with_font(
				521/2-100 , 700/2-50,
				"Appuyez sur la touche 'space' pour arrêter le programme",font,
				MLV_COLOR_BLUE
				);
		MLV_actualise_window();
		MLV_wait_seconds( 3 );
		
		do{
            MLV_clear_window(MLV_COLOR_BLACK);
			event = MLV_get_event( 
			&sym, NULL, NULL, 
			NULL, NULL, NULL, 
			NULL, NULL, NULL);
			
			if(event == MLV_KEY){
				if(sym == MLV_KEYBOARD_SPACE)
					break;
			}
			Nouvelle_population(&pop, tab, alpha, beta, gamma, svg);
			Nouvelle_populationM(pop, alpha, svg);
			for(i = 0 ; i < alpha ; i++)
				calculeDistance(&(pop.tab[i]), svg);
			qsort(pop.tab, K, sizeof(Visite), compare);
			
			dessine_carte();
			dessine_ville(pop.tab[0].tab, svg);
			trace_chemin(pop, svg);
			MLV_actualise_window();
			system("sleep 0");
			
		}while(1);
		
		for(j = K ; j > 0 ; j--){
			if( j == 128)
				continue;
			printf("v%d : %.6f\n", j-1, sqrt(pop.tab[j].longueur));
		}

		MLV_wait_keyboard_or_mouse(NULL, NULL, NULL, NULL, NULL);
		fclose(fichier);
		MLV_free_font(font);
		MLV_free_window();		
		return 0;
		
		
		
	}
	else{
		MLV_draw_filled_rectangle(800/2-100, 700/2-50, 500, 50, MLV_COLOR_WHITE);
		MLV_draw_text_with_font(800/2-85 , 700/2-50 ,"VEUILLEZ REVOIR VOS FONCTIONS", font, MLV_COLOR_BLUE);
		MLV_actualise_window();
		MLV_wait_seconds( 7 );
		MLV_free_font( font );
		MLV_free_window();
		return 0;
	}
    
    MLV_free_font( font );
	MLV_free_window();
	return 0;
}
