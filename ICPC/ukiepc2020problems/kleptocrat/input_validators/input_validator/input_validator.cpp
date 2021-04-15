#include "validation.h"

#include <stack>

using namespace std;

// Check the grammar of the input files.
// You should also check properties of the input.
// E.g., check that a graph is connected.
// TODO: Remove this comment, and summarize your input validator.

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 2, 10000);
	v.space();
	int m = v.read_integer("m", n-1, 100000);
	v.space();
	int q = v.read_integer("q", 1, 100000);
	v.newline();

	vector<vector<int>> adj(n);

	set<pair<int, int>> edges;

	for(int i = 0; i < m; i++) {
		int x = v.read_integer("x", 1, n);
		v.space();
		int y = v.read_integer("y", 1, n);
		v.space();
		long long w = v.read_integer("w", 0, 1'000'000'000'000'000'000LL);
		v.newline();

		v.check(x != y, "Self loops are not allowed!");

		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);

		edges.emplace(min(x, y), max(x, y));
	}

	v.check(edges.size() == m, "Graph is not simple!");

	stack<int> s;
	vector<bool> done(n, false);
	done[0] = true;
	s.push(0);

	while(!s.empty()) {
		int cur = s.top();
		s.pop();
		for(int nb : adj[cur]) {
			if(!done[nb]) {
				done[nb] = true;
				s.push(nb);
			}
		}
	}

	if(!all_of(done.begin(), done.end(), [](bool v) { return v; })) {
		v.WA("Graph not connected.");
	}

	for(int i = 0; i < q; i++) {
		int a = v.read_integer("a", 1, n);
		v.space();
		int b = v.read_integer("b", 1, n);
		v.newline();
	}
}
