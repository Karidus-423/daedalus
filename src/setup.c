#include "origin.h"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdlib.h>

bool InitApp(AppState *app) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s",
                 SDL_GetError());
    return false;
  };

  app->win =
      SDL_CreateWindow(app->title, app->width, app->height, SDL_WINDOW_OPENGL);
  if (app->win == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't Create Window: %s",
                 SDL_GetError());
    return false;
  }

  app->rndr = SDL_CreateRenderer(app->win, NULL);
  if (app->rndr == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't Create Renderer: %s",
                 SDL_GetError());
    return false;
  }

  // TODO: Pixel format needs to become dynamic.
  app->txtr =
      SDL_CreateTexture(app->rndr, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_TARGET, app->width, app->height);
  if (app->rndr == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't Create Texture: %s",
                 SDL_GetError());
    return false;
  }

  // TODO: CHANGE TO USE ARENAS.

  app->bfr = malloc(sizeof(Buffer));
  app->bfr->size = app->width * app->height * sizeof(Pixel);
  app->bfr->pixels = malloc(app->bfr->size);
  app->bfr->pitch = app->width * sizeof(Pixel);

  app->running = true;
  return true;
}

void DenitApp(AppState *app) {
  SDL_DestroyRenderer(app->rndr);
  SDL_DestroyWindow(app->win);

  // TODO: Replace with Arenas
  free(app->bfr->pixels);
  free(app->bfr);
}
