// Standard Includes
#include <cstdlib>

// Third-Party Libraries
#include <boost/filesystem.hpp>
#include <libconfig.h++>

// Local Headers
#include "config.hxx"

bool ai::config::create(const char* config_name) {
};

bool ai::config::update(void) {
};

bool ai::config::load(void) {
	const char *home = getenv("HOME");

    try {
        configuration.readFile("example.cfg");
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file."
                  << std::endl;
        return false;
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at "
                  << pex.getFile()
                  << ":" << pex.getLine()
                  << " - " << pex.getError()
                  << std::endl;
        return false;
    }

    return true;
};

bool ai::config::save(void) {
};

bool ai::config::_home_dir_env_var(void) {
};
