#include "log.h"

void ai_sndEnumerateDevices(void) {
	int i;

	for (i = 0; i < SDL_GetNumAudioDrivers(); ++i) {
		const char* driver_name = SDL_GetAudioDriver(i);

		if (SDL_AudioInit(driver_name)) {
			ai_logDebug("Audio driver failed to initialize: %s\n", driver_name);
			continue;
		} else {
			ai_logDebug("Initialized audio driver: %s\n", driver_name);
			ai_logDebug("* Audio device %d: %s\n", i, SDL_GetAudioDeviceName(i, 0));
		}
	}
}
