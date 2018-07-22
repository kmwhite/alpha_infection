#include <stdbool.h>

// Window Information Constants
const char * AI_WINDOW_TITLE = "AlphaInfection";
const int AI_WINDOW_WIDTH = 640;
const int AI_WINDOW_HEIGHT = 480;

// Exit Codes
const int AI_EXIT_NO_ERR = 0;
const int AI_EXIT_ERR_SDL = 1;
const int AI_EXIT_ERR_WINDOW = 2;

// Function Prototypes
bool AI_initRenderer();