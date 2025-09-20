#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <stdio.h>
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>

typedef struct _Engine
{
    SDL_Window* window;
} Engine;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv)
{
    SDL_SetAppMetadata("Daedalus Engine", "v0.0.1", "com.daedalus-engine");

    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) == false)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL INIT ERROR: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Window* window =
        SDL_CreateWindow("Daedalus Dev v0.0.1", 800, 800, SDL_WINDOW_HIDDEN | SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL CREATE WINDOW ERROR: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_GPUDevice* gpu = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_INVALID, false, NULL);
    if (gpu == NULL)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL CREATE GPU ERROR: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (SDL_ClaimWindowForGPUDevice(gpu, window) == false)
    {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL CLAIM GPU FOR WINDOW ERROR: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    Engine engine = {
        .window = window,
    };

    *(Engine**)appstate = &engine;

    SDL_ShowWindow(window);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return SDL_APP_CONTINUE;
        break;
    }
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    SDL_free(appstate);
}
