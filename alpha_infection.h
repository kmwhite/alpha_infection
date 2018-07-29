#include <stdbool.h>

#include <SDL2/SDL.h>

// The renderer we'll be rendering with
extern SDL_Renderer * gRenderer;
// Font to write with
extern TTF_Font *gFont;

// Function Prototypes
bool AI_init(SDL_Window * window);
void AI_loadMenu(void);
void AI_shutDown(SDL_Window * window);