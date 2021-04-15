#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct UnionFind {
	vector<int> par, rank, size;
	int c;
	UnionFind(int n) : par(n), rank(n, 0), size(n, 1), c(n) {
		for(int i = 0; i < n; ++i) par[i] = i;
	}

	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }

	void merge(int i, int j) {
		if((i = find(i)) == (j = find(j))) return;
		c--;
		if(rank[i] > rank[j]) swap(i, j);
		par[i] = j;
		size[j] += size[i];
		if(rank[i] == rank[j]) rank[j]++;
	}
};

struct E {
	long long w;
	int u, v;
	bool operator<(const E& r) const { return w < r.w; }
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<E> g;
	while(m--) {
		int u;
		long long w;
		cin >> u >> w;
		--u;
		g.push_back({w, u, n});
	}
	for(int i = 0, j = 1; i < n; ++i, j = (j + 1) % n) {
		long long w;
		cin >> w;
		g.push_back({w, i, j});
	}
	sort(begin(g), end(g));
	UnionFind uf(n + 1);
	long long ans = 0;
	for(auto e : g)
		if(!uf.same(e.u, e.v)) uf.merge(e.u, e.v), ans += e.w;
	cout << ans << endl;
}
