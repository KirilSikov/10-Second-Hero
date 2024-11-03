/*
Names:  	Enrik R
			Kiril S

Module:		Const

Purpose: 	Contains consts, typedefs, and bitmap data to be used by other modules
*/

#ifndef CONST_H
#define CONST_H


/* */
#define BITMAP_HEIGHT 16
#define SPRITE_SIZE 16
#define XBOUNDS 640
#define YBOUNDS 400

#define IN_BOUNDS(x, y) (x >= 0 && x < XBOUNDS && y >= 0 && y < YBOUNDS)

#define SCORE_TICK 1
#define FPS 35

#define TIME_ADD 3
#define TIME_SUB 1
#define SCORE_ADD 1

/* ground initilization data*/
#define PLATFORM_AMNT 6

#define GROUND 0
#define GROUND_X 0
#define GROUND_Y 355
#define GROUND_LEN 40

/* initilization data of other platforms*/
/* platform 1*/
#define P1_X 40
#define P1_Y 280
#define P1_LEN 3
/* platform 2*/
#define P2_X 80
#define P2_Y 110
#define P2_LEN 6
/* platform 3*/
#define P3_X 150
#define P3_Y 230
#define P3_LEN 8
/* platform 4*/
#define P4_X 270
#define P4_Y 160
#define P4_LEN 10
/* platform 5*/
#define P5_X 500
#define P5_Y 205
#define P5_LEN 6

/* initilization of player */
#define PLAYER_X 340
#define PLAYER_Y 330
#define PLAYER_X_VEL 0
#define PLAYER_Y_VEL 0 
#define PLAYER_JUMP_SPEED -15
#define PLAYER_MAX_FALL_SPEED 5
#define PLAYER_RUN_SPEED 12

/* initilization of crystal */
#define CRYSTAL_X 125
#define CRYSTAL_Y 90

#define MAX_RAND 6
#define MIN_RAND 0
#define SRAND_TEST_KEY 69
#define CRYSTAL_RAND_X0 40
#define CRYSTAL_RAND_Y0 335
#define CRYSTAL_RAND_X1 60
#define CRYSTAL_RAND_Y1 260
#define CRYSTAL_RAND_X2 125
#define CRYSTAL_RAND_Y2 90
#define CRYSTAL_RAND_X3 175
#define CRYSTAL_RAND_Y3 210
#define CRYSTAL_RAND_X4 300
#define CRYSTAL_RAND_Y4 140
#define CRYSTAL_RAND_X5 525
#define CRYSTAL_RAND_Y5 185
#define CRYSTAL_RAND_X6 575
#define CRYSTAL_RAND_Y6 335


/* initilization of timer */
#define TIMER_X 10
#define TIMER_Y 380
#define TIMER_SECS 10

/* initilization of score*/
#define SCORE_X 450
#define SCORE_Y 380
#define SCORE_AMNT 0
#define MAX_SCORE 99

/* keys for the events*/
#define ESC_KEY 0x0001001B
#define ESC_ASCII 27
#define A_ASCII 97
#define A_KEY 0x001E0061
#define D_ASCII 100
#define D_KEY 0x00200064
#define SPACE_ASCII 32
#define SPACE_KEY 0x00390020

typedef int bool;
#define true 1
#define false 0

typedef unsigned char UINT8;  /* for 8x8 bitmaps */
typedef unsigned int  UINT16; /* for 16x16 bitmaps*/
typedef unsigned long UINT32; /* for 32x32 bitmaps */

typedef enum
{
	left, right
} Direction;

extern UINT16 BLACKOUT_BITMAP[BITMAP_HEIGHT];
extern UINT16 CLEAR_BITMAP[BITMAP_HEIGHT];
extern UINT16 PLAYER_BITMAP[BITMAP_HEIGHT];
extern UINT16 CRYSTAL_BITMAP[BITMAP_HEIGHT];

extern UINT16 LETTER_S[BITMAP_HEIGHT];
extern UINT16 LETTER_C[BITMAP_HEIGHT];
extern UINT16 LETTER_O[BITMAP_HEIGHT];
extern UINT16 LETTER_R[BITMAP_HEIGHT];
extern UINT16 LETTER_E[BITMAP_HEIGHT];

extern UINT16 LETTER_T[BITMAP_HEIGHT];
extern UINT16 LETTER_I[BITMAP_HEIGHT];
extern UINT16 LETTER_M[BITMAP_HEIGHT];

extern UINT16 NUMBER_0[BITMAP_HEIGHT];
extern UINT16 NUMBER_1[BITMAP_HEIGHT];
extern UINT16 NUMBER_2[BITMAP_HEIGHT];
extern UINT16 NUMBER_3[BITMAP_HEIGHT];
extern UINT16 NUMBER_4[BITMAP_HEIGHT];
extern UINT16 NUMBER_5[BITMAP_HEIGHT];
extern UINT16 NUMBER_6[BITMAP_HEIGHT];
extern UINT16 NUMBER_7[BITMAP_HEIGHT];
extern UINT16 NUMBER_8[BITMAP_HEIGHT];
extern UINT16 NUMBER_9[BITMAP_HEIGHT];

#endif