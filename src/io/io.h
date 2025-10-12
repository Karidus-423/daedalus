#ifndef DAEDALUS_IO
#define DAEDALUS_IO


#include <SDL3/SDL_error.h>
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_log.h>

#include "../types/types.h"

#define END_OF_FILE -1
#define NULL_TERMINATOR '\0'

typedef struct _Token{
	List* tokens;
	Uint32 size;
}Token;


Token* ParseString(const char *str, char delimiter);
bool IsFileType(const char* filename, const char* filetype);
char* ReadFile(const char* filename);
Uint32 CountCharInBfr(char* bfr, char c);

#endif
