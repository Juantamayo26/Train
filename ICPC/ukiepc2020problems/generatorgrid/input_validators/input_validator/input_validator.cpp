#include "validation.h"

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 3, 100000);
	v.space();
	int m = v.read_integer("m", 1, n);
	v.newline();

	int lastt = -1;
	for(int i = 0; i < m; ++i) {
		int t = v.read_integer("c_i", 1, n);
		if(lastt >= t) { v.WA("Cities should be given as a strictly increasing sequence."); }
		lastt = t;
		v.space();
		v.read_integer("a_i", 1, 1'000'000'000);
		v.newline();
	}
	v.read_integers("b", n, 1, 1'000'000'000);
}
