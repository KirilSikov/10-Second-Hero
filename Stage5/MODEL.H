/*
Names:  	Enrik R
			Kiril S

Module:		Model 

Purpose: 	The model module contains the structs and functions related to the 
			model of the game, and the functions that directly impact the model. 

Details: 	The model handles the behaviours or actions that results from events
			occuring in the game. Ex: Space bar is pressed (event) = player jumps (action)
*/

#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <osbind.h>
#include <time.h>
#include <stdlib.h>
#include "const.h"

/* 
The following structure represents a hitbox that is used by
platforms, player, and crystal, within 10 Second Hero. The
hitbox is used to handle collisions between models. 
*/
struct Hitbox{
    UINT16 topLeftX;
    UINT16 topLeftY;
    UINT16 bottomRightX;
    UINT16 bottomRightY;
};

/*
The following structure represents a platform 
within 10 Second Hero. The platform is defined by 
three parameters. The two parameters are the x and
y coordinates of where the platform would begin to be
drawn. Length is a whole number that represents how 
long a platform could be. For example, assuming the 
length is 3, the platform would be drawn BASE_LEN*length 
long, where BASE_LEN is the base length of the platform.
*/
struct Platform
{
	unsigned int x;			
	unsigned int y;			
	unsigned int length;
	struct Hitbox hitbox;
};

/*The following structure represents the player
character within 10 second hero, sans its bitmap.
x and y represent the coordinates of the player, while
xVel and yVel represent the directional movement of the
player per game tick. Negatives represent left and up
respectively, while positive values represent right and
down, again respectively.*/
struct Player
{
	unsigned int x;
	unsigned int y;
	int xVelocity;
	int yVelocity;
	struct Hitbox hitbox;
};

/*The following strucutre represents the collectable
crystal within the game. X and y represent the coordinates
of the crystal. The hitbox is the hitbox of the crystal.
*/
struct Crystal
{
	unsigned int x;
	unsigned int y;
	struct Hitbox hitbox;
};

/*The following structure represents the timer within
10 second hero. Currently, this holds the x and y cordinate
of the int wholeSeconds, which represents the remaining time.
Each game tick, the time gets subtracted by 1/(Game ticks/s).
*/
struct TimeRemaining
{
	unsigned int x;
	unsigned int y;
	unsigned int wholeSecs;
	unsigned int ticks;
};

/*The following structure holds the score of the played game.
x and y represent the coordinates of the scoreboard, while
score itself is the numeric representation of the points
attained by the player.*/

struct Score
{
	unsigned int x;
	unsigned int y;
	unsigned int scoreAmnt;
};

/* 
This struct contains all the structs needed for the game. This
is where the game's individual models/game related structs are
going to be initialized, accessed, and changed. A bool "isTimer0"
is also contained in the model, which checks if the timer has
ticked down to 0 seconds, in which case the game would be over.
*/
struct Model
{
	struct Player player;
	struct Crystal crystal;
	struct Platform platforms[PLATFORM_AMNT]; /* 0 is ground platform */
	struct Score score;
	struct TimeRemaining timeLeft;
	bool isTimer0;
};



void playerJump (struct Model *model);	

void playerFall (struct Model *model);	

void playerRun(struct Model *model, Direction direction);

int calcRand();

void crystalRandomSpawn(struct Crystal *crystal);

void increaseScore(struct Score *score);

void decreaseTime(struct TimeRemaining *timeLeft);

void increaseTime(struct TimeRemaining *timeLeft);

bool collision(struct Hitbox box1, struct Hitbox box2);

bool collideRightOfPlatform(struct Hitbox box1, struct Hitbox box2);

bool collideLeftOfPlatform(struct Hitbox box1, struct Hitbox box2);

bool collideBottomOfPlatform(struct Hitbox box1, struct Hitbox box2);

bool collideTopOfPlatform(struct Hitbox box1, struct Hitbox box2);

int platformCollisionsCheck(struct Model model);

bool airborneCheck (struct Model model);

/* initiliziers*/


void initPlatform(struct Platform *platform, unsigned int x,
	unsigned int y, unsigned int length);	

void initPlayer(struct Player *playChar);		

void initCrystal(struct Crystal *crystal);	

void initScore(struct Score *score);	

void initTimer(struct TimeRemaining *timeLeft);	

void initModel(struct Model *model);	

#endif