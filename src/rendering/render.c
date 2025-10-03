#include "render.h"
#include "../vectors/vectors.h"

void RenderPixel(SDL_Renderer* renderer, Vec2 pos, Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderPoint(renderer, pos.x, pos.y);
}

void Render2DLine(SDL_Renderer* renderer, Vec2 alpha, Vec2 beta, Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderLine(renderer, alpha.x, alpha.y, beta.x, beta.y);
}

void RenderPolygon(SDL_Renderer* renderer, Vec2 alpha, Vec2 beta, Vec2 charlie, Color color)
{
    Render2DLine(renderer, alpha, beta, color);
    Render2DLine(renderer, beta, charlie, color);
    Render2DLine(renderer, charlie, alpha, color);
}

void RenderApp(Engine* engine)
{
    SDL_Renderer* renderer = engine->renderer;
    Render2DLine(renderer, (Vec2){0, 400}, (Vec2){400, 800}, (Color){0, 255, 0, 255});
}
