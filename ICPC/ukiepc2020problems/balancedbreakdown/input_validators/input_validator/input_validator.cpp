#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 1, 1'000'000'000'000'000'000 - 1LL);
	v.newline();
	return 0;
}
