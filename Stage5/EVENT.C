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

/* Synchronous Events */

void makePlayerFall(struct Model *model)
{
	playerFall(&model->player);
}

void tickTimeDown(struct Model *model)
{
	decreaseTime(&model->timeLeft);
}

/* Asynchronous Events*/

void movePlayer (struct Model *model, char key)
{
	if (key == A_ASCII)
	{
		playerRun(model, left);
	} else if (key == D_ASCII)
	{
		playerRun(model, right);
	} else if (key == SPACE_ASCII)
	{
		playerJump(model);
	}
		
	
}
/* Conditional Events*/

bool isTimer0 (struct Model model)
{
	return model.timeLeft.wholeSecs <= 0;
}

void crystalCollected (struct Model *model)
{
	increaseTime(&model->timeLeft);
	increaseScore(&model->score);
	crystalRandomSpawn(&model->crystal);
}
