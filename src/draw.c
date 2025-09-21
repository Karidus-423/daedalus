#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>

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

Model* LoadModel(char* filename)
{
	Model* model = SDL_calloc(1,sizeof(Model));
	Sint8 vertices[2] = {0,5};
	model->vertices = vertices;

	return model;
}

void DrawApp(Engine* engine)
{
    SDL_Renderer* renderer = engine->renderer;
}
