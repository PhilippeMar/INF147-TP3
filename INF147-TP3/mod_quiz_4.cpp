/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Decembre 2022

--Description
	Ce fichier permet 

On y retrouve les sous-programmes suivants :
	- 
*****************************************************************************************/

#include "mod_quiz_4.h"

#include <stdio.h>


/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Initialise une image dynamique.
t_image* t_image_initialiser(void)
{
	t_image* image_ptr = (t_image*)malloc(sizeof(t_image));

	if (image_ptr == NULL)
	{
		printf("t_image_initialiser > Erreur d'allocation de memoire\n");
		return NULL;
	}

	return image_ptr;
}

// Charge une animation a partir d'un fichier CSV.
t_animation* t_animation_charger_pile(const char* nom_fichier)
{
	// Ouverture du fichier d'animation
	FILE* fichier_animation;
	fichier_animation = fopen(nom_fichier, "r");
	// On verifie que le fichier a bien ete ouvert
	if (fichier_animation == NULL)
	{
		printf("t_animation_charger_pile > ERREUR > Impossible d'ouvrir le fichier\n");
		return NULL;
	}

	// On initialise une image
	t_image* image_ptr = t_image_initialiser();
	// On verifie que l'image c'est bien initialise
	if (image_ptr == NULL)
	{
		printf("t_animation_charger_pile > ERREUR > L'initialisation de l'image a echoue\n");
		return NULL;
	}

	// On initialise une animation
	t_animation* animation_ptr = t_pile_dynamique_image_initialiser(NULL);
	// On verifie que l'animation c'est bien initialise
	if (animation_ptr == NULL)
	{
		printf("t_animation_charger_pile > ERREUR > L'initialisation de l'animation a echoue\n");
		return NULL;
	}

	// Extraire l'image du fichier
	char* ligne = (char*)malloc(sizeof(char) * TAILLE_LIGNE_MAX);
	if (ligne == NULL)
	{
		printf("t_animation_charger_pile > Erreur d'allocation de memoire\n");
		return NULL;
	}
	unsigned int x = 0, y = 0;
	unsigned char couleur = ROUGE;
	while (fgets(ligne, TAILLE_LIGNE_MAX, fichier_animation) != NULL)
	{
		char* token = strtok(ligne, ",");
		while(token != NULL)
		{
			switch (couleur)
			{
			case ROUGE:
				image_ptr->pixels[y][x].r = atoi(token);
				break;
			case VERT:
				image_ptr->pixels[y][x].g = atoi(token);
				break;
			case BLEU:
				image_ptr->pixels[y][x].b = atoi(token);
				break;
			default:
				break;
			}

			++x;

			token = strtok(NULL, ",");
		}

		x = 0;
		if (++y >= 286)
		{
			y = 0;
			if (++couleur > BLEU)
			{
				couleur = ROUGE;
				// On empile l'image dans l'animation
				t_pile_dynamique_image_empiler(animation_ptr, image_ptr);
				// On initialise une image
				image_ptr = t_image_initialiser();
				// On verifie que l'image c'est bien initialise
				if (image_ptr == NULL)
				{
					printf("t_animation_charger_pile > ERREUR > L'initialisation de l'image a echoue\n");
					return NULL;
				}
			}

		}
	}
	free(ligne);
	fclose(fichier_animation);

	return animation_ptr;
}

// Joue une animation fournie.
void t_animation_jouer(t_animation* une_animation)
{
	// On verifie que l'animation est initialise
	if(une_animation == NULL)
	{
		printf("t_animation_jouer > ERREUR > Animation non initialise\n");
		return;
	}

	initwindow(IMAGE_LARGEUR, IMAGE_HAUTEUR);

	while (!t_pile_dynamique_image_est_vide(une_animation))
	{
		// Afficher l'image sur le dessus de la pile
		t_image* image_ptr = t_pile_dynamique_image_depiler(une_animation);
		t_image_afficher(image_ptr);
		// On libere la memoire
		free(image_ptr);
	}
}