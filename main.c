#include "alpha_infection.h"

// Main app Launch
int main(int argc, char const * argv[]) {
	bool initSuccess = false;

	initSuccess = AI_init();
	if (initSuccess) {
		AI_shutdown();
	}

	return 0;
};