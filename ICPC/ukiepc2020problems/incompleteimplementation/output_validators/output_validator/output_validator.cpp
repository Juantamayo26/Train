#include "validation.h"

int main(int argc, char** argv) {
	// Set up the input and answer streams.
	std::ifstream in(argv[1]);
	// std::ifstream ans(argv[2]); // Only for custom checker.
	OutputValidator v(argc, argv);

	int n;
	in >> n;
	std::vector<int> perm(n);
	for(auto& x : perm) in >> x;

	const int moves = v.read_integer("moves", 0, 3);
	v.newline();
	for(int m = 0; m < moves; ++m) {
		std::vector<long long> positions = v.read_integers("positions", n / 2, 1, n, Unique);
		sort(begin(positions), end(positions));
		std::vector<int> values(n / 2);
		for(int i = 0; i < n / 2; ++i) values[i] = perm[positions[i] - 1];
		sort(begin(values), end(values));
		for(int i = 0; i < n / 2; ++i) perm[positions[i] - 1] = values[i];
	}

	std::vector<int> target(n);
	std::iota(begin(target), end(target), 1);
	if(perm != target) {
		// for(auto x : perm) std::cerr << x << " ";
		// std::cerr << std::endl;
		v.check(perm == target, "Permutation is not sorted!");
	}
}
