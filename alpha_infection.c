#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "alpha_infection.h"


// Window Information Constants
const char * AI_WINDOW_TITLE = "AlphaInfection";
const int AI_WINDOW_WIDTH = 640;
const int AI_WINDOW_HEIGHT = 480;

bool AI_init() {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_VIDEO) < 0) {
		printf("[error] SDL failed initialization! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		printf("[warning] Linear texture filtering not enabled!" );
	}
		
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
		printf("[error] Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Create renderer
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_SOFTWARE);
	if (gRenderer == NULL) {
		printf("[error] Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	// Image Rendering
	int sdlImageFlags = IMG_INIT_JPG;
	if (!(IMG_Init(sdlImageFlags) & sdlImageFlags)) {
		printf("[error] SDL_image initialization failed! SDL_image Error: %s\n", IMG_GetError() );
        return false;
	}

	// True-Type Fonts
	if (TTF_Init() == -1) {
		printf("[error] SDL_ttf initialization failed! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	} else {
		// Load the font
		gFont = TTF_OpenFont("assets/ai.ttf", 60);
	}

	return true;
}

void AI_loadMenu() {
	SDL_Event event;
	SDL_Texture * menuBg = NULL;
	SDL_Color color = { 0x00, 0x00, 0x00 };
	SDL_Surface * textSurface = TTF_RenderText_Solid(gFont, AI_WINDOW_TITLE, color);
	SDL_Texture * textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	int textWidth = 0;
	int textHeight = 0;
	SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
	SDL_Rect textPlacement = {
		(AI_WINDOW_WIDTH - textWidth) / 2, // X-start
		(AI_WINDOW_HEIGHT / 8), // Y-start
		textWidth,
		textHeight
	};

    menuBg = IMG_LoadTexture(gRenderer, "./assets/menu/bg.jpg");
    while (1) {
        SDL_RenderCopy(gRenderer, menuBg, NULL, NULL);
		SDL_RenderCopy(gRenderer, textTexture, NULL, &textPlacement);
        SDL_RenderPresent(gRenderer);
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
			printf("Received SDL_QUIT event\n");
    		break;
		}
    }

    SDL_DestroyTexture(menuBg);
	SDL_DestroyTexture(textTexture);
	SDL_FreeSurface(textSurface);
	menuBg = NULL;
}

void AI_shutDown() {
	TTF_CloseFont(gFont);
	gFont = NULL;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Quit SDL
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}