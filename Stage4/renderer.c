#include "renderer.h"
#define MAX_HEIGHT 16

int main(){
	struct Model *tenSecondHero;
	UINT16 *base = Physbase();
	render(tenSecondHero,base);
	return 0;
}

void render_player(const struct Player *Player,UINT16 *base){
	plotBitmap16(base,Player->x,Player->y,PLAYER_BITMAP,MAX_HEIGHT);
	return;
}

void render_crystal(const struct Crystal *crystal,UINT16 *base){
	plotBitmap16(base,crystal->x,crystal->y,CRYSTAL_BITMAP,MAX_HEIGHT);
	return;
}

void render_platform(const struct Platform *platform[],UINT16 *base){
	int i;
	for (i = 0;i < 6; i++) {
		plotBitmap16(base,platform[i]->x,platform[i]->y,BLACKOUT_BITMAP,MAX_HEIGHT);
	}
	return;
}

void render_timer(const struct TimeRemaining *timeLeft, UINT16 *base){
	plotBitmap16(base,timeLeft->x,timeLeft->y,BLACKOUT_BITMAP,MAX_HEIGHT);
	return;
}

void render_score(const struct Score *score,UINT16 *base){
	plotBitmap16(base,score->x,score->y,BLACKOUT_BITMAP,MAX_HEIGHT);
	return;
}

void render(const struct Model *model, UINT16 *base){
	clearScreen();
	initModel(model);

	/*
	render_player(&model->player,base);
	render_platform(&model->platforms,base);
	render_crystal(&model->crystal,base);
	render_timer(&model->timeLeft,base);
	render_score(&model->score,base);
	*/
	return;
}