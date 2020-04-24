#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constante.h"
#include "game1.h"

/*
 main.c
 ......

 Par obmco inspirer de mateo (sitedu0)

 Menu du jeu.Permet de choisir entre l'editeur et le jeu lui meme
 */

int main(int argc, char *argv[])
{

	//definitions des var
	//Surface pour le menu et l'ecran 
	SDL_Surface *surfaceMenu=NULL, *ecran=NULL;
	SDL_Texture *texture=NULL; //texture du menu et de l'ecran
	SDL_Rect positionMenu={0,0,LONGUEUR,LONGUEUR};
	SDL_Event event;
	SDL_Renderer *render=NULL;
	SDL_Window *window=NULL;
	SDL_bool quit=SDL_FALSE;
	int surface=0, statut=EXIT_FAILURE;

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

	texture=SDL_CreateTextureFromSurface(render,surfaceMenu);

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
					switch(event.key.keysym.sym)
					{
						case SDLK_SPACE :
							quit=SDL_TRUE;
						break;

						case SDLK_KP_1 : //commencer le jeu
							if(game1(ecran,event)==2)
							{
								quit=SDL_TRUE;
							}
							surface=1;
						break;

					}
				break;

			}

			if(surface==1)
			{
				texture=SDL_CreateTextureFromSurface(render,ecran);
            	SDL_RenderCopy(render,texture,NULL,&positionMenu);
			}
			else
			{
            	SDL_RenderCopy(render,texture,NULL,&positionMenu);
			}

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