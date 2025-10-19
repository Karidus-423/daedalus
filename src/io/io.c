#include "io.h"
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>
#include <string.h>


// Check if the given path/filename is of the passed filetype.
bool File_IsType(const char* filename, const char* filetype)
{
    // Parse filaname till last set of '.'.
	String str = {
		.chars = filename,
		.len = String_GetLen(filename),
	};

	//TODO: Fix this two problems.
    Token* extensions = String_Parse(&str, '.');
	if (extensions == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "IsFileType no file extensions for %s", filename);

        SDL_free(extensions);
        return false;
	}

	char* ft = "obj";
    List* last_token = List_Search(extensions->list, ft);
	if (last_token == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "List Search  could not find, %s", ft);

        SDL_free(extensions);
        return false;
	}

    char* extension = (char*)last_token->data;
    if (strcmp(filetype, extension)) {
        SDL_free(extensions);
        return true;
    }

    SDL_free(extensions);
    return false;
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
