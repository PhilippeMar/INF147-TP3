/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Decembre 2022

--Description
	Ce fichier permet  d'utiliser des file dynamique d'image

On y retrouve les sous-programmes suivants :
	- t_file_dynamique_image_initialiser
	- t_file_dynamique_image_enfiler
	- t_file_dynamique_image_est_vide
	- t_file_dynamique_image_defiler
*****************************************************************************************/

#include "mod_quiz_3_2.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Initialise une file dynamique d'images.
t_file_dynamique_image* t_file_dynamique_image_initialiser(t_image* image_ptr)
{
	// On allocalise la memoire pour la file
	t_file_dynamique_image* file_image_ptr = (t_file_dynamique_image*)malloc(sizeof(t_file_dynamique_image));

	// On verifie que la memoire a ete alloue
	if (file_image_ptr == NULL)
	{
		printf("t_file_dynamique_image_initialiser > Erreur d'allocalisation de memoire\n");
		return NULL;
	}

	// On assigne le pointeur du premier noeud et la taille
	if (image_ptr == NULL)
	{
		file_image_ptr->tete = NULL;
		file_image_ptr->taille = 0;
	}
	else
	{
		file_image_ptr->tete = t_noeud_image_initialiser(image_ptr);
		file_image_ptr->taille = 1;

		// On verifie que le noeud a bien ete initialiser
		if (file_image_ptr->tete == NULL)
		{
			free(file_image_ptr);
			return NULL;
		}
	}

	return file_image_ptr;
}

// Enfile une image dans une file dynamique.
unsigned char t_file_dynamique_image_enfiler(t_file_dynamique_image* file_image_ptr, t_image* image_ptr)
{
	return EXIT_FAILURE;
}

// Indique si la file est vide ou non.
unsigned char t_file_dynamique_image_est_vide(t_file_dynamique_image* file_image_ptr)
{
	return 1;
}

// Defile une image dans une file dynamique.
t_image* t_file_dynamique_image_defiler(t_file_dynamique_image* file_image_ptr)
{
	return NULL;
}