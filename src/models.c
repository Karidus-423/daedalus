#include "data-structs.h"
#include "vectors.h"
// TODO: Use SDL functions for file operations.
#include <SDL3/SDL_stdinc.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

// Copies the contents of the file to a char*.
//===Warning: Must free bfr.===
char* CopyFile(char* filename)
{
    FILE* fp = fopen(filename, "r");
    size_t file_size = fseek(fp, 0, SEEK_END);
    rewind(fp);

    char* bfr = SDL_malloc(file_size);
    fread(bfr, sizeof(char), file_size, fp);
    fclose(fp);

    return bfr;
}

Model* LoadModel(char* filename)
{
    // Create buffer from file.
    char* file_bfr = CopyFile(filename);
    char* track = file_bfr;

    // Parse buffer for vertices.
    DynamicArray* vectors = InitDynamicArray(sizeof(Vec3), 50);

    const char* vec_entries = NULL;
    int i = 0;
    while ((vec_entries = strtok_r(file_bfr, "v", &track))) {
		UpdateDynamicArray(vectors,i,sizeof(char*));
        char* vec_slot = ((char**)vectors->array)[i];
        vec_slot = SDL_malloc(StringLength(vec_entries) + NULL_TERMINATOR_OFFSET);
        strcpy(vec_slot, vec_entries);

        ++i;
    }

	i = 0;
	char* vec_line = NULL;
	while ((vec_line = ((char**)vectors->array)[i])) {
		printf("%s",vec_line);
	}
    // Parse buffer for faces.

    // Create Model allocation in heap to return ptr to it.
	return NULL;
}
