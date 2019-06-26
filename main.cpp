#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "alpha_infection.h"
#include "sound.h"
#include "log.h"
#include "config.h"

// The renderer we'll be render	ing with
SDL_Renderer * gRenderer = NULL;
// Font to write with
TTF_Font *gFont = NULL;
// Config Settings
cfg_t *cfg = NULL;

void _ai_gui_init(void);

// Main app Launch
int main(int argc, char const * argv[]) {
	cfg = ai_cfgLoad();
	int logLevel = cfg_getint(cfg, "log_level");
	ai_logDebug("Setting log_level to %d", logLevel);

	ai_sndEnumerateDevices();
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
