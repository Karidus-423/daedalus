#include "models.h"
#include <SDL3/SDL_stdinc.h>


Model* LoadModel(const char* filename)
{
    char* bfr = ReadFile(filename);
    Model* model = SDL_malloc(sizeof(Model));


    return model;
}
