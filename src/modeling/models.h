#pragma once

#include "../io/io.h"
#include "../types.h"
#include "../vectors/vectors.h"
#include <SDL3/SDL.h>
#include <string>

class Model {
public:
  Vec3 *vertices;
  Polygon *faces;

  Model(std::string filename);
};
