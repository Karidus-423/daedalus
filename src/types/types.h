#pragma once

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_stdinc.h>

#define NULL_TERMINATOR '\0'

typedef float f32;
typedef double f64;
typedef long double f80;

typedef struct _DyanmicArray {
  void *data;
  Uint32 stored;
  Uint32 limit;
} DyamicArray;

typedef struct _List {
  struct _List *prev;
  void *data;
  struct _List *next;
} List;

typedef struct _Array{
	void* data;
	Uint32 len;
}Array;

typedef struct _String{
	char* chars;
	Uint32 len;
}String;

typedef struct _Token{
	List* tokens;
	Uint32 size;
}Token;

//STRINGS
Uint32 CountCharInString(char* bfr, char c);
Token* StringParse(Array* str, char delimiter);

//ARRAYS
Array* ArrayGetSub(Array* arr, size_t t_size, Uint32 start, Uint32 end);

//DYANMIC ARRAYS

//LISTS
List *CreateNode(void *data);
List *ListSearch(List *head, void *data);
void ListInsert(List* old_node, List* new_node);
void ListDelete(List** head, List* node);
void ListFree(List *head);
