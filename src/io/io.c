#include "io.h"
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>


// Check if the given path/filename is of the passed filetype.
bool File_IsType(const String* filename, const String* filetype)
{
	List* tokens = String_Parse(filename, '.');
	if (tokens == NULL) {
		//TODO: Handle this error gracefully.
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "String Parse head node NULL.");
	}
	String* tok = (String*)tokens->data;

	if (String_Equal(tok, filetype) == true) {
		return true;
	}

	return false;
}

// Return the contents of a file as a char* buffer.
// Must be freed when done with buffer.
String* File_Read(const String* filename)
{
	//TODO: Make this to only call the OS once.
	SDL_IOStream * ctx = SDL_IOFromFile(filename->chars, "r");
	SDL_SeekIO(ctx, 0, SDL_IO_SEEK_END);
	Sint64 size = SDL_TellIO(ctx);
	SDL_CloseIO(ctx);

    char* data = (char*)SDL_LoadFile(filename->chars, NULL);
    if (data == NULL) {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL LoadFile: %s", SDL_GetError());
        return NULL;
    }

	String* str = SDL_malloc(sizeof(String));
	str->chars = data;
	str->len = size;

    return str;
}
