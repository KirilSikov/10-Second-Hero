#include "model.h"
#include "const.h"
#include "raster.h"
#include <osbind.h>

void render_player(const struct Player *Player,UINT16 *base);

void render_crystal(const struct Crystal *crystal,UINT16 *base);

void render_score(const struct Score *score,UINT16 *base);

void render_timer(const struct TimeRemaining *timeLeft, UINT16 *base);

void render_platform(const struct Platform *platform[],UINT16 *base);

void render(const struct Model *model, UINT16 *base);