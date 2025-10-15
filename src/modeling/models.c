#include "models.h"
#include <SDL3/SDL_stdinc.h>

// Model Loading Arena, once LoadModel ends free all the allocations of the model loading process.
// Model Arena

typedef struct _ModelMetaData
{
    Uint32 v_size;
    Uint32 f_size;
} ModelMetaData;

ModelMetaData* GetOBJMetaData(char* bfr)
{
    ModelMetaData* meta = SDL_malloc(sizeof(ModelMetaData));

    Uint32 v_size = CountCharInString(bfr, 'v');
    Uint32 f_size = CountCharInString(bfr, 'f');
    meta->v_size = v_size;
    meta->f_size = f_size;

    return meta;
}

Model* LoadOBJMOdel(char* bfr)
{
    Model* model = SDL_malloc(sizeof(Model));
    // Create an array of vertices
    ModelMetaData* meta_data = GetOBJMetaData(bfr);
    model->vertices = SDL_malloc(sizeof(Vec3) * meta_data->v_size);
    model->faces = SDL_malloc(sizeof(Polygon) * meta_data->f_size);

    // Create an array of faces.
    return model;
}

Model* LoadModel(const char* filename)
{
    char* bfr = ReadFile(filename);

    if (IsFileType(filename, "obj")) {
        return LoadOBJModel(bfr);
    }

    return NULL;
}
