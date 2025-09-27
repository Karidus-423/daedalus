#ifndef SOUPC_STRINGS
#define SOUPC_STRINGS
#include <SDL3/SDL_intrin.h>

#define NULL_TERMINATOR_OFFSET 1

char* RemoveSubString(const char* string,const char* sub);
Uint64 StringLength(const char* start);

#endif // !SOUPC_STRINGS


#ifdef SOUPC_STRINGS_IMPLEMENTED

Uint64 StringLength(const char* start)
{
	const char* end;
	for (end = start; *end; ++end)
		;
	return (end - start);
}

char* RemoveSubString(const char* string, const char* sub)
{
	int str_len = StringLength(string);
	int sub_len = StringLength(sub);

	Uint8** lookup = SDL_calloc(str_len, sizeof(Uint8*));
	for (int i = 0; i < str_len; ++i) {
		lookup[i] = SDL_calloc(sub_len, sizeof(Uint8));
	}

	Uint8* filter = SDL_calloc(str_len, sizeof(Uint8));
	for (int i = 0; i < str_len; ++i) {
		for (int j = 0; j < sub_len; ++j) {

			if (string[i] == sub[j]) {
				if (i > 0 && j > 0) {
					lookup[i][j] = lookup[i - 1][j - 1] + 1;
				} else {
					lookup[i][j] = 1;
				}
			}

			if (lookup[i][j] > 0) {
				filter[i] = 1;
			}
		}
	}

	char* s = SDL_calloc(str_len, sizeof(char));

	SDL_free(lookup);
	return s;
}

#endif // SOUPC_STRINGS_IMPLEMENTED


