#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<tuple<int, long long, bool>>> g(n);
	while(m--) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		--u, --v;
		g[u].emplace_back(v, w, true);
		g[v].emplace_back(u, w, true);
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
			for(auto& [v, w, active] : g[u]) {
				if(not active) continue;
				auto dv = d[u] ^ w;
				if(d[v] == -1) {
					d[v] = dv;
					if(not dfs(v, dfs)) return false;
				} else if(auto wc = d[v] ^ dv; wc & b) {
					// Found a cycle!
					active = false;
					for(auto& [v2, w2, active2] : g[v])
						if(v2 == u) {
							active2 = false;
							break;
						}
					// g[u].erase(v);
					// g[v].erase(u);
					// all edges containing b are xor'ed with wc.
					for(auto& s : g)
						for(auto& [v2, w2, active2] : s)
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
