#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>

#include <SDL3/SDL_assert.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>

#include "./utils/utils.hpp"

#define APP_NAME "Daedalus"
#define APP_VERSION "v1.0.0"
#define APP_IDENTIFIER "com.daedalus.engine"
#define APP_CREATOR "Karidus"
#define APP_LICENCE "MIT"
#define APP_REPO "https://github.com/Karidus-423/Daedalus"
#define APP_TYPE "Game Engine"


static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

bool Init_SdlAppMetadata(){
	if(!SDL_SetAppMetadata(APP_NAME, APP_VERSION, APP_IDENTIFIER)){
		Error_HandleSDL(SDL_LOG_PRIORITY_WARN,SDL_LOG_CATEGORY_APPLICATION,"SDL_SetAppMetadata");
	}
	if(!SDL_SetAppMetadataProperty(APP_CREATOR, SDL_PROP_APP_METADATA_CREATOR_STRING)){
		Error_HandleSDL(SDL_LOG_PRIORITY_WARN,SDL_LOG_CATEGORY_APPLICATION,"SDL_SetAppMetadataProperty");
	}
	if(!SDL_SetAppMetadataProperty(APP_LICENCE, SDL_PROP_APP_METADATA_COPYRIGHT_STRING)){
		Error_HandleSDL(SDL_LOG_PRIORITY_WARN,SDL_LOG_CATEGORY_APPLICATION,"SDL_SetAppMetadataProperty");
	}
	if(!SDL_SetAppMetadataProperty(APP_REPO, SDL_PROP_APP_METADATA_URL_STRING)){
		Error_HandleSDL(SDL_LOG_PRIORITY_WARN,SDL_LOG_CATEGORY_APPLICATION,"SDL_SetAppMetadataProperty");
	}
	if(!SDL_SetAppMetadataProperty(APP_TYPE, SDL_PROP_APP_METADATA_TYPE_STRING)){
		Error_HandleSDL(SDL_LOG_PRIORITY_WARN,SDL_LOG_CATEGORY_APPLICATION,"SDL_SetAppMetadataProperty");
	}

	return true;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv){
	if (!Init_SdlAppMetadata()) {
		Error_HandleSDL(SDL_LOG_PRIORITY_ERROR,SDL_LOG_CATEGORY_APPLICATION,"Init_SdlAppMetadata");
		return SDL_APP_FAILURE;
	}

	if(!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO)){
		Error_HandleSDL(SDL_LOG_PRIORITY_ERROR,SDL_LOG_CATEGORY_APPLICATION,"SDL_Init");
		return SDL_APP_FAILURE;

	};

	if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", 640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    return SDL_APP_CONTINUE;

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
	switch (event->type) {
		case SDL_EVENT_QUIT: return SDL_APP_SUCCESS;
	}

	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void *appstate){
	  const double now = ((double)SDL_GetTicks()) / 1000.0;  /* convert from milliseconds to seconds. */
    /* choose the color for the frame we will draw. The sine wave trick makes it fade between colors smoothly. */
    const float red = (float) (0.5 + 0.5 * SDL_sin(now));
    const float green = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
    const float blue = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));
    SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);  /* new color, full alpha. */

    /* clear the window to the draw color. */
    SDL_RenderClear(renderer);

    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){}
