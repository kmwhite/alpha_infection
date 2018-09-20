#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "alpha_infection.h"


// Window Information Constants
const char * AI_WINDOW_TITLE = "AlphaInfection";
const int AI_WINDOW_WIDTH = 640;
const int AI_WINDOW_HEIGHT = 480;

bool _sdl_init(void) {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
		printf("[error] SDL failed initialization! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		printf("[warning] Linear texture filtering not enabled!" );
	}

	return true;
}

bool AI_init(SDL_Window * window) {
	_sdl_init();
	// Create window
	window = SDL_CreateWindow(
		AI_WINDOW_TITLE,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		AI_WINDOW_WIDTH,
		AI_WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) {
		printf("[error] Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	} else {
		printf("[debug] WINDOW IS NOT NULL: %s\n", SDL_GetWindowTitle(window));
	}

	// Create renderer
	gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
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

void AI_loadMenu(void) {
	// Input Event
	SDL_Event event;

	// Menu Variables
	SDL_Color textColor = { 0x00, 0x00, 0x00 };
	SDL_Surface * textSurface = TTF_RenderText_Solid(gFont, AI_WINDOW_TITLE, textColor);
	SDL_Texture * textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	SDL_Texture * menuBg = IMG_LoadTexture(gRenderer, "./assets/menu/bg.jpg");
	int textWidth = 0;
	int textHeight = 0;

	// Get dimensions of the textTexture (textWidth and textHeight)
	SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

	// Create a placement rectangle defining where to put the textTexture
	SDL_Rect textPlacement = {
		(AI_WINDOW_WIDTH - textWidth) / 2, // X-start
		(AI_WINDOW_HEIGHT / 8), // Y-start
		textWidth,
		textHeight
	};

	// Setup for Audio Playback
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8 * wavBuffer;
	SDL_AudioDeviceID deviceId = 0;

	// Start playing background music
	if (SDL_LoadWAV("./assets/menu/bg.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
		printf("[error] Wav file could not be loaded\n");
	}
	deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
	if (deviceId == 0) {
		printf("[error] Failed to open audio: %s\n", SDL_GetError());
	} else {
		// open audio device
		int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
		if (success == 0) {
			SDL_PauseAudioDevice(deviceId, 0);
		} else {
			printf("[error] Failed to queue music!\n");
			printf("[info] Recv %d, expecting %d\n", success, 0);
		}
	}

    SDL_RenderCopy(gRenderer, menuBg, NULL, NULL);
	SDL_RenderCopy(gRenderer, textTexture, NULL, &textPlacement);
    SDL_RenderPresent(gRenderer);
	// TODO: Fix crappy event loop 
    while (true) {
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
			printf("Received SDL_QUIT event\n");
    		break;
		}
    }

	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
    SDL_DestroyTexture(menuBg);
	SDL_DestroyTexture(textTexture);
	SDL_FreeSurface(textSurface);
	menuBg = NULL;
}

void AI_shutDown(SDL_Window * window) {
	TTF_CloseFont(gFont);
	gFont = NULL;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	SDL_DestroyWindow(window);

	// Quit SDL
	TTF_Quit();
	IMG_Quit();
	SDL_AudioQuit();
	SDL_Quit();
}