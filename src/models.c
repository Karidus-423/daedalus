#include "vectors.h"

Model* LoadModel(char* filename)
{
	//Detect file extension
	//Then Return Model using appropiate function.

	Model* model = SDL_calloc(1,sizeof(Model));
	Sint8 vertices[2] = {0,5};
	model->vertices = vertices;

	return model;
}
