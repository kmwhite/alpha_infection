#include <iostream>
#include <libconfig.h++>

namespace ai {
    class Game {
        public:
            // Data Members
            libconfig::Config configuration;

        private:
            // Prototypes
            bool _ai_init_cfg(void);

    };
}
