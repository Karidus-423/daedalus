#include "types.h"
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>
#include <string.h>

// Parses src and makes dest the String that was split by the delimiter.
// When dest is == NULL. Then the str has not more tokens to parse.
//@return : void
void String_ParseStream(String* src, String* dest, char delimiter);

// TODO: Test after String_GetSub
//@return : List of tokens split by the passed delimiter.
List* String_Parse(const String* str, char delimiter)
{
    List* head = List_CreateNode(NULL);

    Uint32 start = 0;
    for (Uint32 i = 0; i <= str->len; ++i) {
        char ch = str->chars[i];
        if (ch == delimiter || ch == '\0') {
            if (start - i != 0) {

                String* tok = String_GetSub(str, start, i);

                if (head == NULL) {
                    head = List_CreateNode(tok);
                } else {
                    List* new_tok = List_CreateNode(tok);
                    List_Insert(head, new_tok);
                }
                start = i + 1;
            }
        }
    }

    return head;
}

//@return: String* of substring of str.
String* String_GetSub(const String* str, Uint32 begin, Uint32 end)
{
    String* sub = SDL_malloc(sizeof(String));
    sub->len = end - begin + 1;
    sub->chars = SDL_malloc(sizeof(char) * sub->len);

    char tmp[sub->len];
    tmp[sub->len - 1] = '\0';

    for (Uint32 i = 0; i < sub->len - 1; ++i) {
        tmp[i] = str->chars[begin + i];
    }

    strcpy((char*)sub->chars, tmp);

    return sub;
}

//@return : Uint32 | Represents the number of characters in the passed char*, counting the
// NULL_TERMINATOR '\0'
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
