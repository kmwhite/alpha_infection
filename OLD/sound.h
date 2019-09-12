#include <SDL2/SDL.h>

#define AI_SND_SUCCESS 0;
#define AI_SND_ERRNOASSET 1;
#define AI_SND_ERRNODEV 2;
#define AI_SND_ERRNOQUEUE 3;

void ai_sndEnumerateDevices(void);
