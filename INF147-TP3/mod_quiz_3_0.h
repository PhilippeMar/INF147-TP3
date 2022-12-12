#ifndef _MOD_QUIZ_3_0_
#define _MOD_QUIZ_3_0_

#include "mod_quiz_1.h"

/* Type structure qui represente un noeud d'une liste chainee simple d'images */
typedef struct t_noeud_image
{
	t_image* image;
	t_noeud_image* prochain;
} t_noeud_image;

/* Type structure qui represente une liste chainee d'images */
typedef struct t_liste_image
{
	t_noeud_image* tete;
	unsigned int taille;
} t_liste_image;

/*
T_NOEUD_IMAGE_INITIALISER

	Initialise un noeud qui contient une reference vers une image et une reference vers un autre noeud.

 PARAMÈTRES :

	- image_ptr: Une reference vers un image (type: t_image*).

 VALEUR DE RETOUR :

	- noeud_image_ptr: Une reference vers un noeud (type: t_noeud_image*).
*/
t_noeud_image* t_noeud_image_initialiser(t_image* image_ptr);

/*
T_NOEUD_IMAGE_DETRUIRE

	Libere la memoire allouee a un noeud.

 PARAMÈTRES :

	- noeud_image_ptr: Une reference vers un noeud (type: t_noeud_image*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_noeud_image_detruire(t_noeud_image* noeud_image_ptr);

#endif 