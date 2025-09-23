#include "main.h"
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>

Uint64 StringLength(const char* start)
{
    const char* end;
    for (end = start; *end; ++end)
        ;
    return (end - start);
}

char* RemoveSubString(const char* string, const char* sub)
{
    int s_len = StringLength(string);
    char* s = SDL_calloc(s_len - StringLength(sub), sizeof(char));

    int** lookup = SDL_calloc(s_len, sizeof(Uint8));
	//NOTE: Check if i,j should be = 1.
    for (int i = 1; i < s_len; ++i)
    {
        for (int j = 1; j < s_len; ++j)
        {
            if (lookup[i] == lookup[j])
            {
				lookup[i][j] = lookup[i-1][j-1] + 1;
            }
        }
    }

    return s;
}
