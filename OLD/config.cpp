#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "utils.h"
#include "log.h"

/* ai_cfgFile
 *
 * Scope: Private (not in config.h)
 * Params: None
 * Return: char ptr
 *
 * Description: Determine the proper file path for accessing the
 * AlphaInfection configuration file.
 *
 */
char * ai_cfgFile(void) {
	const char * configName = ".airc";
	const char * homeDir = ai_utilGetHomeDir();

	int filePathSize = 2;
	filePathSize += strlen(homeDir);
	filePathSize += strlen(configName);

	char * filePath = (char *)malloc(sizeof(char) * filePathSize);

	sprintf(filePath, "%s/%s", homeDir, configName);

	return filePath;
}

/* ai_cfgLoad
 *
 *
 *
 *
 */
cfg_t * ai_cfgLoad(void) {
	const char * configPath = ai_cfgFile();
	ai_logDebug("Loading: %s", configPath);

	cfg_opt_t opts[] = {
		CFG_STR("log_level", "debug", CFGF_NONE),
		CFG_STR("name", "Marine", CFGF_NONE),
		CFG_END()
	};
	cfg_t * localConfig;
	localConfig = cfg_init(opts, CFGF_NONE);

	if (cfg_parse(localConfig, configPath) == CFG_PARSE_ERROR) {
		ai_logError("Error parsing config file!");
		return NULL;
	}

	return localConfig;
}

int ai_cfgUnload(cfg_t * cfgResource) {
	int result = 0;

	result = cfg_free(cfgResource);
	if (result != 0) {
		ai_logError("Unable to unload config! Error %d", result);
		// TODO: Check into libconfuse for error messages here
	} else {
		ai_logInfo("Successfully unload configuration.");
		cfgResource = NULL;
	}

	return result;
}

int ai_cfgSave(cfg_t * cfgResource) {
	const char * configPath = ai_cfgFile();
	ai_logDebug("Saving: %s", configPath);

	// TODO: overwrite the cfgResource here

	return 0;
}
