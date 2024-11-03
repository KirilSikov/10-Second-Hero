#include <stdio.h>
#include "psg.h"
#define CHANNEL_OFFSET 8
/*CHANNEL_OFFSET exists to skip making
if else structures in methods who pass in
only channel values. This way, registers 8,9 and
10 can be reached with channel 0,1,2 via x+8*/

void write_psg(int reg, UINT8 val){
	volatile char *PSG_reg_select = 0xFF8800;
    volatile char *PSG_reg_write  = 0xFF8802;
    long old_ssp = Super(0);
	
	*PSG_reg_select = reg;
    *PSG_reg_write  = val;
    Super(old_ssp);
	return;
}

void set_tone(int channel, int tuning){
	int reg = channel * 2;
	int noiseReg = reg+1;

	write_psg(reg,tuning);
	write_psg(noiseReg,0);
	return;
}

void stop_sound(){
	set_volume(8,0);
	set_volume(9,0);
	set_volume(10,0);
	return;
}

void set_volume(int channel, int volume){
	write_psg(channel,volume);
	return;
}

void enable_channel(int channel, int tone_on, int noise_on){
	if(tone_on == 0 && noise_on == 0){
		write_psg(7,0x3F);
	}
	else{
		if(channel == 0){
			if(tone_on == 0 && noise_on == 1){
				write_psg(7,0x37);
			}
			else if(tone_on == 1 && noise_on == 0){
				write_psg(7,0x3E);
			}
		}
		else if (channel == 1){
			if(tone_on == 0 && noise_on == 1){
				write_psg(7,0x2F);
			}
			else if(tone_on == 1 && noise_on == 0){
				write_psg(7,0x3D);
			}
		}
		else if (channel == 2) {
			if(tone_on == 0 && noise_on == 1){
				write_psg(7,0x1F);
			}
			else if(tone_on == 1 && noise_on == 0){
				write_psg(7,0x3B);
			}
		}
	}
	return;
}
