#pragma once

#include <SDL3/SDL.h>
#include "../types.h"
#include "../vectors/vectors.h"

// Model Fields:
// Uint8* vertices;
// f32* normals;
typedef struct _Model{
	Vec3* vertices;
	Uint32* faces;
}Model;

Model* LoadModel(char* filename);
