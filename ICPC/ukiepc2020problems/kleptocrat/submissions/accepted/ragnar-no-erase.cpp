#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<pair<int, long long>>> g(n);
	while(m--) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		--u, --v;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	// -1 if not visited yet; xor of path from root to here otherwise.
	vector<vector<long long>> done(64, vector<long long>(n, -1));
	vector<bool> bip(64, false);
	for(int i = 63; i >= 0; --i) {
		auto b = 1ll << i;

		auto& d = done[i];

		// Check whether the graph of edges containing b is bipartite.
		auto dfs = [&](int u, const auto& dfs) -> bool {
			assert(d[u] != -1);
			for(auto [v, w] : g[u]) {
				auto dv = d[u] ^ w;
				if(d[v] == -1) {
					d[v] = dv;
					if(not dfs(v, dfs)) return false;
				} else if(auto wc = d[v] ^ dv; wc & b) {
					// Found a cycle!
					// g[u].erase(v);
					// g[v].erase(u);
					// all edges containing b are xor'ed with wc.
					for(auto& s : g)
						for(auto& [v2, w2] : s)
							if(w2 & b) w2 ^= wc;
					return false;
				}
			}
			return true;
		};

		d[0]   = 0;
		bip[i] = dfs(0, dfs);
	}

	while(q--) {
		int x, y;
		cin >> x >> y;
		--x, --y;

		long long w = 0;
		for(int i = 63; i >= 0; --i) {
			if(not bip[i]) continue;
			auto xc = done[i][x];
			auto yc = done[i][y];
			assert(xc != -1 and yc != -1);
			w += (xc ^ yc) & (1ll << i);
		}
		cout << w << endl;
	}
}
