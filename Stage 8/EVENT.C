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
#include "renderer.h"

bool muted = false;

/* Synchronous Events */

void makePlayerFall(struct Model *model)
{
	playerFall(model);
}

void tickTimeDown(struct Model *model)
{
	decreaseTime(&model->timeLeft);
}

/* Asynchronous Events*/

void movePlayer (struct Model *model, unsigned long key)
{
	if (key == A_KEY)
	{
		model->player.xVelocity = -1 *PLAYER_RUN_SPEED;
	} else if (key == D_KEY)
	{
		model->player.xVelocity = PLAYER_RUN_SPEED;
	} else if (key == SPACE_KEY)
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
	if (collision(model->player.hitbox, model->crystal.hitbox))
	{
		increaseTime(&model->timeLeft);
		increaseScore(&model->score);
		crystalRandomSpawn(&model->crystal);
	}
}