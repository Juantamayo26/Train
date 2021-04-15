#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct E {
	int v;
	ll w;
};

void dfs(int u, const vector<vector<E>>& G, vi& x, vi& vec) {
	for(const E& e : G[u])
		if(x[e.v] == -1)
			x[e.v] = (x[u] ^ e.w), dfs(e.v, G, x, vec);
		else
			vec.push_back(x[u] ^ e.w ^ x[e.v]);
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<E>> G(n);
	for(ll u, v, w; m--;) {
		cin >> u >> v >> w;
		u--;
		v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	vi x(n, -1), vec;
	dfs(x[0] = 0, G, x, vec);

	size_t basis = 0;
	while(true) {
		for(size_t i = basis + 1; i < vec.size(); ++i)
			if(vec[i] > vec[basis]) swap(vec[i], vec[basis]);
		if(vec[basis] == 0) break;
		for(size_t i = basis + 1; i < vec.size(); ++i)
			if((vec[i] ^ vec[basis]) < vec[i]) vec[i] ^= vec[basis];
		++basis;
	}

	for(int a, b; q--;) {
		cin >> a >> b;
		a--;
		b--;
		int ans = (x[a] ^ x[b]);
		for(size_t i = 0; i < basis; ++i)
			if((ans ^ vec[i]) < ans) ans ^= vec[i];
		cout << ans << '\n';
	}
}
