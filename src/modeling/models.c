#include "models.h"
#include <SDL3/SDL_stdinc.h>
#include <stdio.h>

// TODO: Model Loading Arena, once LoadModel ends free all the allocations of the model loading process.
// Model Arena

Vec3 Model_parseOBJVectors(const String* str){

	return (Vec3){
		.x = 2,
		.y = 1,
		.z = 3,
	};
}

Polygon Model_parseOBJFaces(const String* str){
	return (Polygon){
	};
}

Model* Model_loadOBJ(String* bfr)
{
	Model* model = SDL_malloc(sizeof(Model));

	String* line = String_Init(" ");
	while (line != NULL) {
		String_ParseStream(bfr, line, '\n');

		if (String_ContainsChar(line,'v')) {
			//Parse Vectors
			Vec3 vec = Model_parseOBJVectors(line);
			// Slice_pushBack(model->vertices,vec);
		}else if (String_ContainsChar(line,'f')) {
			Polygon face = Model_parseOBJFaces(line);
			// Slice_pushBack(model->faces,face);
		}
	}


	return model;
}

Model* Model_load(String* filename)
{
    String* bfr = File_Read(filename);
	String* obj = String_Init("obj");

    if (File_IsType(filename, obj)) {
        return Model_loadOBJ(bfr);
    }

    return NULL;
}
