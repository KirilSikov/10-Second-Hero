/*
Names:  	Enrik R
			Kiril S

Module:		Model 

Purpose: 	The model module contains the structs and functions related to the 
			model of the game, and the functions that directly impact the model. 

Details: 	The model is not responsible for handling events, whether they be
			synchronous, asychronous, or conditional. The model handles the
			behaviours or actions that result from those events occuring.
			Ex: Space bar is pressed (event) = player jumps (action)
*/
#include <stdio.h>
#include <osbind.h>
#include "model.h"
#include "event.h"

int calcRand(){
	srand((unsigned)time(NULL));
	
	return rand() % (MAX_RAND + 1 - MIN_RAND) + MIN_RAND;
}

void crystalRandomSpawn(struct Crystal *crystal)
{
	int randomNum = calcRand();
	switch(randomNum)
	{
		case 0:
			crystal->x = CRYSTAL_RAND_X0;
			crystal->y = CRYSTAL_RAND_Y0;
			crystal->hitbox.topLeftX = CRYSTAL_RAND_X0;
			crystal->hitbox.topLeftY = CRYSTAL_RAND_Y0;
			crystal->hitbox.bottomRightX = CRYSTAL_RAND_X0 + SPRITE_SIZE;
			crystal->hitbox.bottomRightY = CRYSTAL_RAND_Y0 + SPRITE_SIZE;
			
			break;

		case 1:
			crystal->x = CRYSTAL_RAND_X1;
			crystal->y = CRYSTAL_RAND_Y1;
			crystal->hitbox.topLeftX = CRYSTAL_RAND_X1;
			crystal->hitbox.topLeftY = CRYSTAL_RAND_Y1;
			crystal->hitbox.bottomRightX = CRYSTAL_RAND_X1 + SPRITE_SIZE;
			crystal->hitbox.bottomRightY = CRYSTAL_RAND_Y1 + SPRITE_SIZE;
			break;

		case 2:
			crystal->x = CRYSTAL_RAND_X2;
			crystal->y = CRYSTAL_RAND_Y2;
			crystal->hitbox.topLeftX = CRYSTAL_RAND_X2;
			crystal->hitbox.topLeftY = CRYSTAL_RAND_Y2;
			crystal->hitbox.bottomRightX = CRYSTAL_RAND_X2 + SPRITE_SIZE;
			crystal->hitbox.bottomRightY = CRYSTAL_RAND_Y2 + SPRITE_SIZE;
			break;

		case 3:
			crystal->x = CRYSTAL_RAND_X3;
			crystal->y = CRYSTAL_RAND_Y3;
			crystal->hitbox.topLeftX = CRYSTAL_RAND_X3;
			crystal->hitbox.topLeftY = CRYSTAL_RAND_Y3;
			crystal->hitbox.bottomRightX = CRYSTAL_RAND_X3 + SPRITE_SIZE;
			crystal->hitbox.bottomRightY = CRYSTAL_RAND_Y3 + SPRITE_SIZE;
			break;

		case 4:
			crystal->x = CRYSTAL_RAND_X4;
			crystal->y = CRYSTAL_RAND_Y4;
			crystal->hitbox.topLeftX = CRYSTAL_RAND_X4;
			crystal->hitbox.topLeftY = CRYSTAL_RAND_Y4;
			crystal->hitbox.bottomRightX = CRYSTAL_RAND_X4 + SPRITE_SIZE;
			crystal->hitbox.bottomRightY = CRYSTAL_RAND_Y4 + SPRITE_SIZE;
			break;

		case 5:
			crystal->x = CRYSTAL_RAND_X5;
			crystal->y = CRYSTAL_RAND_Y5;
			crystal->hitbox.topLeftX = CRYSTAL_RAND_X5;
			crystal->hitbox.topLeftY = CRYSTAL_RAND_Y5;
			crystal->hitbox.bottomRightX = CRYSTAL_RAND_X5 + SPRITE_SIZE;
			crystal->hitbox.bottomRightY = CRYSTAL_RAND_Y5 + SPRITE_SIZE;
			break;

		case 6:
			crystal->x = CRYSTAL_RAND_X6;
			crystal->y = CRYSTAL_RAND_Y6;
			crystal->hitbox.topLeftX = CRYSTAL_RAND_X6;
			crystal->hitbox.topLeftY = CRYSTAL_RAND_Y6;
			crystal->hitbox.bottomRightX = CRYSTAL_RAND_X6 + SPRITE_SIZE;
			crystal->hitbox.bottomRightY = CRYSTAL_RAND_Y6 + SPRITE_SIZE;
			break;

		default:
			break;
	}
}

