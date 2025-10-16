#pragma once

#include <SDL3/SDL.h>
#include "../vectors/vectors.h"
#include "../engine/engine.h"
#include "../modeling/models.h"

typedef struct _Color{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
}Color;

//Render Engine
void RenderApp(Engine* engine);

//Render Primitives
void RenderPixel(SDL_Renderer* renderer, Vec2 pos, Color color);
void Render2DLine(SDL_Renderer* renderer, Vec2 alpha, Vec2 beta, Color color);
void RenderPolygon(SDL_Renderer* renderer, Vec2 alpha, Vec2 beta, Vec2 charlie, Color color);

//Render Objects
void Render_Model(SDL_Renderer* renderer, Model* model);
