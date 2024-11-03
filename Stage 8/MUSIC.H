/*
Authors: 	Enrik Rushiti
			Kiril Sikov

Module: 	Music

Purpose: contains functions to start and update music.
*/


/*Holds the song to be played by the game. */
extern UINT8 tstMelody[8];


/* 
Purpose:	The function starts the melody defined by tstMelody and plays the first element
through the sound chip, initializing channel A.

Details: 	Starting with the first element of tstMelody, the function calls setTone, enableChannel
and setVolume to initialize sound to the program.
*/
void startMusic();

/* 
Input:	  	timeElapsed: the amount of time passed since last note played.

Purpose: 	Changes the tone being played through the sound chip with the next element of
tstMelody.

Details:	Depending on if enough time has passed (20 ticks), the function will
update to the next element in tstMelody. If at the end of the array, it gets set
back to the first element of the array.
*/
void updateMusic(UINT32 timeElapsed);