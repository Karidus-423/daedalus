#include "./src/types/types.h"
#include <stdio.h>

int main()
{
	String str = {
		.chars = "E.g.e.g",
		.len = 8,
	};

    List* tokens = String_Parse(&str, '.');

    while (tokens->next != NULL) {
        tokens = tokens->next;
        String* token = (String*)tokens->data;
		printf("%s",token->chars);
    }
}
