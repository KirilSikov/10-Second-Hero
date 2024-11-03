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

void start_music(){
	index = 0;
	time = 0;
	set_tone(0,tstMelody[index]);
	set_tone(1,0);
	enable_channel(0,1,0);
	set_volume(8,11);
	
	return;
}

void update_music(UINT32 time_elapsed){
	if(musicIndex < 7){
		musicIndex += 1;
	}
	else{
		musicIndex = 0;
	}
	set_tone(0,tstMelody[musicIndex]);
	set_volume(8,8);
	return;
}