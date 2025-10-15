#include "io.h"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>
#include <string.h>


// Check if the given path/filename is of the passed filetype.
bool IsFileType(const char* filename, const char* filetype)
{
    // Parse filaname till last set of '.'.
    Token* extensions = ParseString(filename, '.');
    List* last_token = &extensions->tokens[extensions->size];

    if (last_token == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "IsFileType no file extensions for %s", filename);

        SDL_free(extensions);
        return false;
    }

    char* extension = last_token->data;
    if (strcmp(filetype, extension)) {
        SDL_free(extensions);
        return true;
    }

    SDL_free(extensions);
    return false;
}

// Return the contents of a file as a char* buffer.
// Must be freed when done with buffer.
char* ReadFile(const char* filename)
{
    char* data = (char*)SDL_LoadFile(filename, NULL);
    if (data == NULL) {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL LoadFile: %s", SDL_GetError());
        return NULL;
    }

    return data;
}
