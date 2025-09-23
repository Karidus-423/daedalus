#include "../main.h"
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>

#define LOG_RED "\33[0:31m\\]"
#define LOG_FLUSH "\33[0m\\]"

// TODO: Make this better.
void LogTestFailure(char* test_name, char* expect, char* actual)
{
    printf("%sTEST%s FAILURE: %s | Expected: %s ~~~ GOT: %s\n", LOG_RED, LOG_FLUSH, test_name,
           expect, actual);
}
