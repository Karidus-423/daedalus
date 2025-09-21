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
	int8_t r;
	int8_t g;
	int8_t b;
	int8_t a;
}Color;

void UpdateApp(Engine* engine);
void DrawApp(Engine* engine);
