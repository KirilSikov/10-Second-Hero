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
	unsigned int oldX;
	unsigned int oldY;
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
	unsigned int oldX;
	unsigned int oldY;
	int currPlace;
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
	int wholeSecs;
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


/*
Input:	model: the gamestate and all structures accociated with it.

Purpose: give player vertical velocity so that he jumps once gravity kicks in.
*/
void playerJump (struct Model *model);	

/*
Input:	model: the gamestate and all structures accociated with it.

Purpose: acts as gravity in order to make the player fall when he jumps
or walks off a platform.
*/
void playerFall (struct Model *model);	

/*
Input:	model: the gamestate and all structures accociated with it.

Purpose: makes the player run (or glide if airborne) left or right,
based on player input.
*/

/*
Input:	model: the gamestate and all structures accociated with it.

Purpose: makes the player run (or glide if airborne) left or right,
based on player input.
*/
void playerRun(struct Model *model);

/*
Input:	model: the gamestate and all structures accociated with it.
		hitbox: the hitbox of a struct where collision affects the model

Purpose: checks if a collision will occur based on the given hitbox's location.
*/
int possibleCollisionsCheck(struct Model model, struct Hitbox hitbox);

/*
Input:	currNum: the current/previous random number used

Purpose: generate a random number, and regenerates a new
number if the result is same as currNum
*/
int calcRand(int currNum);

/*
Input:	crystal: struct of the ingame crystal

Purpose: randomly teleports the crystal to one of 7 different locations. 
*/
void crystalRandomSpawn(struct Crystal *crystal);

/*
Input:	score: the struct of the ingame score.

Purpose: increments the score amount.
*/
void increaseScore(struct Score *score);

/*
Input:	timeLeft: struct of the remaining time in the game.

Purpose: decrements the timer's seconds.
*/
void decreaseTime(struct TimeRemaining *timeLeft);

/*
Input:	timeLeft: struct of the remaining time in the game.

Purpose: increments the timer by 3 seconds, with the max
amount of seconds the timer can reach being 10 seconds.
*/
void increaseTime(struct TimeRemaining *timeLeft);

/*
Input:	box1: hitbox of the first object
		box2: hitbox of the second object

Purpose: checks if a collision happened between two objects.
*/
bool collision(struct Hitbox box1, struct Hitbox box2);

/*
Input:	box1: hitbox of the first object
		box2: hitbox of the second object

Purpose: checks if object 1 collided with the right side
of object 2 (a platform).
*/
bool collideRightOfPlatform(struct Hitbox box1, struct Hitbox box2);

/*
Input:	box1: hitbox of the first object
		box2: hitbox of the second object

Purpose: checks if object 1 collided with the left side
of object 2 (a platform).
*/
bool collideLeftOfPlatform(struct Hitbox box1, struct Hitbox box2);

/*
Input:	box1: hitbox of the first object
		box2: hitbox of the second object

Purpose: checks if object 1 collided with the bottom
of object 2 (a platform).
*/
bool collideBottomOfPlatform(struct Hitbox box1, struct Hitbox box2);

/*
Input:	box1: hitbox of the first object
		box2: hitbox of the second object

Purpose: checks if object 1 collided with the top
of object 2 (a platform).
*/
bool collideTopOfPlatform(struct Hitbox box1, struct Hitbox box2);

/*
Input:	model: the gamestate and all structures accociated with it.

Purpose: checks if the player has collided with a platform. If so,
returns which platform he collided with.
*/
int platformCollisionsCheck(struct Model model);

/*
Input:	model: the gamestate and all structures accociated with it.

Purpose: checks if the player is "airborne", aka not colliding with the
top/surface of a platform.
*/
bool airborneCheck (struct Model model);


/* initiliziers*/


/*
Input:	platform: the struct of the in game platforms
		x: x pos of the platform
		y: y pos of the platform
		length: length of the platform

Purpose: initializes the platforms' data.
*/
void initPlatform(struct Platform *platform, unsigned int x,
	unsigned int y, unsigned int length);	

/*
Input:	playChar: struct of the ingame player.

Purpose: initializes the player's data.
*/
void initPlayer(struct Player *playChar);		

/*
Input:	crystal: struct of the ingame crystal.

Purpose: initializes the crystal's data.
*/
void initCrystal(struct Crystal *crystal);	

/*
Input:	score: struct of the ingame score.

Purpose: initializes the score's data.
*/
void initScore(struct Score *score);	

/*
Input:	timeLeft: struct of the ingame timer.

Purpose: initializes the timer's data.
*/
void initTimer(struct TimeRemaining *timeLeft);	

/*
Input:	model: the gamestate and all structures accociated with it.

Purpose: initializes the model's data.
*/
void initModel(struct Model *model);	


#endif