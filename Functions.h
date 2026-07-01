#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

//returns a random number between min and max
int randomNumber(int min, int max);

//opens and initializes the allegro graphics screen (written by Mr. Creelman)
int initializeAllegro(int width, int height, const char title[]);

#endif // FUNCTION_H
