#include "types.h"

Uint32 CountCharInString(char* bfr, char ch)
{
    Uint32 count = 0;

    char c = ' ';
    int i = 0;
    while (c != NULL_TERMINATOR) {
        c = bfr[i];
        if (ch == c) {
            count++;
        }
    }

    return count;
}

// Returns a struct that stores a list of tokens split by the
// delimiter and the number of tokens.
Token* ParseString(Array* str, char delimiter)
{
    Token* result = SDL_malloc(sizeof(Token));
    int str_size = str->size;

    int start = 0;
    int size = 0;
    for (int i = 0; i < str_size; ++i) {
        char c = ((char*)str->data)[i];
        if (c == delimiter || c == '\0') {
            Array* sub = GetSubArray(str, sizeof(char), start, size);
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
