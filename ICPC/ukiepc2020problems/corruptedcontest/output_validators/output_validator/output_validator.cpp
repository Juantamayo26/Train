#include "validation.h"

int main(int argc, char** argv) {
	// Set up the input and answer streams.
	std::ifstream in(argv[1]);
	// std::ifstream ans(argv[2]); // Only for custom checker.
	OutputValidator v(argc, argv);

	if(v.peek('a')) {
		v.test_string("ambiguous");
		v.newline();
	} else {
		int n;
		in >> n;
		v.read_integers("v", n, 0, 10'000, Arbitrary, Newline);
	}
}
