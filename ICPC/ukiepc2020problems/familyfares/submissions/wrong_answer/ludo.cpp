#include<algorithm>
#include<cassert>
#include<climits>
#include<iostream>
#include<set>
#include<vector>
#include<utility>
using namespace std;

#define x first
#define y second
#define sz(v) ((int) (v).size())

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

// (dist, prev)
pair<vi,vi> dijkstra(const vector<vii> &G, int s) {
	vi d(sz(G), INT_MAX), p(sz(G), -1);
	set<ii> Q{ ii{ d[s] = 0, s } }; // (dist[v], v)
	while (!Q.empty()) {
		int v = Q.begin()->y;
		Q.erase(Q.begin());
		for(ii e : G[v]) if (d[v] + e.y < d[e.x]) {
			Q.erase(ii(d[e.x], e.x));
			Q.emplace(d[e.x] = d[v] + e.y, e.x);
			p[e.x] = v;
		}
	}
	return {d, p};
}

int main() {
	int n, m, p, g;
	cin >> n >> m >> p >> g;

	vi v(p);
	for (int &x : v)
		cin >> x, x--;

	vector<vii> G(n);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		G[--a].emplace_back(--b, c);
		G[b].emplace_back(a, c);
	}

	auto [to_bapc, route] = dijkstra(G, 0);

	long long dry = 0;
	for (int x : v)
		dry += to_bapc[x];

	// possible reduction at location s:
	// #{x in v | s on shortest path 0 -- s -- x} * (g - to_bapc[s]).
	vi order;
	for (int i=0; i<n; i++)
		order.push_back(i);
	sort(order.begin(), order.end(), [&] (int a, int b) -> bool {
		return to_bapc[a] > to_bapc[b];
	});

	vi nr_x(n, 0);
	for (int x : v)
		nr_x[x]++;

	long long res = dry;

	for (int i : order) {
		if (route[i] >= 0) {
			nr_x[route[i]] += nr_x[i];
			res = min(res, dry + nr_x[i] * (g - to_bapc[i]));
		}
	}
	assert(nr_x[0] == p);
	cout << res << endl;
	return 0;
}
