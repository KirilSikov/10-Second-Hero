/* 
This file contains constants and type declerations utilized by other files.

*/

#ifndef CONST_H
#define CONST_H


/* */
#define BITMAP_HEIGHT 16
#define SPRITE_SIZE 16
#define XBOUNDS 640
#define YBOUNDS 400

#define SCORE_TICK 50
#define FPS 35

#define TIME_ADD 3
#define TIME_SUB 1
#define SCORE_ADD 1

/* ground initilization data*/
#define PLATFORM_AMNT 6

#define GROUND 0
#define GROUND_X 0
#define GROUND_Y 375
#define GROUND_LEN 40

/* initilization data of other platforms*/
/* platform 1*/
#define P1_X 40
#define P1_Y 300
#define P1_LEN 3
/* platform 2*/
#define P2_X 80
#define P2_Y 130
#define P2_LEN 6
/* platform 3*/
#define P3_X 150
#define P3_Y 250
#define P3_LEN 8
/* platform 4*/
#define P4_X 270
#define P4_Y 180
#define P4_LEN 10
/* platform 5*/
#define P5_X 500
#define P5_Y 225
#define P5_LEN 6

/* initilization of player */
#define PLAYER_X 340
#define PLAYER_Y 350
#define PLAYER_X_VEL 0
#define PLAYER_Y_VEL 0 
#define PLAYER_JUMP_SPEED -11
#define PLAYER_MAX_FALL_SPEED 5

/* initilization of crystal */
#define CRYSTAL_X 125
#define CRYSTAL_Y 110

#define MAX_RAND 6
#define MIN_RAND 0
#define SRAND_TEST_KEY 69
#define CRYSTAL_RAND_X0 40
#define CRYSTAL_RAND_Y0 355
#define CRYSTAL_RAND_X1 60
#define CRYSTAL_RAND_Y1 280
#define CRYSTAL_RAND_X2 125
#define CRYSTAL_RAND_Y2 110
#define CRYSTAL_RAND_X3 175
#define CRYSTAL_RAND_Y3 230
#define CRYSTAL_RAND_X4 300
#define CRYSTAL_RAND_Y4 160
#define CRYSTAL_RAND_X5 525
#define CRYSTAL_RAND_Y5 205
#define CRYSTAL_RAND_X6 575
#define CRYSTAL_RAND_Y6 355


/* initilization of timer */
#define TIMER_X 50
#define TIMER_Y 370
#define TIMER_SECS 10
#define TIMER_TICKS 0

/* initilization of score*/
#define SCORE_X 600
#define SCORE_Y 370
#define SCORE_AMNT 0
#define MAX_SCORE 9999

typedef int bool;
#define true 1
#define false 0


typedef unsigned char UINT8;  /* for 8x8 bitmaps */
typedef unsigned int  UINT16; /* for 16x16 bitmaps*/
typedef unsigned long UINT32; /* for 32x32 bitmaps */

extern UINT16 BLACKOUT_BITMAP[BITMAP_HEIGHT];
extern UINT16 CLEAR_BITMAP[BITMAP_HEIGHT];
extern UINT16 PLAYER_BITMAP[BITMAP_HEIGHT];
extern UINT16 CRYSTAL_BITMAP[BITMAP_HEIGHT];

#endif