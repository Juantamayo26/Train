#include<algorithm>
#include<bitset>
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

const int maxp = 100;

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

	vector<bitset<maxp>> on_sp(n);
	vector<vii> G(n);
	vi v(p); // people's position

	for (int &x : v)
		cin >> x, x--;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		G[--a].emplace_back(--b, c);
		G[b].emplace_back(a, c);
	}

	// the 'route' might not be unique!
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

	for (int i=0; i<p; i++)
		on_sp[v[i]].set(i);

	long long res = dry;

	for (int i : order) {
		int shorter = to_bapc[i] - g;
		if (shorter <= 0) break;
		res = min(res, dry - ((long long) on_sp[i].count()) * shorter);
		for (auto [j, w] : G[i])
			if (to_bapc[j] + w == to_bapc[i])
				on_sp[j] |= on_sp[i];
	}

	cout << res << endl;
	return 0;
}
