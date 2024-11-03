#include <osbind.h>
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "renderer.h"
#include "model.h"
#include "event.h"

#define CLOCK 0x462
#define MAX_HEIGHT 16
#define BUFFER_SIZE 32000

typedef unsigned long ULONG32;

ULONG32 getTime();

typedef struct ScreenBuffer{
	int currentIndex;
	
	void *logbase;
	void *frameBuffers[2];
	void *origFrameBuffer;
};

const UINT8 buffer2[32256];
const UINT8 staticBuffer[32000]; 

int main(){
	UINT16 *base1 = (UINT16 *)Physbase();
	UINT16 *base2;
	UINT16 *staticBuffPtr = (UINT16 *)staticBuffer;
	UINT16 offset;
	UINT16 align;
	UINT16 *ptr = staticBuffPtr;
	bool gameIsRunning = true;
	ULONG32 timeNow, timeThen, timeElapsed,
		fallTime, currFallTicks, timerTime, currTimerTicks;
	struct Model tenSecondHero;
	unsigned long currInput = 0x00000000;
	
	srand(SRAND_TEST_KEY);
	initModel(&tenSecondHero);
	
	offset = (UINT16)buffer2;
	align = offset % 256;
	base2 = (UINT16 *)(buffer2 + (256-align));
	
	renderStatic(&tenSecondHero,staticBuffPtr);
	
	timeThen = getTime();
	currFallTicks = timeThen;
	currTimerTicks = timeThen;
	
	memcpy(base2,staticBuffPtr,32000);
	renderMovable(&tenSecondHero,base2);

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
	
			if (fallTime >= 0) /* have falling happen every x ticks?*/
			{
				currFallTicks = getTime();
				playerFall(&tenSecondHero);
			}
			
			if (timerTime >= 70) 
			{
				currTimerTicks = getTime();
				tickTimeDown(&tenSecondHero);
			}
			
			playerRun(&tenSecondHero);
			crystalCollected(&tenSecondHero);

			renderMovable(&tenSecondHero, base2);
			if (isTimer0(tenSecondHero))
			{
				gameIsRunning = false;
			}
		}
		memcpy(base1,base2,32000);
		memcpy(base2,staticBuffPtr,32000);
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