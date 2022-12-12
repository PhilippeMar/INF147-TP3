/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Decembre 2022

--Description
	Ce fichier permet d'utiliser des pile dynamique d'image

On y retrouve les sous-programmes suivants :
	- t_pile_dynamique_image_initialiser
	- t_pile_dynamique_image_empiler
	- t_pile_dynamique_image_est_vide
	- t_pile_dynamique_image_depiler
*****************************************************************************************/

#include "mod_quiz_3_1.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Initialise une pile dynamique d'images.
t_pile_dynamique_image* t_pile_dynamique_image_initialiser(t_image* image_ptr)
{
	// On allocalise la memoire pour la pile
	t_pile_dynamique_image* pile_image_ptr = (t_pile_dynamique_image*)malloc(sizeof(t_pile_dynamique_image));

	// On verifie que la memoire a ete alloue
	if (pile_image_ptr == NULL)
	{
		printf("t_pile_dynamique_image_initialiser > Erreur d'allocalisation de memoire\n");
		return NULL;
	}

	// On assigne le pointeur du premier noeud et la taille
	if (image_ptr == NULL)
	{
		pile_image_ptr->tete = NULL;
		pile_image_ptr->taille = 0;
	}
	else
	{
		pile_image_ptr->tete = t_noeud_image_initialiser(image_ptr);
		pile_image_ptr->taille = 1;

		// On verifie que le noeud a bien ete initialiser
		if (pile_image_ptr->tete == NULL)
		{
			free(pile_image_ptr);
			return NULL;
		}
	}

	return pile_image_ptr;
}

// Empile une image dans une pile dynamique.
unsigned char t_pile_dynamique_image_empiler(t_pile_dynamique_image* pile_image_ptr, t_image* image_ptr)
{
	// Verifier que la pile est initialise
	if (pile_image_ptr == NULL)
	{
		printf("t_pile_dynamique_image_empiler > Erreur de memoire non allocalise (pile)\n");
		return EXIT_FAILURE;
	}
	// Verifier que l'image est initialise
	if (image_ptr == NULL)
	{
		printf("t_pile_dynamique_image_empiler > Erreur de memoire non allocalise (image)\n");
		return EXIT_FAILURE;
	}
	// Initialiser un nouveau noeud
	t_noeud_image* noeud_image_ptr = t_noeud_image_initialiser(image_ptr);
	if (noeud_image_ptr == NULL)
	{
		return EXIT_FAILURE;
	}
	// Inserer le nouveau noeud au debut de la pile
	noeud_image_ptr->prochain = pile_image_ptr->tete;
	pile_image_ptr->tete = noeud_image_ptr;
	pile_image_ptr->taille++;

	return EXIT_SUCCESS;
}

// Indique si la pile est vide ou non.
unsigned char t_pile_dynamique_image_est_vide(t_pile_dynamique_image* pile_image_ptr)
{
	unsigned char pile_vide = 1;

	if (pile_image_ptr == NULL)
	{
		printf("t_pile_dynamique_image_est_vide > Erreur de memoire non allocalise (pile)\n");
	}
	else
	{
		pile_vide = pile_image_ptr->taille == 0;
	}
	
	return pile_vide;
}

// Depile une image dans une pile dynamique.
t_image* t_pile_dynamique_image_depiler(t_pile_dynamique_image* pile_image_ptr)
{
	// On verifie que la pile est initialise
	if (pile_image_ptr == NULL)
	{
		printf("t_pile_dynamique_image_depiler > Erreur de memoire non allocalise (pile)\n");
		return NULL;
	}
	// On verifie que la pile n'est pas vide
	if (t_pile_dynamique_image_est_vide(pile_image_ptr))
	{
		printf("t_pile_dynamique_image_depiler > ERREUR > La pile est vide\n");
		return NULL;
	}

	// On prend le premier noeud de la pile
	t_noeud_image* noeud_image_ptr = pile_image_ptr->tete;
	// On copie l'adresse de l'image du noeud
	t_image* image_ptr = noeud_image_ptr->image;
	// On remplace la tete de la pile par le prochain noeud
	pile_image_ptr->tete = noeud_image_ptr->prochain;
	// On libere la memoire du noeud
	t_noeud_image_detruire(noeud_image_ptr);
	// Decremente la taille
	--pile_image_ptr->taille;

	return image_ptr;
}