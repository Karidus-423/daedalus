#include "io.h"

//On error returns NULL.
char* ReadFile(const char* filename){
	char* data = (char*)SDL_LoadFile(filename, NULL);
	if (data == NULL){
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL LoadFile: %s", SDL_GetError());
		return NULL;
	}
	return data;
}
