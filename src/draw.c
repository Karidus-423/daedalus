#include <SDL3/SDL_filesystem.h>
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_storage.h>
#include <SDL3/SDL_surface.h>

#include <stdio.h>

#include "main.h"
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

void DrawPolygon(SDL_Renderer* renderer, Vec2 alpha, Vec2 beta, Vec2 charlie, Color color)
{
    DrawLine2D(renderer, alpha, beta, color);
    DrawLine2D(renderer, beta, charlie, color);
    DrawLine2D(renderer, charlie, alpha, color);
}


void DrawApp(Engine* engine)
{
    SDL_Renderer* renderer = engine->renderer;

	DrawLine2D(renderer, (Vec2){0,400}, (Vec2){400,800}, (Color){0,255,0,255});
}
