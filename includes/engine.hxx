// show-menu, select-option, etc
#include <iostream>
#include <memory>

#include <libconfig.h++>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "logger.hxx"

#define AI_WINDOW_TITLE "AlphaInfection"
#define AI_WINDOW_WIDTH_DEFAULT 640
#define AI_WINDOW_HEIGHT_DEFAULT 480

namespace ai {
    class Engine {
        public:
            Engine(std::shared_ptr<libconfig::Config> loadedConfiguration,
                   std::shared_ptr<ai::Logger> sharedLogger) {
                logger = sharedLogger;

                logger->debug("[   engine ] Set Configuration");
                config = loadedConfiguration;

                setupWasSuccessful = initialize_resources();
            }

            ~Engine() {
                logger->debug("[   engine ] Initiating Engine cleanup...");
                if (cleanup_resources() == true) {
                    logger->debug("[   engine ] Cleanup complete!");
                } else {
                    logger->fatal("[   engine ] ERROR FREEING RESOURCES");
                }
            }
            bool setupWasSuccessful = false;
            
            void start_loop(void);

        private:
            std::shared_ptr<libconfig::Config> config = NULL;
            std::shared_ptr<ai::Logger> logger = NULL;
            SDL_Renderer * uiRenderer = NULL;
            SDL_Window * uiWindow = NULL;
            TTF_Font * uiFont = NULL;
            int uiWinWidth = 0;
            int uiWinHeight = 0;

        bool cleanup_resources();
        bool initialize_resources();
    };
}
