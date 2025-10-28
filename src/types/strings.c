#include "types.h"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>
#include <string.h>

// Parses src and makes dest the String that was split by the delimiter.
// When dest is == NULL. Then the str has not more tokens to parse.
//@return : void
void String_ParseStream(String* src, String* dest, char delimiter)
{
    Uint32 start = 0;
    Uint32 end = 0;

    for (Uint32 i = 0; i < src->len; ++i) {
        char ch = src->chars[i];
        start = end;

        if (ch == delimiter) {
            end = i;
            String* parsed = String_GetSub(src, start, end);
            SDL_memcpy(dest, parsed, sizeof(String));
        }
    }

    dest = NULL;
}

//@return : List of tokens split by the passed delimiter, the first node is the last token parsed.
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

String* String_Init(const char* string)
{
    String* str = SDL_malloc(sizeof(String));
    Uint32 len = String_GetLen(string);

    str->chars = string;
    str->len = len;

    return str;
}

bool String_ContainsChar(const String* str, char ch){
	for (Uint32 i = 0; i < str->len; ++i) {
		if (str->chars[i] == ch) {
			return true;
		}
	}
	return false;
}

bool String_Equal(const String* s1, const String* s2)
{
	if (s1 == NULL | s2 == NULL) {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "String_Equal NULL : %s", s1 == NULL ? "s1" : "s2");
		//TODO: Handle this gracefully.
		return false;
	}

    if (s1->len != s2->len) {
        return false;
    }

    for (Uint32 i = 0; i < s1->len; ++i) {
        if (s1->chars[i] != s2->chars[i]) {
            return false;
        }
    }

    return true;
}

//@return : Uint32 | Represents the number of characters in the passed char*, counting the
// NULL_TERMINATOR '\0'
Uint32 String_GetLen(const char* string)
{
    Uint32 size = 0;

    char c = ' ';
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
