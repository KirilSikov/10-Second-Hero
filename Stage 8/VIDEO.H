/*
Authors: 	Enrik R
			Kiril S

This is the .H file for video.s and super.s, which are system calls
that replace Physbase() and Setscreen()
 */
#ifndef VIDEO_H
#define VIDEO_H

#include "const.h"

/*
Purpose: Same as Physbase(), returns the screen/video base

*/
UINT16 *getVideoBase();

/*
Input: the start address of the frame buffer.

Purpose: Same as Setscreen(), sets screen base to given address. 
*/
void setVideoBase(UINT16 *base);

#endif
