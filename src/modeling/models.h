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

Model *LoadModel(const char *filename);
