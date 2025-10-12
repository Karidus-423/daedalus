#pragma once

#include "../io/io.h"
#include "../types/types.h"
#include "../vectors/vectors.h"
#include <SDL3/SDL.h>

// Vec3* vertices;
// Polygon* faces;
typedef struct _Model {
  Vec3 *vertices;
  Polygon *faces;
} Model;

typedef struct _ModelFileData{
	Uint32 vert_start;
	Uint32 vert_size;
	Uint32 faces_start;
	Uint32 faces_size;
}ModelFileData;

Model *LoadModel(const char *filename);