void playerFall (struct Model *model)
{
	int platformNum = -1;
	
	model->player.y += model->player.yVelocity;
	model->player.hitbox.topLeftY += model->player.yVelocity;
	model->player.hitbox.bottomRightY += model->player.yVelocity;
	if (airborneCheck(*model))
	{
		platformNum = platformCollisionsCheck(*model);
		
		if (platformNum != -1 && collideBottomOfPlatform(model->player.hitbox,
			model->platforms[platformNum].hitbox))
		{ /*snap player's position below the bottom of the
			platform so they aren't inside the platform*/
			model->player.y =
			model->platforms[platformNum].hitbox.bottomRightY + 1;
			model->player.hitbox.topLeftY =
			model->player.y;
			model->player.hitbox.bottomRightY =
			model->player.y + SPRITE_SIZE;
			model->player.yVelocity = 0;
		}
		else /* gravity pushes player down faster, up to 5 pixels/s */
		{
			if (model->player.yVelocity < PLAYER_MAX_FALL_SPEED)
			{
				model->player.yVelocity++;
			}
		}
	} else /* if not airborne, snap player ontop of platform
			  so he isn't inside platform, then make velocity 0*/
	{
		platformNum = platformCollisionsCheck(*model);
		
		model->player.y = model->platforms[platformNum].y - SPRITE_SIZE;
		model->player.hitbox.topLeftY = model->player.y;
		model->player.hitbox.bottomRightY =
		model->platforms[platformNum].y;
		model->player.yVelocity = 0;	
		model->player.hitbox.bottomRightY;
	}
}

void playerJump (struct Model *model)
{
	if (!airborneCheck(*model))
	{
		printf("player jumped\n");
		model->player.yVelocity = PLAYER_JUMP_SPEED;
	}
}


void playerRun(struct Player *playChar)
{
	playChar->x += playChar->xVelocity;
	playChar->hitbox.topLeftX = playChar->x;
	playChar->hitbox.bottomRightX = playChar->x + SPRITE_SIZE;
}

void moveCrystal(struct Crystal *crystal, unsigned int x, unsigned int y)
{
	crystal->x = x;
	crystal->y = y;
	crystal->hitbox.topLeftX = x;
	crystal->hitbox.topLeftY = y;
	crystal->hitbox.bottomRightX = x + SPRITE_SIZE;
	crystal->hitbox.bottomRightY = y + SPRITE_SIZE;
}

void increaseScore(struct Score *score)
{
	score->scoreAmnt += SCORE_ADD;
	
	/*TODO: add function to update to screen at later stage.*/
}

void decreaseTime(struct TimeRemaining *timeLeft)
{
	/*
	if (timeLeft->ticks < fps)
	{
		timeLeft->ticks += 1;
	}
	else
	{
		timeLeft->wholeSecs -= 1;
		timeLeft->ticks = 0;
	}
	This implementation sucks, will have to be revisited later.
	Probably in stage 5 is when we handle this, not here.*/
	timeLeft->wholeSecs -= TIME_SUB;
}

void increaseTime(struct TimeRemaining *timeLeft)
{
	if (timeLeft->wholeSecs <= 7)
	{
		timeLeft->wholeSecs += TIME_ADD;
	}
	else
	{
		timeLeft->wholeSecs = TIMER_SECS;
	}
}

bool collision(struct Hitbox box1, struct Hitbox box2)
{
	return(
    box1.topLeftX <= box2.bottomRightX && /*box 1 collides with right of platform */
    box1.bottomRightX >= box2.topLeftX && /*box 1 collides with left of platform */
    box1.topLeftY <= box2.bottomRightY && /*box 1 collides with bottom of platform */
    box1.bottomRightY >= box2.topLeftY);  /*box 1 collides with top of platform */
}

bool collideRightOfPlatform(struct Hitbox box1, struct Hitbox box2)
{
	return
	(box1.topLeftX <= box2.bottomRightX &&
	box1.topLeftX > box2.topLeftX);
}

