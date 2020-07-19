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
                    std::cout << "Constructing Game(infection:"
                              << aiId
                              << ", home: "
                              << home
                              << ")."
                              << std::endl;

                    if (_initialize_cfg()) {
                        std::cout << "Loaded configuration!" << std::endl;
                        if (_initialize_ui()) {
                            std::cout << "Setup Complete!" << std::endl;
                            engine->start_loop();
                        } else {
                            std::cout << "Setup Failed!" << std::endl;
                        };
                    } else {
                        std::cout << "Failure to initialize config"
                                  << std::endl;
                    };
                } else {
                    std::cout << "Failure to initialize game."
                              << std::endl;
                }
            }

            ~Game() {
                std::cout << "Deconstruction Game(infection:"
                          << aiId
                          << ")."
                          << std::endl;
            }

        private:
            // Data Members
            std::string home;
            std::string aiId;
            std::shared_ptr<libconfig::Config> config = NULL;
            std::unique_ptr<ai::Engine> engine = NULL;

            // Prototypes
            bool _initialize_game(void);
            bool _initialize_cfg(void);
            bool _initialize_ui(void);
    };
}
