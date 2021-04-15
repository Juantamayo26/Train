#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 4, 100'000);
	v.newline();
	v.check(n % 4 == 0, "n must be divisible by 4.");
	v.read_integers("permutation", n, 1, n, Unique);
}
