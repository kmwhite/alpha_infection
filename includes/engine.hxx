// show-menu, select-option, etc
#include <iostream>
#include <memory>

#include <libconfig.h++>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define AI_WINDOW_TITLE "AlphaInfection"
#define AI_WINDOW_WIDTH_DEFAULT 640
#define AI_WINDOW_HEIGHT_DEFAULT 480

namespace ai {
    class Engine {
        public:
            Engine(std::shared_ptr<libconfig::Config> loadedConfiguration) {
                std::cout << "Set Configuration"
                          << std::endl;
                config = loadedConfiguration;

                setupWasSuccessful = initialize_resources();
            }

            ~Engine() {
                cleanup_resources();
                std::cout << "Free Configuration"
                          << std::endl;
            }
            bool setupWasSuccessful = false;

        private:
            std::shared_ptr<libconfig::Config> config = NULL;
            SDL_Renderer * uiRenderer = NULL;
            SDL_Window * uiWindow = NULL;
            TTF_Font * uiFont = NULL;

        void cleanup_resources();
        bool initialize_resources();
    };
}
