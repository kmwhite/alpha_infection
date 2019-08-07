#include <iostream>
#include <libconfig.h>

namespace AI {
    class Player {
        // Access specifier
        public:

            // Data Members
            std::string name;

            // Member Functions()
            void printname() {
                std::cout << "Player name is: " << name;
            }
    };

    class Game {
        public:

        Player player;
        cfg_t configuration;

    };
}

int main() {
    AI::Player player;

    // accessing data member
    player.name = "Abhi";

    // accessing member function
    player.printname();

    return 0;
}

