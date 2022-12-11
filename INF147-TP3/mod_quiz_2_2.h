#ifndef _MOD_QUIZ_2_2_
#define _MOD_QUIZ_2_2_

#include "mod_quiz_1.h"

/* Taille maximale d'une pile d'images */
#define TAILLE_FILE_IMAGE_MAX 2

/* Type structure qui represente une pile de image */
typedef struct
{
	t_image* tab_image[TAILLE_FILE_IMAGE_MAX];
	unsigned char taille;
	unsigned char i_defiler;
	unsigned char i_enfiler;
} t_file_image;

/*
T_FILE_IMAGE_INITIALISER

	Initialise une File d'images.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_file_image_initialiser(t_file_image* file_image_ptr)
{
	file_image_ptr->taille = 0;
	file_image_ptr->i_defiler = 0;
	file_image_ptr->i_enfiler = 0;
}

/*
T_FILE_IMAGE_EST_VIDE

	Indique si la file est vide ou non.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).

 VALEUR DE RETOUR :

	- est_vide: Indicateur de vide (type: unsigned char).
*/
unsigned char t_file_image_est_vide(t_file_image* file_image_ptr)
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
T_FILE_IMAGE_EST_PLEINE

	Indique si la file est pleine ou non.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).

 VALEUR DE RETOUR :

	- est_pleine: Indicateur de plein (type: unsigned char).
*/
unsigned char t_file_image_est_pleine(t_file_image* file_image_ptr)
{
	unsigned char est_pleine;

	if (file_image_ptr->taille == TAILLE_FILE_IMAGE_MAX)
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
T_FILE_IMAGE_ENFILER

	Enfile une image.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).
	- image_ptr: Une reference vers une image a empiler (type: t_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_file_image_enfiler(t_file_image* file_image_ptr, t_image* image_ptr)
{
	if (t_file_image_est_pleine(file_image_ptr))
	{
		printf("t_file_image_emfiler > ERREUR > La file est pleine\n");
	}
	else
	{
		file_image_ptr->tab_image[file_image_ptr->i_enfiler] = image_ptr;
		file_image_ptr->taille++;
		file_image_ptr->i_enfiler = file_image_ptr->taille % TAILLE_FILE_IMAGE_MAX;
		
		printf("t_file_image_emfiler > Il reste %d/%d places dans la file\n", TAILLE_FILE_IMAGE_MAX - file_image_ptr->taille, TAILLE_FILE_IMAGE_MAX);
	}
}

/*
T_FILE_IMAGE_DEFILER

	Defile une image.

 PARAMÈTRES :

	- file_image_ptr: Une reference vers une file d'images (type: t_file_image*).

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image defilee (type: t_image*).
*/
t_image* t_file_image_defiler(t_file_image* file_image_ptr)
{
	t_image* image_ptr = 0;

	if (t_file_image_est_vide(file_image_ptr))
	{
		printf("t_file_image_defiler > ERREUR > La file est vide\n");
	}
	else
	{
		image_ptr = file_image_ptr->tab_image[file_image_ptr->i_defiler];
		file_image_ptr->taille--;
		file_image_ptr->i_defiler = file_image_ptr->taille % TAILLE_FILE_IMAGE_MAX;
		printf("t_file_image_defiler > Il reste %d/%d places dans la file\n", TAILLE_FILE_IMAGE_MAX - file_image_ptr->taille, TAILLE_FILE_IMAGE_MAX);
	}

	return image_ptr;
}

#endif