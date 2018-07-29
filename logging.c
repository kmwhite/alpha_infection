#include <stdio.h>
#include <stdlib.h>

#include "logging.h"

void ai_logMessage(const char * log_level, const char * message) {
	fprintf(stderr, "[%s] %s\n", log_level, message);
};

void ai_logDebug(const char * message) {
	ai_logMessage("debug", message);
};

void ai_logInfo(const char * message) {
    ai_logMessage("info", message);
};

void ai_logWarning(const char * message) {
    ai_logMessage("warning", message);
}

void ai_logFatal(const char * message) {
    ai_logMessage("fatal", message);
};

void ai_logPlatform(void) {
	#ifdef _WIN32 // note the underscore: without it, it's not msdn official!
	    ai_logDebug("On Windows!");
	#elif __linux__
	    ai_logDebug("On Linux!");
	#elif __unix__ // all unices, not all compilers
	    ai_logDebug("On Unix!");
	#elif __APPLE__
	    ai_logDebug("On Apple!");
	#else
		ai_logDebug("Unknown platform!");
	#endif
};