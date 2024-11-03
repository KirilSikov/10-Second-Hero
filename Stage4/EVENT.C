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

#include "model.h"
#include "event.h"

/* Synchronous Events 

  need to figure out the clock bullshit
void tickTimeDown(struct Model *model)
{
	decreaseTime(model->timeLeft);
}*/

/* Asynchronous Events*/
/* implement later
void movePlayer ()
{
	/*long key_pressed = Cnecin(); */
	
	
/*	
}

void jumpKeyPressed ()
{
	
	
}
*/

/* Conditional Events*/

bool isTimer0 (struct Model model)
{
	return model.timeLeft.wholeSecs <= 0;
}

void crystalCollected (struct Model *model)
{
	increaseTime(&model->timeLeft);
	increaseScore(&model->score);
	moveCrystal(&model->crystal, 210, 290);
}
