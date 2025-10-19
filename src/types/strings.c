#include "types.h"
#include <SDL3/SDL_stdinc.h>
#include <string.h>

// Parses src and makes dest the String that was split by the delimiter.
// When dest is == NULL. Then the str has not more tokens to parse.
//@return : void
void String_ParseStream(String* src, String* dest, char delimiter);

//TODO: Test after String_GetSub
//@return : List of tokens split by the passed delimiter.
List* String_Parse(String* str, char delimiter)
{
    List* token_list = SDL_malloc(sizeof(List));
    Uint32 start = 0;
    for (Uint32 i = 0; i < str->len; ++i) {
        if (str->chars[i] == delimiter) {
            String* tok = String_GetSub(str, start, i);

            if (token_list->data == NULL) {
                memcpy(token_list, List_CreateNode(tok), sizeof(List));
            }else{
				List* new_tok = List_CreateNode(tok);
				List_Insert(token_list, new_tok);
			}
            start = i + 1;
        }
    }

    return token_list;
}

//TODO: Test before String_Parse
String* String_GetSub(String* str, Uint32 begin, Uint32 end)
{
    String* sub = SDL_malloc(sizeof(String));
	
	//TODO: Finish implementation.
	memcpy(sub->chars,str->chars + begin,sizeof(char));

    return sub;
}

//@return : Uint32 | Represents the number of characters in the passed char*, counting the
//NULL_TERMINATOR '\0'
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

