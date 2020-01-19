#include <iostream>

#include <libconfig.h++>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace ai {
    class Game {
        public:
            // Constructor
            Game() {
                _initialize_game();
                _initialize_cfg();

                std::cout << "Constructing Game(infection:"
                          << aiId
                          << ", home: "
                          << home
                          << ")."
                          << std::endl;
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

            // Prototypes
            bool _initialize_game(void);
            bool _initialize_cfg(void);

    };
}
