#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "alpha_infection.h"

// Global Values
// The window we'll be rendering to
SDL_Window * gWindow = NULL;
// The surface contained by the window
SDL_Surface * gScreenSurface = NULL;
// The image we will load and show on the screen
SDL_Surface * gHelloWorld = NULL;

// Window Information Constants
const char * AI_WINDOW_TITLE = "AlphaInfection";
const int AI_WINDOW_WIDTH = 640;
const int AI_WINDOW_HEIGHT = 480;

bool AI_init(void) {
	bool completedSuccessfully = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		completedSuccessfully = false;
	} else {
		// Create window
		gWindow = SDL_CreateWindow(
			AI_WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			AI_WINDOW_WIDTH,
			AI_WINDOW_HEIGHT,
			SDL_WINDOW_SHOWN
		);

		if (gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			completedSuccessfully = false;
		} else {
			// SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
			// SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			// SDL_RenderClear(renderer);
			// SDL_RenderPresent(renderer);

			// Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			// Fill the surface white
			SDL_FillRect(
				gScreenSurface,
				NULL,
				SDL_MapRGB(
					gScreenSurface->format,
					0xFF,
					0xFF,
					0xFF
				)
			);

			// Update the surface
			SDL_UpdateWindowSurface(gWindow);

			// Wait two seconds
			SDL_Delay(2000);
		}
	}

	return completedSuccessfully;
}

void AI_shutdown(void) {
	// Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	// Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Quit SDL subsystems
	SDL_Quit();
}