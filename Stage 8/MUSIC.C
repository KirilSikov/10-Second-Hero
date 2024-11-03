/*
Authors: 	Enrik Rushiti
			Kiril Sikov

Module: 	Music

Purpose: contains functions to start and update music.
*/


#include <stdio.h>
#include "const.h"
#include "psg.h"
#include "music.h"

UINT8 tstMelody[8] = {150,180,165,210,195,240,225,250};
UINT8 jmpSFX[2] = {170, 175};
int musicIndex;
UINT32 time;

/*int main(){
	char tst;
	start_music();
	
	while(tst != ESC_ASCII){
		if(Cconis()){
			tst = Cconin();
			update_music(4);
		}
	}
	stop_sound();
	return 0;
}*/

void startMusic(){
	musicIndex = 0;
	time = 0;
	setTone(0,tstMelody[musicIndex]);
	setTone(1,0);
	enableChannel(0,1,0);
	setVolume(8,11);
	
	return;
}

void updateMusic(UINT32 timeElapsed){
	if(musicIndex < 7){
		musicIndex += 1;
	}
	else{
		musicIndex = 0;
	}
	setTone(0,tstMelody[musicIndex]);
	setVolume(8,8);
	return;
}