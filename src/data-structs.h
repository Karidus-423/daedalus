#pragma once

#include <SDL3/SDL_stdinc.h>

typedef struct _DynamicArray{
	Uint64 limit;
	Uint64 stored;
	void* array;
}DynamicArray;

DynamicArray* InitDynamicArray(size_t type_size, Uint32 start_size);
void UpdateDynamicArray(DynamicArray* d_array, Uint64 quantity, size_t type_size);
