#include "types.h"
#include <SDL3/SDL_stdinc.h>

Uint32 String_GetLen(const char* string)
{
    Uint32 size = 0;

    char c;
    int i = 0;
    while (c != NULL_TERMINATOR) {
        c = string[i];
        ++i;
    }

    return size;
}

Uint32 String_CountCharsIn(String* bfr, char ch)
{
    Uint32 count = 0;

    char c = ' ';
    int i = 0;
    while (c != NULL_TERMINATOR) {
        c = bfr->chars[i];
        if (ch == c) {
            count++;
        }
    }

    return count;
}

String* String_GetSub(String* str, Uint32 begin, Uint32 end)
{
    String* sub = SDL_malloc(sizeof(String));
    // TODO: Run algorithm.
    return sub;
}

// Returns a struct that stores a list of tokens split by the
// delimiter and the number of tokens.
Token* String_Parse(String* str, char delimiter)
{
    Token* result = SDL_malloc(sizeof(Token));
    int str_size = String_GetLen(str->chars);

    int start = 0;
    int size = 0;
    for (int i = 0; i < str_size; ++i) {
        char c = str->chars[i];

        if (c == delimiter || c == '\0') {
            String* sub = String_GetSub(str, start, str_size);
            if (result->tokens == NULL) {
                List* head = CreateNode(sub);
                result->tokens = head;
            } else {
                List* token = CreateNode(sub);
                ListInsert(result->tokens, token);
            }
            start = i;
        }
        ++size;
    }

    return result;
}
