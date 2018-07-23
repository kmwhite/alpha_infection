#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "alpha_infection.h"

// The window we'll be rendering to
SDL_Window * gWindow = NULL;
// The renderer we'll be rendering with
SDL_Renderer * gRenderer = NULL;
// Font to write with
TTF_Font *gFont = NULL;

// Main app Launch
int main(int argc, char const * argv[]) {

	if (AI_init()) {
		AI_loadMenu();
		SDL_Delay(2500);
		AI_shutDown();
	}

	return 0;
};