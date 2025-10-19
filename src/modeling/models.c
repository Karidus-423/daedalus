#include "models.h"
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>

// Model Loading Arena, once LoadModel ends free all the allocations of the model loading process.
// Model Arena
typedef struct _ModelMetaData
{
    Uint32 v_size;
    Uint32 f_size;
} ModelMetaData;

ModelMetaData* GetOBJMetaData(String* bfr)
{
    ModelMetaData* meta = SDL_malloc(sizeof(ModelMetaData));

    Uint32 v_size = String_CountCharsIn(bfr, 'v');
    Uint32 f_size = String_CountCharsIn(bfr, 'f');
    meta->v_size = v_size;
    meta->f_size = f_size;

    return meta;
}

Model* Model_LoadOBJ(String* bfr)
{
    Model* model = SDL_malloc(sizeof(Model));
    // Create an array of vertices
    ModelMetaData* meta_data = GetOBJMetaData(bfr);
    model->vertices = SDL_malloc(sizeof(Vec3) * meta_data->v_size);
    model->faces = SDL_malloc(sizeof(Polygon) * meta_data->f_size);

	char c;
	//Parse Vertices
	int i = 0;
	while (c != END_OF_FILE) {
		c = bfr->chars[i];
		printf("%c",c);
		++i;
	}


	//Parse Faces

    // Create an array of faces.
    return model;
}

Model* Model_Load(const char* filename)
{
    String* bfr = File_Read(filename);

    if (File_IsType(filename, "obj")) {
        return Model_LoadOBJ(bfr);
    }

    return NULL;
}
