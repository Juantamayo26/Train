#include "validation.h"

using namespace std;

int main(int argc, char** argv) {
	// Set up the input and answer streams.
	std::ifstream in(argv[1]);
	OutputValidator v(argc, argv);

	int n;
	in >> n;
	vector<set<string>> input(n);
	set<string> dishes;
	for(auto& l : input) {
		int k;
		in >> k;
		for(int i = 0; i < k; ++i) {
			string s;
			in >> s;
			l.insert(s);
			dishes.insert(s);
		}
	}

	const int count = v.read_integer("count", 1, 42);
	v.newline();

	auto ans = v.read_strings("s", count, 1, 20, "abcdefghijklmnopqrstuvwxyz", Unique, Newline);
	set<string> ans_set;
	for(const auto& x : ans) {
		v.check(dishes.count(x), "Team printed ", x, " which is not in the input.");
		ans_set.insert(x);
	}

	bool ac = false;
	for(const auto& l : input) {
		if(l == ans_set) { v.eof_and_AC(); }
	}
	v.WA("Team output set is not equal to any input list.");
}
