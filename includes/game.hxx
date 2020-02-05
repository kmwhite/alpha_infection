#include <iostream>

#include <libconfig.h++>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "engine.hxx"

namespace ai {
    class Game {
        public:
            // Constructor
            Game() {
                if (_initialize_game() && _initialize_cfg()) {
                    std::cout << "Constructing Game(infection:"
                              << aiId
                              << ", home: "
                              << home
                              << ")."
                              << std::endl;

                    _initialize_ui();
                } else {
                    std::cout << "Failure to initialize!"
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
            libconfig::Config config;
            ai::Engine engine;

            // Prototypes
            bool _initialize_game(void);
            bool _initialize_cfg(void);
            bool _initialize_ui(void);

    };
}
