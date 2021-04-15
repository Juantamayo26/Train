#include "validation.h"

using namespace std;

const long long MAXWH = 1'000'000'002;

int main(int argc, char** argv) {
	// Set up the input and answer streams.
	std::ifstream in(argv[1]);
	std::ifstream ans(argv[2]); // Only for custom checker.
	OutputValidator v(argc, argv);

	long long c, e, m;
	in >> c >> e >> m;

	string expected;
	ans >> expected;

	if(expected == "impossible") {
		v.test_string("impossible");
	} else {
		__int128 w = v.read_integer("w", 2, MAXWH);
		v.space();
		__int128 h = v.read_integer("h", 2, MAXWH);

		v.check(m == (w - 2) * (h - 2), "different number of center pieces");
		v.check(e == 2 * (w - 2) + 2 * (h - 2), "different number of edge pieces");
		v.check(c == 4, "different number of corner pieces");
	}

	v.newline();

	return 0;
}
