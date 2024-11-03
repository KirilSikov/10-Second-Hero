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

void plotBitmapAlt(UINT16 *base,
		    unsigned int x, unsigned int y,
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

void plotBitmap16(UINT16 *base, unsigned int x, unsigned int y, 
					const UINT16 *bitmap, unsigned int height)
{
	UINT16 *draw = base + y * 40 + (x / 16);
	int shift = x % 16; /*amount of shift required*/
	unsigned int i;
	
	if (x <= 640 && y <= 400)
	{
		if (shift > 0) /*if shift needed*/
		{
			for (i = 0; i < height && draw < base + 16000; i++)
			{
				*draw |= (bitmap[i] >> shift);
				draw += 40;
			}
			draw = draw - (40 * height) + 1;
/*			draw = (base + y * 40 + (x / 16)) + 1;*/
			for (i = 0; i < height && draw < base + 16000; i++)
			{
				*draw = (bitmap[i] << 16 - shift);
				draw += 40;
			}
		}
		else /* No shift needed*/
		{
			for  (i = 0; i < height; i++)
			{
				*draw |= bitmap[i];
				draw += 40;
			}
		
		}
	}
	
	return;
}