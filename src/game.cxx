#include "game.hxx"

#include <iomanip>
#include <cstdlib>

// Member Functions()
bool ai::Game::_ai_init_cfg(void) {
    // Read the file. If there is an error, report it and exit.
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

    return 0;

}
