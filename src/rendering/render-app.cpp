#include "render.h"

void RenderApp(Engine* engine)
{
    SDL_Renderer* renderer = engine->renderer;
    Render2DLine(renderer, (Vec2){0, 400}, (Vec2){400, 800}, (Color){0, 255, 0, 255});
}
