#include "logger.hxx"

namespace ai {
    struct resourceMap_t {
        std::string gameName;
    };

    class ResourceMap {
        public:
            ai::resourceMap_t resourceMap;

        private:
            class Reader {};
            class Writer {};
    };
}