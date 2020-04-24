#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constante.h"
#include "editer.h"
#include "fonction.h"

/*
    Fonction game1 permet de jouer (deplacer les block et le joueur et retourne 0 si le joueur veut quitter
    1 si la partie continue et 2 si la partie est finie)
*/

int game1(SDL_Surface *ecran,SDL_Event event)
{
    /* la fonction retourne 0 si le joueur veut quitter 1 si la partie continue et 2 si la partie est finie*/

    SDL_Surface *mur=NULL, *mariodown=NULL, *marioup=NULL, *marioleft=NULL, *marioright=NULL, *objectif=NULL, *bloc=NULL, *blocok=NULL;
    SDL_Rect rectsizebloc={0,0,BLOC,BLOC};
    int retour, i, j, move=DOWN ;

    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            if(carte[i][j]==player)
            {
                xplayer=i;
                yplayer=j;
            }
        }   

    }

    //initialisations des surfaces 

    mariodown=SDL_LoadBMP("img/marioBas.bmp");
    if(mariodown==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    marioup=SDL_LoadBMP("img/mario_haut.bmp");
    if(marioup==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    marioleft=SDL_LoadBMP("img/mario-gauche.bmp");
    if(marioleft==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    marioright=SDL_LoadBMP("img/mario_droite.bmp");
    if(marioright==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    bloc=SDL_LoadBMP("img/caisse.bmp");
    if(bloc==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    blocok=SDL_LoadBMP("img/caisse-ok.bmp");
    if(blocok==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    objectif=SDL_LoadBMP("img/objectif.bmp");
    if(objectif==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    mur=SDL_LoadBMP("img/mur.bmp");
    if(mur==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    switch(event.type)
    {
        case SDL_QUIT :
            retour=0;
        break;

        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {

                case SDLK_a :
                    move=LEFT;
                    if(carte[xplayer-1][yplayer]==vide)
                    {
                        carte[xplayer][yplayer]=vide;
                        carte[xplayer-1][yplayer]=player;
                        xplayer-=1;
                    }
                    else if(carte[xplayer-1][yplayer]==casier)
                    {
                        if(carte[xplayer-2][yplayer]==vide)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer-1][yplayer]=player;
                            carte[xplayer-2][yplayer]=casier;
                            xplayer-=1;
                        }
                        else if(carte[xplayer-2][yplayer]==cible)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer-1][yplayer]=player;
                            carte[xplayer-2][yplayer]=casierOk;
                            xplayer-=1;
                        }
                    }
                    else if(carte[xplayer-1][yplayer]==casierOk)
                    {
                        if(carte[xplayer-2][yplayer]==vide)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer-1][yplayer]=player;
                            carte[xplayer-2][yplayer]=casier;
                            xplayer-=1;
                        }
                        else if(carte[xplayer-2][yplayer]==cible)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer-1][yplayer]=player;
                            carte[xplayer-2][yplayer]=casierOk;
                            xplayer-=1;
                        }
                    }
                    else if(carte[xplayer-1][yplayer]==cible)
                    {
                        carte[xplayer][yplayer]=vide;
                        carte[xplayer-1][yplayer]=player;
                        xplayer-=1;
                    }
                break;

                case SDLK_f :
                    move=RIGHT;
                    if(carte[xplayer+1][yplayer]==vide)
                    {
                        carte[xplayer][yplayer]=vide;
                        carte[xplayer+1][yplayer]=player;
                        xplayer+=1;
                    }
                    else if(carte[xplayer+1][yplayer]==casier)
                    {
                        if(carte[xplayer+2][yplayer]==vide)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer+1][yplayer]=player;
                            carte[xplayer+2][yplayer]=casier;
                            xplayer+=1;
                        }
                        else if(carte[xplayer+2][yplayer]==cible)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer+1][yplayer]=player;
                            carte[xplayer+2][yplayer]=casierOk;
                            xplayer+=1;
                        }
                    }
                    else if(carte[xplayer+1][yplayer]==casierOk)
                    {
                        if(carte[xplayer+2][yplayer]==vide)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer+1][yplayer]=player;
                            carte[xplayer+2][yplayer]=casier;
                            xplayer+=1;
                        }
                        else if(carte[xplayer+2][yplayer]==cible)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer+1][yplayer]=player;
                            carte[xplayer+2][yplayer]=casierOk;
                            xplayer+=1;
                        }
                    }
                    else if(carte[xplayer+1][yplayer]==cible)
                    {
                        carte[xplayer][yplayer]=vide;
                        carte[xplayer+1][yplayer]=player;
                        xplayer+=1;
                    }
                break;

                case SDLK_s :
                    move=UP;
                    if(carte[xplayer][yplayer-1]==vide)
                    {
                        carte[xplayer][yplayer]=vide;
                        carte[xplayer][yplayer-1]=player;
                        yplayer-=1;
                    }
                    else if(carte[xplayer][yplayer-1]==casier)
                    {
                        if(carte[xplayer][yplayer-2]==vide)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer][yplayer-1]=player;
                            carte[xplayer][yplayer-2]=casier;
                            yplayer-=1;
                        }
                        else if(carte[xplayer][yplayer-2]==cible)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer][yplayer-1]=player;
                            carte[xplayer][yplayer-2]=casierOk;
                            yplayer-=1;
                        }
                    }
                    else if(carte[xplayer][yplayer-1]==casierOk)
                    {
                        if(carte[xplayer][yplayer-2]==vide)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer][yplayer-1]=player;
                            carte[xplayer][yplayer-2]=casier;
                            yplayer-=1;
                        }
                        else if(carte[xplayer][yplayer-2]==cible)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer][yplayer-1]=player;
                            carte[xplayer][yplayer-2]=casierOk;
                            yplayer-=1;
                        }
                    }
                    else if(carte[xplayer][yplayer-1]==cible)
                    {
                        carte[xplayer][yplayer]=vide;
                        carte[xplayer][yplayer-1]=player;
                        yplayer-=1;
                    }
                break;

                case SDLK_d :
                    move=DOWN;
                    if(carte[xplayer][yplayer+1]==vide)
                    {
                        carte[xplayer][yplayer]=vide;
                        carte[xplayer][yplayer+1]=player;
                        yplayer+=1;
                    }
                    else if(carte[xplayer][yplayer+1]==casier)
                    {
                        if(carte[xplayer][yplayer+2]==vide)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer][yplayer+1]=player;
                            carte[xplayer][yplayer+2]=casier;
                            yplayer+=1;
                        }
                        else if(carte[xplayer][yplayer+2]==cible)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer][yplayer+1]=player;
                            carte[xplayer][yplayer+2]=casierOk;
                            yplayer+=1;
                        }
                    }
                    else if(carte[xplayer][yplayer+1]==casierOk)
                    {
                        if(carte[xplayer][yplayer+2]==vide)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer][yplayer+1]=player;
                            carte[xplayer][yplayer+2]=casier;
                            yplayer+=1;
                        }
                        else if(carte[xplayer][yplayer+2]==cible)
                        {
                            carte[xplayer][yplayer]=vide;
                            carte[xplayer][yplayer+1]=player;
                            carte[xplayer][yplayer+2]=casierOk;
                            yplayer+=1;
                        }
                    }
                    else if(carte[xplayer][yplayer+1]==cible)
                    {
                        carte[xplayer][yplayer]=vide;
                        carte[xplayer][yplayer+1]=player;
                        yplayer+=1;
                    }
                break;
            }
            retour=1;
        break;
    }


    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));        //on netoie la surface pour l update

    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            
            switch(carte[i][j])
            {

                case plein :
                    rectsizebloc.x=BLOC*i;
                    rectsizebloc.y=BLOC*j;
                    SDL_BlitSurface(mur,NULL,ecran,&rectsizebloc);
                break;

                case casier :
                    if(putcible(i,j)==1)
                    {
                        carte[i][j]=casierOk;
                        rectsizebloc.x=BLOC*i;
                        rectsizebloc.y=BLOC*j;
                        SDL_BlitSurface(blocok,NULL,ecran,&rectsizebloc);
                    }
                    else
                    {
                        rectsizebloc.x=BLOC*i;
                        rectsizebloc.y=BLOC*j;
                        SDL_BlitSurface(bloc,NULL,ecran,&rectsizebloc);
                    }
                break;

                case casierOk :
                    rectsizebloc.x=BLOC*i;
                    rectsizebloc.y=BLOC*j;
                    SDL_BlitSurface(blocok,NULL,ecran,&rectsizebloc);
                break;

                case cible :
                    rectsizebloc.x=BLOC*i;
                    rectsizebloc.y=BLOC*j;
                    SDL_BlitSurface(objectif,NULL,ecran,&rectsizebloc);
                break;

                case player :
                    rectsizebloc.x=BLOC*i;
                    rectsizebloc.y=BLOC*j;
                    switch(move)
                    {

                        case UP :
                            SDL_BlitSurface(marioup,NULL,ecran,&rectsizebloc);        
                        break;

                        case DOWN :
                            SDL_BlitSurface(mariodown,NULL,ecran,&rectsizebloc);        
                        break;

                        case LEFT :
                            SDL_BlitSurface(marioleft,NULL,ecran,&rectsizebloc);        
                        break;

                        case RIGHT :
                            SDL_BlitSurface(marioright,NULL,ecran,&rectsizebloc);        
                        break;

                    }
                break;

                case vide :
                    rectsizebloc.x=BLOC*i;
                    rectsizebloc.y=BLOC*j;
                    if(putcible(i,j)==0)
                    {    
                        SDL_FillRect(ecran,&rectsizebloc,SDL_MapRGB(ecran->format,255,255,255));
                    }
                    else if(putcible(i,j)==1)
                    {
                       SDL_BlitSurface(objectif,NULL,ecran,&rectsizebloc);
                    }
                break;

            }

        }
    }


    if(retour==1) //indique si la partie est finie
    {
        if(partiefinie(carte)==1)
            retour=2;
    }
    
    

Quit:
    if(mur!=NULL)
        SDL_FreeSurface(mur);
    if(bloc!=NULL)
        SDL_FreeSurface(bloc);
    if(blocok!=NULL)
        SDL_FreeSurface(blocok);
    if(objectif!=NULL)
        SDL_FreeSurface(objectif);
    if(marioup!=NULL)
        SDL_FreeSurface(marioup);
    if(mariodown!=NULL)
        SDL_FreeSurface(mariodown);
    if(marioleft!=NULL)
        SDL_FreeSurface(marioleft);
    if(marioright!=NULL)
        SDL_FreeSurface(marioright);                                           
    return retour;
}
