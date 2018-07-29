#include "logging.h"

void ai_sndEnumerateDevices(void) {
	int i;

	for (i = 0; i < SDL_GetNumAudioDrivers(); ++i) {
	    const char* driver_name = SDL_GetAudioDriver(i);

	    if (SDL_AudioInit(driver_name)) {
	        debug("[debug] Audio driver failed to initialize: %s\n", driver_name);
	        continue;
	    } else {
			printf("[debug] Initialized audio driver: %s\n", driver_name);
			printf("[debug] * Audio device %d: %s\n", i, SDL_GetAudioDeviceName(i, 0));
		}
	}
}