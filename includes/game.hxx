#include "config.hxx"

namespace ai {
    class Game {
        public:
            // Constructor
            Game() {
                if ( cfg.load() ) {
                } else {
                };
            }

        private:
            // Data Members
            ai::Configuration cfg;
            // Prototypes
            // bool _ai_init_cfg(void);

    };
}
