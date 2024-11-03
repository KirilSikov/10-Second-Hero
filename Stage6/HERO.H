

#ifndef HERO_H
#define HERO_H


#include <osbind.h>
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "renderer.h"
#include "model.h"
#include "event.h"

ULONG32 getTime();

void processSyncEvents(struct Model *model, ULONG32 *currTimerTicks, 
	ULONG32 *timerTime, bool *gameIsRunning);


#endif