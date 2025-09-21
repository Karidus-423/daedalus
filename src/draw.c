#include "main.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>

#define TEXTURE_SIZE 150
#include "vectors.h"

void DrawPixel(SDL_Renderer* renderer, Vec2 pos, Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderPoint(renderer, pos.x, pos.y);
}

void DrawLine2D(SDL_Renderer* renderer, Vec2 alpha, Vec2 beta, Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderLine(renderer, alpha.x, alpha.y, beta.x, beta.y);
}

void DrawApp(Engine* engine)
{
    SDL_Renderer* renderer = engine->renderer;

    DrawPixel(renderer, (Vec2){400, 500}, (Color){0, 255, 255, 255});
	DrawLine2D(renderer, (Vec2){400,0}, (Vec2){800,800}, (Color){255,0,255,255});
	DrawLine2D(renderer, (Vec2){0,800}, (Vec2){800,800}, (Color){255,0,255,255});
}
