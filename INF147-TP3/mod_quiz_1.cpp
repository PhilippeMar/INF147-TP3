/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Decembre 2022

--Description
	Ce fichier permet 

On y retrouve les sous-programmes suivants :
	- t_pixel_calculer_norme
	- t_pixel_normaliser
	- t_pixel_permuter
	- t_pixel_afficher
	- t_image_initialiser_aleatoire
	- t_image_normaliser
	- t_image_afficher
*****************************************************************************************/

#include "mod_quiz_1.h"

#include "graphics.h"

#include <math.h>


/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Calcule la norme d'un pixel.
unsigned char t_pixel_calculer_norme(const t_pixel* pixel_ptr)
{
	unsigned char norme = sqrt(pow(pixel_ptr->r, 2) + pow(pixel_ptr->g, 2) + pow(pixel_ptr->b, 2));

	return norme;
}

// Normalise un pixel en divisant les composants par la norme.
void t_pixel_normaliser(t_pixel* pixel_ptr)
{
	unsigned char norme = t_pixel_calculer_norme(pixel_ptr);

	if (norme > 0)	// Pour ne pas diviser par 0
	{
		pixel_ptr->r /= norme;
		pixel_ptr->g /= norme;
		pixel_ptr->b /= norme;
	}
}

// Permute deux pixels en permutant leurs composants.
void t_pixel_permuter(t_pixel* pixel_1_ptr, t_pixel* pixel_2_ptr)
{
	t_pixel pixel_temp = *pixel_1_ptr;
	*pixel_1_ptr = *pixel_2_ptr;
	*pixel_2_ptr = pixel_temp;
}

// Affiche un pixel sur un canevas a une position (x,y) donnee.
void t_pixel_afficher(const unsigned int x,
	const unsigned int y,
	const t_pixel* pixel_ptr)
{
	putpixel(y, x, COLOR(pixel_ptr->r, pixel_ptr->g, pixel_ptr->b));
}

// Initialise une image avec des pixels dont les composants sont choisis de maniere aleatoire.
void t_image_initialiser_aleatoire(t_image* image_ptr)
{
	unsigned int h = 0;
	unsigned int l = 0;
	for (h = 0; h < IMAGE_HAUTEUR; h++)
	{
		for (l = 0; l < IMAGE_LARGEUR; l++)
		{
			image_ptr->pixels[h][l].r = GENERER_PIXEL_ALEATOIRE;
			image_ptr->pixels[h][l].g = GENERER_PIXEL_ALEATOIRE;
			image_ptr->pixels[h][l].b = GENERER_PIXEL_ALEATOIRE;
		}
	}
}

// Normalise les pixels d'une image.
void t_image_normaliser(t_image* image_ptr)
{
	unsigned int h = 0;
	unsigned int l = 0;
	for (h = 0; h < IMAGE_HAUTEUR; h++)
	{
		for (l = 0; l < IMAGE_LARGEUR; l++)
		{
			t_pixel_normaliser(&(image_ptr->pixels[h][l]));
		}
	}
}

// Affiche une image sur un canevas.
void t_image_afficher(const t_image* image_ptr)
{
	unsigned int h = 0;
	unsigned int l = 0;
	for (h = 0; h < IMAGE_HAUTEUR; h++)
	{
		for (l = 0; l < IMAGE_LARGEUR; l++)
		{
			t_pixel_afficher(h, l, &(image_ptr->pixels[h][l]));
		}
	}
}