
/*Holds the song to be played by the game. */
extern UINT8 tstMelody[8];

/* 
Function: 	start_music
Purpose:	The function starts the melody defined by tstMelody and plays the first element
through the sound chip, initializing channel A.
Details: 	Starting with the first element of tstMelody, the function calls set_tone, enable_channel
and set_volume to initialize sound to the program.
*/
void start_music();

/* 
Function: 	update_music
Input:	  	time_eelapsed: the amount of time passed since last note played.
Purpose: 	Changes the tone being played through the sound chip with the next element of
tstMelody.
Details:	Depending on if enough time has passed (20 ticks), the function will
update to the next element in tstMelody. If at the end of the array, it gets set
back to the first element of the array.
*/
void update_music(UINT32 time_elapsed);
