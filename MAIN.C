#include <osbind.h>
#include <stdio.h>
#include "const.h"
#include "renderer.h"
#include "model.h"

#define CLOCK 0x462
#define ESC_ASCII 27
#define MAX_HEIGHT 16

typedef unsigned long ULONG32;
    
ULONG32 getTime();
void keyInput(struct Model *model, UINT16 *base,struct Model *last, char input);

void processAsyncEvents(struct Model *model);
void processSyncEvents(struct Model *model);

int main(){
	ULONG32 timeNow, timeThen, timeElapsed;
	struct Model tenSecondHero;
	struct Model lastFrame;
	UINT16 *base = Physbase();
	char tst = NULL;

	Vsync();
	timeNow = getTime();
	render(&tenSecondHero,base);
	/*For future use as the game state loop.
	when the user hits the escape button, the game
	will immediately exit.*/
	while(tst != ESC_ASCII){
		lastFrame = tenSecondHero;
		playerFall(&tenSecondHero);
		renderMovable(&tenSecondHero,&lastFrame,base);
		if(Cconis()){
			tst = (char)Cnecin();
			keyInput(&tenSecondHero,base,&lastFrame,tst);
		}
	}

	return 0;
}

void keyInput(struct Model *model, UINT16 *base, struct Model *last, char tst){
	Direction playDirec;
	int OldX = last->player.x;
	int OldY = last->player.y;
		if(tst == 'a'){
			playDirec = left;
		}
		else if(tst == 'd'){
			playDirec = right;
		}
		else if(tst == ' '){
			playerJump(model);
		}
		plotBitmap16(base,OldX,OldY,CLEAR_BITMAP,MAX_HEIGHT);
		playerRun(model,playDirec);
	return;
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


void processAsyncEvents(struct Model *model)
{
	
	
}


void processSyncEvents(struct Model *model)
{
	
	
}