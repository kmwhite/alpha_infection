#define AI_GAME_RC ".alpha_infection.cfg"

#include "game.hxx"

#include <cstdlib>

// Member Functions()
bool ai::Game::_initialize_game(void) {
    boost::uuids::uuid cfgIdAsUuid;

    aiId = boost::uuids::to_string(cfgIdAsUuid);
    home = getenv("HOME");

    return true;
};

bool ai::Game::_initialize_cfg(void) {
    try {
        config.readFile(AI_GAME_RC);
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

bool ai::Game::_initialize_ui(void) {
    return false;
};
