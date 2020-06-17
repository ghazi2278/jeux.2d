#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct joueur
{
	char name[20];
	char score[20];
	char time[256];

}joueur;
typedef struct hero
{
	int changervie1;
int changervie2;
int changervie3;

int nombre_vie;

SDL_Surface *affichage_vie;

SDL_Rect position_vie;
SDL_Surface *cadre;

int score;

SDL_Surface *score_affichage;

TTF_Font *policescore;
TTF_Font *policegame;
char scorechaine[25];
int aux;
SDL_Rect position_hero;
SDL_Rect position_aux;
SDL_Surface *win_or_lose;
SDL_Rect win_or_lose_position;
SDL_Rect frame;

int tempprecedentezdin;

SDL_Surface *affichage_hero;

SDL_Rect position_map;
int temp2;
int speed;

int button;

int curframe;

int maxframe;

int activer_defaut;

int curframe2;

int maxframe2;

int sens;

int clavierdown;

} hero;


hero Initialiser_Personnage (hero ezdin);

void Afficher_Personnage (hero *ezdin , SDL_Surface *ecran);
void deplacment_Personnage_clavier (hero *ezdin );

void animation_Personnage (hero *ezdin);
#endif
