#pragma once

#include <SDL3/SDL_init.h>

typedef float f32;
typedef double f64;
typedef long double f80;

typedef struct _DyanmicArray {
  void *data;
  int stored;
  int limit;
} DyamicArray;

typedef struct _List {
  struct _List *prev;
  void *data;
  struct _List *next;
} List;

// DYANMIC ARRAYS

// LISTS
List *CreateNode(void *data);
List *ListSearch(List *head, void *data);
void ListConcat(List *tail, List *node);
void ListAppend(List *tail, List *node);
void ListDelete(List** head, List* node);
void ListFree(List *head);
