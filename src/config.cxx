// Standard Includes
#include <cstdlib>

// Third-Party Libraries
#include <boost/filesystem.hpp>

// Local Headers
#include "config.hxx"

// libconfig(++) is not THREAD-SAFE. Use this interface for providing
// requisite locking mechanisms (mutex?)
// configuration.writeFile
bool ai::Configuration::create(void) {
    return false;
};

// configuration.writeFile
bool ai::Configuration::update(void) {
    return false;
};

// configuration.readFile
bool ai::Configuration::load(void) {
    try {
        config.readFile("./alpha_infection.cfg");
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

// configuration.writeFile
bool ai::Configuration::save(void) {
    return false;
};
