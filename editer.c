#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constante.h"

/*
    Terminer les differente fonction
    Ecrire le make final
*/

void editer(int niveau, int t[TAILLE][TAILLE])
{
    //la fonction modifier la carte en fonction du niveau
    switch(niveau)
    {
        case NIVEAU1 :
            editer1(t);
        break;

        case NIVEAU2:
            editer2(t);
        break;

        case NIVEAU3 :
            editer3(t);
        break;

        default:
        break;
    }

    return;    
}



void editer1(int t[TAILLE][TAILLE])
{

    int i, j;

    for(i=0;i<TAILLE;i++)
    {

        for(j=0;j<TAILLE;j++)
        {

            switch(i)
            {

                case 1 :
                    if((j==1)||(j==5)||(j==6)||(j==7)||(j==8))
                        t[i][j]=vide;
                    else if( j==2 || j==4 )
                        t[i][j]=cible;
                    else
                        t[i][j]=plein;    
                break;

                case 2 :
                    if((j==0)||(j==3)||(j>8))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;    
                break;

                case 3:
                    if((j==0)||(j==3)||(j>8))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;    
                break;

                case 4 :
                    if(j==2)
                        t[i][j]=casier;
                    else if((j==0)||(j==3)||(j>8))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;    
                break;

                case 5 :
                    if(j==1)
                        t[i][j]=player;
                    else if(j==2)
                        t[i][j]=casier;
                    else if((j==0)||(j>8))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;     
                break;

                case 6 :
                    if((j==2))
                        t[i][j]=casier;
                    else if((j==0)||(j==3)||(j>8))
                        t[i][j]=plein;
                    else 
                        t[i][j]=vide;    
                break;

                case 7 :
                    if((j==0)||(j==3)||(j>8))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;    
                break;

                case 8 :
                    if((j==0)||(j==3)||(j>8))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;    
                break;

                case 9 :
                    if(j==2)
                        t[i][j]=cible;
                    else if((j==0)||(j==3)||(j>8))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;    
                break;

                default:
                    t[i][j]=plein;
                break;

            }

        }

    }

    return;
}

void editer2(int t[TAILLE][TAILLE])
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
                    if(j==3)
                        t[i][j]=cible;
                    else if((j==4)||(j==5))
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;    
                break;

                case 2 :
                    if(j==3)
                        t[i][j]=cible;
                    else if((j==4)||(j==5))
                        t[i][j]=vide;
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
                    if(j==8)
                        t[i][j]=cible;
                    else if((j==2)||(j==3)||(j==4)||(j==5)||(j==6)||(j==8))
                        t[i][j]=vide;
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
                    if((j==0)||(j==1)||(j==2)||(j==3)||(j==4)||(j==5)||(j==6)||(j==8))
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;    
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
                    if((j==4)||(j==6))
                        t[i][j]=casier;
                    else if((j==1)||(j==2)||(j==3)||(j==5)||(j==7)||(j==8))
                        t[i][j]=vide;
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

            
            }

        }

    }

    return;
}

void editer3(int t[TAILLE][TAILLE])
{
    int i, j;

    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            switch(i)
            {

                case 0 :
                    t[i][j]=plein;
                break;

                case 1 :
                    if((j==0)||(j>8))
                        t[i][j]=plein;
                    else if((j==5)||(j==6))
                        t[i][j]=cible;
                    else
                        t[i][j]=vide;            
                break;

                case 2 :
                    if((j==1)||(j==3)||(j==8))
                        t[i][j]=vide;
                    else if(j==6)
                        t[i][j]=cible;
                    else
                        t[i][j]=plein;            
                break;

                case 3 :
                    if((j==0)||(j==7)||(j>8))
                        t[i][j]=plein;
                    else if(j==8)
                        t[i][j]=casier;
                    else   
                        t[i][j]=vide;            
                break;

                case 4 :
                    if((j<3)||(j==7)||(j>8))
                        t[i][j]=plein;
                    else if((j==4)||(j==6))
                        t[i][j]=casier;
                    else
                        t[i][j]=vide;            
                break;

                case 5 :
                    if((j<4)||(j==7)||(j>9))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;        
                break;

                case 6 :
                    if((j<3)||(j==6)||(j==7)||(j>9))
                        t[i][j]=plein;
                    else if(j==3)
                        t[i][j]=player;
                    else
                        t[i][j]=vide;            
                break;

                case 7 :
                    if((j<5)||(j>9))
                        t[i][j]=plein;
                    else
                        t[i][j]=vide;        
                break;

                case 8 :
                    if((j==5)||(j==6))
                        t[i][j]=vide;
                    else
                        t[i][j]=plein;        
                break;

                default :
                    t[i][j]=plein;
                break;

            }
        }
    }

    return;
}