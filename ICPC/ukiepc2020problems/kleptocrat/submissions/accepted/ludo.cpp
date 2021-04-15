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

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 10'000;

vector<ii> E[MAXN];
ll xor_to_root[MAXN] = {};
bool vis[MAXN]       = {};
vector<ll> masks; // size(masks) <= m

void dfs(int u, int v) {
	assert(!vis[v]);
	vis[v] = true;

	for(ii edge : E[v]) {
		int w = (int)edge.first;
		if(u == w) continue;

		ll xor_value = xor_to_root[v] ^ edge.second;
		if(vis[w] && xor_value != xor_to_root[w]) {
			// cycle reduction:
			masks.pb(xor_value ^ xor_to_root[w]);
		} else if(!vis[w]) {
			xor_to_root[w] = xor_value;
			dfs(v, w);
		}
	}
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	for(int i = 0; i < m; i++) {
		ll x, y, cost;
		cin >> x >> y >> cost;
		x--;
		y--;
		E[x].eb(y, cost);
		E[y].eb(x, cost);
	}

	xor_to_root[0] = 0;
	dfs(0, 0);

	// now find the row-reduced form of the bitmasks
	sort(masks.begin(), masks.end());
	masks.resize(unique(masks.begin(), masks.end()) - masks.begin());

	vector<ll> basis;
	for(int bit = 63; bit >= 0; bit--) {
		for(int i = 0; i < (int)masks.size(); i++) {
			if(~(masks[i] >> bit) & 1) continue;
			ll vec = masks[i];

			for(ll& v : basis)
				if((v >> bit) & 1) v ^= vec;

			basis.pb(vec);
			masks[i] = masks.back();
			masks.pop_back();

			for(int j = i; j < (int)masks.size(); j++)
				if((masks[j] >> bit) & 1) masks[j] ^= vec;
		}
	}

	while(q--) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		ll value = xor_to_root[x] ^ xor_to_root[y];
		for(ll vec : basis) {
			if((value ^ vec) < value) value ^= vec;
		}

		printf("%lld\n", value);
	}

	return 0;
}
