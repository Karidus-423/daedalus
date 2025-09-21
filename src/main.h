#pragma once

#include <SDL3/SDL.h>
#include <stdint.h>

typedef float f32;
typedef double f64;
typedef long double f80;

typedef struct _Engine
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
} Engine;

typedef struct _Color{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
}Color;

void UpdateApp(Engine* engine);
void DrawApp(Engine* engine);

