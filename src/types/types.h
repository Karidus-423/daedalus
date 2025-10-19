#pragma once

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_stdinc.h>

#define NULL_TERMINATOR '\0'

typedef float f32;
typedef double f64;
typedef long double f80;

// @field : void *data		|
// @field : Uint32 stored   | 
// @field : Uint32 limit	|
typedef struct _DyanmicArray{
  void *data;
  Uint32 stored;
  Uint32 limit;
} DynamicArray;

// void* data;
// Uint32 len;
typedef struct _Array{
	void* data;
	Uint32 len;
}Array;

// const char* chars;
// @field : Uint32 len |  Always includes the NULL_TERMINATOR in its count.
typedef struct _String{
	const char* chars;
	Uint32 len;
}String;

typedef struct _List {
  struct _List *prev;
  void *data;
  struct _List *next;
} List;



//STRINGS
Uint32 String_CountCharsIn (String* bfr, char ch);
List* String_Parse(String* str, char delimiter);
Uint32 String_GetLen(const char* string);
String* String_GetSub(const String* str, Uint32 begin, Uint32 end);

//ARRAYS
Array* ArrayGetSub(Array* arr, size_t t_size, Uint32 begin, Uint32 end);

//DYANMIC ARRAYS

//LISTS
List *List_CreateNode(void *data);
List *List_Search(List *head, void *data);
void List_Insert(List* old_node, List* new_node);
void List_Delete(List** head, List* node);
void List_Free(List *head);
