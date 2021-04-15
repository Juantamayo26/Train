#include "validation.h"

// Checks that the input gives the height, width of the grid, and that an h x w grid follows.

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int h = v.read_integer("h", 1, 500);
	v.space();
	int w = v.read_integer("w", 1, 500);
	v.newline();
	for(int i = 0; i < h; i++) v.read_integers("b", w, 0, 1000000000);
	return 0;
}
