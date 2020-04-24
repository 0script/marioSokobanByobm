#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constante.h"
#include "game1.h"

/*
 main.c
 ......

 Par obmco inspirer de mateo (sitedu0)

 Fonction principale du jeu
 */

 /*

	3-sauveguarder partie???
	4-gestion du temps apres un certains temps la partie est finie???
	5-gestion du passage des niveau dans la boucle risque d etre asser compliquer
		----solution une var contiendrat la valeur de l ancien niveau entouka debroulle toi!!!!
	6-Reverifier la gestion des colisions	

 */

int main(int argc, char *argv[])
{

	//definitions des var
	
	SDL_Surface *surfaceMenu=NULL, *ecran=NULL;			//Surface pour le menu et l'ecran
	SDL_Texture *texture=NULL; 		//texture du menu et de l'ecran
	SDL_Rect positionMenu={0,0,LONGUEUR,LONGUEUR};
	SDL_Event event;
	SDL_Renderer *render=NULL;
	SDL_Window *window=NULL;
	SDL_bool quit=SDL_FALSE;
	int  function, statut=EXIT_FAILURE;		//fonction permet de boucler sur les bonnes instruction (menu princi edition game ect)

	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		fprintf(stderr,"Error SDL_Init: %s\n",SDL_GetError());
		goto Quit;
	}

	if(SDL_CreateWindowAndRenderer(LONGUEUR,LONGUEUR,SDL_WINDOW_SHOWN,&window,&render)!=0)
	{
		fprintf(stderr,"Error SDL_CreateWindowAndRenderer: %s\n",SDL_GetError());
		goto Quit;	
	}

	surfaceMenu=SDL_LoadBMP("img/menu.bmp");
	if(surfaceMenu==NULL)
	{
		fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
		goto Quit;
	}

	ecran=SDL_CreateRGBSurface(0,LONGUEUR,LONGUEUR,32,0,0,0,0);
	if(ecran==NULL)
	{
		fprintf(stderr,"Error SDL_CreateRGBSurface: %s\n",SDL_GetError());
		goto Quit;
	}

	level=NIVEAU1;
	editer(level,carte);

	SDL_BlitSurface(surfaceMenu,NULL,ecran,&positionMenu);
	texture=SDL_CreateTextureFromSurface(render,ecran);
	function=MENU;

	while(!quit)
	{

		while(SDL_PollEvent(&event))
		{

			switch(event.type)
			{
				case SDL_QUIT :
					quit=SDL_TRUE;
				break;

				case SDL_KEYDOWN : //arrete le jeu
					if(function==MENU)
					{
						switch(event.key.keysym.sym)
						{
							case SDLK_SPACE :
								quit=SDL_TRUE;
							break;
						
							case SDLK_KP_1 : //commencer le jeu
								function=GAME;
								if(game1(ecran,event)==2)	//retourne 2 le jeu est fini
								{
									if(level!=NIVEAU3)
										level++;
									else
									{
										printf("felicitation vous avez terminer la partie\n");
										quit=SDL_TRUE;
									}
								}
							break;


						}
					}
					else if(game1(ecran,event)==2)
					{
						if(level<NIVEAU3)
						{	
							level++;
							editer(level,carte);
						}	
						else
						{
							printf("felicitation vous avez terminer la partie\n");
							quit=SDL_TRUE;
						}
					}
				break;

				

			}

			texture=SDL_CreateTextureFromSurface(render,ecran);		//on update la texture avant l'affichage
            SDL_RenderCopy(render,texture,NULL,&positionMenu);

		}

		SDL_Delay(20);
		SDL_RenderPresent(render);

	}

	statut=EXIT_SUCCESS;

Quit:
	if(surfaceMenu!=NULL)
		SDL_FreeSurface(surfaceMenu);
	if(ecran!=NULL)
		SDL_FreeSurface(ecran);
	if(texture!=NULL)
		SDL_DestroyTexture(texture);	
	if(render!=NULL)
		SDL_DestroyRenderer(render);
	if(window!=NULL)
		SDL_DestroyWindow(window);
	SDL_Quit();
	printf("statut sortie=%d\n",statut);
	return statut;		

}