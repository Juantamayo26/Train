#include "validation.h"

// One integer 1 <= N <= 100; newline
// N lines with one number 1 <= k <= 42 and k strings with length between 1 and 20

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	const int n = v.read_integer("n", 1, 100);
	v.newline();
	for(int i = 0; i < n; ++i){
		const int k = v.read_integer("k", 1, 42);
		v.space();
		v.read_strings("s", k, 1, 20, "abcdefghijklmnopqrstuvwxyz", Unique);
	}
}
