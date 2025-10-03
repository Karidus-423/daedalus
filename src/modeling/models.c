#include "models.h"

Model* LoadModel(char* filename)
{
	//Read from a file.
	Model* model = SDL_calloc(1,sizeof(Model));
	Sint8 vertices[2] = {0,5};
	model->vertices = vertices;

	return model;
}
