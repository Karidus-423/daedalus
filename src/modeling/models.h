#pragma once

#include <SDL3/SDL.h>
#include "../io/io.h"
#include "../types.h"
#include "../vectors/vectors.h"

class Model{
	Vec3* vertices;
	Polygon* faces;
	Model(const char *filename);
};
