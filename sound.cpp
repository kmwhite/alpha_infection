#include <iostream>

#include "sound.h"
#include "log.h"

void ai_sndEnumerateDevices(void) {
	int i;
	bool isCapture = false;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
		ai_logError("SDL failed initialization! SDL_Error: %s", SDL_GetError());
	}

	for (i = 0; i < SDL_GetNumAudioDrivers(); ++i) {
		const char* driverName = SDL_GetAudioDriver(i);

		if (SDL_AudioInit(driverName)) {
			ai_logDebug("Audio driver failed to initialize: %s", driverName);
			continue;
		} else {
            const char* deviceName = SDL_GetAudioDeviceName(i, isCapture);
			ai_logDebug("Initialized audio driver: %s", driverName);
			if (deviceName) {
			  ai_logInfo(" * Audio device (%d): %s", i, deviceName);
			} else {
			  ai_logInfo(" * Audio device not found!");
			}
		}
	}

	SDL_AudioQuit();
	SDL_Quit();
}

int ai_sndPlayMusic(std::string asset_path) {
	// Setup for Audio Playback
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8 * wavBuffer;
	SDL_AudioDeviceID deviceId = 0;
	bool pauseOn = false;
	bool isCapture = false;

	// Start playing background music
	if (SDL_LoadWAV(asset_path.c_str(), &wavSpec, &wavBuffer, &wavLength) == NULL) {
		ai_logError("Wav file could not be loaded");
		return AI_SND_ERRNOASSET;
	}
	deviceId = SDL_OpenAudioDevice(NULL, (int)isCapture, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
	if (deviceId == 0) {
		ai_logError("Failed to open audio: %s", SDL_GetError());
		return AI_SND_ERRNODEV;
	} else {
		// open audio device
		int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
		if (success == 0) {
			SDL_PauseAudioDevice(deviceId, (int)pauseOn);
			return AI_SND_SUCCESS;
		} else {
			ai_logError("Failed to queue music!");
			ai_logInfo("Recv %d, expecting %d", success, 0);
			return AI_SND_ERRNOQUEUE;
		}
	}
}
