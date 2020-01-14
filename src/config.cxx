// Standard Includes
#include <cstdlib>

// Third-Party Libraries
#include <boost/filesystem.hpp>

// Local Headers
#include "config.hxx"

// libconfig(++) is not THREAD-SAFE. Use this interface for providing
// requisite locking mechanisms (mutex?)
// configuration.writeFile
bool ai::Config::create(void) {
};

// configuration.writeFile
bool ai::Config::update(void) {
};

// configuration.readFile
bool ai::Config::load(void) {
    try {
        boost::filesystem::path config_file = home / AI_CONFIG_NAME;
        config.readFile(configFile::string());
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
bool ai::Config::save(void) {
};
