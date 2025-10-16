#include "render.h"
#include "../modeling/models.h"
#include <stdio.h>

void RenderApp(Engine* engine)
{
    SDL_Renderer* renderer = engine->renderer;

	Model* teacup = Model_Load("assets/meshes/Teapot.obj");
	if (teacup != NULL) {
		printf("Model Loaded SuccessFully!\n");
	}else{
		printf("Model Loaded Unsuccesfully!\n");
	}
}
