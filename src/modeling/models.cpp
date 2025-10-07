#include "models.h"
#include <SDL3/SDL_stdinc.h>
#include <cstdio>

Model::Model(const char *filename){
	char* data = ReadFile(filename);

	//If v comes after \n. Then new vec is found. Read all of that.
	//If f comes after \n. Then a new face entry is found.
}

