#define AI_GAME_RC ".alpha_infection.cfg"

#include "game.hxx"

#include <fmt/core.h>
#include <cstdlib>

// Member Functions()
bool ai::Game::_initialize_game(void) {
    boost::uuids::uuid cfgIdAsUuid;

    aiId = boost::uuids::to_string(cfgIdAsUuid);
    home = getenv("HOME");

    return true;
};

bool ai::Game::_initialize_cfg(void) {
    logger->debug("[     game ] Loading Configuration File");
    config = std::make_shared<libconfig::Config>();

    try {
        config->readFile(AI_GAME_RC);
        logger->debug("[     game ] Configuration loaded!");
    } catch(const libconfig::FileIOException &fioex) {
        logger->fatal("[     game ] I/O error while reading file.");
        return false;
    } catch(const libconfig::ParseException &pex) {
        logger->fatal(fmt::format(
            "[     game ] Configuration {} at {}:{}",
            pex.getError(),
            pex.getFile(),
            pex.getLine()
        ));

        return false;
    }

    return true;
};

bool ai::Game::_initialize_ui(void) {
    engine = std::make_unique<ai::Engine>(config, logger);
    return engine->setupWasSuccessful;
};
