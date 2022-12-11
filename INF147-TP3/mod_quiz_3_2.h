#ifndef _MOD_QUIZ_3_2_
#define _MOD_QUIZ_3_2_

#include "mod_quiz_3_0.h"

/* Type structure qui represente une file dynamique d'images */
typedef t_liste_image t_file_dynamique_image;

/*
T_FILE_DYNAMIQUE_IMAGE_INITIALISER

	Initialise une file dynamique d'images.

 PARAMÈTRES :

	- image_ptr: Une reference vers un image (type: t_image*).

 VALEUR DE RETOUR :

	- file_image_ptr: Une reference vers la file (type: t_file_dynamique_image*).
*/
t_file_dynamique_image* t_file_dynamique_image_initialiser(t_image* image_ptr)
{
	t_file_dynamique_image* file_image_ptr = (t_file_dynamique_image*)malloc(sizeof(t_file_dynamique_image));

	if (file_image_ptr == NULL)
	{
		printf("t_file_dynamique_image_initialiser > Erreur d'allocation de memoire");
		return NULL;
	}
	else
	{
		if (image_ptr == NULL)
		{
			file_image_ptr->taille = 0;
			file_image_ptr->tete = NULL;
			return file_image_ptr;
		}
		else
		{
			file_image_ptr->tete = t_noeud_image_initialiser(image_ptr);
			if (file_image_ptr->tete == NULL)
			{
				free(file_image_ptr);
				return NULL;
			}
			else
			{
				file_image_ptr->taille = 1;
				return file_image_ptr;
			}
		}
	}
}

/*
T_FILE_DYNAMIQUE_IMAGE_ENFILER

	Enfile une image dans une file dynamique.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers la file (type: t_file_dynamique_image*).
	- image_ptr: Une reference vers l'image a enfiler (type: t_image*).

 VALEUR DE RETOUR :

	- est_succes: Un indicateur de succes/echec (type: unsigned char).
*/
unsigned char t_file_dynamique_image_enfiler(t_file_dynamique_image* file_image_ptr, t_image* image_ptr)
{
	t_noeud_image* nouveau_noeud = (t_noeud_image*)malloc(sizeof(t_noeud_image));
	t_file_dynamique_image* fin_file = (t_file_dynamique_image*)malloc(sizeof(t_file_dynamique_image));

	nouveau_noeud = t_noeud_image_initialiser(image_ptr);

	if (nouveau_noeud == NULL)
	{
		return EXIT_FAILURE;
	}
	else
	{
		//nouveau_noeud->prochain = file_image_ptr->tete;
		//file_image_ptr->tete = nouveau_noeud;
		//file_image_ptr->taille++;
		
		fin_file->tete = file_image_ptr->tete;
		int i = fin_file->taille;
		for (i; i>0;i--)
		{
			file_image_ptr->tete = file_image_ptr->tete->prochain;
		}
		file_image_ptr->tete->prochain = nouveau_noeud;
		file_image_ptr->tete = fin_file->tete;
		file_image_ptr->taille++;

		return EXIT_SUCCESS;
	}
}

/*
T_FILE_DYNAMIQUE_IMAGE_EST_VIDE

	Indique si la file est vide ou non.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers la file (type: t_file_dynamique_image*).

 VALEUR DE RETOUR :

	- est_vide: Un indicateur de vide (type: unsigned char).
*/
unsigned char t_file_dynamique_image_est_vide(t_file_dynamique_image* file_image_ptr)
{
	unsigned char est_vide;

	if (file_image_ptr->taille == 0)
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
T_FILE_DYNAMIQUE_IMAGE_DEFILER

	Defile une image dans une file dynamique.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers la file (type: t_file_dynamique_image*).

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image defilee (type: t_image*).
*/
t_image* t_file_dynamique_image_defiler(t_file_dynamique_image* file_image_ptr)
{
	if (file_image_ptr->taille == 0)
	{
		printf("t_file_dynamique_image_defiler > ERREUR > La file est vide\n");
	}
	else
	{
		t_image* image_ptr = (t_image*)malloc(sizeof(t_image));
		t_noeud_image* noeud_defiler = (t_noeud_image*)malloc(sizeof(t_noeud_image));

		noeud_defiler = file_image_ptr->tete;
		image_ptr = noeud_defiler->image;
		file_image_ptr->tete = noeud_defiler->prochain;

		t_noeud_image_detruire(noeud_defiler);
		file_image_ptr->taille--;
		return image_ptr;
	}
}

#endif