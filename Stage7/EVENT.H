/*
Names:  	Enrik R
			Kiril S

Module:		Event

Purpose: 	The event module contains the functions related to handling events
			in the game.

Details: 	Event handlers affect the game based on synchronous, asynchronous, or 
			conditional events that occur, such as the pressing of keys requesting
			the player to move a specific direction, or the collection of a crystal.
*/
#ifndef EVENT_H
#define EVENT_H

#include <stdio.h>
#include <osbind.h>
#include "const.h"

/* Synchronous Events */

/*
Function: makePlayerFall

Input: 		model: pointer to the model containing the ingame structures.
			
Purpose: make the player fall.

Details: behaves as the gravity of the game, affecting the player. If the
player is airborne at any point, this function, aka gravity, will be utilized
in order to make him fall back down to the ground/a platform.
*/
void makePlayerFall(struct Model *model);

/*
Function: tickTimeDown

Input: 		model: pointer to the model containing the ingame structures.
			
Purpose: make the ingame time tick down by a second.

Details: will be called to decrement the in game timer once a second's
worth of game ticks have passed.
*/
void tickTimeDown(struct Model *model);


/* Asynchronous Events*/

/*
Function: movePlayer

Input: 		model: pointer to the model containing the ingame structures.
			
Purpose: make the player move based on user's key presses.

Details: depending on what keys the user pressed, the player will run left
or right if A or D are pressed, respectively, and the player will jump if
the user presses the space bar.
*/
void movePlayer (struct Model *model, unsigned long key);


/* Conditional Events*/

/*
Function: isTimer0

Input: 		model: value of the model containing the ingame structures.
			
Purpose: returns if the in game timer is 0 seconds (or lower)

Details: this function will be continuously called in order to check if
the in game timer has reached 0, which is the end condition for the game.
*/
bool isTimer0 (struct Model model);

/*
Function: crystalCollected

Input: 		model: pointer to the model containing the ingame structures.
			
Purpose: handles the collection of a crystal in the game

Details: once a crystal is collected, the time and score are increased,
and the crystal is respawned in a different, random location.
*/
void crystalCollected (struct Model *model);




#endif