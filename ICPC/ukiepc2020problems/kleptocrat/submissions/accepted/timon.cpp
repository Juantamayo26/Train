#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
struct E {
	int v;
	ll w;
};

void dfs(int u, const vector<vector<E>>& G, vector<ll>& xors, vector<ll>& rows) {
	for(const E& e : G[u])
		if(xors[e.v] == -1)
			xors[e.v] = (xors[u] ^ e.w), dfs(e.v, G, xors, rows);
		else
			rows.push_back(xors[u] ^ e.w ^ xors[e.v]);
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<E>> G(n);
	for(ll u, v, w; m--;) {
		cin >> u >> v >> w;
		u -= 1;
		v -= 1;
		G[u].push_back({static_cast<int>(v), w});
		G[v].push_back({static_cast<int>(u), w});
	}

	vector<ll> xors(n, -1), rows, basis;
	dfs(xors[0] = 0, G, xors, rows);
	do {
		basis.push_back(*max_element(rows.begin(), rows.end()));
		for(ll& v : rows) v = min(v, v ^ basis.back());
	} while(basis.back());

	for(int a, b; q--;) {
		cin >> a >> b;
		a--;
		b--;
		ll ans = (xors[a] ^ xors[b]);
		for(ll v : basis) ans = min(ans, ans ^ v);
		cout << ans << '\n';
	}
}
