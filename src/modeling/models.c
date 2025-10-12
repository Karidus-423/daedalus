#include "models.h"
#include <SDL3/SDL_stdinc.h>

ModelFileData* GetOBJFileData(char* bfr)
{
    ModelFileData* meta_data = SDL_malloc(sizeof(ModelFileData));

    char c;
    Uint32 size = 0;
    Uint32 i = 0;
    while (c != END_OF_FILE) {
        c = bfr[i];
        if (c == 'v') {
            if (size == 0) {
                meta_data->vert_start = i;
            }
            ++size;
        }
        ++i;
    }

    while (c != END_OF_FILE) {
        c = bfr[i];
        if (c == 'f') {
            if (size == 0) {
                meta_data->faces_start = i;
            }
            ++size;
        }
        ++i;
    }

    meta_data->faces_size = size;

    return meta_data;
}

Vec3* GetOBJVertices(ModelFileData* meta_data,char* bfr){
}

Polygon* GetOBJFaces(ModelFileData* meta_data,char* bfr){
}

Model* LoadModel(const char* filename)
{
    char* bfr = ReadFile(filename);
    Model* model = SDL_malloc(sizeof(Model));

    ModelFileData* meta_data = GetOBJFileData(bfr);

    model->vertices = GetOBJVertices(meta_data,bfr);
	model->faces = GetOBJFaces(meta_data,bfr);

	return model;
}
