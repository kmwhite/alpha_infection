#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "config.h"
#include "utils.h"

char * ai_cfgFile(void) {
    const char * configName = ".airc";
    const char * homeDir = ai_utilGetHomeDir();
    
    int filePathSize = 2;
    filePathSize += strlen(homeDir);
    filePathSize += strlen(homeDir);

    char * filePath = (char *)malloc(sizeof(char) * filePathSize);
    
    sprintf(filePath, "%s/%s", homeDir, configName);

    return filePath;
}

cfg_t * ai_cfgLoad(void) {
    const char * configPath = ai_cfgFile();
    printf("%s\n", configPath);

    cfg_opt_t opts[] = {
        CFG_STR("log_level", "debug", CFGF_NONE),
        CFG_STR("name", "Marine", CFGF_NONE),
        CFG_END()
    };
    cfg_t * localConfig;
    localConfig = cfg_init(opts, CFGF_NONE);

    if (cfg_parse(localConfig, configPath) == CFG_PARSE_ERROR) {
        return NULL;
    }

    return localConfig;
}