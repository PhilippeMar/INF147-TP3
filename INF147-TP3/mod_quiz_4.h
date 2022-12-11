#ifndef _MOD_QUIZ_4
#define _MOD_QUIZ_4

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

#include "mod_quiz_3_1.h"

/* Taille maximale d'une ligne lue lors du chargement d'une image */
#define TAILLE_LIGNE_MAX 1024

/* Les trois couleurs primaires d'une image */
#define ROUGE 0
#define VERT  1
#define BLEU  2

/* Type structure qui represente une animation base sur une pile */
typedef t_pile_dynamique_image t_animation;

/*
T_IMAGE_INITIALISER

	Initialise une image dynamique.

 PARAMÈTRES :

	- Aucuns.

 VALEUR DE RETOUR :

	- image_ptr: Une reference vers l'image depilee (type: t_image*).
*/
t_image* t_image_initialiser(void)
{
	t_image* image_ptr = (t_image*)malloc(sizeof(t_image));

	if (image_ptr == NULL)
	{
		printf("t_image_initialiser > Erreur d'allocation de memoire\n");
		return NULL;
	}
	else
	{
		return image_ptr;
	}
}

/*
T_ANIMATION_CHARGER_PILE

	Charge une animation a partir d'un fichier CSV.

 PARAMÈTRES :

	- nom_fichier: Le nom du fichier CSV a lire (type: const unsigned char*).

 VALEUR DE RETOUR :

	- animation_ptr: Une reference vers l'animation chargee (type: t_animation*).
*/
t_animation* t_animation_charger_pile(const char* nom_fichier)
{
	FILE *mon_fichier;

	mon_fichier = fopen("INF147_A2022_TP3_GIF.csv", "r");
	if (mon_fichier == NULL)
	{
		printf("t_animation_charger > ERREUR > Impossible d'ouvrir le fichier\n");
		return NULL;
	}
	t_image* image_ptr = (t_image*)malloc(TAILLE_LIGNE_MAX * sizeof(t_image));
	if (image_ptr == NULL)
	{
		printf("t_animation_charger > ERREUR > L'initialisation de l'image a echoue\n");
		return NULL;
	}
	t_animation* animation_ptr = (t_animation*)malloc(sizeof(t_animation));
	if (animation_ptr == NULL)
	{
		printf("t_animation_charger > ERREUR > L'initialisation de l'animation a echoue\n");
		return NULL;
	}
	char ligne_lu[TAILLE_LIGNE_MAX];
	while (fgets(ligne_lu, TAILLE_LIGNE_MAX, mon_fichier) != NULL)
	{
		strncpy((char*)image_ptr, ligne_lu, TAILLE_LIGNE_MAX);
		;
	}
	
	
	if (true)
	{
		free(image_ptr);
	}
	else
	{
		printf("t_animation_charger > ERREUR > La reinitialisation de l'image a echoue\n");
	}
	
	fclose(mon_fichier);
	return animation_ptr;
}

/*
T_ANIMATION_JOUER

	Joue une animation fournie.

 PARAMÈTRES :

	- animation_ptr: Une reference vers l'animation chargee (type: t_animation*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_animation_jouer(t_animation* une_animation)
{
	if (une_animation == NULL)
	{
		EXIT_FAILURE;
	}
	else
	{
		initwindow(IMAGE_LARGEUR, IMAGE_HAUTEUR);
		while (une_animation != NULL)
		{
			t_pile_dynamique_image_depiler(une_animation);
			t_image_afficher(une_animation->tete->image);
		}
	}
}

#endif
