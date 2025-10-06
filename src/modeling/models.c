#include "models.h"

Model* LoadModel(char* filename)
{
	//Read from a file.
	//Get the vertices
	//Save them into array.
	//Get the faces
	//Save the information of each face in an array.
	//Draw each face,
	//Each face has three array of length 3. 
	Model* model = SDL_calloc(1,sizeof(Model));
	Sint8 vertices[2] = {0,5};
	model->vertices = vertices;

	return model;
}
