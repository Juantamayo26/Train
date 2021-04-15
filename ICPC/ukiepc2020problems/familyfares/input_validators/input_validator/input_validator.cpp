#include "validation.h"

#include <queue>

int main(int argc, char** argv) {
	InputValidator v(argc, argv);
	int n = v.read_integer("n", 2, 1'000);
	v.space();
	int m = v.read_integer("m", 1, 100'000);
	v.space();
	int p = v.read_integer("p", 1, 100);
	v.space();
	int g = v.read_integer("g", 1, 1'000'000);
	v.newline();

	v.read_integers("v", p, 1, n);

	std::vector<std::vector<int>> adj(n);
	std::set<std::pair<int, int>> edges;

	for(int i = 0; i < m; ++i) {
		int a = v.read_integer("a", 1, n);
		v.space();
		int b = v.read_integer("b", 1, n);
		v.space();
		v.read_integer("c", 1, 1'000'000);
		v.newline();
		v.check(a != b, "Roads should not be loops.");

		edges.emplace(std::min(a - 1, b - 1), std::max(a - 1, b - 1));
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}

	v.check(edges.size() == m, "Graph is not simple!");
	std::vector<bool> visited(n, false);
	visited[0] = true;
	std::queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : adj[u]) {
			if(!visited[v]) {
				visited[v] = true;
				q.push(v);
			}
		}
	}

	if(!all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
		v.WA("Graph not connected");
	}
}
