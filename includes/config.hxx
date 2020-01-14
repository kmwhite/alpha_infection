#define AI_CONFIG_NAME ".alpha_infection.cfg"

#include <libconfig.h++>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace ai {
    class Configuration {
        public:
            Configuration() {
                boost::uuids::uuid cfgIdAsUuid;

                home = getenv("HOME");
                cfgId = boost::uuids::to_string(cfgIdAsUuid);

                std::cout << "Constructing Configuration("
                          << cfgId
                          << ", home: "
                          << home
                          << ")."
                          << std::endl;
            }

            ~Configuration() {
                std::cout << "Deconstruction Configuration("
                          << cfgId
                          << ")."
                          << std::endl;
            }

            bool create(void);
            bool update(void);
            bool load(void);
            bool save(void);

        private:
            std::string home;
            std::string cfgId;
    };
}
