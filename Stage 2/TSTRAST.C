#include <stdio.h>
#include <osbind.h>
#include "raster.h"

int main(){
    UINT16 *base = (UINT16*) Physbase();
    UINT8 *pixel = (UINT8 *) Physbase();

    int height = BITMAP_HEIGHT;
    int x;
    int y;
	/* ground + platforms 1-5*/
	clearScreen(base);
	drawHorizontal(base, 0, 375, BLACKOUT_BITMAP, height, 40);
	drawHorizontal(base, 40, 300, BLACKOUT_BITMAP, height, 3);
	drawHorizontal(base, 80, 130, BLACKOUT_BITMAP, height, 6);
	drawHorizontal(base, 150, 250, BLACKOUT_BITMAP, height, 8);
	drawHorizontal(base, 270, 180, BLACKOUT_BITMAP, height, 10);
	drawHorizontal(base, 500, 225, BLACKOUT_BITMAP, height, 6);
	
	drawVertical(base, 10, 200, BLACKOUT_BITMAP, height, 5);
	
	drawPixel(pixel, 320, 250);
	drawPixel(pixel, 335, 250);
    /* draw game layout here*/
	plotBitmap16(base, 340, 350, PLAYER_BITMAP, height);
	plotBitmap16(base, 125, 110, CRYSTAL_BITMAP, height);
	
	
	return 0;
}
