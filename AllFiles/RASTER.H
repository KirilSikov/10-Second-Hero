/*
This is a library containing functions used to plot bitmaps.
These will serve a purpose in later stages, remember how they work.
*/

#ifndef RASTER_H
#define RASTER_H

#include <stdio.h>
#include <osbind.h>
#include "const.h"

/* 
Function: 	plotBitmap16

Input:	  	base: pointer to the start of the frame buffer address.
			x: x coordinate of the bitmap to be plotted
			y: y coordinate of the bitmap to be plotted
			bitmap: the bitmap that is going to be plotted
			height: how tall the bitmap is

Purpose:	Plots a 16xHeight bitmap on the screen at a specified location

Details: 	Using the address of the frame buffer and an offset calculated from
			the x and y coordinates, the bitmap gets placed based on the screen.
*/
void plotBitmap16(UINT16 *base,
		    unsigned int x, unsigned int y,
		    const UINT16 *bitmap,
		    unsigned int height);

/* 
Function: 	drawHorizontal 

Input:	  	base: pointer to the start of the frame buffer address.
			x: x coordinate of the bitmap to be plotted
			y: y coordinate of the bitmap to be plotted
			bitmap: the bitmap that is going to be plotted
			height: how tall the bitmap is
			length: how long the horizontal line will be, ex 4 bitmaps long
		
Purpose:	Plots a horizontal line of bitmaps at specified length and height		

Details:	Plots 16xHeight bitmaps several times (as specified by length) in
			order to form a horizontal line of said bitmaps. Any bitmap can be
			used, as long as it 16 pixels wide.        
*/
void drawHorizontal(UINT16 *base,
			  int x, int y,
			  const UINT16 *bitmap,
			  unsigned int height,
			  int length);

/* 
Function: 	drawVertical

Input:	  	base: pointer to the start of the frame buffer address.
			x: x coordinate of the bitmap to be plotted
			y: y coordinate of the bitmap to be plotted
			bitmap: the bitmap that is going to be plotted
			height: how tall the bitmap is
			length: how long the vertical line will be, ex: 4 bitmaps long
			
Purpose:	Plots a vertical line of bitmaps at specified length and height

Details:	Plots 16xHeight bitmaps several times (as specified by length) in
			order to form a vertical line of said bitmaps. Any bitmap can be
			used, as long as it 16 pixels wide.
         
*/
void drawVertical(UINT16 *base,
			  int x, int y,
			  const UINT16 *bitmap,
			  unsigned int height,
			  int length);
			  
/* 
Function: 	drawPixel 

Input:	  	base: pointer to the start of the frame buffer address.
			x: x coordinate of the pixel to be plotted
			y: y coordinate of the pixel to be plotted
			
Purpose:	Plots a pixel on the screen

Details:	Plots a pixel (turns the pixel on) if a pixel isn't already plotted
			on he specified location.
*/			  
void drawPixel(UINT8 *base, int x,
			   int y);

/* 
Function: 	clearScreen

Purpose:	Clears the screen of all pixels.

Details:	Turns off all pixels in the frame buffer, making the whole screen white.
*/	
void clearScreen();

void plotBitmapAlt(UINT16 *base,
		    unsigned int x, unsigned int y,
		    const UINT16 *bitmap,
		    unsigned int height);

#endif