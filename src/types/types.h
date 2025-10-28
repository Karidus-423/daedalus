#pragma once

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_stdinc.h>

#define NULL_TERMINATOR '\0'

typedef enum _ListOrder{
	LISTORDER_FIRST_LAST,
	LISTORDER_LAST_FIRST,
}ListOrder;

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

// @field : struct _List *prev | The node that comes before it, if null node is head;
// @field : void *data | Data address of any type. Type needs to be known at compile to access;
// @field : struct _List *next | The node that comes after it, if null node is tail;
typedef struct _List {
  struct _List *prev;
  void *data;
  struct _List *next;
} List;



//STRINGS
Uint32 String_CountCharsIn (String* bfr, char ch);

//@return : List of tokens split by the passed delimiter, the first node is the last token parsed.
List* String_Parse(const String* str, char delimiter);

//Constantly rewrites the memory of *dest, to the String parsed by the delimiter until there are
//no more left. Stops when dest == NULL.
void String_ParseStream(String* src, String* dest, char delimiter);

//@return : Uint32 | Represents the number of characters in the passed char*, counting the
// NULL_TERMINATOR '\0'
Uint32 String_GetLen(const char* string);
String* String_GetSub(const String* str, Uint32 begin, Uint32 end);
String* String_Init(const char* string);
bool String_Equal(const String* s1,const String*s2);
bool String_ContainsChar(const String* str, char ch);

//ARRAYS
Array* ArrayGetSub(Array* arr, size_t t_size, Uint32 begin, Uint32 end);

//DYANMIC ARRAYS

//LISTS
List *List_CreateNode(void *data);
List *List_Search(List *head, void *data);
void List_Insert(List* old_node, List* new_node);
void List_Delete(List** head, List* node);
void List_Free(List *head);
