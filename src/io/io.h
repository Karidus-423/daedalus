#ifndef DAEDALUS_IO
#define DAEDALUS_IO


#include <SDL3/SDL_error.h>
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_log.h>

#include "../types/types.h"

#define END_OF_FILE -1

bool File_IsType(const String* filename, const String* filetype);
String* File_Read(const String* filename);

#endif
