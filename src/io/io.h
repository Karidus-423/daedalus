#ifndef DAEDALUS_IO
#define DAEDALUS_IO


#include <SDL3/SDL_error.h>
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_log.h>

#include "../types/types.h"

#define END_OF_FILE -1

bool IsFileType(const char* filename, const char* filetype);
char* ReadFile(const char* filename);

#endif
