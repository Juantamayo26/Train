#include "validation.h"

int main(int argc, char** argv) {
	// Set up the input and answer streams.
	std::ifstream in(argv[1]);
	// std::ifstream ans(argv[2]); // Only for custom checker.
	OutputValidator v(argc, argv);

	int input;
	in >> input;
	int answer = v.read_integer("answer", 0, 500 * 500 / 2);
	v.newline();
}
