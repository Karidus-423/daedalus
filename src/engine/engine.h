#pragma once

#include <SDL3/SDL.h>

typedef struct _Engine
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
	const char* dir;
} Engine;

void UpdateEngine(Engine* engine);
