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

int main() {
	ll c, e, m;
	cin >> c >> e >> m;

	if(c == 4 && e % 2 == 0)
		for(int w = 2; 2 * w <= c + e && w * w <= c + e + m; ++w) {
			ll h = (c + e + m) / w;
			if(w * h != c + e + m) continue;
			if(c + e == 2 * (w - 1) + 2 * (h - 1)) {
				cout << w << ' ' << h << endl;
				exit(0);
			}
		}
	cout << "impossible" << endl;
}
