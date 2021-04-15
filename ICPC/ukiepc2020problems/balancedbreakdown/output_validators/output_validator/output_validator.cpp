#include "validation.h"

bool is_palindrome(long long p) {
	auto s = std::to_string(p);
	auto t = s;
	reverse(begin(t), end(t));
	return s == t;
}

int main(int argc, char** argv) {
	// Set up the input and answer streams.
	std::ifstream in(argv[1]);
	OutputValidator v(argc, argv);

	long long n;
	in >> n;
	const int k = v.read_integer("k", 1, 10);
	v.newline();

	const std::vector<long long> ps = v.read_integers("p", k, 0, n, Arbitrary, Newline);

	v.check(accumulate(begin(ps), end(ps), 0ll) == n, "Sum of numbers is not ", n);

	for(auto p : ps) { v.check(is_palindrome(p), p, " is not a palindrome!"); }
}
