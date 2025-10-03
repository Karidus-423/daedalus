#pragma once

#include <SDL3/SDL.h>
#include "../vectors/vectors.h"
#include "../engine/engine.h"

typedef struct _Color{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
}Color;

void RenderPixel(SDL_Renderer* renderer, Vec2 pos, Color color);
void Render2DLine(SDL_Renderer* renderer, Vec2 alpha, Vec2 beta, Color color);
void RenderPolygon(SDL_Renderer* renderer, Vec2 alpha, Vec2 beta, Vec2 charlie, Color color);
void RenderApp(Engine* engine);