bool collideLeftOfPlatform(struct Hitbox box1, struct Hitbox box2)
{
	return
	(box1.bottomRightX >= box2.topLeftX &&
	box1.bottomRightX < box2.bottomRightX);
}

bool collideBottomOfPlatform(struct Hitbox box1, struct Hitbox box2)
{
	return
	(box1.topLeftY <= box2.bottomRightY &&
	box1.topLeftY > box2.topLeftY);
}

bool collideTopOfPlatform(struct Hitbox box1, struct Hitbox box2)
{
	return
	(box1.bottomRightY >= box2.topLeftY &&
	box1.bottomRightY < box2.bottomRightY);
}

int platformCollisionsCheck(struct Model model) 
{
	int collidedPlatform = -1;
	bool collided = false;
	int i;
	for (i = 0; i < PLATFORM_AMNT; i++) 
	{
		collided = collision(model.player.hitbox, model.platforms[i].hitbox);
		if (collided)
		{
			collidedPlatform = i;
		}
	}
	return collidedPlatform;
}

bool airborneCheck (struct Model model)
{
	int platformNum = -1;
	int inAirOrNo = true;
	bool collidedTop = false;
	platformNum = platformCollisionsCheck(model);
	
	if (platformNum != -1)
	{
		if (collideTopOfPlatform(model.player.hitbox,
		model.platforms[platformNum].hitbox))
		{
			inAirOrNo = false;	
		}
	}
	
	return inAirOrNo;
}

/* INITIALIZERS */
void initPlatform(struct Platform *platform, unsigned int x,
	unsigned int y, unsigned int length)
{
	platform->x = x;
	platform->y = y;
	platform->length = length;
	platform->hitbox.topLeftX = x;
	platform->hitbox.topLeftY = y;
	platform->hitbox.bottomRightX = x + (SPRITE_SIZE * length);
	platform->hitbox.bottomRightY = y + SPRITE_SIZE;
}

void initPlayer(struct Player *playChar)
{
	playChar->x = PLAYER_X;
	playChar->y = PLAYER_Y;
	playChar->xVelocity = PLAYER_X_VEL;
	playChar->yVelocity = PLAYER_Y_VEL;
	playChar->hitbox.topLeftX = playChar->x;
	playChar->hitbox.topLeftY = playChar->y;
	playChar->hitbox.bottomRightX = playChar->x + SPRITE_SIZE;
	playChar->hitbox.bottomRightY = playChar->y + SPRITE_SIZE;
}	

void initCrystal(struct Crystal *crystal)
{
	crystal->x = CRYSTAL_X;
	crystal->y = CRYSTAL_Y;
	crystal->hitbox.topLeftX = crystal->x;
	crystal->hitbox.topLeftY = crystal->y;
	crystal->hitbox.bottomRightX = crystal->x + SPRITE_SIZE;
	crystal->hitbox.bottomRightY = crystal->y + SPRITE_SIZE;
}	

void initTimer(struct TimeRemaining *timeLeft)
{
	timeLeft->x = TIMER_X;
	timeLeft->y = TIMER_Y;
	timeLeft->wholeSecs = TIMER_SECS;
	timeLeft->ticks = TIMER_TICKS;
}	

void initScore(struct Score *score)
{
	score->x = SCORE_X;
	score->y = SCORE_Y;
	score->scoreAmnt = SCORE_AMNT;
}

void initModel(struct Model *model)
{
	initPlatform(&(model->platforms[GROUND]),GROUND_X,GROUND_Y,GROUND_LEN);
	initPlatform(&(model->platforms[1]),P1_X,P1_Y,P1_LEN);
	initPlatform(&(model->platforms[2]),P2_X,P2_Y,P2_LEN);
	initPlatform(&(model->platforms[3]),P3_X,P3_Y,P3_LEN);
	initPlatform(&(model->platforms[4]),P4_X,P4_Y,P4_LEN);
	initPlatform(&(model->platforms[5]),P5_X,P5_Y,P5_LEN);
	
	initPlayer(&model->player);
	
	initCrystal(&model->crystal);
	
	initScore(&model->score);
	
	initTimer(&model->timeLeft);
	
	model->isTimer0 = false;
}	
