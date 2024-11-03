/*
Names:  	Enrik R
			Kiril S
Module:		Renderer 
Purpose: 	The renderer module contains the subroutine and function calls related to the 
			output of current gamestate to the screen. 
Details: 	A model structure is created and initialized to set values from const.h,
			const.c and model.c. The model then gets printed onto the screen via 16x16
			bitmaps.
*/
#include "renderer.h"

/*
int main(){
	struct Model tenSecondHero;
	UINT16 *base = Physbase();
	render(&tenSecondHero,base);
	return 0;
}
*/

void renderPlayer(const struct Player *Player,UINT16 *base){
	plotBitmap16(base,Player->x,Player->y,PLAYER_BITMAP,BITMAP_HEIGHT);
	return;
}

void renderCrystal(const struct Crystal *crystal,UINT16 *base){
	plotBitmap16(base,crystal->x,crystal->y,CRYSTAL_BITMAP,BITMAP_HEIGHT);
	return;
}

void renderPlatform(const struct Platform platform[],UINT16 *base){
	int i = 0;
	for (i = 0;i < 6; i++) {
		drawHorizontal(base,platform[i].x,platform[i].y,
		BLACKOUT_BITMAP, BITMAP_HEIGHT, platform[i].length);	
	}
	return;
}

void renderTimer(const struct TimeRemaining *timeLeft, UINT16 *base){
	plotBitmap16(base,timeLeft->x,timeLeft->y,LETTER_T,BITMAP_HEIGHT);
	plotBitmap16(base,(timeLeft->x)+POS2,timeLeft->y,LETTER_I,BITMAP_HEIGHT);
	plotBitmap16(base,(timeLeft->x)+POS3,timeLeft->y,LETTER_M,BITMAP_HEIGHT);
	plotBitmap16(base,(timeLeft->x)+POS4,timeLeft->y,LETTER_E,BITMAP_HEIGHT);
	return;
}

void renderScore(const struct Score *score,UINT16 *base){
	plotBitmap16(base,score->x,score->y,LETTER_S,BITMAP_HEIGHT);
	plotBitmap16(base,(score->x)+POS2,score->y,LETTER_C,BITMAP_HEIGHT);
	plotBitmap16(base,(score->x)+POS3,score->y,LETTER_O,BITMAP_HEIGHT);
	plotBitmap16(base,(score->x)+POS4,score->y,LETTER_R,BITMAP_HEIGHT);
	plotBitmap16(base,(score->x)+POS5,score->y,LETTER_E,BITMAP_HEIGHT);
	return;
}

void renderMovable(const struct Model *model, UINT16 *base){
	renderPlayer(&model->player, base);
	renderCrystal(&model->crystal, base);
	rerenderScore(&model->score, base);
	rerenderTimer(&model->timeLeft, base);
	return;
}

void rerenderScore(struct Score *score, UINT16 *base)
{
	int ones = score->scoreAmnt % 10;
	int tens = score->scoreAmnt / 10;
	if(score->scoreAmnt >= 10)
	{
		renderNewScore(tens,(score->x)+SCORE_TENS,score->y,base);
	}
	renderNewScore(ones,(score->x)+SCORE_ONES,score->y,base);
	return;
}

void rerenderTimer(struct TimeRemaining *timeLeft, UINT16 *base)
{
	int ones = (timeLeft->wholeSecs) % 10;
	int tens = (timeLeft->wholeSecs) / 10;
	if((timeLeft->wholeSecs) >= TIMER_SECS)
	{
		renderNewTimer(tens, (timeLeft->x) + TIMER_TENS, timeLeft->y, base);
	}
	renderNewTimer(ones, (timeLeft->x) + TIMER_ONES, timeLeft->y, base);
	return;
}

void renderNewTimer(int digit, unsigned int x, unsigned int y, UINT16 *base)
{
	plotBitmapAlt(base, x, y, CLEAR_BITMAP, BITMAP_HEIGHT);
	switch (digit)
	{
		case 0:
			plotBitmapAlt(base,x,y,NUMBER_0,BITMAP_HEIGHT);
			break;
		case 1:
			plotBitmapAlt(base,x,y,NUMBER_1,BITMAP_HEIGHT);
			break;
		case 2:
			plotBitmapAlt(base,x,y,NUMBER_2,BITMAP_HEIGHT);	
			break;
		case 3:
			plotBitmapAlt(base,x,y,NUMBER_3,BITMAP_HEIGHT);
			break;
		case 4:
			plotBitmapAlt(base,x,y,NUMBER_4,BITMAP_HEIGHT);
			break;
		case 5:
			plotBitmapAlt(base,x,y,NUMBER_5,BITMAP_HEIGHT);
			break;
		case 6:
			plotBitmapAlt(base,x,y,NUMBER_6,BITMAP_HEIGHT);
			break;
		case 7:
			plotBitmapAlt(base,x,y,NUMBER_7,BITMAP_HEIGHT);
			break;
		case 8:
			plotBitmapAlt(base,x,y,NUMBER_8,BITMAP_HEIGHT);
			break;
		case 9:
			plotBitmapAlt(base,x,y,NUMBER_9,BITMAP_HEIGHT);
			break;
		default:
			break;
	}
}

void renderNewScore(int digit, unsigned int x, unsigned int y, UINT16 *base)
{
	plotBitmapAlt(base, x, y, CLEAR_BITMAP, BITMAP_HEIGHT);
	switch (digit)
	{
		case 0:
			plotBitmapAlt(base,x,y,NUMBER_0,BITMAP_HEIGHT);
			break;
		case 1:
			plotBitmapAlt(base,x,y,NUMBER_1,BITMAP_HEIGHT);
			break;
		case 2:
			plotBitmapAlt(base,x,y,NUMBER_2,BITMAP_HEIGHT);	
			break;
		case 3:
			plotBitmapAlt(base,x,y,NUMBER_3,BITMAP_HEIGHT);
			break;
		case 4:
			plotBitmapAlt(base,x,y,NUMBER_4,BITMAP_HEIGHT);
			break;
		case 5:
			plotBitmapAlt(base,x,y,NUMBER_5,BITMAP_HEIGHT);
			break;
		case 6:
			plotBitmapAlt(base,x,y,NUMBER_6,BITMAP_HEIGHT);
			break;
		case 7:
			plotBitmapAlt(base,x,y,NUMBER_7,BITMAP_HEIGHT);
			break;
		case 8:
			plotBitmapAlt(base,x,y,NUMBER_8,BITMAP_HEIGHT);
			break;
		case 9:
			plotBitmapAlt(base,x,y,NUMBER_9,BITMAP_HEIGHT);
			break;
		default:
			break;
	}
}

/*
Subroutine: render
Input Parameters: model
					The Gamestate and all structures accociated with it.
Purpose: Initialises the gamestate to the starting position.
Details: The function clears the screen before initializing the gamestate to
a starting position. When this has finished, the function then goes on to
output the gamestate to the user, with every substructure within model being
"rendered".
*/
void renderStatic(const struct Model *model, UINT16 *base){
	clearScreen();
	initModel(model);
	renderPlatform(model->platforms,base);
	renderTimer(&model->timeLeft,base);
	renderScore(&model->score,base);
	return;
}