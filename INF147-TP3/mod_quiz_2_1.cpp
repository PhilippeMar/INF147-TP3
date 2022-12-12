/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Decembre 2022

--Description
	Ce fichier permet d'utiliser des piles statiques

On y retrouve les sous-programmes suivants :
	- t_pile_image_initialiser
	- t_pile_image_est_vide
	- t_pile_image_est_pleine
	- t_pile_image_empiler
	- t_pile_image_depiler
*****************************************************************************************/

#include "mod_quiz_2_1.h"

#include <stdio.h>

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Initialise une pile d'images.
void t_pile_image_initialiser(t_pile_image* pile_image_ptr)
{
	pile_image_ptr->taille = 0;
}

// Indique si la pile est vide ou non.
unsigned char t_pile_image_est_vide(t_pile_image* pile_image_ptr)
{
	unsigned char pile_vide = pile_image_ptr->taille == 0;
	
	return pile_vide;
}

// Indique si la pile est pleine ou non.
unsigned char t_pile_image_est_pleine(t_pile_image* pile_image_ptr)
{
	unsigned char pile_pleine = pile_image_ptr->taille == TAILLE_PILE_IMAGE_MAX;

	return pile_pleine;
}

// Empile une image.
void t_pile_image_empiler(t_pile_image* pile_image_ptr, t_image* image_ptr)
{
	printf("t_pile_image_empiler > ");

	if (t_pile_image_est_pleine(pile_image_ptr))
	{
		// On affiche un message d'erreur
		printf("ERREUR > La pile est pleine\n");
	}
	else
	{
		// On empile l'image dans le tableau
		pile_image_ptr->tab_image[pile_image_ptr->taille] = image_ptr;
		// On increment la taille
		++pile_image_ptr->taille;
		// On affiche un message
		printf("Il reste %i/%i places dans la pile\n"
			, TAILLE_PILE_IMAGE_MAX - pile_image_ptr->taille
			, TAILLE_PILE_IMAGE_MAX);
	}
}

// Depile une image.
t_image* t_pile_image_depiler(t_pile_image* pile_image_ptr)
{
	t_image* image_ptr = NULL;

	printf("t_pile_image_depiler > ");
	
	if (t_pile_image_est_vide(pile_image_ptr))
	{
		// On affiche un message d'erreur
		printf("ERREUR > La pile est vide\n");
	}
	else
	{
		// On depile l'image dans le tableau puis decremente la taille
		image_ptr = pile_image_ptr->tab_image[pile_image_ptr->taille];
		//On decremente la taille
		--pile_image_ptr->taille;
		// On affiche un message
		printf("Il reste %i/%i places dans la pile\n"
			, TAILLE_PILE_IMAGE_MAX - pile_image_ptr->taille
			, TAILLE_PILE_IMAGE_MAX);
	}

	return image_ptr;
}
