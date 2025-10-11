#include "io.h"
#include <SDL3/SDL_stdinc.h>
#include <string.h>

//Returns a struct that stores a list of tokens split by the
//delimiter and the number of tokens.
Tokens* ParseString(const char *str, char delimiter){
	Tokens* tokens = SDL_malloc(sizeof(Tokens));

	return tokens;
}

//Check if the given path/filename is of the passed filetype.
bool IsFileType(const char *filename, const char *filetype){
	char* extension;
	//Get file extension.
	if (strcmp(filetype, extension)){

	}
	return false;
}


//Return the contents of a file as a char* buffer.
//Must be freed when done with buffer.
char* ReadFile(const char* filename){
	char* data = (char*)SDL_LoadFile(filename, NULL);
	if (data == NULL){
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL LoadFile: %s", SDL_GetError());
		return NULL;
	}

	return data;
}
