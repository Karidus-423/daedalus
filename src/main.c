#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "engine/engine.h"
#include "rendering/render.h"

#define IMPLEMENT_SOUP_IO
#include "../soupc/soup-io.h"

#define WIDTH 800
#define HEIGHT 800

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv)
{
    SDL_SetAppMetadata("Daedalus Engine", "v0.0.1", "com.daedalus-engine");

    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) == false)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL INIT : %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("Daedalus Dev v0.0.1", WIDTH, HEIGHT,
                                          SDL_WINDOW_HIDDEN | SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL CREATE WINDOW : %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL CREATE RENDERER : %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR32,
                                             SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
    if (texture == NULL)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL CREATE TEXTURE: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    Engine* engine = (Engine*)SDL_calloc(1, sizeof(Engine));
    if (engine == NULL)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL CALLOC ENGINE: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    engine->window = window;
    engine->renderer = renderer;
    engine->texture = texture;

    *(Engine**)appstate = engine;
    if (SDL_ShowWindow(window) == false)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL SHOW WINDOW: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    };

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    Engine* engine = (Engine*)appstate;

    // UpdateApp(engine);

    SDL_SetRenderTarget(engine->renderer, engine->texture);
    SDL_SetRenderDrawColor(engine->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(engine->renderer);

    RenderApp(engine);

    SDL_SetRenderTarget(engine->renderer, NULL);
    SDL_RenderTexture(engine->renderer, engine->texture, NULL, NULL);
    SDL_RenderPresent(engine->renderer);
    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    SDL_free(appstate);
}
