#include <osbind.h>
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "renderer.h"
#include "model.h"
#include "event.h"
#include "music.h"
#include "psg.h"

UINT32 getTime();
void muteUnmute(bool muted);

const UINT8 buffer2[BUFFER_256];
const UINT8 staticBuffer[BUFFER_SIZE]; 

int main(){
	UINT16 *base1 = (UINT16 *)Physbase();
	UINT16 *base2;
	UINT16 *staticBuffPtr = (UINT16 *)staticBuffer;
	UINT16 offset;
	UINT16 align;
	UINT16 *ptr = staticBuffPtr;
	bool gameIsRunning = true;
	bool muted = false;
	UINT32 timeNow, timeThen, timeElapsed,
		fallTime, currFallTicks, timerTime, currTimerTicks;
	UINT32 lastNotePlayed = 0;
	struct Model tenSecondHero;
	unsigned long currInput = 0;
	bool swapBuff = true;
	srand(SRAND_TEST_KEY);
	initModel(&tenSecondHero);
	
	offset = (UINT16)buffer2;
	align = offset % 256;
	base2 = (UINT16 *)(buffer2 + (256 - align));
	
	renderStatic(&tenSecondHero,staticBuffPtr);
	
	timeThen = getTime();
	currFallTicks = timeThen;
	currTimerTicks = timeThen;
	
	/*memcpy(base2,staticBuffPtr, BUFFER_SIZE);
	renderMovable(&tenSecondHero,base2);*/
	start_music();
	
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

		if (timeElapsed > 0)
		{
			timeNow = getTime();
			timeThen = timeNow;
	
			if (fallTime >= 1) /* have falling happen every x ticks?*/
			{
				currFallTicks = getTime();
				playerFall(&tenSecondHero);
			}
			
			if (timerTime >= SECOND_TICK) 
			{
				currTimerTicks = getTime();
				tickTimeDown(&tenSecondHero);
			}
			if (timerTime - lastNotePlayed >= 20){
				update_music(timerTime);
				lastNotePlayed = timerTime;
			}
			
			playerRun(&tenSecondHero);
			crystalCollected(&tenSecondHero);
			
			if (swapBuff)
			{
				memcpy(base1, staticBuffPtr, BUFFER_SIZE);
				renderMovable(&tenSecondHero, base1);
				Setscreen(-1, base1, -1);
				
				Vsync();
			} else
			{
				memcpy(base2, staticBuffPtr, BUFFER_SIZE);
				renderMovable(&tenSecondHero, base2);
				Setscreen(-1, base2, -1);
				
				Vsync();
			}
			swapBuff = !swapBuff;
			if (isTimer0(tenSecondHero))
			{
				gameIsRunning = false;
			}
		}
	}
	stop_sound();
	Setscreen(-1, base1, -1);
	return 0;
}

UINT32 getTime(){
	long old_ssp;
	UINT32 timeNow;
	long *timer = (long *)CLOCK;

	old_ssp = Super(0);
	timeNow = *timer;
	Super(old_ssp);
	return timeNow;
}