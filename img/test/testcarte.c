#include <stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#define TAILLE 12
#define TAILLE_BLOC 34
#define LONGUEUR TAILLE_BLOC*12

enum{vide,plein,player,casier,cible};

void editer(int t[TAILLE][TAILLE]);

int main(int argc, char *argv[])
{
    SDL_Window *window=NULL;
    SDL_Renderer *render=NULL;
    SDL_Texture *texture=NULL;
    SDL_Surface *mainsurface=NULL, *mur=NULL, *playeurDroit=NULL, *bloc=NULL, *objectif=NULL;
    SDL_Rect rectblitsurface={0,0,TAILLE_BLOC,TAILLE_BLOC};
    
    int carte[TAILLE][TAILLE];
    int i, j;
    int statut=EXIT_FAILURE;

    editer(carte);

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



    mur=SDL_LoadBMP("../mur.bmp");
    if(mur==NULL)
   {
       fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
   }

   playeurDroit=SDL_LoadBMP("../marioBas.bmp");
   if(playeurDroit==NULL)
   {
       fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
       goto Quit;
   }

   bloc=SDL_LoadBMP("../caisse.bmp");
   if(bloc==NULL)
   {
       fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
       goto Quit;
   }

   objectif=SDL_LoadBMP("../objectif.bmp");
   if(objectif==NULL)
   {
       fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
       goto Quit;
   }

   

   mainsurface=SDL_CreateRGBSurface(0,LONGUEUR,LONGUEUR,32,0,0,0,0);
   if(mainsurface==NULL)
   {
       fprintf(stderr,"Error SDL_CreateRGBSurface: %s\n",SDL_GetError());
        goto Quit;
   }
    
    SDL_FillRect(mainsurface,NULL,SDL_MapRGB(mainsurface->format,255,255,255));

    for(i=0;i<TAILLE;i++)
    {
        
        for(j=0;j<TAILLE;j++)
        {

            switch(carte[i][j])
            {

                case plein :
                    rectblitsurface.x=TAILLE_BLOC*i;
                    rectblitsurface.y=TAILLE_BLOC*j;
                    SDL_BlitSurface(mur,NULL,mainsurface,&rectblitsurface);
                break;

                case player :
                    rectblitsurface.x=TAILLE_BLOC*i;
                    rectblitsurface.y=TAILLE_BLOC*j;
                    SDL_BlitSurface(playeurDroit,NULL,mainsurface,&rectblitsurface);
                break;

                case casier :
                    rectblitsurface.x=TAILLE_BLOC*i;
                    rectblitsurface.y=TAILLE_BLOC*j;
                    SDL_BlitSurface(bloc,NULL,mainsurface,&rectblitsurface);
                break;

                case cible :
                    rectblitsurface.x=TAILLE_BLOC*i;
                    rectblitsurface.y=TAILLE_BLOC*j;
                    SDL_BlitSurface(objectif,NULL,mainsurface,&rectblitsurface);
                break;    

            }

        }

    }

    texture=SDL_CreateTextureFromSurface(render,mainsurface);
    if(texture==NULL)
    {
        fprintf(stderr,"Error SDL_TextureFromSurface: %s\n",SDL_GetError());
        goto Quit;
    }

    SDL_RenderClear(render);
    SDL_RenderCopy(render,texture,NULL,NULL);
    SDL_RenderPresent(render);
    SDL_Delay(20000);

    statut=EXIT_SUCCESS;

Quit:
    if(mur!=NULL)
        SDL_FreeSurface(mur);
    if(bloc!=NULL)
        SDL_FreeSurface(bloc);
    if(playeurDroit!=NULL)
        SDL_FreeSurface(playeurDroit);
    if(objectif!=NULL)
        SDL_FreeSurface(objectif);            
    if(mainsurface!=NULL)
        SDL_FreeSurface(mainsurface);
    if(texture!=NULL)
        SDL_DestroyTexture(texture);
    if(render!=NULL)
        SDL_DestroyRenderer(render);
    if(window!=NULL)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;                    

}

void editer(int t[TAILLE][TAILLE])
{

    int i, j;

        for(i=0;i<TAILLE;i++)
    {

        for(j=0;j<TAILLE;j++)
        {

            switch(i)
            {

                case 0 :
                    if((j==3)||(j==4))
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;    
                break;

                case 1 :
                    if((j==4)||(j==5))
                        t[i][j]=vide;
                    else if(j==3) 
                        t[i][j]=cible;
                    else
                        t[i][j]=plein;       
                break;

                case 2 :
                    if((j==4)||(j==5))
                        t[i][j]=vide;
                    else if(j==3)
                        t[i][j]=cible;    
                    else
                        t[i][j]=plein;    
                break;

                case 3:
                    if(j==4)
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;    
                break;

                case 4 :
                    if((j==2)||(j==3)||(j==4)||(j==5)||(j==6))
                        t[i][j]=vide;
                    else if(j==8)
                        t[i][j]=cible;
                    else
                        t[i][j]=plein;        
                break;

                case 5 :
                    if(j==1)
		                t[i][j]=player;
		            else if(j==4)
                        t[i][j]=casier;
                    else if((j==0)||(j==2)||(j==6)||(j==8))
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;     
                break;

                case 6 :
                    if((j==7)||(j==9)||(j==10)||(j==11))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;    
                break;

                case 7 :
                    if((j==1)||(j==4)||(j==5)||(j==8))
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;
                break;

                case 8 :
                    if((j==1)||(j==5)||(j==8))
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;    
                break;            

                case 9 :
                    if((j==1)||(j==2)||(j==3)||(j==5)||(j==7)||(j==8))
                        t[i][j]=vide;
                    else if((j==4)||(j==6))
                        t[i][j]=casier;
                    else
                        t[i][j]=plein;        
                break;

                case 10 :
                    if((j==1)||(j==2)||(j==7)||(j==8))
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;     
                break;

                case 11 :
                    t[i][j]=plein;
                break;
            }

        }

    }

    return;
}