#include "render.h"
#include "../modeling/models.h"
#include <SDL3/SDL_render.h>
#include <stdio.h>

void RenderApp(Engine* engine)
{
    SDL_Renderer* renderer = engine->renderer;

	String str = {
		.chars = "OnlyThisRender",
		.len = 15,
	};

	String* out = String_GetSub(&str, 4, 8);

	SDL_SetRenderDrawColor(renderer, 50, 255, 0, 255);
	SDL_RenderDebugTextFormat(renderer, 50, 50, "Chars: %s, Len: %d", out->chars, out->len);
	SDL_SetRenderScale(renderer, 2.0f, 2.0f);

	// Model* teacup = Model_Load("assets/meshes/Teapot.obj");
	// if (teacup != NULL) {
	// 	printf("Model Loaded SuccessFully!\n");
	// }else{
	// 	printf("Model Loaded Unsuccesfully!\n");
	// }
}
