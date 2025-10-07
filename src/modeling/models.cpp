#include "models.h"
#include "../../soupc/soup-datatypes.h"
#include "../../soupc/soup-io.h"
#include <SDL3/SDL_stdinc.h>

Model* LoadModel(char* filename)
{
    SoupFile* file = SoupReadFile(filename);
    Model* model = (Model*)SDL_malloc(sizeof(Model));

    DynamicArray* vertices = SoupInitDynamicArray("Vec3");
	DynamicArray* faces = SoupInitDynamicArray("Uint32");

    model->vertices = vertices;
	model->faces = faces;
}
