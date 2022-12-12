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
	// Vérifier que la file est initialise
	if (file_image_ptr == NULL)
	{
		printf("t_file_dynamique_image_enfiler > Erreur de memoire non allocalise (file)\n");
		return EXIT_FAILURE;
	}
	// Vérifier que l'image est initialise
	if (image_ptr == NULL)
	{
		printf("t_file_dynamique_image_enfiler > Erreur de memoire non allocalise (image)\n");
		return EXIT_FAILURE;
	}
	// Initialiser un nouveau noeud
	t_noeud_image* noeud_image_ptr = t_noeud_image_initialiser(image_ptr);
	if (noeud_image_ptr == NULL)
	{
		return EXIT_FAILURE;
	}
	// Trouver le dernier noeud
	t_noeud_image* prochain_noeud_ptr = file_image_ptr->tete;
	while (prochain_noeud_ptr->prochain != NULL)
		prochain_noeud_ptr = prochain_noeud_ptr->prochain;
	// Inserer le nouveau noeud a la fin de la file
	prochain_noeud_ptr->prochain = noeud_image_ptr;
	file_image_ptr->taille++;

	return EXIT_SUCCESS;
}

// Indique si la file est vide ou non.
unsigned char t_file_dynamique_image_est_vide(t_file_dynamique_image* file_image_ptr)
{
	unsigned char file_vide = 1;

	if (file_image_ptr == NULL)
	{
		printf("t_file_dynamique_image_est_vide > Erreur de memoire non allocalise (file)\n");
	}
	else
	{
		file_vide = file_image_ptr->taille == 0;
	}

	return file_vide;
}

// Defile une image dans une file dynamique.
t_image* t_file_dynamique_image_defiler(t_file_dynamique_image* file_image_ptr)
{
	// On verifie que la file est initialise
	if (file_image_ptr == NULL)
	{
		printf("t_file_dynamique_image_defiler > Erreur de memoire non allocalise (file)\n");
		return NULL;
	}
	// On verifie que la file n'est pas vide
	if (t_file_dynamique_image_est_vide(file_image_ptr))
	{
		printf("t_file_dynamique_image_defiler > ERREUR > La file est vide\n");
		return NULL;
	}

	// On prend le premier noeud de la file
	t_noeud_image* noeud_image_ptr = file_image_ptr->tete;
	// On copie l'adresse de l'image du noeud
	t_image* image_ptr = noeud_image_ptr->image;
	// On remplace la tete de la file par le prochain noeud
	file_image_ptr->tete = noeud_image_ptr->prochain;
	// On libere la memoire du noeud
	free(noeud_image_ptr);
	// Decremente la taille
	--file_image_ptr->taille;

	return image_ptr;
}