#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

typedef struct AppState {
  bool running;
  const char *title;
  int width;
  int height;
  SDL_Window *win;
  SDL_Renderer *rndr;
  SDL_Texture *txtr;
  SDL_Event event;
} AppState;

typedef struct {
  int size;
  SDL_FPoint pos;
  SDL_Vertex *vertices;
} Polygon;

bool InitApp(AppState *app);
void DenitApp(AppState *app);
void HandleEvents(AppState *app);
void DrawApp(AppState *app, Polygon obj, float theta);
Polygon BuildPolygon(int vertices);
