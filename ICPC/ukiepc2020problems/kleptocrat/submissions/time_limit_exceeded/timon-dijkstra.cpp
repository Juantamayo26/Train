#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct E {
	int v;
	ll w;
	E(ll _v, ll _w) : v(_v), w(_w) {}
	bool operator<(const E& o) const { return w > o.w; }
};

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<E>> G(n);
	for(ll u, v, w; m--;) {
		cin >> u >> v >> w;
		u--;
		v--;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}

	for(int a, b; q--;) {
		cin >> a >> b;
		a--;
		b--;
		vi dist(n, -1);
		priority_queue<E> pq;
		pq.push({a, dist[a] = 0});
		while(!pq.empty()) {
			E t = pq.top();
			pq.pop();
			if(dist[t.v] != t.w) continue;
			for(const E& e : G[t.v])
				if(dist[e.v] == -1 || (dist[t.v] ^ e.w) < dist[e.v])
					pq.push({e.v, dist[e.v] = (dist[t.v] ^ e.w)});
		}
		cout << dist[b] << '\n';
	}
}
