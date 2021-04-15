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
#include <queue>
#include <bitset>
using namespace std;

/* Note: this solution also works when shortest paths are not unique. */

using ll  = long long;
using vi  = vector<ll>;
using vvi = vector<vi>;

struct E {
	int v;
	ll c;
	bool operator<(const E& o) const { return c > o.c; }
};

vi dijkstra(int s, vector<vector<E>>& edges) {
	vi dist(edges.size(), -1);
	priority_queue<E> pq;
	pq.push({s, dist[s] = 0});
	while(!pq.empty()) {
		int u = pq.top().v;
		ll d  = pq.top().c;
		pq.pop();
		if(dist[u] != d) continue;

		for(const auto& e : edges[u])
			if(dist[e.v] == -1 || dist[e.v] > dist[u] + e.c)
				pq.push({e.v, dist[e.v] = dist[u] + e.c});
	}
	return dist;
}

void dfs(int u, vector<vector<E>>& edges, const vvi& s, vector<bitset<100>>& pass) {
	for(int i : s[u]) pass[u].set(i, 1);
	for(const auto& e : edges[u]) dfs(e.v, edges, s, pass), pass[u] |= pass[e.v];
	edges[u].clear();
}

int main() {
	int n, m, p, g;
	cin >> n >> m >> p >> g;

	vvi s(n);
	for(int i = 0, vi; i < p; ++i) cin >> vi, s[vi - 1].push_back(i);

	vector<vector<E>> edges(n);
	for(int a, b, c, j = 0; j < m; ++j)
		cin >> a >> b >> c, --a, --b, edges[a].push_back({b, (ll)c}),
		    edges[b].push_back({a, (ll)c});

	vi dist = dijkstra(0, edges);
	for(int u = 0; u < n; ++u) {
		size_t last = 0;
		for(size_t i = 0; i < edges[u].size(); ++i) {
			E& e = edges[u][i];
			if(dist[u] + e.c == dist[e.v]) swap(edges[u][i], edges[u][last]), ++last;
		}
		edges[u].erase(edges[u].begin() + last, edges[u].end());
	}

	ll base = 0LL;
	for(int u = 0; u < n; ++u) base += dist[u] * s[u].size();

	vector<bitset<100>> pass(n);
	dfs(0, edges, s, pass);

	ll ans = base;
	for(int u = 0; u < n; ++u) ans = min(ans, base + (g - dist[u]) * (ll)pass[u].count());
	cout << ans << endl;
}
