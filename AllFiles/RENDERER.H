/*
Names:  	Enrik R
			Kiril S
Module:		Renderer
Purpose: 	The renderer module contains the subroutine and function calls related to the 
			output of current gamestate to the screen. 
Details: 	A model structure is created and initialized to set values from const.h,
			const.c and model.c. The model then gets printed onto the screen via 16x16
			bitmaps.
*/
#include "model.h"
#include "const.h"
#include "raster.h"
#include <osbind.h>

/*
Function: renderPlayer

Input: 		Player: pointer to the player structure controlled by the user.
			base: Pointer to the start of the frame buffer address.
			
Purpose: Print the player bitmap onto the screen.

Details: Passing in the player and the framebuffer, the function
calls the bitmap plot function to display the designated bitmap onto the
screen at the coordinates within the player structure.
*/
void renderPlayer(const struct Player *Player,UINT16 *base);

/*
Function: renderCrystal

Input:		Player: pointer to the crystal structure within the game.
			base: Pointer to the start of the frame buffer address.

Purpose: Print the crystal bitmap onto the screen.

Details: Passing in the crystal and the framebuffer, the function
calls the bitmap plot function to display the designated bitmap onto the
screen at the coordinates within the crystal structure.
*/
void renderCrystal(const struct Crystal *crystal,UINT16 *base);

/*
Function: renderScore

Input: 		score: the score structure in the gamestate.
			base: pointer to the start of the frame buffer address.

Purpose: Print the Score onto the screen.

Details: Passing in the score and the framebuffer, the function
prints SCORE onto the right, upmost corner of the screen. Note that the
actual score will be dealt with at a later date once the player is actually
able to score.
*/
void renderScore(const struct Score *score,UINT16 *base);

/*
Function: renderTimer

Input: 		timeLeft: the timer structure in the gamestate.
			base: pointer to the start of the frame buffer address.

Purpose: Print the Time onto the screen.

Details: Passing in the timer and the framebuffer, the function
prints TIME onto the left, upmost corner of the screen. Note that the
actual time will be dealt with at a later date once the game
is synced to the clock.
*/
void renderTimer(const struct TimeRemaining *timeLeft, UINT16 *base);

/*
Function: renderPlatform
Input: 		platform: array of platforms in the game.
			base: pointer to the start of the frame buffer address.

Purpose: Print all platforms onto the screen.

Details: Passing in the platform and the framebuffer, the function
goes into a for loop that processes every platform within the array
and puts them onto the screen using the drawHorizontal function.
*/
void renderPlatform(const struct Platform platform[],UINT16 *base);

/*
Function: render

Input: 		model: the gamestate and all structures accociated with it.
			base: pointer to the start of the frame buffer address.
	
Purpose: Initialises the gamestate to the starting position.

Details: The function clears the screen before initializing the gamestate to
a starting position. When this has finished, the function then goes on to
output the gamestate to the user, with every substructure within model being
"rendered".
*/
void render(const struct Model *model, UINT16 *base);

void renderMovable(const struct Model *model, UINT16 *base);

/*void wipeMovables(const struct Player *Player,const struct Crystal *crystal,
				  UINT16 *base);*/

void rerenderScore(struct Score *score);

void renderNewScore(int ones,unsigned int x,unsigned int y, UINT16 *base);

void rerenderTimer(struct TimeRemaining *timeLeft);

void renderNewTimer(int digit, unsigned int x, unsigned int y, UINT16 *base);