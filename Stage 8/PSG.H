/*
Authors: 	Enrik Rushiti
			Kiril Sikov

Module: 	PSG

Purpose: contains functions related to the PSG register, which is used to play music/sound effects.
*/


#include <osbind.h>
#include "const.h"

/* 
Input:	  	reg: The register being read.
            val: The value to be deposited at the register

Purpose: 	Deposits a value at the register specified on the soundchip.

Details:	The function defines the read/write addresses for the sound chip
before calling super. Afterwards, the function sets the "read" value with
the register and writes with the val passed in.
*/
void writePsg(int reg, UINT8 val);

/* 
Input:	  	reg: The register being read.

Purpose: 	Reads a register on the soundchip and returns its value.

Details:	]Assuming that the reg value passed in is valid, it
enters supervisor mode to go to the sound chip's address and read
what is contained in the specified address.
*/
UINT8 readPsg(int reg);

/* 
Input:	  	channel: Channel being used (A,B or C).
            tuning: value of the tune.

Purpose: 	Set the tone for one of the channels.

Details:	Assuming the channel is valid, the function calls writePsg
with the channel being added by 8 to get the correct channel to be set.
channel 0 is A, and +8 gets the register for channel A. 9 gets B, and 10
gets C.
*/
void setTone(int channel, int tuning);

/* 
Input:	  	channel: channel being set active.
            tone_on: determines if channel activates its tone.
            tone_off: determines if channel activates its noise.

Purpose: 	Activate a channel with either tone or noise.

Details:	Assuming the channel is valid, the function determines if
the noise or tone would be activated by the user. NOTE: BOTH CANNOT
BE TURNED ON AT THE SAME TIME. Once this is accomplised, it calls
writePsg with values that activate noise/tone for the given channel.
The numbers presented should have been defined in the header file here,
but I got lazy. At the same time, its not like the chip is getting any
enhancements anytime soon.
*/
void enableChannel(int channel, int tone_on, int noise_on);

/* 
Input:	  	channel: Channel being used (A,B or C).
            volume: how loud to set the channel

Purpose: 	Set the volume for a given channel.

Details:	Assuming the channel is valid, the function calls writePsg
with the channel given and the volume as a value.
*/
void setVolume(int channel, int volume);

/* 
Purpose: 	Stops sound being played on the Atari ST.

Details:	When this function is called, it sets the volume
on channels A,B and C to 0, silencing audio.
*/
void stopSound();