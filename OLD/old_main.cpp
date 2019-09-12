#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "alpha_infection.h"
#include "sound.h"
#include "log.h"
#include "config.h"

// The renderer we'll be render	ing with
SDL_Renderer * gRenderer = NULL;
SDL_Window * gWindow = NULL;

// Font to write with
TTF_Font *gFont = NULL;
// Config Settings
cfg_t *cfg = NULL;

void _ai_gui_init(void);

// Global Struct Reqs
// * cfg_t configuration
// * SDL_Renderer renderer
// * SDL_Window window
// * TTF_Font font
//
// Game Struct
// Engine Struct
// Config Struct
// Player Struct


// Main app Launch
int main(int argc, char const * argv[]) {
	// init mainStruct for config and game data
	// load configuration
	// pass mainStruct
	cfg = ai_cfgLoad();
	int logLevel = cfg_getint(cfg, "log_level");
	ai_logDebug("Setting log_level to %d", logLevel);

	ai_sndEnumerateDevices();
	AI_init(gWindow);
	AI_loadMenu();
	AI_shutDown(gWindow);
	// ai_gfxEnumerateResolutions();

	// load menu
	//  * new game
	//  * load game
	//  * settings
	//  * credits

	ai_cfgUnload(cfg);

	return 0;
};

void _ai_gui_init(void) {
	// The window we'll be rendering to
	SDL_Window * aiWindow = NULL;

	if (AI_init(aiWindow)) {
		ai_logDebug("passed AI_init");
		if (aiWindow == NULL) {
			ai_logDebug("window was NULL");
		} else {
			ai_logDebug("window was not NULL");
		}
		AI_loadMenu();
		SDL_Delay(2500);
		AI_shutDown(aiWindow);
		aiWindow = NULL;
	}
};
