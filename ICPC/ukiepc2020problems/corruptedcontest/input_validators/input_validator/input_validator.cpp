#include "validation.h"

constexpr int N    = 10'000;
constexpr int MaxT = 1'000'000;

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 1, N);
	v.space();
	int np = v.read_integer("p", 1, N);
	v.newline();
	v.read_integers("v", n, 0, MaxT, Arbitrary, Newline);
}
