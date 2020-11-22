#include <iostream>
#include <memory>

#include <libconfig.h++>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "engine.hxx"

namespace ai {
    class Game {
        public:
            // Constructor
            Game() {
                if (_initialize_game()) {
                    logger->debug("Constructing Game(infection:" + aiId + ", home: " + home + ").");

                    if (_initialize_cfg()) {
                        logger->info("Loaded Configuration");

                        if (_initialize_ui()) {
                            logger->info("Setup Complete!");
                            engine->start_loop();
                        } else {
                            logger->info("Setup Failed!");
                        };
                    } else {
                        logger->info("Failure to initialize config");
                    };
                } else {
                    logger->info("Failure to initialize game.");
                }
            }

            ~Game() {
                logger->debug("Deconstruction Game(infection:" + aiId + ").");
            }

            // Logger logger;

        private:
            // Data Members
            std::string home;
            std::string aiId;
            std::shared_ptr<libconfig::Config> config = NULL;
            std::shared_ptr<ai::Logger> logger = NULL;
            std::unique_ptr<ai::Engine> engine = NULL;

            // Prototypes
            bool _initialize_game(void);
            bool _initialize_cfg(void);
            bool _initialize_ui(void);
    };
}
