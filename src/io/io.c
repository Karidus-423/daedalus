#include "io.h"
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>
#include <string.h>


//TODO: Implement
// Check if the given path/filename is of the passed filetype.
bool File_IsType(const char* filename, const char* filetype)
{
	return true;
}

// Return the contents of a file as a char* buffer.
// Must be freed when done with buffer.
String* File_Read(const char* filename)
{
	String* str = SDL_malloc(sizeof(String));

	//TODO: Make this to only call the OS once.
	SDL_IOStream * ctx = SDL_IOFromFile(filename, "r");
	SDL_SeekIO(ctx, 0, SDL_IO_SEEK_END);
	Sint64 size = SDL_TellIO(ctx);
	SDL_CloseIO(ctx);

    char* data = (char*)SDL_LoadFile(filename, NULL);
    if (data == NULL) {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL LoadFile: %s", SDL_GetError());
        return NULL;
    }

	str->chars = data;
	str->len = size;

    return str;
}
