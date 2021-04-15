#include "validation.h"

const int maxn = 1000;

int main(int argc, char** argv) {
	InputValidator v(argc, argv);

	// first line
	int n = v.read_integer("n", 1, maxn);
	v.space();
	int k = v.read_integer("k", 1, n);
	v.newline();

	// second line
	v.read_integers("p", k, 1, n, StrictlyIncreasing);

	// third line
	v.read_integers("d", k, 1, n, StrictlyIncreasing);

	return 0;
}
