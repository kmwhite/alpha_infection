#include "log.h"

void ai_sndEnumerateDevices(void) {
	int i;

	for (i = 0; i < SDL_GetNumAudioDrivers(); ++i) {
		const char* driver_name = SDL_GetAudioDriver(i);

		if (SDL_AudioInit(driver_name)) {
			log_debug("Audio driver failed to initialize: %s\n", driver_name);
			continue;
		} else {
			log_debug("Initialized audio driver: %s\n", driver_name);
			log_debug("* Audio device %d: %s\n", i, SDL_GetAudioDeviceName(i, 0));
		}
	}
}
