#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "projet.h"
#include <string.h>



hero Initialiser_Personnage (hero ezdin)
{
ezdin.position_hero.x=375;
ezdin.position_hero.y=275;
ezdin.position_aux.x=375;
ezdin.position_aux.y=275;
ezdin.position_map.x=5800;
ezdin.position_map.y=693;
ezdin.sens=0;
ezdin.clavierdown=0;
ezdin.frame.y=49;
ezdin.frame.x=48;
ezdin.frame.w=48;
ezdin.frame.h=48;
ezdin.nombre_vie=3;
ezdin.score=0;
ezdin.score_affichage=NULL;
ezdin.button=0;
ezdin.affichage_hero=NULL;
ezdin.affichage_hero=IMG_Load("ezdin.png");
ezdin.affichage_vie=NULL;
ezdin.affichage_vie=IMG_Load("vie3.png");
ezdin.position_vie.x=620;
ezdin.position_vie.y=0;
ezdin.curframe=0;
ezdin.maxframe=2;
ezdin.changervie1=0;
ezdin.changervie2=0;
ezdin.changervie3=0;
ezdin.policescore=TTF_OpenFont("arial.ttf",36);
ezdin.policegame=TTF_OpenFont("arial.ttf",80);
ezdin.win_or_lose=NULL;
ezdin.win_or_lose_position.x=200;
ezdin.win_or_lose_position.y=200;
ezdin.speed=10;
ezdin.temp2=0;
strcpy(ezdin.scorechaine,"000");


ezdin.activer_defaut=0;

ezdin.tempprecedentezdin=0;

ezdin.curframe2=0;

ezdin.maxframe2=119;


return ezdin;

}
void Afficher_Personnage (hero *ezdin , SDL_Surface *ecran)
{

SDL_BlitSurface(ezdin->affichage_hero,&ezdin->frame,ecran,&ezdin->position_hero);
SDL_BlitSurface(ezdin->affichage_vie,NULL,ecran,&ezdin->position_vie);

}
void animation_Personnage (hero *ezdin)
{

	switch(ezdin->button)
	{

		case 8:
		{




			ezdin->frame.y=146;
	ezdin->frame.h=48;
ezdin->frame.w=48;


ezdin->curframe+=1;

	if(ezdin->curframe>ezdin->maxframe)
	{
		ezdin->curframe=0;
	}

ezdin->frame.x=ezdin->curframe*ezdin->frame.w;



		}
		break;

		case 2:
		{





				ezdin->frame.y=0;
	ezdin->frame.h=48;
ezdin->frame.w=48;


ezdin->curframe+=1;

	if(ezdin->curframe>ezdin->maxframe)
	{
		ezdin->curframe=0;
	}

ezdin->frame.x=ezdin->curframe*ezdin->frame.w;










		}
		break;

		case 6:
		{





ezdin->frame.y=97;
	ezdin->frame.h=48;
ezdin->frame.w=48;


ezdin->curframe+=1;

	if(ezdin->curframe>ezdin->maxframe)
	{
		ezdin->curframe=0;
	}

ezdin->frame.x=ezdin->curframe*ezdin->frame.w;







		}
		break;

		case 4:
		{






ezdin->frame.y=49;
	ezdin->frame.h=48;
ezdin->frame.w=49;

ezdin->curframe+=1;

	if(ezdin->curframe>ezdin->maxframe)
	{
		ezdin->curframe=0;
	}

ezdin->frame.x=ezdin->curframe*ezdin->frame.w;











		}
		break;










	}
	if (ezdin->activer_defaut>=4)
					{

							ezdin->frame.y=194;
							ezdin->curframe2+=1;

	if(ezdin->curframe2>ezdin->maxframe2)
	{
		ezdin->curframe2=0;
	}


ezdin->frame.x=ezdin->curframe2*ezdin->frame.w;

					}







}
void deplacment_Personnage_clavier (hero *ezdin )

{


switch (ezdin->button)
{

	case 8:
	{
ezdin->position_map.y-=ezdin->speed;

	}
break;
	case 2:
	{
ezdin->position_map.y+=ezdin->speed;
	}
break;
	case 6:
	{
ezdin->position_map.x+=ezdin->speed;
	}
break;
	case 4:
	{
ezdin->position_map.x-=ezdin->speed;
	}
break;


}
}
