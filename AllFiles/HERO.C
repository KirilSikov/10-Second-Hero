#include <osbind.h>
#include <stdio.h>
#include "const.h"
#include "renderer.h"
#include "model.h"
#include "event.h"

#define CLOCK 0x462
#define MAX_HEIGHT 16

typedef unsigned long ULONG32;
    
ULONG32 getTime();

/*void keyInput(struct Model *model, UINT16 *base, int x, int y, long input); */

void processAsyncEvents(struct Model *model);
void processSyncEvents(struct Model *model);

int main(){
	bool gameIsRunning = true;
	ULONG32 timeNow, timeThen, timeElapsed,
		fallTime, currFallTicks, timerTime, currTimerTicks;
	struct Model tenSecondHero;
	UINT16 *base = Physbase();
	unsigned long currInput = 0x00000000;

	timeThen = getTime();
	currFallTicks = timeThen;
	currTimerTicks = timeThen;
	render(&tenSecondHero,base);

	while(gameIsRunning && tenSecondHero.score.scoreAmnt <= MAX_SCORE){
		/* Async events*/
		if (Cconis())
		{
			currInput = Cnecin();	
			if (currInput == ESC_KEY)
			{
				gameIsRunning = false;
			} else
			{
				movePlayer(&tenSecondHero, currInput);
			}		
		}	
		
		timeNow = getTime();
		timeElapsed = timeNow - timeThen;
		fallTime = timeNow - currFallTicks;
		timerTime = timeNow - currTimerTicks;
		/* Sync events*/
		if (timeElapsed > 0)
		{
			timeNow = getTime();
			timeThen = timeNow;
	
			if (fallTime >= 2) /* have falling happen every x ticks?*/
			{
				currFallTicks = getTime();
				playerFall(&tenSecondHero);
			}
			
			if (timerTime >= 70) 
			{
				currTimerTicks = getTime();
				tickTimeDown(&tenSecondHero);
				rerenderTimer(&(tenSecondHero.timeLeft));
			}
			
			playerRun(&tenSecondHero);
			crystalCollected(&tenSecondHero);

			rerenderScore(&(tenSecondHero.score));
			renderMovable(&tenSecondHero, base);
			if (isTimer0(tenSecondHero))
			{
				gameIsRunning = false;
			}
		}
	}

	return 0;
}

ULONG32 getTime(){
	long old_ssp;
	ULONG32 timeNow;
	long *timer = (long *)CLOCK;

	old_ssp = Super(0);
	timeNow = *timer;
	Super(old_ssp);
	return timeNow;
}