#include "raster.h"

/* taken from lab 4*/
void clearScreen(){
	printf("\033E\033f\n");     /* blank the screen */
	return;
}

/*
this clearscreen function is relatively slow, just kept
as a backup 
void clearScreen(UINT16 *base){
	int x;
	int y;
	int height = BITMAP_HEIGHT;
	UINT16 clr[16]=
    {
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
    };
	
	for(x = 0; x < XBOUNDS; x+=16){
		for(y = 0; y < YBOUNDS; y+=16){
			plotBitmap16(base,x,y,clr,height);
		}
	}
	return;
}
*/

void drawVertical(UINT16 *base,
			  int x, int y,
			  const UINT16 *bitmap,
			  unsigned int height,
			  int length){
	int i;
	for(i = 0; i < length;i++){
		plotBitmap16(base,x,y,bitmap,height);
		y = y + 16;
	}
	return;
}

void drawHorizontal(UINT16 *base,
			  int x, int y,
			  const UINT16 *bitmap,
			  unsigned int height,
			  int length){
	int i;
	for(i = 0; i < length;i++){
		plotBitmap16(base,x,y,bitmap,height);
		x = x + 16;
	}
	return;
}

void drawPixel(UINT8 *base, int x, int y){
	if( x >= 0 && x < XBOUNDS &&
        y >= 0 && y < YBOUNDS ) {
        *(base + y * 80 + (x >> 3)) |= 1 << (7 - (x & 7));
    }
	return;
}

void plotBitmap16(UINT16 *base,
		    int x, int y,
		    const UINT16 *bitmap,
		    unsigned int height){
    int i;
    int offset;
	
    offset = (x>>4) + (y*40);
    for(i = 0; i < height; i++){
		*(base + offset + (40*i)) = bitmap[i];
    }
    return;
}