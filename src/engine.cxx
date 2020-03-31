#include "engine.hxx"

void ai::Engine::cleanup_resources(void) {
    TTF_CloseFont(uiFont);
    uiFont = NULL;

    SDL_DestroyRenderer(uiRenderer);
    uiRenderer = NULL;

    SDL_DestroyWindow(uiWindow);
    uiWindow = NULL;

    // Quit SDL
    TTF_Quit();
    IMG_Quit();
    SDL_AudioQuit();
    SDL_Quit();
};

bool ai::Engine::initialize_resources(void) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
        printf("[error] SDL failed initialization! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Image Rendering
    int sdlImageFlags = IMG_INIT_JPG;
    if (!(IMG_Init(sdlImageFlags) & sdlImageFlags)) {
        printf("[error] SDL_image initialization failed! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }

    // Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("[warning] Linear texture filtering not enabled!" );
    }

    // True-Type Fonts
    if (TTF_Init() == -1) {
        printf("[error] SDL_ttf initialization failed! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    } else {
        // Load the font
        uiFont = TTF_OpenFont("assets/ai.ttf", 60);
    }

    // Create window
    uiWindow = SDL_CreateWindow(
        AI_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        AI_WINDOW_WIDTH_DEFAULT,
        AI_WINDOW_HEIGHT_DEFAULT,
        SDL_WINDOW_SHOWN
    );
    if (uiWindow == NULL) {
        printf("[error] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    } else {
        printf("[debug] WINDOW IS NOT NULL: %s\n", SDL_GetWindowTitle(uiWindow));
    }

    // Create renderer
    uiRenderer = SDL_CreateRenderer(uiWindow, -1, SDL_RENDERER_SOFTWARE);
    if (uiRenderer == NULL) {
        printf("[error] Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(uiRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    return true;
};
