#include <SDL3/SDL.h>

typedef Sint32 S32;
typedef Uint32 U32;

void Error_HandleSDL(SDL_LogPriority priority, SDL_LogCategory category, const char* err_src);
