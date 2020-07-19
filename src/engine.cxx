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

void ai::Engine::start_loop(void) {
    // Menu Variables
    SDL_Color textColor = { 0x00, 0x00, 0x00 };
    SDL_Surface * textSurface = TTF_RenderText_Solid(uiFont, AI_WINDOW_TITLE, textColor);
    SDL_Texture * textTexture = SDL_CreateTextureFromSurface(uiRenderer, textSurface);
    SDL_Texture * menuBg = IMG_LoadTexture(uiRenderer, "./assets/menu/bg.jpg");
    int textWidth = 0;
    int textHeight = 0;

    // Get dimensions of the textTexture (textWidth and textHeight)
    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

    // Create a placement rectangle defining where to put the textTexture
    SDL_Rect textPlacement = {
        (AI_WINDOW_WIDTH_DEFAULT - textWidth) / 2, // X-start
        (AI_WINDOW_HEIGHT_DEFAULT / 8), // Y-start
        textWidth,
        textHeight
    };

    // Setup for Audio Playback
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 * wavBuffer;
    SDL_AudioDeviceID deviceId = 0;

    // Start playing background music
    if (SDL_LoadWAV("./assets/menu/bg.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
        printf("[error] Wav file could not be loaded\n");
    }
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
    if (deviceId == 0) {
        printf("[error] Failed to open audio: %s\n", SDL_GetError());
    } else {
        // open audio device
        int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
        if (success == 0) {
            SDL_PauseAudioDevice(deviceId, 0);
        } else {
            printf("[error] Failed to queue music!\n");
            printf("[info] Recv %d, expecting %d\n", success, 0);
        }
    }

    SDL_RenderCopy(uiRenderer, menuBg, NULL, NULL);
    SDL_RenderCopy(uiRenderer, textTexture, NULL, &textPlacement);
    SDL_RenderPresent(uiRenderer);

    SDL_Event event;
    bool runMainLoop = true;
    while (runMainLoop) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    printf("Received SDL_QUIT event\n");
                    runMainLoop = false;
                    break;
                case SDL_KEYDOWN:
                    std::cout << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
                    break;
                case SDL_KEYUP:
                    std::cout << "Release" << std::endl;
                    break;
                default:
                    runMainLoop = true;
                    break;
            }
        }
    }

    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_DestroyTexture(menuBg);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    menuBg = NULL;
}

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
