#include <osbind.h>
#include "const.h"

/* 
Function: 	write_psg
Input:	  	reg: The register being read.
            val: The value to be deposited at the register
Purpose: 	Deposits a value at the register specified on the soundchip.
Details:	The function defines the read/write addresses for the sound chip
before calling super. Afterwards, the function sets the "read" value with
the register and writes with the val passed in.
*/
void write_psg(int reg, UINT8 val);

/* 
Function: 	read_psg
Input:	  	reg: The register being read.
Purpose: 	Reads a register on the soundchip and returns its value.
Details:	]Assuming that the reg value passed in is valid, it
enters supervisor mode to go to the sound chip's address and read
what is contained in the specified address.
*/
UINT8 read_psg(int reg);

/* 
Function: 	set_tone
Input:	  	channel: Channel being used (A,B or C).
            tuning: value of the tune.
Purpose: 	Set the tone for one of the channels.
Details:	Assuming the channel is valid, the function calls write_psg
with the channel being added by 8 to get the correct channel to be set.
channel 0 is A, and +8 gets the register for channel A. 9 gets B, and 10
gets C.
*/
void set_tone(int channel, int tuning);

/* 
Function: 	enable_channel
Input:	  	channel: channel being set active.
            tone_on: determines if channel activates its tone.
            tone_off: determines if channel activates its noise.
Purpose: 	Activate a channel with either tone or noise.
Details:	Assuming the channel is valid, the function determines if
the noise or tone would be activated by the user. NOTE: BOTH CANNOT
BE TURNED ON AT THE SAME TIME. Once this is accomplised, it calls
write_psg with values that activate noise/tone for the given channel.
The numbers presented should have been defined in the header file here,
but I got lazy. At the same time, its not like the chip is getting any
enhancements anytime soon.
*/
void enable_channel(int channel, int tone_on, int noise_on);

/* 
Function: 	set_volume
Input:	  	channel: Channel being used (A,B or C).
            volume: how loud to set the channel
Purpose: 	Set the volume for a given channel.
Details:	Assuming the channel is valid, the function calls write_psg
with the channel given and the volume as a value.
*/
void set_volume(int channel, int volume);

/* 
Function: 	stop_sound
Purpose: 	Stops sound being played on the Atari ST.
Details:	When this function is called, it sets the volume
on channels A,B and C to 0, silencing audio.
*/
void stop_sound();
