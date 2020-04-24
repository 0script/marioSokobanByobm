/* 
 constante.h
 ...........

 Par mateo21, pour le site du zero
 
 Ce fichier definit les constantes : tailles de blocs taille de la fenetre 
 */

#ifndef CONSTANTES
#define CONSTANTES
	
	#define BLOC 34
	#define TAILLE 12
	#define LONGUEUR BLOC*TAILLE
	
	enum{vide,plein,player,casier,casierOk,cible};
	enum{UP,DOWN,LEFT,RIGHT};
	enum{MENU,GAME,EDITION};
	enum{NIVEAU1,NIVEAU2,NIVEAU3};
	int carte[TAILLE][TAILLE],xplayer, yplayer, level;

#endif	
