#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Window *window=NULL;
    SDL_Renderer *render=NULL;
    SDL_Surface *s=NULL, *playeur=NULL;
    SDL_Texture *texture=NULL;
    SDL_Rect rect={100,100,0,0};
    int statut=EXIT_FAILURE;

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        fprintf(stderr,"Error SDL_Init: %s\n",SDL_GetError());
        goto Quit;
    }

    if(SDL_CreateWindowAndRenderer(640,480,SDL_WINDOW_SHOWN,&window,&render)!=0)
    {
        fprintf(stderr,"Error SDL_CreateWindowAndRenderer: %s\n",SDL_GetError());
        goto Quit;
    }

    s=SDL_CreateRGBSurface(0,34,34,32,0,0,0,0);
    if(s==NULL)
    {
        fprintf(stderr,"Error SDL_CreateWindowAndRenderer: %s\n",SDL_GetError());
        goto Quit;
    }
    SDL_FillRect(s,NULL,SDL_MapRGB(s->format,255,255,255));

    playeur=SDL_LoadBMP("mario_droite.bmp");
    if(playeur==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP: %s\n",SDL_GetError());
        goto Quit;
    }

    SDL_BlitSurface(playeur,NULL,s,NULL);

    texture=SDL_CreateTextureFromSurface(render,s);
    if(texture==NULL)
    {
        fprintf(stderr,"Error SDL_CreateTextureFromSurface: %s\n",SDL_GetError());
        goto Quit;
    }

    SDL_SetRenderDrawColor(render,255,255,255,20);
    SDL_RenderClear(render);
    SDL_QueryTexture(texture,NULL,NULL,&rect.w,&rect.h);
    SDL_RenderCopy(render,texture,NULL,&rect);
    SDL_RenderPresent(render);
    SDL_Delay(3000);

    statut=EXIT_SUCCESS;

Quit:
    if(playeur!=NULL)
        SDL_FreeSurface(playeur);
    if(s!=NULL)
        SDL_FreeSurface(s);    
    if(texture!=NULL)
        SDL_DestroyTexture(texture);
    if(render!=NULL)
        SDL_DestroyRenderer(render);
    if(window!=NULL)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;                

}