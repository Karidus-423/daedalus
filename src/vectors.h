#pragma once

#include "main.h"
#include <SDL3/SDL_stdinc.h>

typedef struct _Vec2{
	f32 x;
	f32 y;
}Vec2;

typedef struct _Vec3{
	f32 x;
	f32 y;
	f32 z;
}Vec3;

typedef struct _Line3D{
	Vec3 start;
	Vec3 end;
}Line3D;

typedef struct _Polygon{
	Line3D line_1;
	Line3D line_2;
	Line3D line_3;
}Polygon;

// Sint8* vertices;
// f32* normals;
typedef struct _Model{
	Sint8* vertices;
	f32* normals;
}Model;
