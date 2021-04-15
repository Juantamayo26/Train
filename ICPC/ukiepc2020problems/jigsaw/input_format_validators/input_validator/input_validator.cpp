#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	v.read_integer("c", 0, 1'000'000'000);
	v.space();
	v.read_integer("e", 0, 1'000'000'000);
	v.space();
	v.read_integer("m", 0, 1'000'000'000);
	v.newline();
	return 0;
}
