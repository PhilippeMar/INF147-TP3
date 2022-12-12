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
t_image* t_image_initialiser(void);

/*
T_ANIMATION_CHARGER_PILE

	Charge une animation a partir d'un fichier CSV.

 PARAMÈTRES :

	- nom_fichier: Le nom du fichier CSV a lire (type: const unsigned char*).

 VALEUR DE RETOUR :

	- animation_ptr: Une reference vers l'animation chargee (type: t_animation*).
*/
t_animation* t_animation_charger_pile(const char* nom_fichier);

/*
T_ANIMATION_JOUER

	Joue une animation fournie.

 PARAMÈTRES :

	- animation_ptr: Une reference vers l'animation chargee (type: t_animation*).

 VALEUR DE RETOUR :

	- Aucune.
*/
void t_animation_jouer(t_animation* une_animation);

#endif