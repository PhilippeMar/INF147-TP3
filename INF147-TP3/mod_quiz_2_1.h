#ifndef _MOD_QUIZ_2_1_
#define _MOD_QUIZ_2_1_

#include "mod_quiz_1.h"	

/* Taille maximale d'une pile de image */
#define TAILLE_PILE_IMAGE_MAX 2

/* Type structure qui represente une pile de image */
typedef struct
{
	t_image* tab_image[TAILLE_PILE_IMAGE_MAX];
	unsigned char taille;
} t_pile_image;

/*
T_PILE_IMAGE_INITIALISER

	Initialise une pile d'images.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_pile_image_initialiser(t_pile_image* pile_image_ptr)
{
	pile_image_ptr->taille = 0;
}

/*
T_PILE_IMAGE_EST_VIDE

	Indique si la pile est vide ou non.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).

 VALEUR DE RETOUR :

	- est_vide: Indicateur de vide (type: unsigned char).
*/
unsigned char t_pile_image_est_vide(t_pile_image* pile_image_ptr)
{
	unsigned char est_vide;

	if (pile_image_ptr->taille == 0)
	{
		est_vide = 1;
	}
	else
	{
		est_vide = 0;
	}

	return est_vide;
}

/*
T_PILE_IMAGE_EST_PLEINE

	Indique si la pile est pleine ou non.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).

 VALEUR DE RETOUR :

	- est_pleine: Indicateur de plein (type: unsigned char).
*/
unsigned char t_pile_image_est_pleine(t_pile_image* pile_image_ptr)
{
	unsigned char est_pleine;

	if (pile_image_ptr->taille == TAILLE_PILE_IMAGE_MAX)
	{
		est_pleine = 1;
	}
	else
	{
		est_pleine = 0;
	}

	return est_pleine;
}

/*
T_PILE_IMAGE_EMPILER

	Empile une image.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).
	- image_ptr: Une reference vers une image a empiler (type: t_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_pile_image_empiler(t_pile_image* pile_image_ptr, t_image* image_ptr)
{
	if (t_pile_image_est_pleine(pile_image_ptr))
	{
		printf("t_pile_image_empiler > ERREUR > La pile est pleine\n");
	}
	else
	{
		pile_image_ptr->tab_image[pile_image_ptr->taille] = image_ptr;
		pile_image_ptr->taille++;
		printf("t_pile_image_empiler > Il reste %d/%d places dans la pile\n", TAILLE_PILE_IMAGE_MAX-pile_image_ptr->taille, TAILLE_PILE_IMAGE_MAX);
	}
}

/*
T_PILE_IMAGE_DEPILER

	Depile une image.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers une pile d'images (type: t_pile_image*).

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image depilee (type: t_image*).
*/
t_image* t_pile_image_depiler(t_pile_image* pile_image_ptr)
{
	t_image* image_ptr = 0;

	if (t_pile_image_est_vide(pile_image_ptr))
	{
		printf("t_pile_image_depiler > ERREUR > La pile est vide\n");
	}
	else
	{
		image_ptr = pile_image_ptr->tab_image[pile_image_ptr->taille];
		pile_image_ptr->taille--;
		printf("t_pile_image_depiler > Il reste %d/%d places dans la pile\n", TAILLE_PILE_IMAGE_MAX - pile_image_ptr->taille, TAILLE_PILE_IMAGE_MAX);
	}

	return image_ptr;
}

#endif