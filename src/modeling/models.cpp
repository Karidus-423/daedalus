#include "models.h"
#include <SDL3/SDL_stdinc.h>
#include <cstdio>
#include <string>

Model::Model(std::string filename){
	char* data = ReadFile(filename.c_str());
	printf("%s",data);

	//If v comes after \n. Then new vec is found. Read all of that.
	//If f comes after \n. Then a new face entry is found.
}

