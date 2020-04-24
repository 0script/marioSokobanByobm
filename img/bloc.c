#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(int argc,char *argv[])
{
    SDL_Window *window=NULL;
    SDL_Renderer *render=NULL;
    SDL_Texture *texture=NULL;
    SDL_Surface *bloc=NULL;
    SDL_Event event;
    SDL_bool quit=SDL_FALSE;
    SDL_Rect src={0,0,0,0}, oldrect;
    SDL_Color rendercolor={110,42,0,255};
    int statut=EXIT_FAILURE;

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        fprintf(stderr,"Error SDL_Init: %s\n",SDL_GetError());
        goto Quit;
    }

    if(SDL_CreateWindowAndRenderer(640,480,SDL_WINDOW_SHOWN,&window,&render)!=0)
    {
        fprintf(stderr,"Error SDL_CreateWindowAndRender:%s\n",SDL_GetError());
        goto Quit;
    }

    bloc=SDL_LoadBMP("caisse.bmp");
    if(bloc==NULL)
    {
        fprintf(stderr,"Error SDL_LoadBMP:%s\n",SDL_GetError());
        goto Quit;
    }

    texture=SDL_CreateTextureFromSurface(render,bloc);
    if(texture==NULL)
    {
        fprintf(stderr,"Error SDL_CreateTextureFromRender:%s\n",SDL_GetError());
        goto Quit;
    }

    SDL_SetRenderDrawColor(render,rendercolor.r,rendercolor.g,rendercolor.b,rendercolor.a);
    SDL_QueryTexture(texture,NULL,NULL,&src.w,&src.h);
    SDL_RenderClear(render);
    

    //Evenement

    while(!quit)
    {
        
        while(SDL_PollEvent(&event))
        {
            
            if(event.type==SDL_QUIT)
                quit=SDL_TRUE;
            else if(event.type==SDL_KEYDOWN)
                {

                    oldrect=src;

                    if(event.key.keysym.sym==SDLK_a)
                    {
                        src.x+=src.w;
                        SDL_RenderCopy(render,texture,NULL,&src);
                        SDL_RenderFillRect(render,&oldrect);
                    }
                }
        }
        SDL_Delay(20);
        SDL_RenderPresent(render);

    }
    printf("%d\n",src.w);

    statut=EXIT_SUCCESS;

Quit:
    if(bloc!=NULL)
        SDL_FreeSurface(bloc);
    if(texture!=NULL)
        SDL_DestroyTexture(texture);
    if(render!=NULL)
        SDL_DestroyRenderer(render);
    if(window!=NULL)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;                

}
