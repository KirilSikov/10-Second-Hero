#include "raster.h"

/* taken from lab 4*/
void clearScreen(){
	printf("\033E\033f\n");     /* blank the screen */
	return;
}

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
	
    offset = (x >> 4) + (y * 40);
    for(i = 0; i < height; i++){
		*(base + offset + (40 * i)) = bitmap[i];
    }
    return;
}

void plotBitmap8(UINT8 *base,
		    unsigned int x, unsigned int y,
		    const UINT8 *bitmap,
		    unsigned int height){
    int i;
    int offset;
	
    offset = (x >> 3) + (y * 40);
    for(i = 0; i < height; i++){
		*(base + offset + (40 * i)) = bitmap[i];
    }
    return;
}

void plotBitmap16(UINT16 *base, unsigned int x, unsigned int y, 
					const UINT16 *bitmap, unsigned int height)
{
	int i, offset, shift_F, shift_B;
	offset = (x >> 4) + (y * 40);
	shift_F = x & (BITS_IN_WORD - 1);
	shift_B = (BITS_IN_WORD) - (x & (BITS_IN_WORD - 1));

	for (i = 0; i < height; i++)
	{
		*(base + offset + (40 * i)) |= ((bitmap[i]) >> shift_F);

		*(base + offset + 1 + (40 * i)) |= ((bitmap[i]) << shift_B);
	}
	
	return;
}