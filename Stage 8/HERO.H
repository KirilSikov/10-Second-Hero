/*
Names:  	Enrik Rushiti
			Kiril Sikov

Module:		Hero

Purpose: 	Contains the main game loop.
*/

#ifndef HERO_H
#define HERO_H


#include <osbind.h>
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "renderer.h"
#include "model.h"
#include "event.h"
#include "video.h"
#include "menu.h"
#include "music.h"
#include "psg.h"

/* 
Input: 	muted: checks if the music is muted or not
	
Purpose: mutes/unmutes the music.
*/
void muteUnmute(bool muted);


ULONG32 getTime();

/* 
Input: 		model: the gamestate and all structures accociated with it.
			currTimerTicks: the current clock ticks being tracked for the timer.
			timerTime: currTimerTicks subtracted by the current clock tick.
			gameIsRunning: bool to check if the game is still in progress or lost.
	
Purpose: handles the processing of synchronous events in the game.

*/
void processSyncEvents(struct Model *model, ULONG32 *currTimerTicks, 
	ULONG32 *timerTime, bool *gameIsRunning);

/* 	
Purpose: loop of the game, containing the async and sync events, and music.
*/	
void gameLoop();


#endif