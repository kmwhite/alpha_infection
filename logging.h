#include <stdio.h>
#include <stdlib.h>

void ai_logMessage(const char * log_level, const char * message);

void ai_logDebug(const char * message);

void ai_logInfo(const char * message);

void ai_logWarning(const char * message);

void ai_logFatal(const char * message);

void ai_logPlatform(void);