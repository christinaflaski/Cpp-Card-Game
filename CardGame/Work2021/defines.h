#pragma once
#include <stdlib.h>
#include <random>

#define CANVAS_WIDTH 28.0f
#define CANVAS_HEIGHT 18.5f
#define ASSET_PATH "assets\\"
#define PLAYER_SIZE 8.0f
#define CARD_SIZE 6.0f
#define SETCOLOR(c,r,g,b){c[0]=r; c[1]=g; c[2]=b;}


inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}
