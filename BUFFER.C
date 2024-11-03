#include <osbind.h>
#include <stdio.h>
#include "const.h"
#include "renderer.h"
#include "model.h"
#include "event.h"

#define CLOCK 0x462
#define MAX_HEIGHT 16
#define BUFFER_SIZE 32000

typedef unsigned long ULONG32;

ULONG32 getTime();

int main(){
	UINT8 staticBuffer[BUFFER_SIZE];
	UINT8 buffer1[BUFFER_SIZE];
	UINT8 buffer2[BUFFER_SIZE];
	
	return 0;
}


ULONG32 getTime(){
	long old_ssp;
	ULONG32 timeNow;
	long *timer = (long *)CLOCK;

	old_ssp = Super(0);
	timeNow = *timer;
	Super(old_ssp);
	return timeNow;
}