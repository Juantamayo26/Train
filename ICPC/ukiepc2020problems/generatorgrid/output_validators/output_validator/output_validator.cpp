#include "validation.h"

int main(int argc, char** argv) {
	// Set up the input and answer streams.
	std::ifstream in(argv[1]);
	OutputValidator v(argc, argv);

	int n;
	in >> n;
	v.read_integer("answer", n, (long long)(n)*1'000'000'000LL);
	v.newline();
}
