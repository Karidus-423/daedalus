#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>

#include <SDL3/SDL_assert.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>

#define APP_NAME "Daedalus"
#define APP_VERSION "v1.0.0"
#define APP_IDENTIFIER "com.daedalus.engine"
#define APP_CREATOR "Karidus"
#define APP_LICENCE "MIT"
#define APP_REPO "https://github.com/Karidus-423/Daedalus"
#define APP_TYPE "Game Engine"

typedef Sint32 S32;
typedef Uint32 U32;


bool Init_SdlAppMetadata();
SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv);
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event);
SDL_AppResult SDL_AppIterate(void *appstate);
void SDL_AppQuit(void *appstate, SDL_AppResult result);
