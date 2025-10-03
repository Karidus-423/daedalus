#pragma once

#include <SDL3/SDL.h>
#include "../types.h"

typedef struct _Model{
	Uint8* vertices;
	f32* normals;
}Model;

Model* LoadModel(char* filename);
