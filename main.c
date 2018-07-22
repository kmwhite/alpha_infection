//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "./alpha_infection.c"

// Main app Launch
int main(int argc, char const * argv[]) {
	// The window we'll be rendering to
	SDL_Window * window = NULL;
	// The surface contained by the window
	SDL_Surface * screenSurface = NULL;
	// The exit status for the program
	int exitStatus = AI_EXIT_NO_ERR;

	if (AI_initRenderer()) {
		// Create the SDL Powered Window
		window = SDL_CreateWindow(
			AI_WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			AI_WINDOW_WIDTH,
			AI_WINDOW_HEIGHT,
			SDL_WINDOW_SHOWN  // was 0
		);

		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			exitStatus = AI_EXIT_ERR_WINDOW;
		}  else {
			// SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
			// SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			// SDL_RenderClear(renderer);
			// SDL_RenderPresent(renderer);

			// Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			// Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			// Update the surface
			SDL_UpdateWindowSurface(window);

			// Wait two seconds
			SDL_Delay(2000);
			// Destroy the window we opened
			SDL_DestroyWindow(window);
		}

		// Cleanup after SDL
		SDL_Quit();
	} else {
		exitStatus = AI_EXIT_ERR_SDL;
	};

	return exitStatus;
};
