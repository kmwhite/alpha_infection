#include <iostream>
#include <string>

int main(const int argc, const char * argv[]) {
	std::string testString = "Hello World!";

	std::cout << "Testing function parameters:\n";
	std::cout << "Set argument to: '" << testString << "'\n";

	std::string foo;
	// pass_by_value()
	// confirm unchanged string
	// pass_by_reference()
	// confirm unchanged string
	// modify_by_reference()
	// config changed string
	return 0;
}

void pass_by_value(std::string argument) {
	std::cout << " => Modifying Reference Value!";
}

void pass_by_reference(const std::string &argument) {
	std::cout << " => Pass by Reference Value!";
}

void modify_by_reference(std::string &argument) {
	std::cout << " => Modifying Reference Value!";
}
