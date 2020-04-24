#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constante.h"
#include "editer.h"

int putcible(int x,int y)
{
    int i, j, trouver, tableau[TAILLE][TAILLE];
    struct poscible
    {
        int absice;
        int ordoner;
    };

    struct poscible cible1={0,0}, cible2={0,0}, cible3={0,0} ;

    editer(level,tableau);

    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            if(tableau[i][j]==cible)
            {
                if((cible1.absice==0)&&(cible1.ordoner==0))
                {
                    cible1.absice=i;
                    cible1.ordoner=j;
                }
                else if((cible2.absice==0)&&(cible2.ordoner==0))
                {
                    cible2.absice=i;
                    cible2.ordoner=j;
                }
                else if((cible3.absice==0)&&(cible3.ordoner==0))
                {
                    cible3.absice=i;
                    cible3.ordoner=j;
                }
            }
        }
    }

    if((cible1.absice==x)&&(cible1.ordoner==y))
        trouver=1;
    else if((cible2.absice==x)&&(cible2.ordoner==y))
        trouver=1;
    else if((cible3.absice==x)&&(cible3.ordoner==y))
        trouver=1;    
    else
        trouver=0;

    return trouver;
}

int partiefinie(int table[TAILLE][TAILLE])
{
    int i, j, retour, nombre, dessin[TAILLE][TAILLE];

    editer(level,dessin);

    retour=0;
    nombre=0;
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            if(dessin[i][j]==cible)
            {
                if(table[i][j]==casierOk)
                    nombre++;
            }
        }
    }

    if(nombre==3)
        retour=1;

    return retour;    

}
