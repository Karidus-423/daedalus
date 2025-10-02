#include "data-structs.h"
#include <SDL3/SDL_stdinc.h>
#include <string.h>

// Check if there is a need to grow the array.
// If there is no need NULL is returned.
// If there is a need then a DynamicArray* is returned.
void UpdateDynamicArray(DynamicArray* d_array, Uint64 quantity, size_t type_size)
{
    Uint64 stored = d_array->stored;
    stored = quantity;

    if (stored == d_array->limit) {
        // Need to reallocate.
        DynamicArray* new_d_array = InitDynamicArray(type_size, d_array->limit * 2);
        new_d_array->stored = quantity;
        // Copy old contents of d_array to new_d_array.
        memcpy(new_d_array->array, d_array->array, d_array->limit);
		d_array = new_d_array;

		SDL_free(d_array->array);
    }
}

DynamicArray* InitDynamicArray(size_t type_size, Uint32 start_size)
{
    DynamicArray* d_array = SDL_malloc(sizeof(DynamicArray));

    d_array->limit = start_size;
    d_array->stored = 0;
    d_array->array = SDL_malloc(type_size);

    return d_array;
}
