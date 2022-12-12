/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Decembre 2022

--Description
	Ce fichier permet 

On y retrouve les sous-programmes suivants :
	- t_file_image_initialiser
	- t_file_image_est_vide
	- t_file_image_est_pleine
	- t_file_image_enfiler
	- t_file_image_defiler
*****************************************************************************************/

#include "mod_quiz_2_2.h"

#include <stdio.h>

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Initialise une File d'images.
void t_file_image_initialiser(t_file_image* file_image_ptr)
{
	file_image_ptr->taille = 0;
	file_image_ptr->i_defiler = 0;
	file_image_ptr->i_enfiler = 0;
}

// Indique si la file est vide ou non
unsigned char t_file_image_est_vide(t_file_image* file_image_ptr)
{
	unsigned char file_vide = file_image_ptr->taille == 0;

	return file_vide;
}

// Indique si la file est pleine ou non.
unsigned char t_file_image_est_pleine(t_file_image* file_image_ptr)
{
	unsigned char file_pleine = file_image_ptr->taille == TAILLE_FILE_IMAGE_MAX;

	return file_pleine;
}

// Enfile une image.
void t_file_image_enfiler(t_file_image* file_image_ptr, t_image* image_ptr)
{
	printf("t_file_image_enfiler > ");

	if (t_file_image_est_pleine(file_image_ptr))
	{
		// On affiche un message d'erreur
		printf("ERREUR > La file est pleine\n");
	}
	else
	{
		// On enfile l'image dans le tableau
		file_image_ptr->tab_image[file_image_ptr->i_enfiler] = image_ptr;
		// On incremente i_enfiler et le ramene a 0 une fois a la fin du tableau
		++file_image_ptr->i_enfiler %= TAILLE_FILE_IMAGE_MAX;
		// On incrémente la taille
		++file_image_ptr->taille;
		// On affiche un message
		printf("Il reste %i/%i places dans la file\n"
			, TAILLE_FILE_IMAGE_MAX - file_image_ptr->taille
			, TAILLE_FILE_IMAGE_MAX);
	}
}

// Defile une image.
t_image* t_file_image_defiler(t_file_image* file_image_ptr)
{
	t_image* image_ptr = NULL;
	printf("t_file_image_defiler > ");

	if (t_file_image_est_vide(file_image_ptr))
	{
		// On affiche un message d'erreur
		printf("ERREUR > La file est vide\n");
	}
	else
	{
		// On defile l'image dans le tableau
		image_ptr = file_image_ptr->tab_image[file_image_ptr->i_defiler];
		// On incremente i_defiler et le ramene a 0 une fois a la fin du tableau
		++file_image_ptr->i_defiler %= TAILLE_FILE_IMAGE_MAX;
		// On décrémente la taille
		--file_image_ptr->taille;
		// On affiche un message
		printf("Il reste %i/%i places dans la file\n"
			, TAILLE_FILE_IMAGE_MAX - file_image_ptr->taille
			, TAILLE_FILE_IMAGE_MAX);
	}

	return image_ptr;
}