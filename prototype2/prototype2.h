#ifndef DS4_H_INCLUDED
#define DS4_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>





void mouvementright (perssonage *p);
void mouvementleft (perssonage *p);
void mouvementdown (perssonage *p);
void gravite (SDL_Surface *screen,perssonage*p,Input *I);
void mouvementjump (perssonage *p);
int rotozoom(SDL_Surface *ecran);

  #endif // DS_H_INCLUDED
