#ifndef DAEDALUS_IO
#define DAEDALUS_IO

#ifdef __cplusplus
extern "C" {
#endif

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_log.h>
char * ReadFile(const char *filename); // or whatever the exact signature is

#ifdef __cplusplus
}
#endif

#endif
