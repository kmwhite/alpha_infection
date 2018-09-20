#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>

const char * ai_utilGetHomeDir(void) {
    const char *homeEnvVar = "HOME";
    char * homeDir;
    homeDir = getenv(homeEnvVar);
    return homeDir;
}