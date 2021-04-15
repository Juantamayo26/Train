#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

using ll = long long;
using vi = vector<ll>;

struct plant {
	int c;
	ll a;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<plant> plants;
	while(m--) {
		int t, a;
		cin >> t >> a;
		--t;
		plants.push_back({t, (ll)a});
	}
	vi j(n);
	for(int i = 0; i < n; ++i) cin >> j[i];

	size_t cheapest = 0;
	for(size_t j = 1; j < plants.size(); ++j)
		if(plants[j].a < plants[cheapest].a) cheapest = j;

	vi c(n + 1, -1);
	for(plant p : plants) c[p.c] = p.a;

	// Now we can assume we have a line and do DP on this.
	vi dp1(n + 1); // Power everything
	vi dp2(n + 1); // Power all but last segment
	for(int i = 1; i < n + 1; ++i) {
		// Connect to previous
		dp1[i] = dp1[i - 1] + j[i - 1];
		if(c[i] >= 0) dp1[i] = min(dp1[i], dp2[i - 1] + j[i - 1] + c[i]);
		dp2[i] = dp2[i - 1] + j[i - 1];
		// Don't connect to previous.
		dp2[i] = min(dp2[i], dp1[i - 1]);
		if(c[i] >= 0) { dp1[i] = min(dp1[i], dp1[i - 1] + c[i]); }
	}
	cout << dp1.back() << endl;
}
