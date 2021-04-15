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
#include <algorithm>
using namespace std;

using ll = long long;
using vi = vector<ll>;

struct UnionFind {
	vi par, rank, size;
	int c;
	UnionFind(int n) : par(n), rank(n, 0), size(n, 1), c(n) {
		for(int i = 0; i < n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }
	int merge(int i, int j) {
		if((i = find(i)) == (j = find(j)))
			return -1;
		else
			--c;
		if(rank[i] > rank[j]) swap(i, j);
		par[i] = j;
		size[j] += size[i];
		if(rank[i] == rank[j]) rank[j]++;
		return j;
	}
};

struct Edge {
	int a, b;
	ll cost;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<Edge> edges;
	while(m--) {
		int t, a;
		cin >> t >> a;
		edges.push_back({0, t, (ll)a});
	}
	for(int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		edges.push_back({i + 1, (i + 1) % n + 1, (ll)b});
	}

	sort(edges.begin(), edges.end(), [](const Edge& l, const Edge& r) { return l.cost < r.cost; });

	ll ans = 0LL;
	UnionFind uf(n + 1);
	for(Edge e : edges) {
		if(!uf.same(e.a, e.b)) ans += e.cost;
		uf.merge(e.a, e.b);
	}
	cout << ans << endl;
}
