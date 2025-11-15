#include <SDL3/SDL.h>
#include <SDL3/SDL_assert.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

#define APP_NAME "Daedalus"
#define APP_VERSION "v1.0.0"
#define APP_IDENTIFIER "com.daedalus.engine"
#define APP_CREATOR "Karidus"
#define APP_LICENCE "MIT"
#define APP_REPO "https://github.com/Karidus-423/Daedalus"
#define APP_TYPE "Game Engine"


typedef struct _ArrayS32{
	Sint32* items;
	Sint32 size;
}ArrayS32;

typedef struct _ArrayBool{
	bool* items;
	Sint32 size;
}ArrayBool;

bool ArrayBool_Get(ArrayBool array, Sint32 idx){
	if (idx > 0 && idx < array.size) {
		return array.items[idx];
	}

	return false;
}

void Error_HandleSDL(const char* err_msg, const char* function_name){
	SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s, FUNCTION: %s", err_msg, function_name);
}

bool Init_SdlAppMetadata(){
	bool base_meta = SDL_SetAppMetadata(APP_NAME, APP_VERSION, APP_IDENTIFIER);
	bool creator_meta = SDL_SetAppMetadataProperty(APP_CREATOR, SDL_PROP_APP_METADATA_CREATOR_STRING);
	bool licence_meta = SDL_SetAppMetadataProperty(APP_LICENCE, SDL_PROP_APP_METADATA_COPYRIGHT_STRING);
	bool url_meta = SDL_SetAppMetadataProperty(APP_REPO, SDL_PROP_APP_METADATA_URL_STRING);
	bool type_meta = SDL_SetAppMetadataProperty(APP_TYPE, SDL_PROP_APP_METADATA_TYPE_STRING);

	SDL_assert(base_meta && creator_meta && licence_meta && url_meta && type_meta);
	ArrayBool metadata = {
		.items = (bool[]){base_meta, creator_meta, licence_meta, url_meta, type_meta},
		.size = 5,
	};

	for (Sint32 i = 0; i < metadata.size; ++i) {
		bool meta_result = ArrayBool_Get(metadata,i);
		if (meta_result == false) {
			Error_HandleSDL(SDL_GetError(), "Init_SdlAppMetadata");
		}
	}

	return true;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv){
	if (!Init_SdlAppMetadata()) {
		Error_HandleSDL(SDL_GetError(), "SDL_AppInit");
		return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
}

