#ifndef _MOD_QUIZ_3_1_
#define _MOD_QUIZ_3_1_

#include "mod_quiz_3_0.h"

/* Type structure qui represente une pile dynamique d'images */
typedef t_liste_image t_pile_dynamique_image;

/*
T_PILE_DYNAMIQUE_IMAGE_INITIALISER

	Initialise une pile dynamique d'images.

 PARAMÈTRES :

	- image_ptr: Une reference vers un image (type: t_image*).

 VALEUR DE RETOUR :

	- pile_image_ptr: Une reference vers la pile (type: t_pile_dynamique_image*).
*/
t_pile_dynamique_image* t_pile_dynamique_image_initialiser(t_image* image_ptr)
{
	t_pile_dynamique_image* pile_image_ptr = (t_pile_dynamique_image*)malloc(sizeof(t_pile_dynamique_image));

	if (pile_image_ptr == NULL)
	{
		printf("t_pile_dynamique_image_initialiser > Erreur d'allocation de memoire");
		return NULL;
	}
	else
	{
		if (image_ptr == NULL)
		{
			pile_image_ptr->taille = 0;
			pile_image_ptr->tete = NULL;
			return pile_image_ptr;
		}
		else
		{
			pile_image_ptr->tete = t_noeud_image_initialiser(image_ptr);
			if (pile_image_ptr->tete == NULL)
			{
				free(pile_image_ptr);
				return NULL;
			}
			else
			{
				pile_image_ptr->taille = 1;
				return pile_image_ptr;
			}
		}
	}
}

/*
T_PILE_DYNAMIQUE_IMAGE_EMPILER

	Empile une image dans une pile dynamique.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers la pile (type: t_pile_dynamique_image*).
	- image_ptr: Une reference vers l'image a empiler (type: t_image*).

 VALEUR DE RETOUR :

	- est_succes: Un indicateur de succes/echec (type: unsigned char).
*/
unsigned char t_pile_dynamique_image_empiler(t_pile_dynamique_image* pile_image_ptr, t_image* image_ptr)
{
	t_noeud_image* nouveau_noeud = (t_noeud_image*)malloc(sizeof(t_noeud_image));
	
	nouveau_noeud = t_noeud_image_initialiser(image_ptr);

	if (nouveau_noeud == NULL)
	{
		return EXIT_FAILURE;
	}
	else
	{
		nouveau_noeud->prochain = pile_image_ptr->tete;
		pile_image_ptr->tete = nouveau_noeud;
		pile_image_ptr->taille++;

		return EXIT_SUCCESS;
	}
}

/*
T_PILE_DYNAMIQUE_IMAGE_EST_VIDE

	Indique si la pile est vide ou non.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers la pile (type: t_pile_dynamique_image*).

 VALEUR DE RETOUR :

	- est_vide: Un indicateur de vide (type: unsigned char).
*/
unsigned char t_pile_dynamique_image_est_vide(t_pile_dynamique_image* pile_image_ptr)
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
T_PILE_DYNAMIQUE_IMAGE_DEPILER

	Depile une image dans une pile dynamique.

 PARAMÈTRES :

	- pile_image_ptr: Une reference vers la pile (type: t_pile_dynamique_image*).

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image depilee (type: t_image*).
*/
t_image* t_pile_dynamique_image_depiler(t_pile_dynamique_image* pile_image_ptr)
{
	if (pile_image_ptr->taille == 0)
	{
		printf("t_pile_dynamique_image_depiler > ERREUR > La pile est vide\n");
	}
	else
	{
		t_image* image_ptr = (t_image*)malloc(sizeof(t_image));
		t_noeud_image* noeud_depiler = (t_noeud_image*)malloc(sizeof(t_noeud_image));

		noeud_depiler = pile_image_ptr->tete;

		image_ptr = noeud_depiler->image;
		pile_image_ptr->tete = noeud_depiler->prochain;

		t_noeud_image_detruire(noeud_depiler);
		pile_image_ptr->taille--;
		return image_ptr;
	}
}

#endif