#include "validation.h"

int main(int argc, char** argv) {
	std::ifstream in(argv[1]);
	std::ifstream ans(argv[2]);
	OutputValidator v(argc, argv);

	std::string s;
	ans >> s;

	if(s == "impossible")
		v.test_string("impossible");
	else
		v.read_integer("answer", 0, 1e18);
	v.newline();

	return 0;
}
