#ifndef SOUPC_STRINGS
#define SOUPC_STRINGS
#include <SDL3/SDL_intrin.h>
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>

#define NULL_TERMINATOR_OFFSET 1

typedef struct _StringList{ 
	char* string;			  
	_StringList* next;      
}StringList;				  

//Remove the first instance of the found `arg_sub` in `arg_string`. ==Warning: Memory must be freed.==
//@return: New string that lacks the passed `arg_sub`.
//@return-err: NULL
char* RemoveSubString(const char* string,const char* sub);
//Parse the given `string` by the `delimiter`. ==Warning: Memory must be freed==.
//@return: Array of strings split by the `delimiter`.
//@return-err: NULL
char** ParseStringChar(const char * string, char delimiter);
//Get the length of a string.
//@return: A `Uint64` representing the length of `string`.
//@return-err: If the string is not NULL terminated, return -1.
Uint64 StringLength(const char* string);

#endif // !SOUPC_STRINGS


#define SOUPC_STRINGS_IMPLEMENTED
#ifdef SOUPC_STRINGS_IMPLEMENTED

char** ParseStringChar(const char *string, char delimiter)
{
	Uint64 string_len = StringLength(string);

	StringList* tokens = (StringList*)SDL_malloc(sizeof(StringList));

	//Should shorten string later to save memory.
	char* tmp_string = (char*)SDL_malloc(sizeof(char*));
	for (int i = 0; i < string_len; ++i) {
		//Save current string.
		tmp_string[i] = string[i];
		if (string[i] == delimiter) {
			//Add to final array.
			//Restart string.
		}
	}

	return tokens;
}

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


