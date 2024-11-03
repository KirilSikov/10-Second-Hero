/*
Names:  	Enrik R
			Kiril S

Module:		Event

Purpose: 	The event module contains the functions related to handling events
			in the game.

Details: 	Event handlers affect the game based on the synchronous asynchronous
			or conditional events that occur, such as the pressing of keys
			requesting the player to move a specific direction, or the
			collection of a crystal.
*/

#ifndef EVENT_H
#define EVENT_H

#include <stdio.h>
#include <osbind.h>
#include "const.h"

/* Synchronous Events */
/* do this in stage 5

player always "falling" since gravity always exists
void makePlayerFall(struct Model *model);

time always ticking down
void tickTimeDown(struct Model *model);
*/

/* Asynchronous Events*/

/*
void moveKeyPressed ();

*/

/* Conditional Events*/

bool isTimer0 (struct Model model);

void crystalCollected (struct Model *model);





#endif