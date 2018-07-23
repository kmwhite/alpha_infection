#include <stdbool.h>

#include <SDL2/SDL.h>

// The window we'll be rendering to
extern SDL_Window * gWindow;
// The renderer we'll be rendering with
extern SDL_Renderer * gRenderer;
// Font to write with
extern TTF_Font *gFont;

// Function Prototypes
bool AI_init(void);
void AI_loadMenu(void);
void AI_shutDown(void);