#include "validation.h"

int main(int argc, char** argv) {
	// Set up the input and answer streams.
	std::ifstream in(argv[1]);
	// std::ifstream ans(argv[2]); // Only for custom checker.
	OutputValidator v(argc, argv);

	int n, m, q;
	in >> n >> m >> q;
	v.read_integers("distance", q, 0, (1LL<<60)-1, Arbitrary, Newline);
}
