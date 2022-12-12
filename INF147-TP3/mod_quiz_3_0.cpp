/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Decembre 2022

--Description
	Ce fichier permet d'initialiser et detruire des noeud pour liste d'image

On y retrouve les sous-programmes suivants :
	- t_noeud_image_initialiser
	- t_noeud_image_detruire
*****************************************************************************************/

#include "mod_quiz_3_0.h"

#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Initialise un noeud qui contient une reference vers une image et une reference vers un autre noeud.
t_noeud_image* t_noeud_image_initialiser(t_image* image_ptr)
{
	// On allocalise la memoire pour le noeud
	t_noeud_image* noeud_image_ptr = (t_noeud_image*)malloc(sizeof(t_noeud_image));

	// On verifie que la memoire a ete alloue
	if (noeud_image_ptr == NULL)
	{
		printf("t_noeud_image_initialiser > Erreur d'allocation de memoire\n");
		return NULL;
	}

	// On verifie que l'image est initialise
	if (image_ptr == NULL)
	{
		free(noeud_image_ptr);
		printf("t_noeud_image_initialiser > Erreur de memoire non allocalise (image)\n");
		return NULL;
	}

	// On assigne le pointeur d'image à l'image en parametre et le prochain a NULL
	noeud_image_ptr->image = image_ptr;
	noeud_image_ptr->prochain = NULL;

	return noeud_image_ptr;
}

// Libere la memoire allouee a un noeud.
void t_noeud_image_detruire(t_noeud_image* noeud_image_ptr)
{
	// On verifie que le pointeur pointe sur quelque chose
	if (noeud_image_ptr != NULL)
	{
		free(noeud_image_ptr);
	}
}