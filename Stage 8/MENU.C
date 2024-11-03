/*
Names:  	Enrik Rushiti
			Kiril Sikov

Module:		Menu

Purpose: 	Contains the function(s) related to the splash screen and main menu
*/
#include "menu.h"

bool splashScreenMenu ()
{
	unsigned long input;
	bool exitGame = false;
	
	while (input != ESC_KEY && input != ONE_KEY)
	{
		if (Cconis())
		{
			input = Cnecin();
		}
	}
	
	if (input == ESC_KEY)
	{
		exitGame = true;
	}
	return exitGame;
}






