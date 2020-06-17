#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include "prototype2.h"
#define gravity 2;
#define GRAVITY_SPEED 20
#define MAX_FALL_SPEED 50
#define JUMP_HEIGHT 30
#define SPEED 2
#define MAX_SPEED 7
#define TEMPS       30 // Le temps qu'il y a entre chaque augmentation de l'angle.




void mouvementright (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x<350)
p->rect.x=p->rect.x+p->xvelocity*p->delta_time;
}



void mouvementleft (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x>150)
p->rect.x=p->rect.x-p->xvelocity*p->delta_time;

}



void mouvementdown (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
p->rect.y=p->rect.y+p->xvelocity*p->delta_time;

}



void mouvementjump (perssonage *p)
{
	if (p->one_jump==1)
	{
		p->yvelocity-=JUMP_HEIGHT;
		//if (p->rect.y<=p->rect.y-p->yvelocity*p->delta_time)
		//p->rect.y=p->rect.y-p->yvelocity*p->delta_time;
		p->onground=0;
	}
}











int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *image = NULL, *rotation = NULL;
    SDL_Rect rect;
    SDL_Event event;
    double angle = 0;
    double zoom = 1;
    int sens = 1;

    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Faire des rotations avec SDL_gfx", NULL);

    image = SDL_LoadBMP("image.bmp");

    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2; //On augmente l'angle pour que l'image tourne sur elle-même.

            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        rotation = rotozoomSurface(image, angle, zoom, 0); //On transforme la surface image.

        //On repositionne l'image en fonction de sa taille.
        rect.x =  event.button.x - rotation->w / 2;
        rect.y =  event.button.y - rotation->h / 2;

        SDL_BlitSurface(rotation , NULL, ecran, &rect); //On affiche la rotation de la surface image.
        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire.

        if(zoom >= 2){sens = 0;}
        else if(zoom <= 0.5){sens = 1;}

        if(sens == 0){zoom -= 0.02;}
        else{zoom += 0.02;}

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
    SDL_Quit();

    return EXIT_SUCCESS;
}