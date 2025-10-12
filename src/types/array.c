#include "types.h"
#include <SDL3/SDL_stdinc.h>



Array* GetSubArray(Array* arr, size_t t_size, Uint32 start, Uint32 end)
{
    Uint32 sub_size = end - start;
	Array* result = SDL_malloc(sizeof(Array));

    void* sub = SDL_malloc(t_size * sub_size);
    memcpy(sub, arr + (start * t_size), (t_size * sub_size));

	result->size = sub_size;
	result->data = sub;

    return result;
}
