#pragma once

#include <SDL3/SDL.h>
#include "../types/types.h"

// f32 x;
// f32 y;
typedef struct _Vec2{
	f32 x;
	f32 y;
}Vec2;

// f32 x;
// f32 y;
// f32 z;
typedef struct _Vec3{
	f32 x;
	f32 y;
	f32 z;
}Vec3;

// Vec3 start;
// Vec3 end;
typedef struct _Line3D{
	Vec3 start;
	Vec3 end;
}Line3D;

// Line3D line_1;
// Line3D line_2;
// Line3D line_3;
typedef struct _Polygon{
	Line3D line_1;
	Line3D line_2;
	Line3D line_3;
}Polygon;

