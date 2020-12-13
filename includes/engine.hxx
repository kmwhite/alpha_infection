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
    struct displayCfg_t {
        int width;
        int height;
        bool fullScreen;
    };

    class Engine {
        public:
            Engine(std::shared_ptr<libconfig::Config> loadedConfiguration,
                   std::shared_ptr<ai::Logger> sharedLogger) {
                logger = sharedLogger;
                config = loadedConfiguration;
                setupWasSuccessful = setup_engine_components();
            }

            ~Engine() {
                if (!setupWasSuccessful) { return; }
                if (teardown_engine_components() == true) {
                    logger->debug("[   engine ] Cleanup complete!");
                } else {
                    logger->fatal("[   engine ] ERROR FREEING RESOURCES");
                }
            }
            bool setupWasSuccessful = false;
            void start(void);

        private:
            std::shared_ptr<libconfig::Config> config = NULL;
            std::shared_ptr<ai::Logger> logger = NULL;
            SDL_Renderer * uiRenderer = NULL;
            SDL_Window * uiWindow = NULL;
            TTF_Font * uiFont = NULL;
            ai::displayCfg_t displayCfg = {
                AI_WINDOW_WIDTH_DEFAULT,
                AI_WINDOW_HEIGHT_DEFAULT,
                false
            };

            void main_loop(void);
            bool initialize_renderer(void);
            bool setup_engine_components(void);
            bool teardown_engine_components(void);
            void _initialize_display_cfg(void);
    };
}
