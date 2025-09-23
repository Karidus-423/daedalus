#include "../main.h"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>

#define SUCCESS true;
#define FAILURE false;

bool Test_RemoveSubString(const char* string, const char* sub){
	const char* s1 = "ACABAD";
	const char* s2 = "ABA";

	char* expected = "ACD";
	char* actual = RemoveSubString(s1, s2);
	if(SDL_strcmp(expected, actual) != 0){
		LogTestFailure("RemoveSubstring", expected, actual);
		return FAILURE;
	}

	return SUCCESS;
}
