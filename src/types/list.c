#include "types.h"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>

List* CreateNode(void* data)
{
    List* node = SDL_malloc(sizeof(List));
    if (node == NULL) {
        SDL_LogError(SDL_LOG_PRIORITY_ERROR, "SDL CreateNode : %s", SDL_GetError());
        return NULL;
    }

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

// Searches for data in the provided list.
//@return
//   |  NULL: data not found in list.
//   |  List*: node where data was found.
List* ListSearch(List* head, void* data)
{
    List* peak = head;
    while (peak != NULL) {
        if (peak->data == data) {
            return peak;
        }
        peak = peak->next;
    }

    return NULL;
}

// Inserts the new_node after the old_node.
void ListInsert(List* old_node, List* new_node)
{
    new_node->next = old_node->next;
    // Checks if old_node->next not a tail.
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }

    new_node->prev = old_node;
    old_node->next = new_node;
    return;
}

// Deletes a node from the list.
void ListDelete(List** head_ref, List* node)
{
    List* head = *head_ref;
    if (head == NULL || node == NULL)
        return;

    if (head == node) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
    }

    node->next = NULL;
    node->prev = NULL;

    return;
}

// Deletes and entire list.
void ListFree(List* head)
{
    while (head != NULL) {
        List* tmp = head;
        head = head->next;
        SDL_free(tmp);
    }
    head = NULL;

    return;
}
