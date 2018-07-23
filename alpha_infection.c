#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

bool AI_initRenderer() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}